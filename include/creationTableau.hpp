#pragma once
#include <vector>
#include <algorithm>
#include "case.hpp"

using namespace std;

class Tableau
{
    private:
        int hauteur;
        int largeur;
        vector<vector<Case>> tableau;

        vector<vector<Case>> initTableau() {
            vector<vector<Case>> outputTab(hauteur, vector<Case>(largeur, Case(0)));
            return outputTab;
        }

    public:
        Tableau(int h, int l) : hauteur(max(h, 1)), largeur(max(l, 1)), tableau(initTableau()) {}

        Tableau() : hauteur(100), largeur(100), tableau(initTableau()) {}

        ~Tableau() = default;

        vector<vector<Case>> getCurrentTab() const {
            return tableau;
        }

        int getHauteur() const { return hauteur; }
        int getLargeur() const { return largeur; }

        Case getCell(int y, int x) const {
            if (y >= 0 && y < hauteur && x >= 0 && x < largeur) {
                return tableau[y][x];
            }
            return Case();
        }

        void setCell(int y, int x, int value) {
            if (y >= 0 && y < hauteur && x >= 0 && x < largeur) {
                tableau[y][x] = Case(value);
            }
        }

        void setTab(vector<vector<Case>> newTab) {
            tableau = std::move(newTab);
        }

        vector<vector<Case>>& getTab() {
            return tableau;
        }
};

Tableau creationTableau();
void addRandomValuesTableau(Tableau& mainTab);
void updateTableau(Tableau& mainTab);
int foundNombreVivantAutour(int posHauteur, int posLargeur, const vector<vector<Case>>& tableauVie);
void addManualValuesTableau(Tableau& mainTab);
