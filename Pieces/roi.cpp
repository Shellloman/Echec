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
Dynamique* Roi::deplacement(coor* pos_a,coor* pos_e,bool proque,bool groque){
    Dynamique *dep = new Dynamique;
    bool test_a =true;
    if (proque){
        for (int i=0;i<16;i++){
            if ((co.x == pos_a[i].x && (co.y+1 == pos_a[i].y || co.y+2 == pos_a[i].y))||(co.x == pos_e[i].x && (co.y+1 == pos_e[i].y || co.y+2 == pos_e[i].y)) ){
                test_a = false;
                break;
            }
        }
        if (test_a){dep->add({co.x,co.y+2});}
    }
    test_a =true;
    if (groque){
        for (int i=0;i<16;i++){
            if ((co.x == pos_a[i].x && (co.y-1 == pos_a[i].y || co.y-2 == pos_a[i].y || co.y-3 ==pos_a[i].y))||(co.x == pos_e[i].x && (co.y-1 == pos_e[i].y || co.y-2 == pos_e[i].y || co.y-3 ==pos_e[i].y)) ){
                test_a = false;
                break;
            }
        }
        if (test_a){dep->add({co.x,co.y-2});}
    }
    test_a =true;
    for (int i=0;i<16;i++){
        if (co.x+1 == pos_a[i].x && co.y == pos_a[i].y){
            test_a = false;
            break;
        }
    }
    if (test_a){dep->add({co.x+1,co.y});}
    test_a = true;
    for (int i=0;i<16;i++){
        if (co.x+1 == pos_a[i].x && co.y+1 == pos_a[i].y){
            test_a = false;
            break;
        }
    }
    if (test_a){dep->add({co.x+1,co.y+1});}
    test_a = true;
    for (int i=0;i<16;i++){
        if (co.x == pos_a[i].x && co.y+1 == pos_a[i].y){
            test_a = false;
            break;
        }
    }
    if (test_a){dep->add({co.x,co.y+1});}
    test_a = true;
    for (int i=0;i<16;i++){
        if (co.x-1 == pos_a[i].x && co.y+1 == pos_a[i].y){
            test_a = false;
            break;
        }
    }
    if (test_a){dep->add({co.x-1,co.y+1});}
    test_a = true;
    for (int i=0;i<16;i++){
        if (co.x-1 == pos_a[i].x && co.y == pos_a[i].y){
            test_a = false;
            break;
        }
    }
    if (test_a){dep->add({co.x-1,co.y});}
    test_a = true;
    for (int i=0;i<16;i++){
        if (co.x-1 == pos_a[i].x && co.y-1 == pos_a[i].y){
            test_a = false;
            break;
        }
    }
    if (test_a){dep->add({co.x-1,co.y-1});}
    test_a = true;
    for (int i=0;i<16;i++){
        if (co.x == pos_a[i].x && co.y-1 == pos_a[i].y){
            test_a = false;
            break;
        }
    }
    if (test_a){dep->add({co.x,co.y-1});}
    test_a = true;
    for (int i=0;i<16;i++){
        if (co.x+1 == pos_a[i].x && co.y-1 == pos_a[i].y){
            test_a = false;
            break;
        }
    }
    if (test_a){dep->add({co.x+1,co.y-1});}
    test_a = true;
    delete []pos_a;
    delete []pos_e;
    return dep;
}
