#include <thread>
#include <vector>
#include "include/creationTableau.hpp"
#include "include/case.hpp"

Tableau creationTableau() {
    Tableau carteInitiale;
    return carteInitiale;
}

void addManualValuesTableau(Tableau& mainTab) {
    // Implementation for manual values
}

void addRandomValuesTableau(Tableau& mainTab) {
    srand(time(0));
    int hauteur = mainTab.getHauteur();
    int largeur = mainTab.getLargeur();
    vector<thread> threads;

    auto worker = [&](int start, int end) {
        for (int h = start; h < end; h++) {
            for (int l = 0; l < largeur; l++) {
                int randomVal = rand() % 2;
                mainTab.setCell(h, l, randomVal * 255);
            }
        }
    };

    int numThreads = thread::hardware_concurrency();
    int chunkSize = hauteur / numThreads;
    for (int i = 0; i < numThreads; i++) {
        int start = i * chunkSize;
        int end = (i == numThreads - 1) ? hauteur : start + chunkSize;
        threads.emplace_back(worker, start, end);
    }

    for (auto& t : threads) {
        t.join();
    }
}

int foundNombreVivantAutour(int posHauteur, int posLargeur, const vector<vector<Case>>& tableauVie) {
    int hauteur = tableauVie.size();
    int largeur = tableauVie[0].size();
    int compteurVivant = 0;
    for (int h = -1; h < 2; h++) {
        for (int c = -1; c < 2; c++) {
            if (h == 0 && c == 0) {
                continue;
            }
            int newH = posHauteur + h;
            int newC = posLargeur + c;
            if (newH >= 0 && newH < hauteur && newC >= 0 && newC < largeur) {
                compteurVivant += tableauVie[newH][newC].getValue() > 0 ? 1 : 0;
            }
        }
    }
    return compteurVivant;
}

void updateTableau(Tableau& mainTab) {
    int hauteur = mainTab.getHauteur();
    int largeur = mainTab.getLargeur();
    vector<vector<Case>> currentTab = mainTab.getCurrentTab();
    vector<vector<Case>> outputTab(hauteur, vector<Case>(largeur, Case(0)));
    vector<thread> threads;

    auto worker = [&](int start, int end) {
        for (int h = start; h < end; h++) {
            for (int c = 0; c < largeur; c++) {
                int nombreAutour = foundNombreVivantAutour(h, c, currentTab);
                bool estVivant = currentTab[h][c].getValue() > 0;
                if (estVivant && (nombreAutour == 2 || nombreAutour == 3)) {
                    outputTab[h][c] = Case(255);
                } else if (!estVivant && nombreAutour == 3) {
                    outputTab[h][c] = Case(255);
                } else {
                    outputTab[h][c] = Case(0);
                }
            }
        }
    };

    int numThreads = thread::hardware_concurrency();
    int chunkSize = hauteur / numThreads;
    for (int i = 0; i < numThreads; i++) {
        int start = i * chunkSize;
        int end = (i == numThreads - 1) ? hauteur : start + chunkSize;
        threads.emplace_back(worker, start, end);
    }

    for (auto& t : threads) {
        t.join();
    }

    mainTab.setTab(std::move(outputTab));
}
