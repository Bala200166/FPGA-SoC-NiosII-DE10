//-------------------------------------------------------
//		My_Filter.v
//
//-------------------------------------------------------

module My_Filter(
	input					Clock,
	input					Resetn,
	input					Cpu_ChipSel,
	input					Cpu_R,
	input					Cpu_W,
	input		[2:0]		Cpu_Addrs,
	input		[31:0]	Cpu_DataWr,
	output	[31:0]	Cpu_DataRd
);

parameter LINE_LENGHT = 384;

	//--------------------------------------------------------------------------
	//---	Declaration des SIGNAUX
	//--------------------------------------------------------------------------
	reg	[31:0]	DataOut;
	reg	[7:0]		Min;
	reg	[7:0]		Old_Min;
	reg	[7:0]		Max;
	reg	[3:0]		State;
	reg	[7:0]		re;
	reg	[7:0]		gr;
	reg	[7:0]		bl;
	reg	[31:0]	Y;
	reg	[15:0]	Fact;

	reg [7:0] a [2:0];			// First line of the matrix
	reg [7:0] b [2:0];			// Second line of the matrix
	reg [7:0] c [2:0];			// Third line of the matrix

	reg [31:0] resreg;			// Result of computation

	reg [7:0] liga [LINE_LENGHT-3-1:0];	// Shift register of the fist line
	reg [7:0] ligb [LINE_LENGHT-3-1:0];  // Idem for the second line


	//--------------------------------------------------------------------------
	//		Cpu_W & Adr = 1 --> init
	//		Cpu_W & Adr = 0 --> New RGB
	//		Cpu_R & Adr = 0 --> Read New Y
	//--------------------------------------------------------------------------

	integer n;

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
						bl <= Cpu_DataWr[24:16];
						gr <= Cpu_DataWr[15:8];
						re <= Cpu_DataWr[7:0];
						State <= 2;
					end

			//if ((Cpu_R == 1) && (Cpu_Addrs == 'b000))
			//			DataOut <= (Y | (Y << 8) | (Y << 16));	
	
			if ((Cpu_R == 1) && (Cpu_Addrs == 'b001))
					DataOut <= 'h12345678;	
					
			case (State)
			
				1:
					begin
							Min <= 255;
							Max <= 0;	
							State <= 0;
					end
				2:
					begin
							Y <= (77 * re + 150 * gr + 29 * bl) >> 8;
							State <= 3;
					end
				3:
					begin
							if (Min > Y)
								Min <= Y;
							if (Max < Y)
								Max <= Y;
							Y <= (((Y - Old_Min) * Fact) >> 8)&255;
							State <= 4;
					end
				4:			
					begin
							for (n=2;n>0;n=n-1)							// Shift of calulation buffer line c
								c[n] = c[n-1];

							c[0] = ligb[LINE_LENGHT-3-1];
							
							for (n=LINE_LENGHT-3-1;n>0;n = n-1)		// Shift of line buffer B
								ligb[n] = ligb[n-1];
							ligb[0] = b[2];	
			
							for (n=2;n>0;n=n-1)							// Shift of calulation buffer line b
								b[n] = b[n-1];
								
							b[0] = liga[LINE_LENGHT-3-1];
		 
							for (n=LINE_LENGHT-3-1;n>0;n = n-1)						// Shift of line buffer B
								liga[n] = liga[n-1];
								
							liga[0] = a[2];	

							for (n=2;n>0;n=n-1)										// Shift of calulation buffer
								a[n] = a[n-1];

							a[0] = Y;


//							for (n=0;n<3;n=n+1)									// comput convolution product
//							ny = -y00 - y01 - y10 + y12  + y21 + y22;
//							resreg = a[0] + a[1] + a[2] + b[0] + b[1] + b[2] + c[1] + c[2] + c[3];				
//							resreg = -a[0] - a[1] - b[0] + b[2] + c[1] + c[2];					;
								
							State <= 5;
					end
				5:			
					begin
						resreg <= ((a[0] + a[1] + a[2] + b[0] + b[1] + b[2] + c[0] + c[1] + c[2])/10) & 255;
							State <= 6;
					end	
		
				6:			
					begin
						DataOut <= (resreg | (resreg << 8) | (resreg << 16));
						State <= 0;
					end
					
				default: 
						State <= 0;

			endcase
		end
	end
	assign Cpu_DataRd = DataOut;	
endmodule
