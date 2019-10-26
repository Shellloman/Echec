#include "piece.h"

Piece::Piece(int r)
{
    roque = r;
    for(int i = 0;i<8;i++){
        for(int j=0;j<8;j++){
            tab[i][j][0] = 244+76*j; //longueur x
            tab[i][j][1] = 744-75*(i+1); //largeur y
        }
        tab[7][8][0]= 0;
        tab[7][8][0]= 0;

    }
}

void Piece::move(int x, int y){
    co.x = x;
    co.y = y;
    image.move(tab[x-1][y-1][0],tab[x-1][y-1][1]);
}

bool Piece::is_here(int x, int y){
    return (co.x==x && co.y==y);
}
void Piece::setimage(QPixmap pix){
    image.setFixedSize(75,75);
    image.setPixmap(pix);
    image.setStyleSheet("background-color:transparent;");
}

int Piece::dead(){
    image.hide();
    move(8,9);
    return valeur;
}
Dynamique* Piece::deplacement(coor*pos_a, coor*pos_e,bool proque,bool groque){
    Dynamique *dep = new Dynamique;
    if(nom=="pion blanc"){
        bool test_a = true,test_e=true;
            int longue;
            if (co.x ==2){
                longue = 3;
            }else{
                longue=2;
            }
            for (int j=1;j<longue;j++){
            for (int i=0;i<16;i++){
                if (co.x+j == pos_a[i].x && co.y == pos_a[i].y){
                    test_a = false;
                    break;
                }
                if(co.x+j == pos_e[i].x && co.y == pos_e[i].y){
                    test_e = false;
                    break;
                }
            }
            if (!test_a || !test_e){break;}
            dep->add({co.x+j,co.y});
            }
            for (int i=0;i<16;i++){
            if(co.x+1 == pos_e[i].x && co.y+1 == pos_a[i].y){
                dep->add({co.x+1,co.y+1});
                break;
            }}
            for (int i=0;i<16;i++){
            if (co.x+1 == pos_e[i].x && co.y-1 == pos_a[i].y){
                dep->add({co.x+1,co.y-1});
                break;
            }}
    }
    if(nom=="pion noir"){
        bool test_a = true,test_e=true;
            int longue;
            if (co.x ==7){
                longue = 3;
            }else{
                longue=2;
            }
            for (int j=1;j<longue;j++){
            for (int i=0;i<16;i++){
                if (co.x-j == pos_a[i].x && co.y == pos_a[i].y){
                    test_a = false;
                    break;
                }
                if(co.x-j == pos_e[i].x && co.y == pos_e[i].y){
                    test_e = false;
                    break;
                }
            }
            if (!test_a || !test_e){break;}
            dep->add({co.x-j,co.y});
            }
            for (int i=0;i<16;i++){
            if(co.x-1 == pos_e[i].x && co.y+1 == pos_e[i].y){
                dep->add({co.x-1,co.y+1});
                break;
            }}
            for (int i=0;i<16;i++){
            if (co.x-1 == pos_e[i].x && co.y-1 == pos_e[i].y){
                dep->add({co.x-1,co.y-1});
                break;
            }}
    }
    if(nom == "tour blanc" || nom =="tour noir"|| nom=="dame blanc" || nom=="dame noir"){
        bool test_a = true,test_e=true;
            int longue,longuem,large,largem;
            longue = 9 - co.x;
            longuem = co.x;
            large = 9 - co.y;
            largem = co.y;
            for (int j=1;j<longue;j++){
            for (int i=0;i<16;i++){
                if (co.x+j == pos_a[i].x && co.y == pos_a[i].y){
                    test_a = false;
                    break;
                }
                if(co.x+j == pos_e[i].x && co.y == pos_e[i].y){
                    test_e = false;
                    break;
                }
            }
            if (!test_a){break;}
            dep->add({co.x+j,co.y});
            if (!test_e){break;}
            }
            test_a = true; test_e = true;
            for (int j=1;j<longuem;j++){
            for (int i=0;i<16;i++){
                if (co.x-j == pos_a[i].x && co.y == pos_a[i].y){
                    test_a = false;
                    break;
                }
                if(co.x-j == pos_e[i].x && co.y == pos_e[i].y){
                    test_e = false;
                    break;
                }
            }
            if (!test_a){break;}
            dep->add({co.x-j,co.y});
            if (!test_e){break;}
            }
            test_a = true; test_e = true;
            for (int j=1;j<large;j++){
            for (int i=0;i<16;i++){
                if (co.x == pos_a[i].x && co.y+j == pos_a[i].y){
                    test_a = false;
                    break;
                }
                if(co.x == pos_e[i].x && co.y+j == pos_e[i].y){
                    test_e = false;
                    break;
                }
            }
            if (!test_a){break;}
            dep->add({co.x,co.y+j});
            if (!test_e){break;}
            }
            test_a = true; test_e = true;
            for (int j=1;j<largem;j++){
            for (int i=0;i<16;i++){
                if (co.x == pos_a[i].x && co.y-j == pos_a[i].y){
                    test_a = false;
                    break;
                }
                if(co.x == pos_e[i].x && co.y-j == pos_e[i].y){
                    test_e = false;
                    break;
                }
            }
            if (!test_a){break;}
            dep->add({co.x,co.y-j});
            if (!test_e){break;}
            }
    }
    if (nom=="fou blanc" || nom =="fou noir"|| nom=="dame blanc" || nom=="dame noir"){
        bool test_a = true,test_e=true;
            int diagNE= 0,diagSE= 0,diagSO= 0,diagNO= 0;
            int k = co.x;
            int l = co.y;
            while(k < 9 && l < 9){
                diagNE ++;
                k++;l++;
            }
            k = co.x;
            l = co.y;
            while(k > 0 && l < 9){
                diagSE ++;
                k--;l++;
            }
            k = co.x;
            l = co.y;
            while(k > 0 && l > 0){
                diagSO ++;
                k--;l--;
            }
            k = co.x;
            l = co.y;
            while(k < 9 && l > 0){
                diagNO ++;
                k++;l--;
            }
            for (int j=1;j<diagNE;j++){
            for (int i=0;i<16;i++){
                if (co.x+j == pos_a[i].x && co.y+j == pos_a[i].y){
                    test_a = false;
                    break;
                }
                if(co.x+j == pos_e[i].x && co.y+j == pos_e[i].y){
                    test_e = false;
                    break;
                }
            }
            if (!test_a){break;}
            dep->add({co.x+j,co.y+j});
            if (!test_e){break;}
            }
            test_a = true;test_e = true;
            for (int j=1;j<diagSE;j++){
            for (int i=0;i<16;i++){
                if (co.x-j == pos_a[i].x && co.y+j == pos_a[i].y){
                    test_a = false;
                    break;
                }
                if(co.x-j == pos_e[i].x && co.y+j == pos_e[i].y){
                    test_e = false;
                    break;
                }
            }
            if (!test_a){break;}
            dep->add({co.x-j,co.y+j});
            if (!test_e){break;}
            }
            test_a = true;test_e = true;
            for (int j=1;j<diagSO;j++){
            for (int i=0;i<16;i++){
                if (co.x-j == pos_a[i].x && co.y-j == pos_a[i].y){
                    test_a = false;
                    break;
                }
                if(co.x-j == pos_e[i].x && co.y-j == pos_e[i].y){
                    test_e = false;
                    break;
                }
            }
            if (!test_a){break;}
            dep->add({co.x-j,co.y-j});
            if (!test_e){break;}
            }
            test_a = true;test_e = true;
            for (int j=1;j<diagNO;j++){
            for (int i=0;i<16;i++){
                if (co.x+j == pos_a[i].x && co.y-j == pos_a[i].y){
                    test_a = false;
                    break;
                }
                if(co.x+j == pos_e[i].x && co.y-j == pos_e[i].y){
                    test_e = false;
                    break;
                }
            }
            if (!test_a){break;}
            dep->add({co.x+j,co.y-j});
            if (!test_e){break;}
            }

    }
    if (nom =="cavalier noir"||nom =="cavalier blanc"){
        bool test_a = true;
        for (int i=0;i<16;i++){
            if (co.x+2 == pos_a[i].x && co.y+1 == pos_a[i].y){
                test_a = false;
                break;
            }
        }
        if (test_a){dep->add({co.x+2,co.y+1});}
        test_a = true;
        for (int i=0;i<16;i++){
            if (co.x+2 == pos_a[i].x && co.y-1 == pos_a[i].y){
                test_a = false;
                break;
            }
        }
        if (test_a){dep->add({co.x+2,co.y-1});}
        test_a = true;
        for (int i=0;i<16;i++){
            if (co.x-2 == pos_a[i].x && co.y+1 == pos_a[i].y){
                test_a = false;
                break;
            }
        }
        if (test_a){dep->add({co.x-2,co.y+1});}
        test_a = true;
        for (int i=0;i<16;i++){
            if (co.x-2 == pos_a[i].x && co.y-1 == pos_a[i].y){
                test_a = false;
                break;
            }
        }
        if (test_a){dep->add({co.x-2,co.y-1});}
        test_a = true;
        for (int i=0;i<16;i++){
            if (co.x+1 == pos_a[i].x && co.y+2 == pos_a[i].y){
                test_a = false;
                break;
            }
        }
        if (test_a){dep->add({co.x+1,co.y+2});}
        test_a = true;
        for (int i=0;i<16;i++){
            if (co.x+1 == pos_a[i].x && co.y-2 == pos_a[i].y){
                test_a = false;
                break;
            }
        }
        if (test_a){dep->add({co.x+1,co.y-2});}
        test_a = true;
        for (int i=0;i<16;i++){
            if (co.x-1 == pos_a[i].x && co.y+2 == pos_a[i].y){
                test_a = false;
                break;
            }
        }
        if (test_a){dep->add({co.x-1,co.y+2});}
        test_a = true;
        for (int i=0;i<16;i++){
            if (co.x-1 == pos_a[i].x && co.y-2 == pos_a[i].y){
                test_a = false;
                break;
            }
        }
        if (test_a){dep->add({co.x-1,co.y-2});}
    }
    if (nom == "roi noir" || nom =="roi blanc"){
        bool test_a =true;
        if (proque){
            for (int i=0;i<16;i++){
                if ((co.x == pos_a[i].x && (co.y+1 == pos_a[i].y || co.y+2 == pos_a[i].y))||(co.x == pos_e[i].x && (co.y+1 == pos_e[i].y || co.y+2 == pos_e[i].y)) ){
                    test_a = false;
                    break;
                }
            }
            if (test_a){dep->add({co.x,co.y+2});}
        }
        test_a =true;
        if (groque){
            for (int i=0;i<16;i++){
                if ((co.x == pos_a[i].x && (co.y-1 == pos_a[i].y || co.y-2 == pos_a[i].y || co.y-3 ==pos_a[i].y))||(co.x == pos_e[i].x && (co.y-1 == pos_e[i].y || co.y-2 == pos_e[i].y || co.y-3 ==pos_e[i].y)) ){
                    test_a = false;
                    break;
                }
            }
            if (test_a){dep->add({co.x,co.y-2});}
        }
        test_a =true;
        for (int i=0;i<16;i++){
            if (co.x+1 == pos_a[i].x && co.y == pos_a[i].y){
                test_a = false;
                break;
            }
        }
        if (test_a){dep->add({co.x+1,co.y});}
        test_a = true;
        for (int i=0;i<16;i++){
            if (co.x+1 == pos_a[i].x && co.y+1 == pos_a[i].y){
                test_a = false;
                break;
            }
        }
        if (test_a){dep->add({co.x+1,co.y+1});}
        test_a = true;
        for (int i=0;i<16;i++){
            if (co.x == pos_a[i].x && co.y+1 == pos_a[i].y){
                test_a = false;
                break;
            }
        }
        if (test_a){dep->add({co.x,co.y+1});}
        test_a = true;
        for (int i=0;i<16;i++){
            if (co.x-1 == pos_a[i].x && co.y+1 == pos_a[i].y){
                test_a = false;
                break;
            }
        }
        if (test_a){dep->add({co.x-1,co.y+1});}
        test_a = true;
        for (int i=0;i<16;i++){
            if (co.x-1 == pos_a[i].x && co.y == pos_a[i].y){
                test_a = false;
                break;
            }
        }
        if (test_a){dep->add({co.x-1,co.y});}
        test_a = true;
        for (int i=0;i<16;i++){
            if (co.x-1 == pos_a[i].x && co.y-1 == pos_a[i].y){
                test_a = false;
                break;
            }
        }
        if (test_a){dep->add({co.x-1,co.y-1});}
        test_a = true;
        for (int i=0;i<16;i++){
            if (co.x == pos_a[i].x && co.y-1 == pos_a[i].y){
                test_a = false;
                break;
            }
        }
        if (test_a){dep->add({co.x,co.y-1});}
        test_a = true;
        for (int i=0;i<16;i++){
            if (co.x+1 == pos_a[i].x && co.y-1 == pos_a[i].y){
                test_a = false;
                break;
            }
        }
        if (test_a){dep->add({co.x+1,co.y-1});}
        test_a = true;
    }
    delete []pos_a;
    delete []pos_e;
    return dep;
}
