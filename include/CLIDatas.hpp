#include <cstring>
#include <cstdlib>
#include <iostream>


using namespace std;

class CLIDatas
{
private:
    string currentFile;
    string nameOfGame;
    float proportion;
    bool isHelp = false;
public:
    CLIDatas(){
        this->proportion = 1.0;
        this->nameOfGame = "Game of life";
    }

    CLIDatas(int argc, char* argv[]){
        this->proportion = 1.0; // default value
        this->nameOfGame = "Game of life";
        this->currentFile = argv[0];
        for (int i = 1; i < argc; i++){
            if (std::strcmp(argv[i], "--p") == 0 && i + 1 < argc){
                this->proportion = std::atof(argv[i + 1]);
            }
            else if (std::strcmp(argv[i], "--help") == 0){
                this->isHelp = true;
            }
            else if (std::strcmp(argv[i], "--n") == 0 && i + 1 < argc){
                this->nameOfGame = argv[i + 1];
            }
        }

        if (this->isHelp){
            displayHelp();
            std::exit(0);
        }
    }
    
    ~CLIDatas();

    float getProportion() const {
        return proportion;
    }

    string getNameOfGame() const {
        return nameOfGame;
    }

    void displayHelp() const {
        std::cout << "Usage: " << currentFile << " [options]\n"
                  << "Options:\n"
                  << "  --p <value>    Set the proportion value\n"
                  << "  --help         Display this help message\n";
    }
};

CLIDatas::~CLIDatas()
{
}
