Bem-vindo ao Gerenciador de Voos UFRN
=====================================

Como compilar
=============
- Ao baixar os arquivos, certifique-se que todos eles se encontram na mesma pasta.
- Abra o terminal do seu computador. Comumente nomeado como "Prompt de comando".
- Por meio do terminal, acesse o diretório em que o código se encontra (Isso é feito a partir do comando: "cd _nome da pasta_").
- Aberto o diretório, digite: "g++ -o _nome_do_executável_ _nome_do_arquivo_.cpp" para compilar. (Observação: o nome_do_executável é fornecido por você no momento da digitação dessa linha). 
- Feita a compilação. Digite: "./_nome_do_executável_".
- Diferentes terminais podem não reconhecer o comando, caso isso ocorra, digite: "_nome_do_executável.exe_". 

Instruções
==========
Inicializado o código, será aberto para o usuário um menu com as seguintes opções: <br />
"(1) - Cadastrar astronauta"<br />
"(2) - Listar astronautas"<br /> 
"(3) - Cadastrar voo" <br />
"(4) - Atribuir astronauta para voo"  <br />
"(5) - Remover astronauta de voo"<br />
"(6) - Lançar voo" <br />
"(7) - Explodir voo" <br />
"(8) - Finalizar voo"<br />
"(9) - Listar voos"<br />
"(10) - Fechar aplicativo"<br />
<br />
Para acessar uma determinada opção do menu, digite o número correspondente a ela.<br />
Por exemplo: Para acessar a função de cadastrar astronauta. Digite "1". <br />
Quando uma opção do menu for finalizada, o programa automáticamente retornará para o menu, abrindo a oportunidade para que você digite outra opção.

(1) - Cadastrar astronauta
==========================
- Digite o nome do astronauta que você deseja cadastrar.
- Digite o CPF do astronauta que você deseja cadastrar.
- Digite a idade do astronauta que você deseja cadastrar.
- Ao fim, o programa exibirá as informações fornecidas.
 
(2) - Listar astronautas
========================
- Ao selecionar essa opção, o programa irá exibir todos os astronautas cadastrados (vivos ou mortos).
- Astronautas mortos virão acompanhados de uma lista de quais voos participaram.
- Opção importante para relembrar o CPF dos Astronautas.

(3) - Cadastrar Voo
====================
- Digite um número inteiro de preferência de até 4 dígitos para representar o código do voo.

(4) - Atribuir astronauta para voo
==================================
- Digite o código do voo (precisa ter sido cadastrado por você anteriormente) o qual você deseja adicionar um astronauta.
- O próprio programa exibirá os voos em planejamento.
- Digite o CPF do Astronauta que você deseja adicionar para esse voo.

(5) - Remover astronauta de voo
================================
- Digite o código do voo (precisa ter sido cadastrado por você anteriormente) o qual você deseja remover um astronauta.
- O próprio programa exibirá os voos em planejamento.
- Digite o CPF do Astronauta que você deseja remover deste voo.

(6) - Lançar voo
================
- Selecionada a opção. O programa exibirá todos os voos que se encontram em planejamento.
- Digite o código do voo que você deseja lançar.
- O voo precisa ter pelo menos um astronauta.
- O astronauta ficará indisponível enquanto estiver no voo.

(7) - Explodir voo
==================
- Selecionada a opção. O programa exibirá todos os voos que se encontram em curso.
- Digite o código do voo que você deseja explodir.
- O voo será marcado como "sem sucesso" e todos os astronautas presente nele serão mortos.

(8) - Finalizar voo
===================
- Selecionada a opção. O programa exibirá todos os voos que se encontram em curso.
- Digite o código do voo que você deseja finalizar.
- O voo será marcado como "sucesso" e todos os astronautas estarão disponíveis novamente para serem atribuidos a outros voo.

(9) - Listar voos
=================
- Selecionada a opção. O programa exibirá todos os voos do programa, bem como seus registros, estado (planejamento, em curso, finalizado ou explodido) e astronautas.

(10) - Fechar aplicativo
========================
- Selecionada a opção. O programa se encerra.


