# Wolfram Cellular Automation

## Introduction
Wolfram Cellular Automata, pioneered by Stephen Wolfram, are a class of simple computational models that consist of a grid of cells, each in one of a finite number of states. These cells evolve through discrete time steps according to a set of rules based on the states of neighboring cells. Despite their simplicity, Wolfram Cellular Automata can exhibit remarkably complex and interesting behavior.

## Build Instructions

To build  Wolfram Cellular Automation, follow these steps:

1. Clone the repository:

    ```
    git clone https://github.com/jagannathhari/conway_gol
    ```

2. Navigate to the project directory:

    ```
    cd wolfram_ca
    ```

3. Initialize and update submodules:

    ```
    git submodule init
    git submodule update
    ```

4. Run the build script:

    ```
    ./build.sh
    ```

3. Run the executable 
    ```
    ./build/wolfram_ca [rle file path]
    ```
