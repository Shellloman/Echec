#include "cavalier.h"

Cavalier::Cavalier(): Piece(0)
{
    valeur = 3;
}

void Cavalier::set(int x, int y, QPixmap pix,std::string name){
    setimage(pix);
    move(x,y);
    this->nom = name;
    // qDebug()<<"ça marche jusque là";
}
void Cavalier::del(){
    delete [] dep;
}
// coor* Cavalier::deplacement(){
//     return NULL;
// }
