#include "jeu.h"

Jeu::Jeu() : QWidget()
{
    //construction timer
    QTimer *timer = new QTimer(this);
    decompte.start();

    // connect(timer, &QTimer::timeout, this, QOverload<>::of(&AnalogClock::update));
    connect(timer, SIGNAL(timeout()), this, SLOT(processOneThing()));
    timer->start(1000);

    // construction réglages
    b_commencer = new QPushButton("commencer",this);
    b_commencer->setGeometry(1075,560,225,70);

    aff_limite_temps = new QLCDNumber(this);
    aff_re_temps = new QLCDNumber(this);
    aff_limite_temps->move(1300,360);
    aff_re_temps->move(1300,420);

    slider_limite_temps = new QSlider(Qt::Horizontal, this);
    slider_re_temps= new QSlider(Qt::Horizontal, this);
    slider_limite_temps->setRange(1,30);
    slider_re_temps->setRange(0,60);
    slider_limite_temps->setGeometry(1050,360,200,30);
    slider_re_temps->setGeometry(1050,420,200,30);

    QObject::connect(slider_limite_temps, SIGNAL(valueChanged(int)), aff_limite_temps, SLOT(display(int)));
    QObject::connect(slider_re_temps, SIGNAL(valueChanged(int)), aff_re_temps, SLOT(display(int)));
    QObject::connect(b_commencer, SIGNAL(clicked()), this, SLOT(commencer()));

    // construction variable
    ptblanc = 0;
    ptnoir = 0;
    re_temps = 10;
    clock = false;
    debut_partie = false;
    depl =  NULL;
    vert = NULL;

    //construction plateau
    pt = new Plateau;

    // construction fenetre
    setGeometry(335,50,1400, 900);

    //construction image
    QLabel *image = new QLabel(this);
    QPixmap *img = new QPixmap(QCoreApplication::applicationDirPath()+"/image/echiquier.png");
    image->setPixmap(*img);
    image->setGeometry(200,100,685,685);

    // construction texte
    temps_noir = new QLabel(QString("00:00:00"),this);
    temps_blanc = new QLabel(QString("00:00:00"),this);
    points = new QLabel(QString("point d'avance"),this);
    Tnoir = new QLabel(QString("noir :"),this);
    Pnoir = new QLabel(QString("0"),this);
    Pblanc = new QLabel(QString("0"),this);
    Tblanc = new QLabel(QString("blanc :"),this);

    titre = new QLabel(QString("nouvelle partie"),this);
    temps_noir->setGeometry(1100,150,100,50);
    temps_blanc->setGeometry(1100,675,100,50);
    temps_blanc->hide();
    temps_noir->hide();
    titre->setGeometry(430,30,200,30);
    points->setGeometry(35,60,150,30);
    Tnoir->setGeometry(35,175,100,30);
    Tblanc->setGeometry(35,650,75,30);
    Pblanc->setGeometry(110,650,50,30);
    Pnoir->setGeometry(95,175,50,30);
    titre->setStyleSheet("font-size : 30px;text-decoration:underline;");
    setstyle();

    //construction équipe
    select = NULL;
    autre = NULL;
    noir = new Equipe(0);
    setequipe(noir);
    blanc = new Equipe(1);
    setequipe(blanc);

    // ici blanc commence
    select = blanc;
    autre = noir;
;
}

void Jeu::mousePressEvent(QMouseEvent * event){
    if (debut_partie){
    int x = event->x();
    int y = event->y();
    qDebug() << x <<", "<<y;
    for(int i = 0;i<8;i++){
        for(int j=0;j<8;j++){
            if (((pt->cases[i][j][0]<= x) && (x <=pt->cases[i][j][0]+76))&&((pt->cases[i][j][1]<= y) && (y <=pt->cases[i][j][1]+75))){
                if (select->is_here(i+1,j+1)){
                    if(vert != NULL){
                    delete [] vert;
                    vert = NULL;
                    }
                    depl = select->deplacement(autre->position());
                    afficher(depl);
                }else if (select->is_ptr_NotNull() && depl != NULL){
                    bool test=true;
                    qDebug() <<test;
                    for (int k=0;k<depl->Taille();k++){
                        if (i+1 == depl->co(k).x && j+1 == depl->co(k).y){
                            test = false;
                            break;
                        }
                    }
                    delete depl;
                    depl = NULL;
                    qDebug() <<test;
                    if (test){break;}
                    select->move(i+1,j+1);
                    if (select->proque || select->groque){
                        if (select->roque(1)){
                            if ((i+1 == 1) && j+1==3){
                                select->tour[0].move(1,4);
                            }
                            if ((i+1 == 1) && j+1==7){
                                select->tour[1].move(1,6);
                            }
                            if ((i+1 == 8) && j+1==3){
                                select->tour[0].move(8,4);
                            }
                            if ((i+1 == 8) && j+1==7){
                                select->tour[1].move(8,6);
                            }
                            select->proque = false;
                            select->groque = false;
                        }
                        if (select->roque(2)){
                            select->proque = false;
                        }
                        if (select->roque(3)){
                            select->groque = false;
                        }
                    }
                    qDebug() <<"piece bougée\n";
                    select->reset_ptr();
                    delete [] vert;
                    vert = NULL;
                    if (autre->is_here(i+1,j+1)){
                        if (autre->color == 1){
                        ptblanc += autre->dead(autre->color,autre->nb_dead);
                        autre->nb_dead++;
                        autre->reset_ptr();
                        std::sprintf(score,"%d",ptblanc-ptnoir);
                        Pnoir->setText(score);
                        std::sprintf(score,"%d",ptnoir-ptblanc);
                        Pblanc->setText(score);
                        }else{
                        ptnoir += autre->dead(autre->color,autre->nb_dead);
                        autre->nb_dead++;
                        autre->reset_ptr();
                        std::sprintf(score,"%d",ptnoir-ptblanc);
                        Pblanc->setText(score);
                        std::sprintf(score,"%d",ptblanc-ptnoir);
                        Pnoir->setText(score);
                        }
                        if (ptnoir >= 99 || ptblanc >= 99) {findujeu(select->color);}
                    }
                    qDebug()<<"ok3";
                    *(select->temps) = select->temps->addMSecs(re_temps*1000);
                    if (select->color == 0){
                    temps_noir->setText(select->temps->toString());
                    }else{
                    temps_blanc->setText(select->temps->toString());
                    }
                    changement_equipe();
                }
                break;
            }
        }
    }
  }
}

