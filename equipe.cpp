#include "equipe.h"

Equipe::Equipe(int couleur)
{
    selected = NULL;
    color = couleur;
    std::string name;
    char nb[2];
    if (couleur==0){
        QPixmap pion_img = QCoreApplication::applicationDirPath()+"/image/pieces/pion_noir.png";
        QPixmap roi_img = QCoreApplication::applicationDirPath()+"/image/pieces/roi_noir.png";
        QPixmap dame_img = QCoreApplication::applicationDirPath()+"/image/pieces/dame_noir.png";
        QPixmap fou_img =  QCoreApplication::applicationDirPath()+"/image/pieces/fou_noir.png";
        QPixmap cavalier_img =  QCoreApplication::applicationDirPath()+"/image/pieces/cavalier_noir.png";
        QPixmap tour_img =  QCoreApplication::applicationDirPath()+"/image/pieces/tour_noir.png";

        std::string nomroi ="roi noir";
        std::string nomdame ="dame noir";
        std::string noir = "pion noir ";
        std::string nomfou1 = "fou noir 1";
        std::string nomfou2 = "fou noir 2";
        std::string nomcavalier1 = "cavalier noir 1";
        std::string nomcavalier2 = "cavalier noir 2";
        std::string nomtour1 = "tour noir 1";
        std::string nomtour2 = "tour noir 2";

        for (int i =0;i<8;i++){
            std::sprintf(nb,"%d",i+1);
            name = noir +nb;
            pion[i].set(7,i+1,pion_img,name);
        }
        roi.set(8,5,roi_img,nomroi);
        dame.set(8,4,dame_img,nomdame);
        fou[0].set(8,3,fou_img,nomfou1);
        fou[1].set(8,6,fou_img,nomfou2);
        cavalier[0].set(8,2,cavalier_img,nomcavalier1);
        cavalier[1].set(8,7,cavalier_img,nomcavalier2);
        tour[0].set(8,1,tour_img,nomtour1);
        tour[1].set(8,8,tour_img,nomtour2);

    }else{
        QPixmap pion_img = QCoreApplication::applicationDirPath()+"/image/pieces/pion_blanc.png";
        QPixmap roi_img = QCoreApplication::applicationDirPath()+"/image/pieces/roi_blanc.png";
        QPixmap dame_img = QCoreApplication::applicationDirPath()+"/image/pieces/dame_blanc.png";
        QPixmap fou_img =  QCoreApplication::applicationDirPath()+"/image/pieces/fou_blanc.png";
        QPixmap cavalier_img =  QCoreApplication::applicationDirPath()+"/image/pieces/cavalier_blanc.png";
        QPixmap tour_img =  QCoreApplication::applicationDirPath()+"/image/pieces/tour_blanc.png";

        std::string nomroi ="roi blanc";
        std::string nomdame ="dame blanc";
        std::string blanc = "pion blanc ";
        std::string nomfou1 = "fou blanc 1";
        std::string nomfou2 = "fou blanc 2";
        std::string nomcavalier1 = "cavalier noir 1";
        std::string nomcavalier2 = "cavalier noir 2";
        std::string nomtour1 = "tour noir 1";
        std::string nomtour2 = "tour noir 2";

        for (int i =0;i<8;i++){
            std::sprintf(nb,"%d",i+1);
            name = blanc+nb;
            pion[i].set(2,i+1,pion_img,name);
        }

        roi.set(1,5,roi_img,nomroi);
        dame.set(1,4,dame_img,nomdame);
        fou[0].set(1,3,fou_img,nomfou1);
        fou[1].set(1,6,fou_img,nomfou2);
        cavalier[0].set(1,2,cavalier_img,nomcavalier1);
        cavalier[1].set(1,7,cavalier_img,nomcavalier2);
        tour[0].set(1,1,tour_img,nomtour1);
        tour[1].set(1,8,tour_img,nomtour2);
    }
}

void Equipe::select(Piece *sel){
    selected = sel;
}

bool Equipe::is_here(int x, int y){
    for (int i =0;i<8;i++){
        if (pion[i].is_here(x,y)){
            select(&(pion[i]));
            return true;
        }
    }
    if(cavalier[0].is_here(x,y)){
        select(&(cavalier[0]));
        return true;}
    if(cavalier[1].is_here(x,y)){
        select(&(cavalier[1]));
        return true;}
    if(fou[0].is_here(x,y)){
        select(&(fou[0]));
        return true;}
    if(fou[1].is_here(x,y)){
        select(&(fou[1]));
        return true;}
    if(tour[0].is_here(x,y)){
        select(&(tour[0]));
        return true;}
    if(tour[1].is_here(x,y)){
        select(&(tour[1]));
        return true;}
    if(dame.is_here(x,y)){
        select(&(dame));
        return true;}
    if (roi.is_here(x,y)){
       select(&(roi));
       return true;}
    return false;
}

void Equipe::setTime(int minutes){
    temps = new QTime(0,minutes,0);
}
