#ifndef ROI_H
#define ROI_H
#include "piece.h"

class Roi : public Piece{
public:
    coor *dep = NULL;
    // coor* deplacement();
    Roi();
    void set(int x, int y, QPixmap pix, std::string nom);
    void del(); // supp les tableaux sur le tas en trop.
};

#endif // ROI_H
