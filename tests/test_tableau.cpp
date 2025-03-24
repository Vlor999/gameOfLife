#include <cassert>
#include "include/creationTableau.hpp"

void testTableau() {
    Tableau tableau(10, 10);
    assert(tableau.getHauteur() == 10);
    assert(tableau.getLargeur() == 10);
    tableau.setCell(0, 0, 255);
    assert(tableau.getCell(0, 0) == 255);
    tableau.setCell(0, 0, 0);
    assert(tableau.getCell(0, 0) == 0);
    assert(tableau.getCell(10, 10) == 0); // Out of bounds
}

int main() {
    testTableau();
    return 0;
}
