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
Dynamique* Cavalier::deplacement(coor* pos_a,coor* pos_e){
    Dynamique *dep = new Dynamique;
    bool test_a = true;
    for (int i=0;i<16;i++){
        if (co.x+2 == pos_a[i].x && co.y+1 == pos_a[i].y){
            test_a = false;
            break;
        }
    }
    if (test_a){dep->add({co.x+2,co.y+1});}
    test_a = true;
    for (int i=0;i<16;i++){
        if (co.x+2 == pos_a[i].x && co.y-1 == pos_a[i].y){
            test_a = false;
            break;
        }
    }
    if (test_a){dep->add({co.x+2,co.y-1});}
    test_a = true;
    for (int i=0;i<16;i++){
        if (co.x-2 == pos_a[i].x && co.y+1 == pos_a[i].y){
            test_a = false;
            break;
        }
    }
    if (test_a){dep->add({co.x-2,co.y+1});}
    test_a = true;
    for (int i=0;i<16;i++){
        if (co.x-2 == pos_a[i].x && co.y-1 == pos_a[i].y){
            test_a = false;
            break;
        }
    }
    if (test_a){dep->add({co.x-2,co.y-1});}
    test_a = true;
    for (int i=0;i<16;i++){
        if (co.x+1 == pos_a[i].x && co.y+2 == pos_a[i].y){
            test_a = false;
            break;
        }
    }
    if (test_a){dep->add({co.x+1,co.y+2});}
    test_a = true;
    for (int i=0;i<16;i++){
        if (co.x+1 == pos_a[i].x && co.y-2 == pos_a[i].y){
            test_a = false;
            break;
        }
    }
    if (test_a){dep->add({co.x+1,co.y-2});}
    test_a = true;
    for (int i=0;i<16;i++){
        if (co.x-1 == pos_a[i].x && co.y+2 == pos_a[i].y){
            test_a = false;
            break;
        }
    }
    if (test_a){dep->add({co.x-1,co.y+2});}
    test_a = true;
    for (int i=0;i<16;i++){
        if (co.x-1 == pos_a[i].x && co.y-2 == pos_a[i].y){
            test_a = false;
            break;
        }
    }
    if (test_a){dep->add({co.x-1,co.y-2});}
    delete []pos_a;
    delete []pos_e;
    return dep;
    }
