#include "dame.h"

Dame::Dame(): Piece(0)
{
    valeur = 9;
}

void Dame::set(int x, int y, QPixmap pix,std::string name){
    setimage(pix);
    move(x,y);
    this->nom = name;
    // qDebug()<<"ça marche jusque là";
}
void Dame::del(){
    delete [] dep;
}
coor* Dame::deplacement(){
    return NULL;
}
