#include "MaFenetre.h"
#include "jeu.h"
#include <fstream>
#include <iostream>

using namespace std;
MaFenetre::MaFenetre() : QWidget()
{
    // construction fenetre
    setGeometry(335,140,1250, 800);

    // construction image
    QLabel *image = new QLabel(this);
    QPixmap *img = new QPixmap(QCoreApplication::applicationDirPath()+"/image/echec.jpg");
    image->setPixmap(*img);
    image->setGeometry(335,160,580,326);

    // construction texte
    titre = new QLabel(QString("Prototype Echéquier avec Qt"),this);
    titre->setGeometry((1250 - 700)/2,50,700,100);

    // Construction du bouton
    b_commencer = new QPushButton("Commencer une nouvelle partie", this);
    b_commencer->setGeometry(375,530,500,50);
    b_charger = new QPushButton("Charger une ancienne partie", this);
    b_charger->setGeometry(375,600,500,50);
    b_quitter = new QPushButton("quitter le jeu", this);
    b_quitter->setGeometry(375,670,500,50);

    setstyle();
    titre->setStyleSheet("font-size : 56px;");

    QObject::connect(b_quitter, SIGNAL(clicked()), this, SLOT(confirm()));
    QObject::connect(b_commencer, SIGNAL(clicked()), this, SLOT(lancement_jeu()));
}
void MaFenetre::setstyle()
{
    /*string css;
    ifstream stylefont(QCoreApplication::applicationDirPath()+"/image/styleFont");  //Ouverture d'un fichier en lecture
    if(stylefont .is_open()){qDebug() <<"fichier ouvert"; getline(stylefont,css); stylefont.close();cout<<css;}else{
        qDebug() <<"erreur ouverture fichier";
    }*/
    setStyleSheet("background-color: rgb(66,66,66);"
                  "color : white;"
                  "font-family : Bitstream Charter;"
                  "font-size : 20px;");
    //setStyleSheet(css);
}

void MaFenetre::confirm()
{
    int rep = QMessageBox::question(this, "Quitter", "Êtes vous sur de fermer le programme ?", QMessageBox::Yes | QMessageBox::No);
    if (rep == QMessageBox::Yes){
        qApp->quit();
    }
}

void MaFenetre::lancement_jeu()
{
    newjeu = new Jeu;
    newjeu->show();
    this->hide();
}
