#ifndef PION_H
#define PION_H
#include "piece.h"

class Pion : public Piece{
public:
    Dynamique *dep = nullptr;
    Pion();
    void del(); // supp les tableaux sur le tas en trop.
    //Dynamique* deplacement(const coor &pos_a[],const coor &pos_e[]);
    void set(int x, int y, QPixmap pix, std::string nom);
    Dynamique* deplacement(Dynamique* pos_a,Dynamique* pos_e,int color);
};

#endif // PION_H
