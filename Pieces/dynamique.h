#ifndef DYNAMIQUE_H
#define DYNAMIQUE_H
struct coor{
    int x,y;
};

class Dynamique
{
public:
    Dynamique();
    ~Dynamique();
    void add(coor news);
    int Taille()const;
    coor co(int i)const;
    //friend std::ostream& operator << (std::ostream& flux, const Dynamique &t);
private:
    coor *tab,*tab2=nullptr;
    int capacite;
    int taille;
};

#endif // DYNAMIQUE_H
