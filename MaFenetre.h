#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
#include <QVBoxLayout>
#include "jeu.h"

class MaFenetre : public QWidget // On hérite de QWidget (IMPORTANT)
{
    Q_OBJECT

    public:
    MaFenetre();

    public slots:
    void confirm();
    void lancement_jeu();
    void setstyle();

    private:
    QPushButton *b_commencer,*b_quitter,*b_charger;
    QLabel *titre ,*image;
    QPixmap *img;
    QGridLayout *gridLayout;
    Jeu *newjeu;

};

#endif // MAFENETRE_H
