#ifndef TOUR_H
#define TOUR_H
#include "piece.h"

class Tour: public Piece{
public:
    coor *dep = NULL;
    coor* deplacement();
    Tour();
    void set(int x, int y,int r, QPixmap pix, std::string nom);
    void del(); // supp les tableaux sur le tas en trop.
};

#endif // TOUR_H
