#ifndef EQUIPE_H
#define EQUIPE_H
#include "Pieces/pion.h"
#include "Pieces/roi.h"
#include "Pieces/dame.h"
#include "Pieces/fou.h"
#include "Pieces/cavalier.h"
#include "Pieces/tour.h"
#include <QTime>
#include "time.h"

class Equipe
{
public:
    int color;
    Piece *selected;
    Pion pion[8];
    Roi roi;
    Dame dame;
    Fou fou[2];
    Cavalier cavalier[2];
    Tour tour[2];

    QTime *temps;
    Equipe(int couleur);

    void select(Piece *sel);
    bool is_here(int x,int y);
    void setTime(int minutes);
};
#endif // EQUIPE_H
