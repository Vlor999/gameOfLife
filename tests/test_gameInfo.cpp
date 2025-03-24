#include <cassert>
#include "include/gameInfo.hpp"

void testGameInfo() {
    gameInfo game("Test Game", 800, 600, 100, 100);
    assert(game.getCellHeight() == 6.0f);
    assert(game.getCellWidth() == 8.0f);
    assert(game.getWindow().isOpen());
}

int main() {
    testGameInfo();
    return 0;
}
