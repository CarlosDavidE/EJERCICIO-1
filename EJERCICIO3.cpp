#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

enum class Estado {INICIO, Q1, Q2, ENTERO, REAL, NO_RECONOCIDO};

Estado reconocerNumero(const string& inputString);

int main() {
    cout << "Generar todos los números racionales escritos en decimal con el formato:  << endl;
    cout <<"Signo Parte entera . Parte fraccionaria" << endl;
     cout <<"Donde el signo es optativo, siendo + o -" << endl;
    string inputString;
    cin >> inputString;
    Estado ultimo = reconocerNumero(inputString);
    if (ultimo == Estado::ENTERO) {
        cout << "La cadena no es aceptada" << endl;
    } else if (ultimo == Estado::REAL) {
        cout << "La cadena es aceptada" << endl;
    } else {
        cout << "La cadena ingresada no es un numero entero ni real" << endl;
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
    Estado actual = Estado::INICIO;
    bool cadenaRechazada = false;
    while (not cadenaRechazada and pos < inputString.length()) {
        char simbolo = inputString[pos];
        switch (actual) {
        case Estado::INICIO:
            if (isdigit(simbolo)) {
                actual = Estado::ENTERO;
            } else if (simbolo == '+' or simbolo == '-') {
                actual = Estado::Q1;
            } else {
                cadenaRechazada = true;
            }
            break;
        case Estado::Q1:
            if (isdigit(simbolo)) {
                actual = Estado::ENTERO;
            } else if (simbolo == '.') {
                actual = Estado::Q2;
            } else {
                cadenaRechazada = true;
            }
            break;
        case Estado::Q2:
            if (isdigit(simbolo)) {
                actual = Estado::REAL;
            } else {
                cadenaRechazada = true;
            }
            break;
        case Estado::ENTERO:
            if (isdigit(simbolo)) {
                actual = Estado::ENTERO;
            } else if (simbolo == '.') {
                actual = Estado::Q2;
            } else {
                cadenaRechazada = true;
            }
            break;
        case Estado::REAL:
            if (isdigit(simbolo)) {
                actual = Estado::REAL;
            } else {
                cadenaRechazada = true;
            }
            break;
        }
        pos++;
    }
    if (cadenaRechazada) {
        return Estado::NO_RECONOCIDO;
    }
    return actual;
}