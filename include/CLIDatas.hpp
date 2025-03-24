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
    int attente;
    bool isHelp = false;
    bool isManual = false;
public:
    CLIDatas(){
        this->proportion = 1.0;
        this->nameOfGame = "Game of life";
        this->attente = 0;
    }

    CLIDatas(int argc, char* argv[]){
        this->proportion = 1.0; // default value
        this->nameOfGame = "Game of life";
        this->attente = 0;
        this->currentFile = argv[0];
        for (int i = 1; i < argc; i++){
            if (std::strcmp(argv[i], "--p") == 0 && i + 1 < argc){
                this->proportion = std::atof(argv[i + 1]);
                i++;
            }
            else if (std::strcmp(argv[i], "--help") == 0){
                this->isHelp = true;
            }
            else if (std::strcmp(argv[i], "--m") == 0){
                this->isManual = true;
                cout << "Command : --m not yet available\n";
            }
            else if (std::strcmp(argv[i], "--n") == 0 && i + 1 < argc){
                this->nameOfGame = argv[i + 1];
                i++;
            }
            else if (std::strcmp(argv[i], "--s") == 0 && i + 1 < argc){
                this->attente = std::atoi(argv[i + 1]);
                i++;
            }
            else {
                displayHelp();
                exit(EXIT_FAILURE);
            }
        }

        if (this->isHelp){
            displayHelp();
            exit(EXIT_SUCCESS);
        }
    }
    
    ~CLIDatas();

    float getProportion() const {
        return proportion;
    }

    string getNameOfGame() const {
        return nameOfGame;
    }

    bool getIsManual() const {
        return isManual;
    }

    int getAttente() const {
        return attente;
    }

    void displayHelp() const {
        std::cout << "Usage: " << currentFile << " [options]\n"
                  << "Options:\n"
                  << "  --p <value>               Set the proportion value\n"
                  << "  --n <name of your game>   Set the name of the window\n"
                  << "  --m                       You are going to set the position of the object\n"
                  << "  --help                    Display this help message\n";
    }
};

CLIDatas::~CLIDatas()
{
}
