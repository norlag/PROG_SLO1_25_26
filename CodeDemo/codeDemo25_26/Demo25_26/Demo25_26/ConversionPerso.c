//-----------------------------------------------------------------------------------//
// Nom du projet 		: Demo25_26
// Nom du fichier 		: ConversionPerso.c
// Date de création 	: 03.11.2025
// Date de modification : xx.xx.20xx
//
// Auteur 				: Philou (Ph. Bovey)
//
// Version				: 0.1
//
// Description          : demo pour SLO1 25-26
//
//
// Remarques :            
//----------------------------------------------------------------------------------//
#define _USE_MATH_DEFINES

//-- librairie standard --// 
#include <math.h>

//#include <corecrt_math_defines.h>

//-- librairie perso --//  
#include "Conversion.h"



//----------------------------------------------------------------------------------//
//-- nom fct : CalculPerimetreCercle
//-- paramètre entrée : rayon_m (reel)
//-- paramètre sortie : perimetre_m (reel)
//-- paramètre IN-OUT : - 
//-- description	  : calculer le perimètre d'un cercle
//----------------------------------------------------------------------------------//
float CalculPerimetreCercle(float rayon_m)
{
	//-- déclaration et initialisation cst --// 
	const float DEUX_PI = 2 * M_PI;

	//-- déclaration variable --// 
	float perimetre_m;

	//-- calcul perimetre --//
	perimetre_m = DEUX_PI * rayon_m;

	//-- retour perimetre --// 
	return (perimetre_m);
}