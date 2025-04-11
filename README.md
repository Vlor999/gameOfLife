# gameOfLife
My first version of the game of life in ```C++```

## Technologies
- ```C++```
- ```Makefile```
- ```bash/zsh```
- [```SFML 2```](#installation)

## Structure
- **src** the main directory with all the files to write the game.
- **include** for all the ```hpp``` files that define functions, classes, and others.
- **build** to create when you clone the repository.
- **tests** to verify every part of the code.

## Launch 
To launch the game of life: 
```sh
mkdir -p build && cd build
cmake ..
make
./GameOfLife <options>
```
or use the ```sh``` file : 
```
./launcher.sh <options>
```

## Exemple : 
```bash
./launcher.sh --p 0.8 --size 1000 1000 
```

## Installation
To install [```SFML 2```](https://www.sfml-dev.org/) for : 
* **macOS**:
```sh
brew install sfml@2
brew link sfml@2 --force
```
* **linux**:
```sh
sudo apt install libsfml-dev
```

## Tests
To tests your changement you can do it locally with : 
```sh
cd build
cmake ..
make test # or ctest
```

Otherwise you can use the pipeline into your github repository that will use the same tests case

## License 
- [MIT License](./LICENSE) in the file: **LICENSE**.
