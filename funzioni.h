#ifndef FUNZIONI_H_INCLUDED
#define FUNZIONI_H_INCLUDED

#include <iostream>
#include <string>

#include "nave.h"
using namespace std;

void trasformazione_coordinate(string s, int &x, int &y, char &o);

void trasformazione_coordinate_ridotta(string s, int &x, int &y);

string trasformazione_coordinate_ridotta_inversa(int x, int y);

void titolo();

void titolo2();

void passo();

// void randomizzatore();

#endif // FUNZIONI_H_INCLUDED
