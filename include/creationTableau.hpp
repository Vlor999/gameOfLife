#pragma once
#include <vector>
#include <algorithm>

using namespace std;

class Tableau
{
    private:
        int hauteur;
        int largeur;
        vector<vector<int>> tableau;

        vector<vector<int>> initTableau() {
            vector<vector<int>> outputTab(hauteur, vector<int>(largeur, 0));
            return outputTab;
        }

    public:
        Tableau(int h, int l) {
            this->hauteur = max(h, 1);
            this->largeur = max(l, 1);
            this->tableau = initTableau();
        }
        
        Tableau() {
            this->hauteur = 100;
            this->largeur = 100;
            this->tableau = initTableau();
        } 
        
        ~Tableau() {}
        
        int getHauteur() const { return hauteur; }
        int getLargeur() const { return largeur; }
        
        int getCell(int y, int x) const {
            if (y >= 0 && y < hauteur && x >= 0 && x < largeur) {
                return tableau[y][x];
            }
            return 0;
        }
        
        void setCell(int y, int x, int value) {
            if (y >= 0 && y < hauteur && x >= 0 && x < largeur) {
                tableau[y][x] = value;
            }
        }
};

Tableau creationTableau();
void addRandomValuesTableau(Tableau& mainTab);
