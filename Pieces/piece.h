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
    int valeur;
    int tab[8][9][2];
    coor co;
    QLabel image;
    Dynamique* deplacement(coor* pos_a,coor* pos_e);
    Piece();

    void move(int x,int y);
    bool is_here(int x, int y);
    void setimage(QPixmap pix);
    int dead();
};

#endif // PIECE_H
