//----------------------------------------------------------------------------------
//	CopyCam.c
//
//----------------------------------------------------------------------------------

#include	<stdio.h>
#include	"APP_CamParam.h"
#include "system.h"
#include "alt_types.h"
#include "altera_avalon_pio_regs.h"
#include "altera_avalon_performance_counter.h"


S_IP_INIT	Sparam;

//#define   USE_FLOAT

// Choisir l'exposition en fonction de la luminosité
// valeur entre 0x0800 et 0x6000 par pas de 0x0100 ou 0x1000
#define		EXPO_TIME	0x600

int		main()
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
{
	int nerr;	uint16  Version;

	printf("\n -----------  Hello from Nios II/e.  Test LCD + Camera VT  -------------   \n");

	Sparam.ImgNbrPx = CAM_NBPIX;	Sparam.ImgNbrLn = CAM_NBLIN;	// taille de l'image du capteur
	Sparam.AfiNbrPx = FEN_NBPIX;	Sparam.AfiNbrLn = FEN_NBLIN;	// taille de l'affichage
	Sparam.AfiZoom  = 1;			Sparam.CamFocus = 0;
	Sparam.Expotime = EXPO_TIME;	Sparam.Expogain = 0x0200;
	Sparam.Color	= COLOR_BGR_FOND;

	DE10Sys_Initialize(&Sparam, &Version);

	printf("\n         --- LCD Hard IP version read = 0x%04X  \n", Version & 0x0FFFF);

	nerr  = DE10Sys_InitInterupt();		// init des interruptions boutons, switchs
	nerr += DE10Sys_InitTactile( );		// init des interruptions ecran tactile
										//
	if (nerr == 0) {
		DE10Sys_AffiEnable();
		Affi_Pattern();
		DE10CAM_RunCapture();			// activer la cam�ra
		App_UserLoop(&Sparam);
	}
	else
		printf("\n  ++++++ erreur d'initialisation des interruptions  ++++++ \n\n");

	printf("\n -----------  Fin de l'application  -------------   \n");

	return 0;
}



volatile int	*MyIP_Addres;



void	App_UserLoop(S_IP_INIT* param)
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
{
	alt_u64 counter;	int n, time;	short result;
	float im;
	MyIP_Addres = (int*)MYIP_BUSMAP;


	while (1) {
		PERF_RESET(PERFCOUNTER_BASE);
		PERF_START_MEASURING(PERFCOUNTER_BASE);
		PERF_BEGIN(PERFCOUNTER_BASE, 1);
		My_Copy();
		PERF_END(PERFCOUNTER_BASE, 1);
		counter = perf_get_section_time((void*)PERFCOUNTER_BASE, 1);
		time = counter / 1000;
		printf("Number of cycles = %lld  -    ", counter);
		im = (float) 50 / ((float) time / 1000);
		printf("%f images / sec\n", im);
		Test_Touche(NULL);
	}
}



void	My_Copy(void)
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
{	uint32 pix, npix;
    uint32 *adpixin, *adpixout;
    int lin,col;
    int i,j;

    int g,r,b,y;


    for (i=0;i<FEN_NBLIN;i++)
    {
        adpixin = DE10Affi_GetAdresse(0, i);
        adpixout = adpixin + DST_DEBPIX;     // 400 pixels further
    	for(j=0;j<FEN_NBPIX;j++)
    	{
    		pix = *adpixin++;
    		npix = pix;
    		*adpixout++ = npix;
    	}
    }

}

