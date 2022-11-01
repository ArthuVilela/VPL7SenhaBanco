#include <iostream>
#include "intruso.hpp"

int main() {
    int num_entradas, i;
    string senha;
    Intruso intruso;

    cin >> num_entradas;
    cin.ignore();


    for (i = 0; i < num_entradas; i++) {
        getline(cin, senha);
        intruso.set_senha_vazada(num_entradas, senha);
    }
    intruso.identificaSenha();

    return 0;
}