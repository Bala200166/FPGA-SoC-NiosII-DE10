//----------------------------------------------------------------------------------
//	Lab5_CopyVideo.c
//
//----------------------------------------------------------------------------------

#include 	"system.h"
#include	"APP_CamParam.h"
#include 	"altera_avalon_performance_counter.h"


S_IP_INIT	Sparam;

//#define   USE_FLOAT

// Choisir l'exposition en fonction de la luminosit�
// valeur entre 0x0800 et 0x6000 par pas de 0x0100 ou 0x1000
#define		EXPO_TIME	0x4000

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

void	My_Simply_Copy(void);
void	My_Project_softFloat(void);
void	My_Project_softInt(void);
void	My_Project_HardIP(void);


void	App_UserLoop(S_IP_INIT* param)
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
{
	alt_u64 counter;	float time, imgRate;	short nbc;

	//MyIP_Addres = (int*)xxxxx_0_BASE;
	nbc = 0;
	while (1) {
		PERF_RESET(PERFCOUNTER_BASE);
		PERF_START_MEASURING(PERFCOUNTER_BASE);
		PERF_BEGIN(PERFCOUNTER_BASE, 1);

		My_Simply_Copy();
		//My_Project_softFloat();
		//My_Project_softInt();
		//My_Project_HardIP();

		PERF_END(PERFCOUNTER_BASE, 1);
		counter = perf_get_section_time((void*)PERFCOUNTER_BASE, 1);
		time = (float)counter / (50.0 * 1000);
		imgRate = 1.0/(time / 1000);
		if (++nbc == 10) {
			printf("Number of cycles = %lld   /  Time = %.3f millisec   /   %.2f images/sec\n", counter, time, imgRate);
			nbc = 0;
		}
		Test_Touche(NULL);
	}
}

void	My_Simply_Copy(void)
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
{	uint32  curpix, newpix;    uint32  *adpixin, *adpixout;
	int lin, col;

	for (lin = 0; lin < FEN_NBLIN; lin++) {
		adpixin = (uint32*)DE10Affi_GetAdresse(0, lin);
		adpixout = adpixin + DST_DEBPIX;		// 400 pixels further
		for (col = 0; col < FEN_NBPIX; col++) {
			curpix = *adpixin++;
			newpix = curpix;
			*adpixout++ = newpix;
		}
	}
}

