#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

// Funcion recursiva: factorial
long long factorial(int n) {
    if (n < 0)
        throw invalid_argument("No existe factorial de negativos");

    if (n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}

// Potencia con parametro por omision
double potencia(double base, int exponente = 2) {
    return pow(base, exponente);
}

// Raiz cuadrada con excepcion
double raiz(double numero) {
    if (numero < 0)
        throw invalid_argument("No se puede calcular raiz negativa");
    return sqrt(numero);
}

// Operaciones basicas (sobrecarga con dos operandos)
double operar(double a, double b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw runtime_error("Division entre cero");
            return a / b;
        default:
            throw invalid_argument("Operacion no valida");
    }
}

// Operaciones avanzadas (sobrecarga con un operando)
double operar(double a, char op) {
    switch(op) {
        case 'f': return factorial(a);
        case 'r': return raiz(a);
        default:
            throw invalid_argument("Operacion avanzada no valida");
    }
}

int main() {
    try {
        double a, b;
        char op;

        cout << "Calculadora completa\n";
        cout << "Operaciones basicas: + - * /\n";
        cout << "Operaciones avanzadas: f factorial, p potencia, r raiz\n\n";

        cout << "Ejemplos:\n";
        cout << "5 + 3\n";
        cout << "5 f\n";
        cout << "4 p 3\n\n";

        cout << "Ingresa operacion:\n";

        cin >> a >> op;

        if (op == '+' || op == '-' || op == '*' || op == '/') {
            cin >> b;
            cout << "Resultado: " << operar(a, b, op) << endl;
        }
        else if (op == 'p') {
            cin >> b;
            cout << "Resultado: " << potencia(a, b) << endl;
        }
        else {
            cout << "Resultado: " << operar(a, op) << endl;
        }
    }
    catch (exception &e) {
        cout << "Excepcion: " << e.what() << endl;
    }

    return 0;
}

