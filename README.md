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

## Launch 
To launch the game of life: 
```sh
mkdir -p build && cd build
cmake ..
make
./GameOfLife
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

## License 
- [MIT License](./LICENSE) in the file: **LICENSE**.