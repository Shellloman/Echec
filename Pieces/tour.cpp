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
Dynamique* Tour::deplacement(Dynamique* pos_a,Dynamique* pos_e){
    Dynamique *dep = new Dynamique;
    bool test_a = true,test_e=true;
    int longue,longuem,large,largem;
    longue = 9 - co.x;
    longuem = co.x;
    large = 9 - co.y;
    largem = co.y;
    for (int j=1;j<longue;j++){
    for (int i=0;i<pos_a->Taille();i++){
        if (co.x+j == pos_a->co(i).x && co.y == pos_a->co(i).y){
            test_a = false;
            break;
        }
    }
    for (int i=0;i<pos_e->Taille();i++){
        if(co.x+j == pos_e->co(i).x && co.y == pos_e->co(i).y){
            test_e = false;
            break;
        }
    }
    if (!test_a){break;}
    dep->add({co.x+j,co.y});
    if (!test_e){break;}
    }
    test_a = true; test_e = true;
    for (int j=1;j<longuem;j++){
    for (int i=0;i<pos_a->Taille();i++){
        if (co.x-j == pos_a->co(i).x && co.y == pos_a->co(i).y){
            test_a = false;
            break;
        }
    }
    for (int i=0;i<pos_e->Taille();i++){
        if(co.x-j == pos_e->co(i).x && co.y == pos_e->co(i).y){
            test_e = false;
            break;
        }
    }
    if (!test_a){break;}
    dep->add({co.x-j,co.y});
    if (!test_e){break;}
    }
    test_a = true; test_e = true;
    for (int j=1;j<large;j++){
    for (int i=0;i<pos_a->Taille();i++){
        if (co.x == pos_a->co(i).x && co.y+j == pos_a->co(i).y){
            test_a = false;
            break;
        }
    }
    for (int i=0;i<pos_e->Taille();i++){
        if(co.x == pos_e->co(i).x && co.y+j == pos_e->co(i).y){
            test_e = false;
            break;
        }
    }
    if (!test_a){break;}
    dep->add({co.x,co.y+j});
    if (!test_e){break;}
    }
    test_a = true; test_e = true;
    for (int j=1;j<largem;j++){
    for (int i=0;i<pos_a->Taille();i++){
        if (co.x == pos_a->co(i).x && co.y-j == pos_a->co(i).y){
            test_a = false;
            break;
        }
    }
    for (int i=0;i<pos_e->Taille();i++){
        if(co.x == pos_e->co(i).x && co.y-j == pos_e->co(i).y){
            test_e = false;
            break;
        }
    }
    if (!test_a){break;}
    dep->add({co.x,co.y-j});
    if (!test_e){break;}
    }
    delete pos_a;
    delete pos_e;
    return dep;
}
