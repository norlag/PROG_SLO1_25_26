//-----------------------------------------------------------------------------------//
// Nom du projet 		: Demo25_26
// Nom du fichier 		: demo.c
// Date de création 	: 29.09.2025
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
//-- librairie standard --// 
#include <stdio.h>
#include <stdint.h>

//-- librairie perso --//  
#include "Conversion.h"



//-- définition --// 
#define FOIX_2 2
#define PI 3.14 

//-- constante gloable --// 




//----------------------------------------------------------------------------------//
//-- nom fct : main
//-- paramètre entrée : -
//-- paramètre sortie : - 
//-- paramètre IN-OUT : - 
//-- description : programme principal =>
//----------------------------------------------------------------------------------//
void main() 
{
	//-- constante --// 
	//-- reel 
	//-- à éviter -> si possible -> raison gestion mémoire 
	/*const float PI_v1 = 3.14;
	const float FOIX_2_2 = 2;*/



	//-- variables --//
	//--- Entier Standard 
	//--- Signé (+/-)
	char varI;		// 1 octet
	short varJ;		// 2 octets 
	int varK;			// 4 octets			int = long 
	long long varL;	// 8 octets 

	//--- Non signé (+) 
	unsigned char varM;		// 1 octet
	unsigned short varN;	// 2 octets 
	unsigned int varO;		// 4 octets			int = long 
	unsigned long long varP;	// 8 octets 


	//--- Entier Notrmalisé -> librairie stdint.h 
		//--- Signé (+/-)
	int8_t varA;		// 1 octet
	int16_t varB;		// 2 octets 
	int32_t varC;			// 4 octets			int = long 
	int64_t varD;	// 8 octets 

	//--- Non signé (+) 
	uint8_t varE;		// 1 octet
	uint16_t varF;		// 2 octets 
	uint32_t varG;			// 4 octets			int = long 
	uint64_t varH;	// 8 octets 
					
	//--- Reel 
	float varQ; 				// 4 octets	
	double varR;				// 8 octets 

	//-- Reel
	float rayon_m = 10;          // _m => metre 
								 // cast implcite -> entier -> reel
	float perimetre1_m, perimetre2_m, perimetre3_m ;



	//-- une imstruction  est composé d'opérandes (variable) et d'opérateur (signe) --//
	//-- cast => (type)variable 
	perimetre1_m = (float)FOIX_2 * (float)PI * rayon_m;

	//-- attention au cast implicite
	perimetre2_m = (float)(FOIX_2 * PI * rayon_m);


	//-- appel de fct 
	//--> calcul perimetre ccercle 
	perimetre3_m = CalculPerimetreCercle(rayon_m);


	//--> printf 
	printf("%f \r\n %f \n %f", perimetre1_m, perimetre2_m, perimetre3_m);
	
}


//-- fonction --- 






