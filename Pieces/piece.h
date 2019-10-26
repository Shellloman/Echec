#ifndef PIECE_H
#define PIECE_H
#include <QLabel>
#include <stdio.h>
#include <QCoreApplication>
#include <QDebug>
#include "dynamique.h"

class Piece
{
public:
    std::string nom;
    int valeur,roque;
    int tab[8][8][2];
    coor co,cemetery_n[3][6],cemetery_b[3][6];
    QLabel image;
    Dynamique* deplacement(coor* pos_a,coor* pos_e,bool proque,bool groque);
    Piece(int r);

    void move(int x,int y);
    bool is_here(int x, int y);
    void setimage(QPixmap pix);
    int dead(int color,int nb_dead);
};

#endif // PIECE_H
