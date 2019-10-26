#include "tour.h"

Tour::Tour(): Piece(0)
{
    valeur = 5;
}

void Tour::set(int x, int y,int r, QPixmap pix,std::string name){
    setimage(pix);
    move(x,y);
    this->nom = name;
    roque =r ;

}
void Tour::del(){
    delete [] dep;
};
coor* Tour::deplacement(){
    return NULL;
};
