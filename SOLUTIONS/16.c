#include <stdio.h>

// 1. Définition de l'Union avec Champs de bits
typedef union {
    unsigned short DateCodee; // Vue globale (16 bits)
    
    // Vue détaillée. ATTENTION À L'ORDRE POUR LE LITTLE-ENDIAN !
    struct {
        unsigned short annee : 7; // LSB : Bits 0 à 6 
        unsigned short mois  : 4; // Milieu : Bits 7 à 10 
        unsigned short jour  : 5; // MSB : Bits 11 à 15 
    } champs;
} U_DateCompress;

// 2. Fonction de compression
unsigned short ZipDate(unsigned char jour, unsigned char mois, unsigned short an) {
    U_DateCompress Tmp; // Union locale [cite: 888]
    
    // Remplissage via la vue "structure"
    Tmp.champs.jour = jour;
    Tmp.champs.mois = mois;
    Tmp.champs.annee = an - 1950; // L'année est une différence par rapport à 1950 [cite: 872]
    
    // Retour via la vue "entier 16 bits"
    return Tmp.DateCodee;
}

int main() {
    printf("--- EX16 : COMPRESSION DE DATE ---\n");
    
    // Test avec les valeurs de la donnée
    unsigned char j = 18;
    unsigned char m = 2;
    unsigned short a = 2015;
    
    unsigned short res = ZipDate(j, m, a);
    
    // Le résultat attendu pour 18/2/2015 est 0x9141 [cite: 896]
    // 0x9A3C est attendu pour 19/4/2010 [cite: 882]
    printf("Date compressee en hexa %X\n\n", res); 

    return 0;
}