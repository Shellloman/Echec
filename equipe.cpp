#include "equipe.h"

Equipe::Equipe(int couleur)
{
    nb_dead = 0;
    proque= true;
    groque =true;
    selected = NULL;
    color = couleur;
    std::string name;
    if (couleur==0){
        QPixmap pion_img = QCoreApplication::applicationDirPath()+"/image/pieces/pion_noir.png";
        QPixmap roi_img = QCoreApplication::applicationDirPath()+"/image/pieces/roi_noir.png";
        QPixmap dame_img = QCoreApplication::applicationDirPath()+"/image/pieces/dame_noir.png";
        QPixmap fou_img =  QCoreApplication::applicationDirPath()+"/image/pieces/fou_noir.png";
        QPixmap cavalier_img =  QCoreApplication::applicationDirPath()+"/image/pieces/cavalier_noir.png";
        QPixmap tour_img =  QCoreApplication::applicationDirPath()+"/image/pieces/tour_noir.png";

        std::string nomroi ="roi noir";
        std::string nomdame ="dame noir";
        std::string noir = "pion noir";
        std::string nomfou1 = "fou noir";
        std::string nomfou2 = "fou noir";
        std::string nomcavalier1 = "cavalier noir";
        std::string nomcavalier2 = "cavalier noir";
        std::string nomtour1 = "tour noir";
        std::string nomtour2 = "tour noir";

        for (int i =0;i<8;i++){
            pion[i].set(7,i+1,pion_img,noir);
        }
        roi.set(8,5,roi_img,nomroi);
        dame.set(8,4,dame_img,nomdame);
        fou[0].set(8,3,fou_img,nomfou1);
        fou[1].set(8,6,fou_img,nomfou2);
        cavalier[0].set(8,2,cavalier_img,nomcavalier1);
        cavalier[1].set(8,7,cavalier_img,nomcavalier2);
        tour[0].set(8,1,3,tour_img,nomtour1);
        tour[1].set(8,8,2,tour_img,nomtour2);

    }else{
        QPixmap pion_img = QCoreApplication::applicationDirPath()+"/image/pieces/pion_blanc.png";
        QPixmap roi_img = QCoreApplication::applicationDirPath()+"/image/pieces/roi_blanc.png";
        QPixmap dame_img = QCoreApplication::applicationDirPath()+"/image/pieces/dame_blanc.png";
        QPixmap fou_img =  QCoreApplication::applicationDirPath()+"/image/pieces/fou_blanc.png";
        QPixmap cavalier_img =  QCoreApplication::applicationDirPath()+"/image/pieces/cavalier_blanc.png";
        QPixmap tour_img =  QCoreApplication::applicationDirPath()+"/image/pieces/tour_blanc.png";

        std::string nomroi ="roi blanc";
        std::string nomdame ="dame blanc";
        std::string blanc = "pion blanc";
        std::string nomfou1 = "fou blanc";
        std::string nomfou2 = "fou blanc";
        std::string nomcavalier1 = "cavalier noir";
        std::string nomcavalier2 = "cavalier noir";
        std::string nomtour1 = "tour noir";
        std::string nomtour2 = "tour noir";

        for (int i =0;i<8;i++){
            pion[i].set(2,i+1,pion_img,blanc);
        }

        roi.set(1,5,roi_img,nomroi);
        dame.set(1,4,dame_img,nomdame);
        fou[0].set(1,3,fou_img,nomfou1);
        fou[1].set(1,6,fou_img,nomfou2);
        cavalier[0].set(1,2,cavalier_img,nomcavalier1);
        cavalier[1].set(1,7,cavalier_img,nomcavalier2);
        tour[0].set(1,1,3,tour_img,nomtour1);
        tour[1].set(1,8,2,tour_img,nomtour2);
    }
}

bool Equipe::is_here(int x, int y){
    for (int i =0;i<8;i++){
        if (pion[i].is_here(x,y)){
            reset_ptr();
            pion[i].selected = true;
            return true;
        }
    }
    if(cavalier[0].is_here(x,y)){
        reset_ptr();
        cavalier[0].selected = true;
        return true;}
    if(cavalier[1].is_here(x,y)){
        reset_ptr();
        cavalier[1].selected = true;
        return true;}
    if(fou[0].is_here(x,y)){
        reset_ptr();
        fou[0].selected = true;
        return true;}
    if(fou[1].is_here(x,y)){
        reset_ptr();
        fou[1].selected = true;
        return true;}
    if(tour[0].is_here(x,y)){
        reset_ptr();
        tour[0].selected = true;
        return true;}
    if(tour[1].is_here(x,y)){
        reset_ptr();
        tour[1].selected = true;
        return true;}
    if(dame.is_here(x,y)){
        reset_ptr();
        dame.selected = true;
        return true;}
    if (roi.is_here(x,y)){
        reset_ptr();
       roi.selected = true;
       return true;}
    return false;
}

