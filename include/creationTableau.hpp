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
        Tableau(int h, int l) : hauteur(max(h, 1)), largeur(max(l, 1)), tableau(initTableau()) {}

        Tableau() : hauteur(100), largeur(100), tableau(initTableau()) {}

        ~Tableau() = default;

        vector<vector<int>> getCurrentTab() const {
            return tableau;
        }

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

        void setTab(vector<vector<int>> newTab) {
            tableau = std::move(newTab);
        }

        vector<vector<int>>& getTab() {
            return tableau;
        }
};

Tableau creationTableau();
void addRandomValuesTableau(Tableau& mainTab);
void updateTableau(Tableau& mainTab);
int foundNombreVivantAutour(int posHauteur, int posLargeur, const vector<vector<int>>& tableauVie);
void addManualValuesTableau(Tableau& mainTab);
