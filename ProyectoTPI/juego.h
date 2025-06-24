#pragma once
#include <cstdlib>

using namespace std;

void comenzarJuego();

int tiradaInicial(string nombreJugador1,string nombreJugador2);

int tirar(int pasardados, string jugadorActual, int puntajes, int& puntosObtenidos, int& puntajeJugador);

void quienComienza(string nombres[2]);

void limpiarPantalla();

