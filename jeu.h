#ifndef JEU_H
#define JEU_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QApplication>
#include <QDebug>
#include "plateau.h"
#include "equipe.h"
#include <QTimer>
#include <QPushButton>
#include <QLCDNumber>
#include <QSlider>

class Jeu : public QWidget
{
    Q_OBJECT

    public:
    Jeu();
    void afficher(const Dynamique *ptr );
    void setstyle();
    void mousePressEvent(QMouseEvent *event);
    void setequipe(Equipe * equipe);
    void changement_equipe();
    void findujeu(int color);
    //Dynamique * deplacement(int color,std::string nom,coor* pos_a,coor* pos_e);
    signals:

    public slots:
    void processOneThing();
    void commencer();

    private:
    Dynamique *depl;
    QTime decompte;
    QTimer *timer;
    int ptblanc,ptnoir,limite_temps,re_temps;
    char score[3];
    Equipe *select,*autre,*noir,*blanc;
    Plateau *pt;
    QLabel *titre,*points,*Tnoir,*Tblanc,*Pnoir,*Pblanc,*temps_noir,*temps_blanc,*vert;
    QLabel *image;
    QPixmap *img;
    QPushButton *b_commencer;
    bool clock,debut_partie;
    QLCDNumber *aff_limite_temps;
    QLCDNumber *aff_re_temps;
    QSlider *slider_limite_temps;
    QSlider *slider_re_temps;
};

#endif // JEU_H
