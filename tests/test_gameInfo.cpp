#include "../include/string_traits.hpp" // Include this first before any SFML headers
#include <iostream>
#include <cassert>
#include "../include/gameInfo.hpp"

void testGameInfo() {
    // Basic test for gameInfo initialization
    gameInfo game("Test Game", 800, 600, 100, 100);
    
    // Test cell dimensions
    assert(game.getCellHeight() == 6.0f); // 600/100
    assert(game.getCellWidth() == 8.0f);  // 800/100
    
    // Verify window is created
    sf::RenderWindow& window = game.getWindow();
    assert(window.isOpen());
    
    std::cout << "GameInfo tests passed successfully!" << std::endl;
}

int main() {
    testGameInfo();
    return 0;
}
