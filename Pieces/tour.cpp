#include "tour.h"

Tour::Tour(): Piece()
{
    valeur = 5;
}

void Tour::set(int x, int y, QPixmap pix,std::string name){
    setimage(pix);
    move(x,y);
    this->nom = name;
    // qDebug()<<"ça marche jusque là";
}
void Tour::del(){
    delete [] dep;
};
coor* Tour::deplacement(){
    return NULL;
};
