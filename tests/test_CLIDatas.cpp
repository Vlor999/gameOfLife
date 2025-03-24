#include <cassert>
#include <iostream>
#include "include/CLIDatas.hpp"

void testCLIDatas() {
    const char* argv[] = {"program", "--p", "0.5", "--n", "Test Game"};
    CLIDatas cliData(5, const_cast<char**>(argv));
    assert((cliData.getProportion() == 0.5f) && "Failed: cliData.getProportion() != 0.5f in argv[] test");
    assert((cliData.getNameOfGame() == "Test Game") && "Failed: cliData.getNameOfGame() != 'Test Game' in argv[] test");

    // Additional tests
    const char* argv2[] = {"program", "--p", "0.8", "--n", "Another Game", "--s", "100"};
    CLIDatas cliData2(7, const_cast<char**>(argv2));
    assert((cliData2.getProportion() == 0.8f) && "Failed: cliData2.getProportion() != 0.8f in argv2[] test");
    assert((cliData2.getNameOfGame() == "Another Game") && "Failed: cliData2.getNameOfGame() != 'Another Game' in argv2[] test");
    assert((cliData2.getAttente() == 100) && "Failed: cliData2.getAttente() != 100 in argv2[] test");

    // Test with wrong arguments
    const char* argv4[] = {"program", "--x", "1.0", "--y", "Wrong Args"};
    CLIDatas cliData4(5, const_cast<char**>(argv4));
    assert((cliData4.getProportion() == 1.0) && "Failed: cliData4.getProportion() != 0.0f in argv4[] test");
    assert((cliData4.getNameOfGame() == "Game of life") && "Failed: cliData4.getNameOfGame() != '' in argv4[] test");

    // Test with redefinition of arguments
    const char* argv5[] = {"program", "--p", "0.3", "--p", "0.7", "--n", "Redefinition"};
    CLIDatas cliData5(7, const_cast<char**>(argv5));
    assert((cliData5.getProportion() == 0.7f) && "Failed: cliData5.getProportion() != 0.7f in argv5[] test"); // Assuming last definition is taken
    assert((cliData5.getNameOfGame() == "Redefinition") && "Failed: cliData5.getNameOfGame() != 'Redefinition' in argv5[] test");
}

int main() {
    testCLIDatas();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
