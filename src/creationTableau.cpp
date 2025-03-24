#include "include/creationTableau.hpp"

Tableau creationTableau() {
    Tableau carteInitiale;
    return carteInitiale;
}

void addRandomValuesTableau(Tableau& mainTab){
    srand(time(0));
    int hauteur = mainTab.getHauteur();
    int largeur = mainTab.getLargeur();

    for(int h = 0; h < hauteur; h++){
        for(int l = 0; l < largeur; l++){
            int randomVal = rand() % 2;
            mainTab.setCell(h, l, randomVal * 255);
        }
    }
}