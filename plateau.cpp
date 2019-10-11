#include "plateau.h"

Plateau::Plateau()
{

    taille_case = 76;
    for(int i = 0;i<8;i++){
        for(int j=0;j<8;j++){
            cases[i][j][0] = 244+76*j; //longueur x
            cases[i][j][1] = 744-75*(i+1); //largeur y
        };
    };
}
