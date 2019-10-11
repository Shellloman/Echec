#include "piece.h"

Piece::Piece()
{
    for(int i = 0;i<8;i++){
        for(int j=0;j<8;j++){
            tab[i][j][0] = 244+76*j; //longueur x
            tab[i][j][1] = 744-75*(i+1); //largeur y
        }
        tab[7][8][0]= 0;
        tab[7][8][0]= 0;

    }
}

void Piece::move(int x, int y){
    co.x = x;
    co.y = y;
    image.move(tab[x-1][y-1][0],tab[x-1][y-1][1]);
}

bool Piece::is_here(int x, int y){
    return (co.x==x && co.y==y);
}
void Piece::setimage(QPixmap pix){
    image.setFixedSize(75,75);
    image.setPixmap(pix);
    image.setStyleSheet("background-color:transparent;");
}

int Piece::dead(){
    image.hide();
    move(8,9);
    return valeur;
}
