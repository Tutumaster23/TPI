#include <iostream>
#include <cstdlib>

#include "dados.h"
#include "juego.h"

using namespace std;

void limpiarPantalla(){
    system("pause");
    system("cls");
}

void comenzarJuego() {
    string nombres[2];
    int puntajes[2] = {0,0};
    int pasardados;
    int puntosObtenidos = 0;

    quienComienza(nombres);

    for (int ronda = 1; ronda <= 3; ronda++) {
        for (int turno = 0; turno < 2; turno++) {
            string jugadorActual = nombres[turno];

            cout << "==========================" << endl;
            cout << "RONDA #" << ronda << " - TURNO DE: " << jugadorActual << endl;
            cout << "==========================" << endl;



            if (turno == 0)
                pasardados = tirar(0, jugadorActual, puntajes[turno], puntosObtenidos, puntajeJugador);
            else
                tirar(pasardados, jugadorActual, puntajes[turno], puntosObtenidos, puntajeJugador);

                puntajes[turno] += puntosObtenidos;
                cout << jugadorActual << " tiene " << puntajes[turno] << endl;

            limpiarPantalla();
        }
    }

    cout << "==========================" << endl;
    cout << "    FIN DEL JUEGO         " << endl;
    cout << "==========================" << endl;

    system("pause");
}

int tiradaInicial(string nombreJugador1,string nombreJugador2) {
        int Jugador1 = 0, Jugador2 = 0, JugadorP = 0;
        while(Jugador1 == Jugador2){
            int dados6[1];

            cout << "Primer dado: " << endl;
            cargarDados6(dados6, 1);
            mostrarDados(dados6, 1);

            Jugador1 = dados6[0];

            system("pause");
            cout << endl;

            cout << "Segundo dado: " << endl;
            cargarDados6(dados6, 1);
            mostrarDados(dados6, 1);

            Jugador2 = dados6[0];

            limpiarPantalla();

            if (Jugador1 == Jugador2){
                cout << "Empate! Tirar de vuelta..." << endl;
                limpiarPantalla();
            }

        }

        if (Jugador1 > Jugador2){
            JugadorP = 1;
            cout << "Empieza " << nombreJugador1 << ": [" << Jugador1 << "]" << endl;
            cout << "Sigue " << nombreJugador2 << ": [" << Jugador2 << "]" << endl;
        } else {
            JugadorP = 2;
            cout << "Empieza " << nombreJugador2 << ": [" << Jugador2 << "]" << endl;
            cout << "Sigue " << nombreJugador1 << ": [" << Jugador1 << "]" << endl;
        }

        limpiarPantalla();
        return JugadorP;
}

void quienComienza(string nombres[2]) {
    string nombreJugador1, nombreJugador2;

    cout << "Nombre del Jugador 1: ";
    cin >> nombreJugador1;
    cout << "Nombre del Jugador 2: ";
    cin >> nombreJugador2;

    system("cls");

    int resultado = tiradaInicial(nombreJugador1, nombreJugador2);

    if (resultado == 1) {
        nombres[0] = nombreJugador1;
        nombres[1] = nombreJugador2;
    } else {
        nombres[0] = nombreJugador2;
        nombres[1] = nombreJugador1;
    }
}

int tirar(int pasardados, string jugadorActual, int puntajes, int& puntosObtenidos, int& puntajeJugador) {
    cout << "2 dados de 12 caras" << endl;
    int dados12[2],suma12 = 0;
    cargarDados12(dados12, 2);
    mostrarDados(dados12, 2);
    for (int i = 0; i <= 1; i++){
        suma12 += dados12[i];
    }

    cout << endl;
    cout << "Numero Objetivo: " << suma12 << endl;
    cout << endl;

    cout << "6 dados de 6 caras" << endl;
    int dados6[6];
    cargarDados6(dados6, 6);
    mostrarDados(dados6, 6);

    cout << endl << "Seleccionar los dados stock para alcanzar el numero objetivo (Selecciona 0 para cerrar la suma): "<< endl;

    int dados6suma = 0;
    bool dados6usados[6] = {false};
    int dados6valor;
    int cont = 0;

    while (true) {
        cin >> dados6valor;
        if (dados6valor == 0) break;

        bool encontrado = false;
        for (int i = 0; i < 6; i++) {
            if (!dados6usados[i] && dados6[i] == dados6valor) {
                dados6usados[i] = true;
                dados6suma += dados6valor;
                encontrado = true;
                cont++;
                break;
            }
        }

        if (!encontrado) {
            cout << "No se encuentro ese valor de dado" << endl;
        } else {
            cout << "Suma actual: " << dados6suma << endl;
        }

        if (cont == 6 && dados6suma == suma12){
        cout << "Usaste todos los dados!! " << jugadorActual << " Gano!!" << endl;
        limpiarPantalla();
        exit(0);
        }
    }

    cout << endl << "Suma final seleccionada: " << dados6suma << endl;
    if (dados6suma == suma12) {
        cout << "Alcanzaste el Numero Objetivo" << endl;
        int puntaje = cont*suma12;

        puntosObtenidos += puntaje;

        cout << puntaje << endl;

    } else if (dados6suma < suma12) {
        cout << "No alcanzaste el numero objetivo!!" << endl;
    } else {
        cout <<"Te pasaste!!" << endl;
    }


    limpiarPantalla();
    return cont;
}
