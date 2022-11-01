#ifndef INTRUSO_H
#define INTRUSO_H

#include <string>
#include <vector>

using namespace std;


class Intruso {
    int numero_entradas;
    vector<vector<char>> VetorIntIn;
    vector<vector<char>> VetorCharIn;
    vector<char> IntIn;
    vector<char> CharIn;
    vector<vector<char>> SenhasPossiveis;
    vector<char> SenhaUsuario;
    string _senha;

public:
    void set_senha_vazada(int num_entradas, string vazou);
    vector<char> identificaNumerosDaPosicao(char letraSenha, vector<char>senha);
    void identificaSenha();
    void comparaSenha();
    bool compare(vector<char> v1, vector<char> v2);
};
#endif