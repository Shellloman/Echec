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
    bool proque,groque;
    int color,nb_dead;
    Piece *selected;
    Pion pion[8];
    Roi roi;
    Dame dame;
    Fou fou[2];
    Cavalier cavalier[2];
    Tour tour[2];

    QTime *temps;
    Equipe(int couleur);

    coor* position();
    void reset_ptr();
    bool is_here(int x,int y);
    void setTime(int minutes);
    Dynamique* deplacement(coor* enemie);
    bool is_ptr_NotNull();
    void move(int x,int y);
    bool roque(int r);
    int dead(int color,int nb_dead);
};
#endif // EQUIPE_H
