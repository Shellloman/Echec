#ifndef DAME_H
#define DAME_H
#include "piece.h"

class Dame: public Piece{
public:
    coor *dep = NULL;
    coor* deplacement();
    Dame();
    void set(int x, int y, QPixmap pix, std::string nom);
    void del(); // supp les tableaux sur le tas en trop.
};

#endif // DAME_H
