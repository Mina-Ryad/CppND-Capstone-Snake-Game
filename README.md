<img src="snake_game.gif"/>

# Description
1 - An additional food is added
2 - The color of the food and the snake changes randomly every time food is eaten
3 - Some code optimizations are made

# Rubric points Covered
## Loops, Functions, I/O
1 - A variety of control structures are used in the project.
    The project code is clearly organized into functions.
2 - The project accepts input from a user as part of the necessary operation of the program.
    --> Using Controller class that handles user input using sdl library
## Object Oriented Programming
3 - The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.
4 - All class data members are explicitly specified as public, protected, or private.
5 - All class members that are set to argument values are initialized through member initialization lists.
    --> Class Game
    --> Class Snake
    --> Class Renderer
6 - All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways.
7 - Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions.
    --> update Snake all previous public member variables to private
8 - At least two variables are defined as references, or two functions use pass-by-reference in the project code.
    --> in main file Controller and Renderer Objects are passed by r-value reference to Run function

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
