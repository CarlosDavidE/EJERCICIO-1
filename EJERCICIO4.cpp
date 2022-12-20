#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string.h>

using namespace std;

enum class Estado {Q0, Q1, Q2, Q3, NO_RECONOCIDO};

Estado reconocerNumero(const string& inputString);

int main() {
    cout << "INGRESE TU CADENA"<<endl;
    string inputString;
    cin >> inputString;
    Estado ultimo = reconocerNumero(inputString);
    if (ultimo == Estado::Q3) {
        cout << "La cadena fue aceptada" << endl;
    } else {
        cout << "La cadena fue rechazada" << endl;
    }

    cout << endl;
    system("pause");
    system("cls");
    main(); 

    return 0;
}

Estado reconocerNumero(const string& inputString)
{
    unsigned int pos = 0;
    Estado actual = Estado::Q0;
    bool cadenaRechazada = false;
    while (not cadenaRechazada and pos < inputString.length()) {
        char simbolo = inputString[pos];
        switch (actual) {
        case Estado::Q0:
            if (simbolo == '1') {
                actual = Estado::Q1;
            } else if (simbolo == '3' ) {
                actual = Estado::Q3;
            } else if (simbolo == '2' ) {
                actual = Estado::Q2;
            } else {
                cadenaRechazada = true;
            }
            break;
        case Estado::Q1:
            if (simbolo == '3') {
                actual = Estado::Q1;
            } else if (simbolo == '1') {
                actual = Estado::Q2;
            } else if (simbolo == '2' ) {
                actual = Estado::Q3;
            } else {
                cadenaRechazada = true;
            }
            break;
        case Estado::Q2:
            if (simbolo == '3') {
                actual = Estado::Q2;
            } else if (simbolo == '1') {
                actual = Estado::Q3;
            } else if (simbolo == '2' ) {
                actual = Estado::Q1;
            } else {
                cadenaRechazada = true;
            }
            break;
        case Estado::Q3:
            if (simbolo == '3') {
                actual = Estado::Q3;
            } else if (simbolo == '2') {
                actual = Estado::Q2;
            } else if (simbolo == '1' ) {
                actual = Estado::Q1;
            } else {
                cadenaRechazada = true;
            }
        }
        pos++;
    }
    if (cadenaRechazada) {
        return Estado::NO_RECONOCIDO;
    }
    return actual;
}