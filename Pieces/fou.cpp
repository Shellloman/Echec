#include "fou.h"

Fou::Fou(): Piece()
{
    valeur = 3;
}

void Fou::set(int x, int y, QPixmap pix,std::string name){
    setimage(pix);
    move(x,y);
    this->nom = name;
    // qDebug()<<"ça marche jusque là";
}
void Fou::del(){
    delete [] dep;
};
coor* Fou::deplacement(){
    return NULL;
};
