#include <cassert>
#include <iostream>
#include "include/creationTableau.hpp"

void testTableau() {
    Tableau tableau(10, 10);
    assert((tableau.getHauteur() == 10) && "Failed: tableau.getHauteur() != 10");
    assert((tableau.getLargeur() == 10) && "Failed: tableau.getLargeur() != 10");
    tableau.setCell(0, 0, 255);
    assert((tableau.getCell(0, 0) == 255) && "Failed: tableau.getCell(0, 0) != 255");
    tableau.setCell(0, 0, 0);
    assert((tableau.getCell(0, 0) == 0) && "Failed: tableau.getCell(0, 0) != 0");
    assert((tableau.getCell(10, 10) == 0) && "Failed: tableau.getCell(10, 10) != 0"); // Out of bounds

    // Additional tests
    tableau.setCell(5, 5, 128);
    assert((tableau.getCell(5, 5) == 128) && "Failed: tableau.getCell(5, 5) != 128");
    tableau.setCell(9, 9, 64);
    assert((tableau.getCell(9, 9) == 64) && "Failed: tableau.getCell(9, 9) != 64");

    vector<vector<int>> newTab(10, vector<int>(10, 1));
    tableau.setTab(newTab);
    assert((tableau.getCell(0, 0) == 1) && "Failed: tableau.getCell(0, 0) != 1");
    assert((tableau.getCell(9, 9) == 1) && "Failed: tableau.getCell(9, 9) != 1");
}

int main() {
    testTableau();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
