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

char Intruso::identificaSenha(){
     std::vector<char>aux;
    
        for (int j = 0; j < VetorCharIn.size(); j++)
        {
            aux = VetorCharIn[j];
            if (aux[i*2] =='a' )
            {
                /* code */
            }
            
            /* code */
        }
    
    
    
}

std::string Intruso::crack_senha(){
    for (int i = 0; i < 6; i++)
    {
        _senha.push_back(i);
    }
   
    switch ()
    {
    case 'A':
        /* code */
        break;
    case 'B':
        /* code */
        break;
    case 'C':
        /* code */
        break;
    case 'D':
        /* code */
        break;
    case 'E':
        /* code */
        break;
    
    default:
        break;
    }
        
    


    return _senha;
}


