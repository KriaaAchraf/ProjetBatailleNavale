#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

class Bateau  {
protected:
    int lignedepart;
    int colonnedepart;
    bool direction;
    int taille;
public :
    Bateau(int taille, plateau p){
    this.taille=taille
           };

    bool estCoule(){

    }

}
class Cellule : public Bateau {
protected:
    Bateau navire ;
    bool estvisitee;
public:
    Cellule(){};
    bool estVisite(){
        if (estvisitee==true)
            return true;
        else
            return false;}

    bool faitPartieBateau(){
        if (navire== null)
            return false;
        else
            return true;}
    void mettreBateau(Bateau b) {
            if (b.faitPartieBateau()==false)
                navire=b;}
    void visite(){
        estvisitee=true;
    }
    bool estcoulee(){
        if (Bateau::estCoule==true)
            return true;
        else
            return false;

    }
}
};


class plateau : public Cellule {

    private:
    //attributs du class plateau :

    Bateau navires[7];
    Cellule grille[10][10];
    public:
    //constantes du jeu :

         int  Taille_plateau =10;
        bool VERTICAL=false;
         bool HORIZONTAL=true;
         int PLACEMENT[7] = {5,4,3,2,2,1,1};

//Le constructeur de la classe Plateau effectue deux actions distinctes, elle cr�e la grille puis elle positionne des navires sur le plateau.

        plateau(){
            peupleGrille();
            peupleNavires();}

//on place les navires 1 par un , leur taille est donn�e par la constante(5,4,3,2,2,1,1):

        void peupleNavires(){
            for (int i = 0; i < PLACEMENT.length; i++)
            navires[i] = Bateau(PLACEMENT[i],this);

            }
// on cr�e les cellules du plateau de jeu une par une :

        void peupleGrille() {
                    for (int ligne = 0; ligne < TAILLE_PLATEAU; ligne++)
                            for (int colonne = 0; colonne < TAILLE_PLATEAU; colonne++){

                                        grille[ligne][colonne] = Cellule();}}
// retourne la cellule aux ligne et colonne pass�es en param�tres ou null si la cellule n'existe pas:

        Cellule getCellule(int ligne, int colonne){
                    if ((ligne >= 0 && ligne < TAILLE_PLATEAU) &&
                                (colonne >= 0 && colonne < TAILLE_PLATEAU))
                                return grille[ligne][colonne];
                return null;}
// retourne vrai ou faux si on peut placer ou pas un bateau dans cette position :

        bool estLibre(int ligne, int colonne,bool direction, int taille) {
//premier cas direction horizontal
            if (direction == HORIZONTAL){
            for (int newColonne = colonne; newColonne <= colonne + taille - 1;newColonne++) {
                        if (getCellule(ligne, newColonne) != null) {
                                if (grille[ligne][newColonne].faitPartieBateau()) {return false;}}
                        else {return false;}}
            return true;}
//deuxi�me cas VERTICAL
            else {for (int newLigne = ligne; newLigne <= ligne + taille - 1; newLigne++){
                    if (getCellule(newLigne,colonne) != null) {
                            if (grille[newLigne][colonne].faitPartieBateau()) {return false;}}
                    else {return false;}
            }
            return true;}
}

//on positionne le bateau � une position donn�e:

   void peuple(int ligneDepart, int colonneDepart, bool direction, int taille, Bateau bateau) {
       //premier cas horizontal:
            if (direction == HORIZONTAL)
                for (int newColonne = colonneDepart; newColonne <= colonneDepart + taille -1;newColonne++)
                        grille[ligneDepart][newColonne].mettreBateau(bateau);
        //deuxi�me cas Vertical:
            else
                    for (int newLigne = ligneDepart; newLigne <= ligneDepart + taille - 1;newLigne++)
                                grille[newLigne][colonneDepart].mettreBateau(bateau);
}
//retourne si la cellule aux coordonn�es ligne, colonne fait partie ou non d'un bateau :

        bool faitPartieDeBateau(int ligne, int colonne){return (grille[ligne][colonne].faitPartieBateau());}
//retourne si la cellule aux coordonn�es ligne, colonne a �t� visit�e (torpill�e):


        bool estVisitee(int ligne, int colonne) {return (grille[ligne][colonne].estVisitee());}
//retourne si la cellule aux coordonn�es ligne, colonne a �t� coul�e :

    bool  estCoulee(int ligne, int colonne){return (grille[ligne][colonne].estCoule());}
//visite (lance une torpille) � cellule � la position ligne, colonne:

    void visite(int ligne, int colonne){grille[ligne][colonne].visite();}
//vrai si tous les b�teaux ont �t� touch�s:

    bool estDetruitPartout(){ for(int newLigne = 0; newLigne < Plateau.TAILLE_PLATEAU; newLigne++)
                                    for(int newColonne = 0; newColonne < Plateau.TAILLE_PLATEAU; newColonne++)
                                                        if (grille[newLigne][newColonne].faitPartieBateau() && !grille[newLigne][newColonne].estVisitee())
                                                                                    return false;
                        return true;
}
}
int main(){
    plateau p;
    while (p.estDetruitPartout==false){

        int ligne;
        int colonne;
        cout<<"donner une ligne suivie d'une colonne"<<endl;
        cin>>ligne;
        cin>>colonne;
        p.visite(ligne,colonne);
        if (p.faitPartieDeBateau(ligne,colonne)==true){
            if (p.estCoulee(ligne,colonne)==true)
                cout<<"bateau d�truit"<<endl;
            else
                cout<<"bateau endommag�"<<endl;
        else
            cout<<"vide"<<endl;

        }

    }


}





