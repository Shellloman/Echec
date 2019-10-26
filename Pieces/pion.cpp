#include "pion.h"

Pion::Pion(): Piece(0)
{
    valeur = 1;
}

void Pion::del(){
    delete [] dep;
};

void Pion::set(int x, int y, QPixmap pix,std::string name){
    setimage(pix);
    move(x,y);
    this->nom = name;
}
