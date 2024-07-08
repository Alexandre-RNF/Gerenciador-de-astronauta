#ifndef CADASTRAR_ASTRONAUTA_H
#define CADASTRAR_ASTRONAUTA_H

#include <iostream>
#include <string>
using namespace std; 

class AstronautaLocal {
public: 
    string nome; 
    string CPF;  // Não vou realizar nenhuma operação então melhor o CPF ser um string 
    int idade; 
    int estado;  // 0 = Morto
                 // 1 = Vivo
    std::vector <int> voos_participados; 
};

AstronautaLocal cadastrar_astronauta(){
    AstronautaLocal novo_astronauta; 

    // Pegando inputs 
    cout << "Informe o nome do astronauta: \n";
    cin.ignore();                                   
    getline(cin, novo_astronauta.nome); 

    cout << "Informe o CPF do astronauta: \n";
    getline(cin, novo_astronauta.CPF);

    cout << "Informe a idade do astronauta: \n";                                
    cin >> novo_astronauta.idade;
    cin.ignore();    

    novo_astronauta.estado = 1;  // Sinalizar que ele está vivo
    novo_astronauta.voos_participados.clear(); 

    // Exibindo os dados do astronauta
    cout << "\nAstronauta cadastrado com sucesso!!! \n";
    cout << "\nNome: " << novo_astronauta.nome << endl;
    cout << "CPF: " << novo_astronauta.CPF << endl; 
    cout << "Idade: " << novo_astronauta.idade << endl;
    cout << "Estado: " << (novo_astronauta.estado == 1 ? "Vivo" : "Morto") << endl;

    return novo_astronauta; 
}

#endif

