# SDL2 Template

This is a simple template for making something with SDL2.

In order to run this project you use the command:

For Debug:
g++ -c *.cpp -std=c++14 -m64 -g -Wall && g++ *.o -o bin/debug/main -lSDL2main -lSDL2 -lSDL2_image && ./bin/debug/main

For Release:
g++ -c *.cpp -std=c++14 -m64 -O3 -Wall && g++ *.o -o bin/release/main -s -lSDL2main -lSDL2 -lSDL2_image && ./bin/release/main
