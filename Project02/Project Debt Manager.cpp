#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <limits>

using namespace std;

string texto = "";

bool esVocal(char c) {
    c = (char)tolower((unsigned char)c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool hayTexto() {
    if (texto.empty()) {
        cout << "  Primero ingresa un texto (opcion 1).\n";
        return false;
    }
    return true;
}

void ingresarTexto() {
    cout << "Escribe una frase (sin tildes): ";
    getline(cin, texto);
    if (texto.empty()) {
        cout << "  No escribiste nada.\n";
    } else {
        cout << "  Texto guardado.\n";
    }
}

void contar() {
    if (!hayTexto()) return;

    int vocales = 0, consonantes = 0, palabras = 0;
    bool enPalabra = false;

    for (size_t i = 0; i < texto.size(); i++) {
        char c = texto[i];
        if (isalpha((unsigned char)c)) {
            if (esVocal(c)) vocales++;
            else consonantes++;
        }
        if (isspace((unsigned char)c)) {
            enPalabra = false;
        } else if (!enPalabra) {
            enPalabra = true;
            palabras++;
        }
    }

    cout << "  Caracteres: " << texto.size() << "\n";
    cout << "  Palabras:   " << palabras << "\n";
    cout << "  Vocales:    " << vocales << "\n";
    cout << "  Consonantes: " << consonantes << "\n";
}

void invertir() {
    if (!hayTexto()) return;

    string invertido = "";
    for (int i = (int)texto.size() - 1; i >= 0; i--) {
        invertido += texto[i];
    }
    cout << "  Al reves: " << invertido << "\n";
}

void verificarPalindromo() {
    if (!hayTexto()) return;

    string limpio = "";
    for (size_t i = 0; i < texto.size(); i++) {
        if (isalnum((unsigned char)texto[i])) {
            limpio += (char)tolower((unsigned char)texto[i]);
        }
    }

    bool esPalindromo = !limpio.empty();
    for (size_t i = 0; i < limpio.size() / 2; i++) {
        if (limpio[i] != limpio[limpio.size() - 1 - i]) {
            esPalindromo = false;
            break;
        }
    }

    if (esPalindromo) cout << "  Si es un palindromo.\n";
    else cout << "  No es un palindromo.\n";
}

void palabraMasLarga() {
    if (!hayTexto()) return;

    stringstream ss(texto);
    string palabra, mayor = "";
    while (ss >> palabra) {
        if (palabra.size() > mayor.size()) mayor = palabra;
    }
    cout << "  Palabra mas larga: " << mayor << " (" << mayor.size() << " letras)\n";
}

void mostrarMenu() {
    cout << "\n===== ANALIZADOR DE TEXTO =====\n";
    cout << "1. Ingresar texto\n";
    cout << "2. Contar caracteres, palabras y letras\n";
    cout << "3. Invertir texto\n";
    cout << "4. Verificar si es palindromo\n";
    cout << "5. Buscar la palabra mas larga\n";
    cout << "6. Salir\n";
    cout << "===============================\n";
}

int main() {
    int opcion;
    do {
        mostrarMenu();
        cout << "Elige una opcion: ";
        if (!(cin >> opcion)) {
            cin.clear();
            opcion = 0;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n";

        switch (opcion) {
            case 1: ingresarTexto(); break;
            case 2: contar(); break;
            case 3: invertir(); break;
            case 4: verificarPalindromo(); break;
            case 5: palabraMasLarga(); break;
            case 6: cout << "Hasta luego!\n"; break;
            default: cout << "  Opcion no valida.\n";
        }
    } while (opcion != 6);

    return 0;
}