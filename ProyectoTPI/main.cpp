#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>

using namespace std;

#include "menu.h"
#include "juego.h"
#include "dados.h"
#include "rlutil.h"

int main() {
    srand(time(0));
    int menu;

    while (true) {
        menu = menuJuego();
        switch(menu) {
            case 1:
                comenzarJuego();
                break;
            case 2:
                cout << "Cargando estadisticas..." << endl;
                estadisticas(nombres, puntajes);
                system("pause");
                break;
            case 3:
                creditos();
                break;
            case 0:
                return 0;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    }
    rlutil::hidecursor();
    return 0;
}