void Jeu::changement_equipe(){
    if (select == noir){
        select = blanc;
        autre = noir;
    }else{
        select  = noir;
        autre = blanc;
    }
}
void Jeu::processOneThing(){
    double tmp = decompte.restart()/(double)1000;
    if (clock){
    *(select->temps) = select->temps->addMSecs(tmp*-1000);
    if (select->color == 0){
    temps_noir->setText(select->temps->toString());
    }else{
    temps_blanc->setText(select->temps->toString());
    }
    }
}

void Jeu::setstyle()
{
    setStyleSheet("background-color: rgb(66,66,66);"
                  "color : white;"
                  "font-family : Bitstream Charter;"
                  "font-size : 20px;");
}
void Jeu::setequipe(Equipe * equipe){
    for(int i=0;i<8;i++){
    equipe->pion[i].image.setParent(this);
    }
    equipe->roi.image.setParent(this);
    equipe->dame.image.setParent(this);
    equipe->fou[0].image.setParent(this);
    equipe->fou[1].image.setParent(this);
    equipe->cavalier[0].image.setParent(this);
    equipe->cavalier[1].image.setParent(this);
    equipe->tour[0].image.setParent(this);
    equipe->tour[1].image.setParent(this);
}

void Jeu::commencer(){
    qDebug() <<"commencer ok";
    b_commencer->hide();
    QTime tempo (0,aff_limite_temps->intValue(),0);
    slider_limite_temps->hide();
    slider_re_temps->hide();
    aff_limite_temps->hide();
    aff_re_temps->hide();
    temps_noir->setText(tempo.toString());
    temps_blanc->setText(tempo.toString());
    temps_blanc->show();
    temps_noir->show();
    noir->setTime(aff_limite_temps->intValue());
    blanc->setTime(aff_limite_temps->intValue());
    re_temps = aff_re_temps->intValue();

    clock = true;
    debut_partie = true;

}
void Jeu::findujeu(int color){
    if (color == 0){
        Pblanc->setText(QString ("noir gagne"));
        Pnoir->setText(QString ("finie mdr xD"));
        Pblanc->setGeometry(300,650,500,100);
        Pnoir->setGeometry(300,175,500,100);
        Pblanc->setStyleSheet("font-size : 50px;text-decoration:underline;");
        Pnoir->setStyleSheet("font-size : 50px;text-decoration:underline;");
    }else{
        Pblanc->setText(QString ("blanc gagne"));
        Pnoir->setText(QString ("finie mdr xD"));
        Pblanc->setGeometry(300,650,500,100);
        Pnoir->setGeometry(300,175,500,100);
        Pblanc->setStyleSheet("font-size : 50px;text-decoration:underline;");
        Pnoir->setStyleSheet("font-size : 50px;text-decoration:underline;");
    }
}
void Jeu::afficher(const Dynamique *dep){
    for (int i=0;i<dep->Taille();i++){
        qDebug()<<dep->co(i).x <<" "<<dep->co(i).y;
    }
    QPixmap verts = QCoreApplication::applicationDirPath()+"/image/vert.png";
    vert = new QLabel[dep->Taille()];
    int x,y;
    for(int i=0;i<dep->Taille();i++){
        x = dep->co(i).x;
        y = dep->co(i).y;
        if (x >= 1 && x <= 8 && y <=8 && y >=1){
            vert[i].setParent(this);
            vert[i].setPixmap(verts);
            vert[i].setFixedSize(76,75);
            vert[i].move(pt->cases[x-1][y-1][0]-1,pt->cases[x-1][y-1][1]-2);
            vert[i].setStyleSheet("background-color:transparent;");
            vert[i].show();
        }
    }
}