void Equipe::setTime(int minutes){
    temps = new QTime(0,minutes,0);
}

Dynamique* Equipe::position(){
    Dynamique *temp = new Dynamique;
    for(int i=0;i<8;i++){
        if (pion[i].co.y !=9) temp->add(pion[i].co);
    }
    if (tour[0].co.y != 9) temp->add(tour[0].co);
    if (tour[1].co.y != 9) temp->add(tour[1].co);
    if (cavalier[0].co.y != 9) temp->add(cavalier[0].co);
    if (cavalier[1].co.y != 9) temp->add(cavalier[1].co);
    if (fou[0].co.y != 9) temp->add(fou[0].co);
    if (fou[1].co.y != 9) temp->add(fou[1].co);
    if (dame.co.y != 9) temp->add(dame.co);
    if (roi.co.y != 9) temp->add(roi.co);
    return temp;
}
void Equipe::reset_ptr(){
    for (int i =0;i<8;i++){
        pion[i].selected = false;
    }
    cavalier[0].selected = false;
    cavalier[1].selected = false;
    fou[0].selected = false;
    fou[1].selected = false;
    tour[0].selected = false;
    tour[1].selected = false;
    dame.selected = false;
    roi.selected = false;
}
bool Equipe::is_ptr_NotNull(){
    return(cavalier[0].selected || pion[0].selected||cavalier[1].selected || pion[1].selected||fou[0].selected || pion[2].selected||fou[1].selected || pion[3].selected||tour[0].selected || pion[4].selected||tour[1].selected || pion[5].selected||dame.selected || pion[6].selected||roi.selected ||  pion[7].selected );
}

Dynamique* Equipe::deplacement(Dynamique* enemie){
    for (int i =0;i<8;i++){
        if (pion[i].selected){
            return (pion[i].deplacement(position(),enemie,color));
        }
    }
    if(cavalier[0].selected){
        return cavalier[0].deplacement(position(),enemie);}
    if(cavalier[1].selected){
        return cavalier[1].deplacement(position(),enemie);}
    if(fou[0].selected){
        return fou[0].deplacement(position(),enemie);}
    if(fou[1].selected){
        return fou[1].deplacement(position(),enemie);}
    if(tour[0].selected){
        return tour[0].deplacement(position(),enemie);}
    if(tour[1].selected){
        return tour[1].deplacement(position(),enemie);}
    if(dame.selected){
        return dame.deplacement(position(),enemie);}
    if(roi.selected){
        return roi.deplacement(position(),enemie,proque,groque);}
    return NULL;

}
void Equipe::move(int x,int y){
    for (int i =0;i<8;i++){
        if (pion[i].selected){
            pion[i].move(x,y);
        }
    }
    if(cavalier[0].selected){
        cavalier[0].move(x,y);}
    if(cavalier[1].selected){
        cavalier[1].move(x,y);}
    if(fou[0].selected){
        fou[0].move(x,y);}
    if(fou[1].selected){
        fou[1].move(x,y);}
    if(tour[0].selected){
        tour[0].move(x,y);}
    if(tour[1].selected){
        tour[1].move(x,y);}
    if(dame.selected){
        dame.move(x,y);}
    if(roi.selected){
        roi.move(x,y);}
}
bool Equipe::roque(int r){
    for (int i =0;i<8;i++){
        if (pion[i].selected){
            return pion[i].roque ==r;
        }
    }
    if(cavalier[0].selected){
        return cavalier[0].roque ==r;}
    if(cavalier[1].selected){
        return cavalier[1].roque ==r;}
    if(fou[0].selected){
        return fou[0].roque ==r;}
    if(fou[1].selected){
        return fou[1].roque ==r;}
    if(tour[0].selected){
        return tour[0].roque ==r;}
    if(tour[1].selected){
        return tour[1].roque ==r;}
    if(dame.selected){
        return dame.roque ==r;}
    if(roi.selected){
        return roi.roque ==r;}
    return false;

}
int Equipe::dead(int color,int nb_dead){
    for (int i =0;i<8;i++){
        if (pion[i].selected){
            pion[i].dead(color,nb_dead);
            return 1;
        }
    }
    if(cavalier[0].selected){
        cavalier[0].dead(color,nb_dead);
        return 3;}
    if(cavalier[1].selected){
        cavalier[1].dead(color,nb_dead);
        return 3;}
    if(fou[0].selected){
        fou[0].dead(color,nb_dead);
        return 3;}
    if(fou[1].selected){
        fou[1].dead(color,nb_dead);
        return 3;}
    if(tour[0].selected){
        tour[0].dead(color,nb_dead);
        return 5;}
    if(tour[1].selected){
        tour[1].dead(color,nb_dead);
        return 5;}
    if(dame.selected){
        dame.dead(color,nb_dead);
        return 9;}
    if(roi.selected){
        roi.dead(color,nb_dead);
        return 1000;}

    return 0;

}
