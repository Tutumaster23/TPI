#include <iostream>
#include <cstdlib>

using namespace std;

int menuJuego(){
    int menu;
        system("cls");
        cout << "-------| MENU PRINCIPAL |-------" <<endl;
        cout << "1. COMENZAR JUEGO NUEVO" <<endl;
        cout << "2. MOSTRAR PUNTUACION MAS ALTA" <<endl;
        cout << "0. SALIR DEL PROGRAMA" <<endl;
        cout << "-------| -------------- |--------" <<endl;
        cin >> menu;
        system("cls");

        return menu;
}

