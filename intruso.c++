#include <string>
#include <vector>
#include "intruso.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

template <typename S>
ostream& operator<<(ostream& os,
    const vector<S>& vector)
{
    // Printing all the elements
    // using <<
    for (auto element : vector) {
        os << element;
    }
    return os;
}

bool Intruso::compare(vector<char> v1, vector<char> v2)
{
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    return v1 == v2;
}

void Intruso::set_senha_vazada(int num_entradas, string vazou) {
    this->numero_entradas = num_entradas;

    for (char aux : vazou) {
        if ((int)aux < 60) {
            this->IntIn.push_back(aux);
        }
        else {
            this->CharIn.push_back(aux);
        }

    }

    this->VetorIntIn.push_back(IntIn);
    this->VetorCharIn.push_back(CharIn);

    this->IntIn.erase(IntIn.begin(), IntIn.end());
    this->CharIn.erase(CharIn.begin(), CharIn.end());
}

vector<char> Intruso::identificaNumerosDaPosicao(char letraSenha, vector<char> senha) {

    vector<char> numerosDaLetra;
    switch (letraSenha)
    {
    case 'A':
        numerosDaLetra.push_back(senha[0]);
        numerosDaLetra.push_back(senha[2]);
        break;
    case 'B':

        numerosDaLetra.push_back(senha[4]);
        numerosDaLetra.push_back(senha[6]);
        break;

    case 'C':
        numerosDaLetra.push_back(senha[8]);
        numerosDaLetra.push_back(senha[10]);
        break;
    case 'D':
        numerosDaLetra.push_back(senha[12]);
        numerosDaLetra.push_back(senha[14]);
        break;
    case 'E':
        numerosDaLetra.push_back(senha[16]);
        numerosDaLetra.push_back(senha[18]);
        break;

    default:
        break;
    }

    return numerosDaLetra;
}

void Intruso::identificaSenha() {
    vector<char> senhaUsuario;
    vector<char> segredoPrimeiraSenha;
    vector<char> segredoSegundaSenha;
    vector<char> primeiraSenha;
    vector<char> segundaSenha;
    vector<char> numerosDaLetraPrimeiraSenha;
    vector<char> numerosDaLetraSegundaSenha;
    int confereNumero;
    char ultimoNumero;

    for (int i = 0; i < 6; i++) {
        confereNumero = 0;

        for (int j = 0; j < this->numero_entradas - 1; j++) {

            segredoPrimeiraSenha = this->VetorIntIn[j];
            segredoSegundaSenha = this->VetorIntIn[j + 1];
            primeiraSenha = this->VetorCharIn[j];
            segundaSenha = this->VetorCharIn[j + 1];
            
            numerosDaLetraPrimeiraSenha = identificaNumerosDaPosicao(primeiraSenha[i], segredoPrimeiraSenha);
            numerosDaLetraSegundaSenha = identificaNumerosDaPosicao(segundaSenha[i], segredoSegundaSenha);

            if (compare(numerosDaLetraPrimeiraSenha, numerosDaLetraSegundaSenha)) {
                confereNumero++;
            }
            else {
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++) {

                        if (numerosDaLetraPrimeiraSenha[k] == numerosDaLetraSegundaSenha[l]) {
                            confereNumero++;
                            ultimoNumero = numerosDaLetraPrimeiraSenha[k];
                            if (confereNumero == (this->numero_entradas - 1)) {

                                senhaUsuario.push_back(numerosDaLetraPrimeiraSenha[k]);
                                confereNumero = 0;
                            }
                        }
                    }
                }

            }

            if (confereNumero == (this->numero_entradas - 1)) {
                senhaUsuario.push_back(ultimoNumero);
                confereNumero = 0;
            }
        }
    }
    cout << senhaUsuario << endl;
}
