#ifndef PION_H
#define PION_H
#include "piece.h"

class Pion : public Piece{
public:
    coor *dep = NULL;
    Pion();
    void del(); // supp les tableaux sur le tas en trop.
    coor* deplacement();
    void set(int x, int y, QPixmap pix, std::string nom);
};

#endif // PION_H
