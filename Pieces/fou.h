#ifndef FOU_H
#define FOU_H
#include "piece.h"

class Fou: public Piece{
public:
    coor *dep = NULL;
    Dynamique* deplacement(coor* pos_a,coor* pos_e);
    Fou();
    void set(int x, int y, QPixmap pix, std::string nom);
    void del(); // supp les tableaux sur le tas en trop.
};

#endif // FOU_H
