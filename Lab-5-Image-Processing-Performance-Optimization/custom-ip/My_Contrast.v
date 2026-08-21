//-------------------------------------------------------
//		My_Contrast.v
//
//-------------------------------------------------------

module My_Contrast(
	input					Clock,
	input					Resetn,
	input					Cpu_ChipSel,
	input					Cpu_R,
	input					Cpu_W,
	input		[2:0]		Cpu_Addrs,
	input		[31:0]	Cpu_DataWr,
	output	[31:0]	Cpu_DataRd
);



	//--------------------------------------------------------------------------
	//---	Declaration des SIGNAUX
	//--------------------------------------------------------------------------
	reg	[31:0]	DataOut;
	reg	[7:0]		Min;
	reg	[7:0]		Old_Min;
	reg	[7:0]		Max;
	reg	[3:0]		State;
	reg	[7:0]		r;
	reg	[7:0]		g;
	reg	[7:0]		b;
	reg	[31:0]	Y;
	reg	[15:0]	Fact;



	//--------------------------------------------------------------------------
	//		Cpu_W & Adr = 1 --> init
	//		Cpu_W & Adr = 0 --> New RGB
	//		Cpu_R & Adr = 0 --> Read New Y
	//--------------------------------------------------------------------------


	always @(posedge Clock)
	begin
		if (Resetn == 0) begin
			// Initialiser a 0 
			DataOut <= 52;
			State <= 0;
			Max <= 254;
			Min <= 1;
		end 
		else begin
		if ((Cpu_W == 1) && (Cpu_Addrs == 'b001))
					begin
						Min <= 20;
						Max <= 250;
						Fact <= (65280 / (Max - Min));
						Old_Min <= Min;
						State <= 1;
					end
								
		if ((Cpu_W == 1) && (Cpu_Addrs == 'b000))
					begin
						b <= Cpu_DataWr[24:16];
						g <= Cpu_DataWr[15:8];
						r <= Cpu_DataWr[7:0];
						State <= 2;
					end

		//if ((Cpu_R == 1) && (Cpu_Addrs == 'b000))
		//			DataOut <= (Y | (Y << 8) | (Y << 16));	
	
		if ((Cpu_R == 1) && (Cpu_Addrs == 'b001))
					DataOut <= 'h12345678;									
		if  (State == 1)
					begin
							Min <= 255;
							Max <= 0;	
							State <= 0;
						end
		if  (State == 2)
					begin
							Y <= (77 * r + 150 * g + 29 * b) >> 8;
							State <= 3;
						end
		if  (State == 3)
						begin
							if (Min > Y)
								Min <= Y;
							if (Max < Y)
								Max <= Y;
							State <= 4;
						end
		if  (State == 4)			
						begin
							Y <= (((Y - Old_Min) * Fact) >> 8)&255;
							State <= 5;
						end
		if  (State == 5)			
						begin
							DataOut <= (Y | (Y << 8) | (Y << 16));
							State <= 0;
						end

		end
	end
	assign Cpu_DataRd = DataOut;	
endmodule
