//----------------------------------------------------------------------------------
//	APP_CamParam.h
//
//----------------------------------------------------------------------------------

#include	<stdio.h>
#include	"DE10Sys_GFonc.h"

//-------------------------------------------
//  Update with your camera settings values
//-------------------------------------------
#define		MIN_BLU		75
#define		MAX_BLU		155

#define		MIN_GRN		90
#define		MAX_GRN		160

#define		MIN_RED		80
#define		MAX_RED		150

#define		MIN_GREY	80
#define		MAX_GREY	150
//-------------------------------------------



#define		MYIP_BUSMAP		IP1_CONVPIX_BASE

#define		COLOR_BGR_FOND	0x00FF4F4F

//  Dimmensions du capteur de la camera
#define		CAM_NBPIX		832
#define		CAM_NBLIN		484

//  Affichage "fenetre" = écran reduit pour le traitement
//  le nombre de pixels par ligne doit etre multiple de 32
#define		FEN_NBPIX		384
#define		FEN_NBLIN		250

#define		SRC_DEBPIX		0
#define		SRC_DEBLIN		0

#define		DST_DEBPIX		400
#define		DST_DEBLIN		0

void	App_UserLoop(S_IP_INIT* param);
int		Pixel_Contrast(int valpix);
int		Color_Contrast(int value, int vmin, int vmax);
int		Calc_Param(int valMin, int valMax);

short	Test_Touche(short pVal[5]);
void 	Affi_Pattern(void);

