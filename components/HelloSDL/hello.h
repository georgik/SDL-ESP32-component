#ifndef HELLO_H
#define HELLO_H

#include "SDL.h"

#define COUNTOF(x) ((unsigned)(sizeof(x) / sizeof *(x)))  // use only on arrays!
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main( int argc, char *argv[] );

#endif
