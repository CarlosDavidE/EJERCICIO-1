#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

enum class Estado {Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7, NO_RECONOCIDO};

Estado reconocerNumero(const string& inputString);

int main() {
    cout << "Numero = Numero operador Numero, donde el operador puede ser + - * / , los numeros" << endl;
    cout << "pueden ser valores reales o enteros, por ejemplo 2.3; 000.89; 0.75; .100; 245; 4.57;" << endl;
    cout << "00000210; 0.0; 000001.0000 pero en ningun caso se admite - numero punto - por" << endl;
    cout << "ejemplo 123. o 00." << endl;
    cout << "-----------------------------------------------------------------------------"<<endl;
    cout << "INGRESE TU CADENA"<<endl;
    string inputString;
    cin >> inputString;
    Estado ultimo = reconocerNumero(inputString);
    if (ultimo == Estado::Q5 or ultimo == Estado::Q7 ) {
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
            if (isdigit(simbolo)) {
                actual = Estado::Q1;
            } else if (simbolo == '.' ) {
                actual = Estado::Q2;
            } else {
                cadenaRechazada = true;
            }
            break;
        case Estado::Q1:
            if (isdigit(simbolo)) {
                actual = Estado::Q1;
            } else if (simbolo == '.') {
                actual = Estado::Q2;
            } else if (simbolo == '+' or simbolo == '-' or simbolo == '*' or simbolo == '/' ) {
                actual = Estado::Q4;
            } else {
                cadenaRechazada = true;
            }
            break;
        case Estado::Q2:
            if (isdigit(simbolo)) {
                actual = Estado::Q3;
            } else {
                cadenaRechazada = true;
            }
            break;
        case Estado::Q3:
            if (isdigit(simbolo)) {
                actual = Estado::Q3;
            } else if (simbolo == '+' or simbolo == '-' or simbolo == '*' or simbolo == '/') {
                actual = Estado::Q4;
            } else {
                cadenaRechazada = true;
            }
            break;
        case Estado::Q4:
            if (isdigit(simbolo)) {
                actual = Estado::Q5;
            } else if (simbolo == '.') {
                actual = Estado::Q6;
            } else {
                cadenaRechazada = true;
            }
            break;
        case Estado::Q5:
            if (isdigit(simbolo)) {
                actual = Estado::Q5;
            }else if (simbolo == '.') {
                actual = Estado::Q6;
            }else {
                cadenaRechazada = true;
            }
            break;
        case Estado::Q6:
            if (isdigit(simbolo)) {
                actual = Estado::Q7;
            } else {
                cadenaRechazada = true;
            }
        case Estado::Q7:
            if (isdigit(simbolo)) {
                actual = Estado::Q7;
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
