#include <cassert>
#include <iostream>
#include "include/creationTableau.hpp"

int main() {
    Tableau tableau(10, 10);
    assert((tableau.getHauteur() == 10) && "Failed: tableau.getHauteur() != 10");
    assert((tableau.getLargeur() == 10) && "Failed: tableau.getLargeur() != 10");
    tableau.setCell(0, 0, 255);
    assert((tableau.getCell(0, 0).getValue() == 255) && "Failed: tableau.getCell(0, 0) != 255");

    // Additional tests
    tableau.setCell(5, 5, 128);
    assert((tableau.getCell(5, 5).getValue() == 128) && "Failed: tableau.getCell(5, 5) != 128");
    tableau.setCell(9, 9, 64);
    assert((tableau.getCell(9, 9).getValue() == 64) && "Failed: tableau.getCell(9, 9) != 64");

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
