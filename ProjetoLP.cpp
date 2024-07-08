// Bibliotecas - Padrão C++ 
#include <iostream>
#include <string> 
#include <vector>
#include <limits> // Não lembro se eu cheguei a usar mas estou com medo de tirar e causar algum bug

using namespace std; 

// Bibliotecas - Modularização
#include "cadastrar_astronauta.h"
#include "cadastrar_voo.h" 

// Definição Astronauta
class Astronauta{
public: 
    std::string nome; 
    std::string CPF; 
    int idade;                       
    int estado; // 0 = morto
                // 1 = disponível-vivo
                // 2 = indisponível. em voo
    std::vector <int> voos_participados;
}; 

// Definição Voo
class Voo{
public: 
    std::vector <Astronauta_Do_Voo> lista; // É
    int registro; 
    int status;  // 0 = planejamento
                // 1 = em voo
                // 2 = finalizado
                // 3 = explodido 
};

// Opções que o usuário tem para escolher 
void Menu(){
    std::cout << "Menu" << endl; 
    std::cout << "==================================" << endl; 
    std::cout << "(1) - Cadastrar astronauta" << endl; 
    std::cout << "(2) - Listar astronautas" << endl; // Falta os mortos com lista de voo
    std::cout << "(3) - Cadastrar voo" << endl; 
    std::cout << "(4) - Atribuir astronauta para voo" << endl; 
    std::cout << "(5) - Remover astronauta de voo" << endl; 
    std::cout << "(6) - Lançar voo" << endl; // Falta deixar o Astronauta indisponível
    std::cout << "(7) - Explodir voo" << endl; // Falta deixar o Astronauta morto
    std::cout << "(8) - Finalizar voo" << endl; // Falta deixar o astronauta disponível de novo 
    std::cout << "(9) - Listar voos" << endl; 
    std::cout << "(10) - Fechar aplicativo" << endl; 
}

