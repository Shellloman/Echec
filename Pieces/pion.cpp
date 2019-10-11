#include "pion.h"

Pion::Pion(): Piece()
{
    valeur = 1;
}
coor* Pion::deplacement(){
    return NULL;
};

void Pion::del(){
    delete [] dep;
};

void Pion::set(int x, int y, QPixmap pix,std::string name){
    setimage(pix);
    move(x,y);
    this->nom = name;
}
