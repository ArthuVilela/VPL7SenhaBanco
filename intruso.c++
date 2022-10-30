#include <string>
#include <vector>
#include "intruso.hpp"
#include <iostream>

//#define TAMANHO_SENHA 6;

void Intruso::set_senha_vazada(std::string vazou){
    for(char aux : vazou){
        if((int)aux < 60 ){
            this->IntIn.push_back(aux);
        }else{
            this->CharIn.push_back(aux);
        }

    }
    VetorIntIn.push_back(IntIn);
    VetorCharIn.push_back(CharIn);
    
    for (char aux : IntIn)
    {
        std::cout<<aux<<" ";
    }
    for (char aux : CharIn)
    {
        std::cout<<aux<<" ";
    }
    
    IntIn.erase(IntIn.begin(),IntIn.end());
    CharIn.erase(CharIn.begin(),CharIn.end());
}

void Intruso::identificaSenha(int posicao, std::vector<char> *aux){

    std::vector<char>IntDia = VetorIntIn[posicao];
    for (int i = 0; i < 6; i++)
    {
        switch (*(aux+i))
        {
        case 'A':
            SenhaDia.push_back(IntDia[0]);
            SenhaDia.push_back(IntDia[1]);
            break;
        case 'B':
            SenhaDia.push_back(IntDia[2]);
            SenhaDia.push_back(IntDia[3]);
            break;
        case 'C':
            SenhaDia.push_back(IntDia[4]);
            SenhaDia.push_back(IntDia[5]);
            break;
        case 'D':
            SenhaDia.push_back(IntDia[6]);
            SenhaDia.push_back(IntDia[7]);
            break;
        case 'E':
            SenhaDia.push_back(IntDia[8]);
            SenhaDia.push_back(IntDia[9]);
            break;
        
        default:
            break;
    }
    SenhasPossiveis.push_back(SenhaDia);

}

void comparaSenha(){
    
}


std::string Intruso::crack_senha(){
    std::vector<char> *aux;

    for (int i = 0; i < VetorCharIn.size(); i++)
    {
        aux = &VetorCharIn[i];
        identificaSenha(i,aux);

    }
            
    


    return _senha;
}
/* 
    
        for (int j = 0; j < VetorIntIn.size(); j++)
        {
            aux = VetorIntIn[j];
            if (aux[posicao*2] =='a' )
            {
                
            }
            
}*//*
aux = VetorIntIn[i];
        switch (aux)
            {
            case 'A':
                identificaSenha(0);
                break;
            case 'B':
                identificaSenha(1);
                break;
            case 'C':
                identificaSenha(2);
                break;
            case 'D':
                identificaSenha(3);
                break;
            case 'E':
                identificaSenha(4);
                break;
            
            default:
                break;
*/