#include "pion.h"

Pion::Pion(): Piece(0)
{
    valeur = 1;
}

void Pion::del(){
    delete [] dep;
};

void Pion::set(int x, int y, QPixmap pix,std::string name){
    setimage(pix);
    move(x,y);
    this->nom = name;
}

Dynamique* Pion::deplacement(Dynamique* pos_a,Dynamique* pos_e,int color){
    Dynamique *dep = new Dynamique;
    if(color==1){
        bool test_a = true,test_e=true;
            int longue;
            if (co.x ==2){
                longue = 3;
            }else{
                longue=2;
            }
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
            if (!test_a || !test_e){break;}
            dep->add({co.x+j,co.y});
            }
            for (int i=0;i<pos_e->Taille();i++){
            if(co.x+1 == pos_e->co(i).x && co.y+1 == pos_e->co(i).y){
                dep->add({co.x+1,co.y+1});
                break;
            }}
            for (int i=0;i<pos_e->Taille();i++){
            if (co.x+1 == pos_e->co(i).x && co.y-1 == pos_e->co(i).y){
                dep->add({co.x+1,co.y-1});
                break;
            }}
    }
    if(color==0){
        bool test_a = true,test_e=true;
            int longue;
            if (co.x ==7){
                longue = 3;
            }else{
                longue=2;
            }
            for (int j=1;j<longue;j++){
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
            if (!test_a || !test_e){break;}
            dep->add({co.x-j,co.y});
            }
            for (int i=0;i<pos_e->Taille();i++){
            if(co.x-1 == pos_e->co(i).x && co.y+1 == pos_e->co(i).y){
                dep->add({co.x-1,co.y+1});
                break;
            }}
            for (int i=0;i<pos_e->Taille();i++){
            if (co.x-1 == pos_e->co(i).x && co.y-1 == pos_e->co(i).y){
                dep->add({co.x-1,co.y-1});
                break;
            }}
    }
    delete pos_a;
    delete pos_e;
    return dep;
}
