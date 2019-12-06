#include "piece.h"

Piece::Piece(int r)
{
    roque = r;
    selected = false;
    for(int i = 0;i<8;i++){
        for(int j=0;j<8;j++){
            tab[i][j][0] = 244+76*j; //longueur x
            tab[i][j][1] = 744-75*(i+1); //largeur y
        }
    }
    for (int i = 0;i<3;i++){
        for(int j = 0;j<6;j++){
            cemetery_b[i][j].x = 950+50*j;
            cemetery_b[i][j].y = 540+75*i;
            cemetery_n[i][j].x = 950+50*j;
            cemetery_n[i][j].y = 225+75*i;
        }
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

int Piece::dead(int color,int nb_dead){
    //move(8,9);
    co.x = 8;co.y=9;
    if (color ==0){
        image.move(cemetery_n[nb_dead/6][nb_dead%6].x,cemetery_n[nb_dead/6][nb_dead%6].y);
    }else{
        image.move(cemetery_b[nb_dead/6][nb_dead%6].x,cemetery_b[nb_dead/6][nb_dead%6].y);
    }
    return valeur;
}
