#include <cassert>
#include <iostream>
#include "include/gameInfo.hpp"

void testGameInfo() {
    gameInfo game("Test Game", 800, 600, 100, 100);
    assert((game.getCellHeight() == 6.0f) && "Failed: game.getCellHeight() != 6.0f");
    assert((game.getCellWidth() == 8.0f) && "Failed: game.getCellWidth() != 8.0f");
    assert((game.getWindow().isOpen()) && "Failed: game.getWindow().isOpen() == false");

    // Additional tests
    game.setBox(0, 0, 255);
    game.setBox(99, 99, 128);
    assert((game.getCell().getSize().x == game.getCellWidth()) && "Failed: game.getCell().getSize().x != game.getCellWidth()");
    assert((game.getCell().getSize().y == game.getCellHeight()) && "Failed: game.getCell().getSize().y != game.getCellHeight()");
}

int main() {
    testGameInfo();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
