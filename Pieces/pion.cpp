#include "pion.h"

Pion::Pion(): Piece()
{
    valeur = 1;
}
//Dynamique* Pion::deplacement(const coor &pos_a[], const coor &pos_e[]){
//    dep = new Dynamique;
//    bool test_a = true,test_e=true;
//        int longue;
//        if (pos.x ==2){
//            longue = 3;
//        }else{
//            longue=2;
//        }
//        for (int j=1;j<longue;j++){
//        for (int i=0;i<8;i++){
//            if (pos.x+j == pos_a[i].x && pos.y == pos_a[i].y){
//                test_a = false;
//                break;
//            }
//            if(pos.x+j == pos_e[i].x && pos.y == pos_e[i].y){
//                test_e = false;
//                break;
//            }
//        }
//        if (!test_a || !test_e){break;}
//        dep.add({pos.x+j,pos.y});
//        }
//        for (int i=0;i<8;i++){
//        if(pos.x+1 == pos_e[i].x && pos.y+1 == pos_a[i].y){
//            dep.add({pos.x+1,pos.y+1});
//            break;
//        }}
//        for (int i=0;i<8;i++){
//        if (pos.x+1 == pos_e[i].x && pos.y-1 == pos_a[i].y){
//            dep.add({pos.x+1,pos.y-1});
//            break;
//        }}
//        return dep;
//};

void Pion::del(){
    delete [] dep;
};

void Pion::set(int x, int y, QPixmap pix,std::string name){
    setimage(pix);
    move(x,y);
    this->nom = name;
}
