#ifndef CAVALIER_H
#define CAVALIER_H
#include "piece.h"

class Cavalier: public Piece{
public:
    coor *dep = NULL;
    Dynamique* deplacement(coor* pos_a,coor* pos_e);
    Cavalier();
    void set(int x, int y, QPixmap pix, std::string nom);
    void del(); // supp les tableaux sur le tas en trop.
};

#endif // CAVALIER_H
