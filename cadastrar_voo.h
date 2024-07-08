#ifndef CADASTRAR_VOO_H
#define CADASTRAR_VOO_H

#include <iostream>
#include <string>
#include <vector> 

using namespace std;

class Astronauta_Do_Voo{
public: 
    std::string nome; 
    std::string CPF; 
    int idade;                       
    int estado; // 0 = morto
                // 1 = vivo
    std::vector <int> voos_participados; 
}; 

class VooLocal{
public: 
    vector <Astronauta_Do_Voo> lista; // É
    int registro; 
    int status; // 0 = planejamento
                // 1 = em voo
                // 2 = finalizado
                // 3 = explodido 
};

VooLocal cadastrar_voo(){
    VooLocal novo_voo;  
    cout << "Digite o código do voo (número inteiro de até 4 caracteres )" << endl;
    cin >> novo_voo.registro;
    novo_voo.lista.clear(); 
    novo_voo.status = 0;

    cout << "Voo cadastrado com sucesso!!!" << endl;
    cout << "" << endl;  
    return novo_voo; 
}

#endif
