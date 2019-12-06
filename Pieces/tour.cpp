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
Dynamique* Tour::deplacement(coor* pos_a,coor* pos_e){
    Dynamique *dep = new Dynamique;
    bool test_a = true,test_e=true;
    int longue,longuem,large,largem;
    longue = 9 - co.x;
    longuem = co.x;
    large = 9 - co.y;
    largem = co.y;
    for (int j=1;j<longue;j++){
    for (int i=0;i<16;i++){
        if (co.x+j == pos_a[i].x && co.y == pos_a[i].y){
            test_a = false;
            break;
        }
        if(co.x+j == pos_e[i].x && co.y == pos_e[i].y){
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
    for (int i=0;i<16;i++){
        if (co.x-j == pos_a[i].x && co.y == pos_a[i].y){
            test_a = false;
            break;
        }
        if(co.x-j == pos_e[i].x && co.y == pos_e[i].y){
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
    for (int i=0;i<16;i++){
        if (co.x == pos_a[i].x && co.y+j == pos_a[i].y){
            test_a = false;
            break;
        }
        if(co.x == pos_e[i].x && co.y+j == pos_e[i].y){
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
    for (int i=0;i<16;i++){
        if (co.x == pos_a[i].x && co.y-j == pos_a[i].y){
            test_a = false;
            break;
        }
        if(co.x == pos_e[i].x && co.y-j == pos_e[i].y){
            test_e = false;
            break;
        }
    }
    if (!test_a){break;}
    dep->add({co.x,co.y-j});
    if (!test_e){break;}
    }
    delete []pos_a;
    delete []pos_e;
    return dep;
}
