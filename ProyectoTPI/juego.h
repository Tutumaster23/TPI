#pragma once
#include <cstdlib>

using namespace std;

void comenzarJuego();

int tiradaInicial(string nombreJugador1,string nombreJugador2);

int tirar(string jugadorActual, int puntajes, int& puntosObtenidos, int dadosStock[2], int turno);

void quienComienza(string nombres[2]);

void limpiarPantalla();

