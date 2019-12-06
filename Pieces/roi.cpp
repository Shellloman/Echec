#include "roi.h"

Roi::Roi(): Piece(1)
{
    valeur = 99;
}

void Roi::set(int x, int y, QPixmap pix,std::string name){
    setimage(pix);
    move(x,y);
    this->nom = name;
    // qDebug()<<"ça marche jusque là";
}
void Roi::del(){
    delete [] dep;
};
// coor* Roi::deplacement(){
//     return NULL;
// };
