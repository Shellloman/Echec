#ifndef ROI_H
#define ROI_H
#include "piece.h"

class Roi : public Piece{
public:
    coor *dep = NULL;
Dynamique* deplacement(Dynamique* pos_a,Dynamique* pos_e,bool proque,bool groque);
    Roi();
    void set(int x, int y, QPixmap pix, std::string nom);
    void del(); // supp les tableaux sur le tas en trop.
};

#endif // ROI_H
