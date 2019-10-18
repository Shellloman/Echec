#include "dynamique.h"

Dynamique::Dynamique(){
    capacite = 1;
    tab = new coor[capacite];
    taille = 0;
}

void Dynamique::add(coor news){
    if (taille ==capacite){
        capacite *=2;
        tab2 = new coor[capacite];
        for(int i = 0;i<taille;i++){tab2[i] = tab[i];}
        delete [] tab;
        tab = tab2;
        tab2 = nullptr;
    }
    tab[taille] = news;
    taille++;
}
Dynamique::~Dynamique(){
    delete []tab;
}

coor Dynamique::co(int i) const{
   return tab[i];
}

int Dynamique::Taille() const{
    return taille;
}

//std::ostream& Dynamique::operator << (std::ostream& flux, const Dynamique &t){
//    if(t.taille == 0){
//        (flux<<" tableau vide ");
//    }else{
//    flux<<"[ ";
//    for(int i=0;i<t.taille-1;i++){
//        flux <<"{" <<t[i].x<<","<<t[i].y<<"}"<<", ";
//    }
//    flux <<"{" <<t[t.taille-1].x<<","<<t[t.taille-1].y<<"}"<<" ]";}
//    return flux;
//}

