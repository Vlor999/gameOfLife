#include <cassert>
#include "include/creationTableau.hpp"

int main() {
    Tableau tableau(10, 10);
    assert(tableau.getHauteur() == 10);
    assert(tableau.getLargeur() == 10);
    tableau.setCell(0, 0, 255);
    assert(tableau.getCell(0, 0) == 255);
    return 0;
}
