#include "basic-terminal.h"


int main(){
    BasicTerminal linux = BasicTerminal();

    linux.mkdir("cow");
    linux.mkdir("rocket");
    linux.mkdir("pig");
    linux.mkdir("door");
    linux.mkdir("zebra");
    linux.touch("airplane.txt");
    linux.ls();

    linux.cd("cow");
    linux.mkdir("legs");
    linux.cd("..");
    linux.touch("cow/legs/thigh.txt");

    linux.cd("cow/legs");
    linux.mkdir("hind_legs");
    linux.mkdir("zad");
    linux.ls();
    linux.pwd();

    linux.mkdir("/rocket/spaceX");
    linux.mkdir("/rocket/NASA");
    linux.cd("/rocket");
    linux.ls();
    linux.pwd();

    return 0;
}

/* TEST */

/*

/
|
| _ _  /cow
|       |
|       | - - /legs
|               |
|               | - - /hind_legs
|               | - - /zad
|               | - - thigh.txt
|       
| - - /rocket
|
|
| - - /pig
|
| - - /door
|
| - - /zebra
|
| - - airplane.txt


*/







/*
Example file system:

/
|
| _ _  Doc
|       |
|       | - - Animals
|       
|
|
|
|
| - - Desktop




Commands:

1. ls:

    \directory1 \directory2 files1 files2 ...





1. ls:

    ls   --> immediate directory

    ls Doc/Anmals --> further down

    In directory Doc

    ls /Desktop --> absolute








*/