int main(){
    std::cout << "Bem-vindo ao Gerenciador de Voos UFRN, por favor escolha a sua opção digitando o número correspondente" << endl; 
    std::cout << "====================================================================================================" << endl; 

    // Lista de astronautas e de voos - Inicialmente vazia - Novos registros virão para cá. 
    vector <AstronautaLocal> lista_de_astronautas; 
    vector <VooLocal> lista_de_voos;

    // Menu em loop. Escolhas apenas se encerram se o usuário escolher a opção de fechar o programa - Feito para salvar os dados durante execução.
    while(true){
        // Introdução visual - Pequeno espaço para melhorar organização e exibição do menu
        std::cout << "\n";
        Menu(); 

        // Input do usuário e ações correspondentes 
        int input;  
        std::cin >> input;
        switch(input){
            case 1:
                std::cout << "Você selecionou: [Cadastrar astronauta]" << endl;
                lista_de_astronautas.push_back(cadastrar_astronauta());
                break;

            //Falta adicionar os voos que participou e o CPF
            // Para o caso que o usuário digita 2 direto sem registrar nada, não aparece nenhuma mensagem 
            case 2:
                int numero_de_mortos;
                numero_de_mortos = 0;             
                std::cout << "Você selecionou: [Listar astronautas]" << endl;

                // Listando astronautas disponíveis
                std::cout << "=== Disponíveis ===" <<endl;
                for(int i = 0; i < lista_de_astronautas.size(); i++){
                    if(lista_de_astronautas[i].estado == 1){
                        std::cout << lista_de_astronautas[i].nome << endl; 
                        std::cout << "CPF:" <<lista_de_astronautas[i].CPF << endl;      
                    }  
                } 

                // Listando astronautas mortos
                std::cout << "=== Mortos ===" << endl; 
                for(int i = 0; i < lista_de_astronautas.size(); i++){
                    if(lista_de_astronautas[i].estado == 0){
                        std::cout << lista_de_astronautas[i].nome << endl;
                        std::cout << "CPF:" << lista_de_astronautas[i].CPF << endl;
                        std::cout << "Voos participados:" << endl; 
                        for(int j = 0; j < lista_de_astronautas[i].voos_participados.size(); j++){
                            cout << "-" << lista_de_astronautas[i].voos_participados[j] << endl; 
                        } 
                        numero_de_mortos ++;        
                    }
                } 
                if(numero_de_mortos == 0){
                    std::cout << "Não há astronautas mortos" << endl; 
                } 

                break;  


            case 3:
                std::cout << "Você selecionou: [Cadastrar voo]" << endl;
                lista_de_voos.push_back(cadastrar_voo());
                break; 

            case 4:
                std::cout << "Você selecionou: [Atribuir astronauta para voo]\n" << endl;

                // Exibe todos os voos em planejamento
                std::cout << "Listando voos em planejamento:" << endl; 
                for(int i = 0; i < lista_de_voos.size(); i++){
                    if(lista_de_voos[i].status == 0){
                        std::cout << lista_de_voos[i].registro << endl; 
                    }
                }
                
                // Pergunta a qual voo adicionar - Input do usuário
                int input_voo; 
                std::cout << "\nDigite o registro do voo que você deseja adicionar o astronauta" << endl;
                std::cin >> input_voo;

                int encontrado2;
                encontrado2 = 0; 
                for(int i = 0; i < lista_de_voos.size(); i++){
                    if(lista_de_voos[i].registro == input_voo){

                        // Pergunta qual astronauta adicionar - Ele precisa estar disponível
                        string input_astronauta;  
                        std::cout << "\nDigite o CPF do astronauta que você deseja adicionar a este voo" << endl;
                        std::cin >> input_astronauta;

                        // Passa pela lista de astronautas e vê se o CPF corresponde ao de algum astronauta que existe
                        int encontrado1;
                        encontrado1 = 0; 
                        for(int j = 0; j < lista_de_astronautas.size(); j++){
                            if(input_astronauta == lista_de_astronautas[j].CPF && lista_de_astronautas[j].estado == 1){
                                
                                // Copiando parâmetros do objeto para dentro da lista de astronautas em um determinado voo
                                Astronauta_Do_Voo astronauta_voo;
                                astronauta_voo.nome = lista_de_astronautas[j].nome;
                                astronauta_voo.CPF = lista_de_astronautas[j].CPF;
                                astronauta_voo.idade = lista_de_astronautas[j].idade;
                                astronauta_voo.estado = lista_de_astronautas[j].estado;

                                lista_de_voos[i].lista.push_back(astronauta_voo);

                                std::cout << "Astronauta registrado com sucesso!!!" << endl;
                                encontrado1++;
                                encontrado2++;  
                                break;
                            }
                        }
                    if(encontrado1 == 0){
                        std::cout << "Astronauta não encontrado ou CPF digitado incorretamente" << endl; 
                    } 
                    }
                }
                if(encontrado2 == 0){
                    std::cout << "Voo não encontrado ou código digitado incorretamente" << endl; 
                }

                // Limpar o buffer 
                std::cin.clear();
                break;  

            case 5:
                std::cout << "Você selecionou: [Remover astronauta de voo]" << endl;

                // Exibe todos os voos em planejamento
                std::cout << "Listando voos em planejamento:" << endl; 
                for(int i = 0; i < lista_de_voos.size(); i++){
                    if(lista_de_voos[i].status == 0){
                        std::cout << lista_de_voos[i].registro << endl; 
                    }
                }
                
                // Pergunta a qual voo remover - Input do usuário
                std::cout << "\nDigite o registro do voo que você deseja remover o astronauta" << endl;
                int input_voo5; 
                std::cin >> input_voo5;

                int encontrado5;
                encontrado5 = 0; 

                // Loop para pegar o voo que quer remover
                for(int i = 0; i < lista_de_voos.size(); i++){
                    if(lista_de_voos[i].registro == input_voo5){

                        // Pergunta qual astronauta remover
                        string input_astronauta2;  
                        std::cout << "\nDigite o CPF do astronauta que você deseja remover deste voo" << endl;
                        std::cin >> input_astronauta2;

                        // Passa pela lista de astronautas e vê se o CPF corresponde ao de algum astronauta que existe
                        int encontrado6;
                        encontrado6 = 0; 
                        for(int j = 0; j < lista_de_astronautas.size(); j++){
                            if(input_astronauta2 == lista_de_astronautas[j].CPF && lista_de_astronautas[j].estado == 1){
                                lista_de_voos[i].lista.erase(lista_de_voos[i].lista.begin() + j);
                                std::cout << "Astronauta removido do voo com sucesso" << endl; 
                                encontrado6++;  
                                break;
                            }
                        }
                    encontrado5++;
                    if(encontrado6 == 0){
                        std::cout << "Astronauta não encontrado ou inativo" << endl; 
                    } 
                    }
                
                }
                if(encontrado5 == 0){
                    std::cout << "Voo não encontrado ou código digitado incorretamente" << endl; 
                }

                // Limpar o buffer 
                std::cin.clear();

                break;

            case 6: 
                std::cout << "Você selecionou: [Lançar voo]" << endl;
                
                // Exibindo todos os voos em planejamento 
                std::cout << "=== Exibindo voos em planejamento ===" << endl;
                for(int i = 0; i < lista_de_voos.size(); i++){
                    if(lista_de_voos[i].status == 0){
                        std::cout << "\nVoo: " << lista_de_voos[i].registro << endl;
                        for(int j = 0; j < lista_de_voos[i].lista.size(); j++){
                            std::cout <<" - "<< lista_de_voos[i].lista[j].nome << endl; 
                        }  
                    }
                }

                // Input do usuario
                std::cout << "Digite o código do voo o qual você deseja lançar" << endl;
                int input_voo2; 
                std::cin >> input_voo2;

                // Checagem para ver se o voo existe mesmo ou se está listado como em planejamento
                int encontrado;
                encontrado = 0; 
                for(int i = 0; i < lista_de_voos.size(); i++){
                    if(input_voo2 == lista_de_voos[i].registro){
                        if(lista_de_voos[i].lista.empty()){
                            std::cout << "O voo não pode ser lançado, não há astronautas nele" << endl; 
                        }
                        else{
                            // Muda estado dos astronautas para "Em voo"
                            // ---------------------------------------------------
                            // ---------------------------------------------------
                            for(int j = 0; j < lista_de_voos[i].lista.size(); j++){
                                for(int k = 0; k < lista_de_astronautas.size(); k++){
                                    if(lista_de_voos[i].lista[j].CPF == lista_de_astronautas[k].CPF){
                                        lista_de_astronautas[k].estado = 2; // Astronauta em voo
                                        lista_de_astronautas[k].voos_participados.push_back(input_voo2); 
                                        break;
                                    }
                                }
                            } 
                            // Muda estado dos voos para "Em curso"
                            lista_de_voos[i].status = 1;
                            encontrado++;
                            std::cout << "Voo lançado com sucesso!!!" << endl; 
                            break; 
                        }
                    }
                }  
                if(encontrado == 0){
                    std::cout << "Erro ao lançar voo. Certifique-se de que ele se encontra em planejamento, o código foi digitado corretamente e que possua astronautas" << endl; 
                }

                break;  

            case 7:
                std::cout << "Você selecionou: [Explodir voo]" << endl;
                             
                // Exibindo todos os voos em curso  
                std::cout << "=== Exibindo voos em curso ===" << endl;
                for(int i = 0; i < lista_de_voos.size(); i++){
                    if(lista_de_voos[i].status == 1){
                        std::cout << "Voo: " << lista_de_voos[i].registro << endl;
                        for(int j = 0; j < lista_de_voos[i].lista.size(); j++){
                            std::cout <<" - "<< lista_de_voos[i].lista[j].nome << endl; 
                        }  
                    }
                }

                // Input usuário
                std::cout << "Digite o código do voo que você deseja explodir" << endl; 
                int input_voo3; 
                std::cin >> input_voo3;

                // Checagem para ver se o voo existe mesmo ou se está listado como em curso
                int encontrado3;
                encontrado3 = 0; 
                for(int i = 0; i < lista_de_voos.size(); i++){
                    if(input_voo3 == lista_de_voos[i].registro && lista_de_voos[i].status == 1){
                        lista_de_voos[i].status = 3;
                        encontrado3++;
                        std::cout << "Voo explodido... O sacrifício dos astronautas não será em vão..." << endl;

                        // Muda estado dos astronautas para morto ------------------------------------------------------------------
                        // --------------------------------------------------------------------------------------------------------
                        for(int j = 0; j < lista_de_voos[i].lista.size(); j++){
                            for (int k = 0; k < lista_de_astronautas.size(); k++){
                                if (lista_de_voos[i].lista[j].CPF == lista_de_astronautas[k].CPF){
                                    lista_de_astronautas[k].estado = 0; // Astronauta morto
                                    encontrado3++; 
                                    break;
                                }
                            }
                        }  
                    }
                }

                if(encontrado3 == 0){
                    std::cout << "Não foi possível explodir o voo, por favor tente novamente" << endl; 
                }

                break; 

            case 8:
                std::cout << "Você selecionou: [Finalizar voo]" << endl;

                // Exibindo todos os voos em curso  
                std::cout << "=== Exibindo voos em curso ===" << endl;
                for(int i = 0; i < lista_de_voos.size(); i++){
                    if(lista_de_voos[i].status == 1){
                        std::cout << "Voo: " << lista_de_voos[i].registro << endl;
                        for(int j = 0; j < lista_de_voos[i].lista.size(); j++){
                            std::cout <<" - "<< lista_de_voos[i].lista[j].nome << endl; 
                        }  
                    }
                }

                // Input usuário
                std::cout << "Digite o código do voo que você deseja finalizar" << endl; 
                int input_voo4; 
                std::cin >> input_voo4;

                // Checagem para ver se o voo existe mesmo ou se está listado como em curso
                int encontrado4;
                encontrado4 = 0; 
                for(int i = 0; i < lista_de_voos.size(); i++){
                    if(input_voo4 == lista_de_voos[i].registro){
                        lista_de_voos[i].status = 2;
                        encontrado4++;

                        // Mudando status dos astronautas envolvidos para disponível de novo
                        for(int j = 0; j < lista_de_voos[i].lista.size(); j++){
                            for(int k = 0; k < lista_de_astronautas.size(); k++) {
                                if (lista_de_voos[i].lista[j].CPF == lista_de_astronautas[k].CPF){
                                    lista_de_astronautas[k].estado = 1; // Astronauta mudando para disponível 
                                    break;
                                }
                            }
                        }
                        std::cout << "Voo finalizado com sucesso!!!" << endl; 
                        break; 
                    }
                }

                if(encontrado4 == 0){
                    std::cout << "Não foi possível finalizar o voo, por favor tente novamente" << endl; 
                }

                break;  

            case 9:
                std::cout << "Você selecionou: [Listar voos]" << endl;   // E os astronautas 

                std::cout << "=== Planejados ===" << endl;
                for(int i = 0; i < lista_de_voos.size(); i++){
                    if(lista_de_voos[i].status == 0){
                        std::cout << "Voo: " << lista_de_voos[i].registro << endl;
                        for(int j = 0; j < lista_de_voos[i].lista.size(); j++){
                            std::cout << " - " << lista_de_voos[i].lista[j].nome << endl;
                        }
                    }
                }

                std::cout << "=== Em curso ===" << endl;
                for(int i = 0; i < lista_de_voos.size(); i++){
                    if(lista_de_voos[i].status == 1){
                        std::cout << "Voo: " << lista_de_voos[i].registro << endl;
                        for(int j = 0; j < lista_de_voos[i].lista.size(); j++){
                            std::cout << " - " << lista_de_voos[i].lista[j].nome << endl;
                        }
                    }
                }

                std::cout << "=== Finalizados com sucesso ===" << endl;
                for(int i = 0; i < lista_de_voos.size(); i++){
                    if(lista_de_voos[i].status == 2){
                        std::cout << "Voo: " << lista_de_voos[i].registro << endl;
                        for(int j = 0; j < lista_de_voos[i].lista.size(); j++){
                            std::cout << " - " << lista_de_voos[i].lista[j].nome << endl;
                        }
                    }
                }

                std::cout << "=== Finalizados sem sucesso ===" << endl;
                for(int i = 0; i < lista_de_voos.size(); i++){
                    if(lista_de_voos[i].status == 3){
                        std::cout << "Voo: " << lista_de_voos[i].registro << endl;
                        for(int j = 0; j < lista_de_voos[i].lista.size(); j++){
                            std::cout << " - " << lista_de_voos[i].lista[j].nome << endl;
                        }
                    }
                }
                break;
        } 
        if(input == 10){
        std::cout << "\nObrigado por utilizar o nosso gerenciador de voo. Tenha um ótimo dia." << endl;
        break;  
        }
    } 
    return 0; 
    }

