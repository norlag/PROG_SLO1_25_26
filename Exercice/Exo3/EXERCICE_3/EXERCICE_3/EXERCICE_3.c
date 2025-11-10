//-----------------------------------------------------------------------------------//
// Nom du projet 		: 
// Nom du fichier 		: 
// Date de création 	: xx.xx.2016
// Date de modification : 08.11.2024
//
// Auteur 				: SSR
//                        Philou (Ph. Bovey)
//
// Description          : 
//
//
// Remarques :            lien pour la table ASCII :
// 						  -> http://www.asciitable.com/
// 						  
//----------------------------------------------------------------------------------//

#include <stdio.h>	// pour usage printf
#include <stdint.h> // uniformation du type entier 
#include <math.h>

enum e_Typefigure {
	cercle,
	ellipse,
	carre,
	rectangle,
	triangle 
};

// Déclaration globales des constantes
// -----------------------------------
const short VMAX = 10000;
const short VMIN = -10000;
const double PI = 3.14159;

int main(void)
{
	// Déclarations locales des variables
	// ----------------------------------
	double Surface, rayon;
	char lettre;
	short tension;
	int bigVal;

	// Affectations
	// ------------
	tension = VMAX - 500;
	bigVal = 0x12345678;
	lettre = 'B';
	Surface = 226.98;
	rayon = 8.5;
    
	// Affichages pour controle
	printf ("Tension = %d \n", tension);
 	printf ("BigVal = %lx \n", bigVal);
	printf ("Lettre  = %c \n", lettre);
	printf ("Figure = %d \n", carre);
	printf ("Rayon = %8.3f Surface = %8.3f \n", rayon, Surface);

	return(0);
}
