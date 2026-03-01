#include <stdio.h>

/* =========================================================================
   TEST A : DEFINITION D'UN SEGMENT (2 variantes)
   ========================================================================= */

// Définition de la structure avec une union imbriquée
typedef struct {
    char TypeInfo; // 'R' (Rectangulaire) ou 'P' (Polaire) [cite: 741]
    
    // Union anonyme contenant deux vues (structures)
    union {
        // Vue 1 : Coordonnées P1 et P2 [cite: 749]
        struct { int P1X; int P1Y; int P2X; int P2Y; } Vue1;
        // Vue 2 : Centre, longueur et angle [cite: 750]
        struct { int CentreX; int CentreY; int longueur; double angle; } Vue2;
    } def;
} S_DefSegment;

// Fonction d'affichage avec pointeur
void ShowSeg(S_DefSegment *pSeg) {
    // On aiguille l'affichage selon le champ TypeInfo
    if (pSeg->TypeInfo == 'R') {
        printf("TypeInfo = R Pos1X = %d Pos1Y = %d Pos2X = %d Pos2Y = %d\n", 
               pSeg->def.Vue1.P1X, pSeg->def.Vue1.P1Y, 
               pSeg->def.Vue1.P2X, pSeg->def.Vue1.P2Y); [cite: 768-769]
    } else if (pSeg->TypeInfo == 'P') {
        printf("TypeInfo = P CentreX = %d CentreY = %d Longueur = %d Angle= %.2f\n", 
               pSeg->def.Vue2.CentreX, pSeg->def.Vue2.CentreY, 
               pSeg->def.Vue2.longueur, pSeg->def.Vue2.angle); [cite: 770-772]
    }
}

/* =========================================================================
   TEST B : TRAME RESEAU ET COMPACTAGE
   ========================================================================= */

// Compactage de la structure : on force l'alignement sur 1 octet [cite: 818-819]
#pragma pack(push, 1)
typedef struct {
    unsigned short STX : 3;   // Poids faible (3 bits) [cite: 783, 784]
    unsigned short Code : 13; // 13 bits (STX + Code = 16 bits = 2 octets) [cite: 783]
    unsigned int Datas;       // 32 bits = 4 octets [cite: 783]
    unsigned short Crc;       // 16 bits = 2 octets [cite: 783]
} S_Frame;                    // Total compacté = 8 octets au lieu de 12 [cite: 829, 834]
#pragma pack(pop)             // Retour à la normale [cite: 822]

// Union pour lire la trame octet par octet [cite: 786-787]
typedef union {
    S_Frame frame;
    unsigned char tabOctets[sizeof(S_Frame)];
} U_Frame;

// Fonction d'affichage de la trame
void ShowFrame(U_Frame *pFrame) {
    printf("Taille S_Frame = %zu\n", sizeof(S_Frame)); [cite: 801]
    
    // Affichage des champs
    printf("STX= %d Code = %X Datas = %X Crc = %X\n", 
           pFrame->frame.STX, pFrame->frame.Code, 
           pFrame->frame.Datas, pFrame->frame.Crc); [cite: 802]
           
    // Lecture de la même mémoire, octet par octet
    for(int i = 0; i < sizeof(S_Frame); i++) {
        printf("%02X ", pFrame->tabOctets[i]); [cite: 793, 794]
    }
    printf("\n");
}

/* =========================================================================
   MAIN
   ========================================================================= */
int main() {
    printf("--- EX17 : TEST A ---\n");
    S_DefSegment DefSeg1 = { 'R', { .Vue1 = {20, 25, 150, 170} } }; [cite: 753]
    S_DefSegment DefSeg2 = { 'P', { .Vue2 = {20, 25, 120, 44.5} } }; [cite: 754]
    
    ShowSeg(&DefSeg1);
    ShowSeg(&DefSeg2);
    
    printf("\n--- EX17 : TEST B ---\n");
    U_Frame Frame1, Frame2;
    
    // Initialisation Frame 1 [cite: 790]
    Frame1.frame.STX = 3;
    Frame1.frame.Code = 0x123;
    Frame1.frame.Datas = 0x12345678;
    Frame1.frame.Crc = 0xACDC;
    
    // Initialisation Frame 2 [cite: 790]
    Frame2.frame.STX = 3;
    Frame2.frame.Code = 0x124;
    Frame2.frame.Datas = 0x10203040;
    Frame2.frame.Crc = 0xABEF;
    
    ShowFrame(&Frame1);
    ShowFrame(&Frame2);

    return 0;
}