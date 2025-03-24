#include <cassert>
#include "include/CLIDatas.hpp"

void testCLIDatas() {
    const char* argv[] = {"program", "--p", "0.5", "--n", "Test Game"};
    CLIDatas cliData(5, const_cast<char**>(argv));
    assert(cliData.getProportion() == 0.5f);
    assert(cliData.getNameOfGame() == "Test Game");
}

int main() {
    testCLIDatas();
    return 0;
}
