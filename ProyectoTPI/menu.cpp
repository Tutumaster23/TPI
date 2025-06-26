#include <iostream>
#include <cstdlib>
#include "rlutil.h"
#include "juego.h"

using namespace std;

int menuJuego(){
    int menu;
    system("cls");
    rlutil::locate(40,2);cout << "-------| MENU PRINCIPAL |-------" <<endl;
    rlutil::locate(40,3);cout << "==     1. JUGAR               ==" <<endl;
    rlutil::locate(40,4);cout << "==     2. ESTADISTICAS        ==" <<endl;
    rlutil::locate(40,5);cout << "==     3. CREDITOS            ==" <<endl;
    rlutil::locate(40,6);cout << "==     0. SALIR DEL PROGRAMA  ==" <<endl;
    rlutil::locate(40,7);cout << "-------| ------------- |--------" <<endl;
    rlutil::locate(55,10);cin >> menu;
    system("cls");

    return menu;
}

void interfaz(int ronda, string jugadorActual, int puntajes[2], int dadosStock[2], int turno){
    cout << "==========================" << endl;
    cout << "RONDA #" << ronda << " - TURNO DE: " << jugadorActual << endl;
    cout << "--------------------------" << endl;
    cout << "Puntaje actual: " << puntajes[turno] << " puntos" << endl;
    cout << "Dados stock disponibles: " << dadosStock[turno] << endl;
    cout << "==========================" << endl;
    cout << endl;
}

void interfazFinal(){
    cout << "==========================" << endl;
    cout << "    FIN DEL JUEGO         " << endl;
    cout << "==========================" << endl;
}

void creditos(){
    rlutil::locate(40,2); cout << "----------| CREDITOS |-----------" << endl;
    rlutil::locate(40,4); cout << "============EQUIPO 21============" << endl;
    rlutil::locate(40,5); cout << "==                             ==" <<endl;
    rlutil::locate(40,6); cout << "==  Renato Canavesi, 28592     ==" <<endl;
    rlutil::locate(40,7); cout << "==  Francisco Cristiani, 32383 ==" << endl;
    rlutil::locate(40,8); cout << "==                             ==" <<endl;
    rlutil::locate(40,9); cout << "=================================" << endl;
    rlutil::locate(40,11);cout << "----------| -------- |----------" << endl;
}

void estadisticas(string nombres[], int puntajes[]){
    for (int i= 0; i<2 ; i++){
        cout << nombres[i] << endl;
        cout << puntajes[i] << endl;

    }

}
