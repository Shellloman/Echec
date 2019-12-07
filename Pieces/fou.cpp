#include "fou.h"

Fou::Fou(): Piece(0)
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
Dynamique* Fou::deplacement(Dynamique* pos_a,Dynamique* pos_e){
    Dynamique *dep = new Dynamique;
    bool test_a = true,test_e=true;
    int diagNE= 0,diagSE= 0,diagSO= 0,diagNO= 0;
    int k = co.x;
    int l = co.y;
    while(k < 9 && l < 9){
        diagNE ++;
        k++;l++;
    }
    k = co.x;
    l = co.y;
    while(k > 0 && l < 9){
        diagSE ++;
        k--;l++;
    }
    k = co.x;
    l = co.y;
    while(k > 0 && l > 0){
        diagSO ++;
        k--;l--;
    }
    k = co.x;
    l = co.y;
    while(k < 9 && l > 0){
        diagNO ++;
        k++;l--;
    }
    for (int j=1;j<diagNE;j++){
    for (int i=0;i<pos_a->Taille();i++){
        if (co.x+j == pos_a->co(i).x && co.y+j == pos_a->co(i).y){
            test_a = false;
            break;
        }
    }
    for (int i=0;i<pos_e->Taille();i++){
        if(co.x+j == pos_e->co(i).x && co.y+j == pos_e->co(i).y){
            test_e = false;
            break;
        }
    }
    if (!test_a){break;}
    dep->add({co.x+j,co.y+j});
    if (!test_e){break;}
    }
    test_a = true;test_e = true;
    for (int j=1;j<diagSE;j++){
    for (int i=0;i<pos_a->Taille();i++){
        if (co.x-j == pos_a->co(i).x && co.y+j == pos_a->co(i).y){
            test_a = false;
            break;
        }
    }
    for (int i=0;i<pos_e->Taille();i++){
        if(co.x-j == pos_e->co(i).x && co.y+j == pos_e->co(i).y){
            test_e = false;
            break;
        }
    }
    if (!test_a){break;}
    dep->add({co.x-j,co.y+j});
    if (!test_e){break;}
    }
    test_a = true;test_e = true;
    for (int j=1;j<diagSO;j++){
    for (int i=0;i<pos_a->Taille();i++){
        if (co.x-j == pos_a->co(i).x && co.y-j == pos_a->co(i).y){
            test_a = false;
            break;
        }
    }
    for (int i=0;i<pos_e->Taille();i++){
        if(co.x-j == pos_e->co(i).x && co.y-j == pos_e->co(i).y){
            test_e = false;
            break;
        }
    }
    if (!test_a){break;}
    dep->add({co.x-j,co.y-j});
    if (!test_e){break;}
    }
    test_a = true;test_e = true;
    for (int j=1;j<diagNO;j++){
    for (int i=0;i<pos_a->Taille();i++){
        if (co.x+j == pos_a->co(i).x && co.y-j == pos_a->co(i).y){
            test_a = false;
            break;
        }
    }
    for (int i=0;i<pos_e->Taille();i++){
        if(co.x+j == pos_e->co(i).x && co.y-j == pos_e->co(i).y){
            test_e = false;
            break;
        }
    }
    if (!test_a){break;}
    dep->add({co.x+j,co.y-j});
    if (!test_e){break;}
    }


    delete pos_a;
    delete pos_e;
    return dep;
    }
