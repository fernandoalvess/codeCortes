## **Sistema de Agendamento para Barbearia** 

Descrição do Problema

Este projeto é um sistema de agendamento de horários para uma barbearia, desenvolvido em linguagem C. O sistema permite que clientes possam marcar e consultar horários disponíveis para atendimento. O objetivo é facilitar o gerenciamento de clientes e horários, otimizando a operação da barbearia.

Funcionalidades principais:

1. Agendamento de horários
2. Cancelamento de agendamentos
3. Visualização de horários disponíveis

O sistema foi desenvolvido com foco em simplicidade e eficiência.


### Passos para Compilar e Executar no *VSCode* (Windows e Linux)

#### 1. Clonar o Repositório do GitHub

1. Abra o *VSCode*.
2. Pressione Ctrl + Shift + P e pesquise por *Git: Clone*.
3. Insira a URL do seu repositório GitHub:

   https://github.com/fernandoalvess/codeCortes
   
4. Escolha uma pasta local para clonar o repositório e aguarde o processo.

5. Após o clone, o VSCode perguntará se deseja abrir a pasta. Clique em *Abrir Projeto*.

#### 2. Abrir o Terminal Integrado

1. Com o projeto aberto no VSCode, abra o terminal integrado pressionando Ctrl + Shift + ' ou vá em *Terminal > Novo Terminal*.
2. O terminal integrado aparecerá na parte inferior do VSCode.

#### 3. Compilar e Executar no *Linux*

1. No terminal do *VSCode*, vá para o diretório do projeto (se ainda não estiver lá):

   cd codeCortes
   
2. Compile o código agendamento.c com o *GCC*:

   gcc -o agendamento agendamento.c
   
3. Após a compilação, execute o programa com:

   ./agendamento
   
#### 4. Compilar e Executar no *Windows*

1. No *Windows, você precisará ter o **MinGW* instalado (com o GCC configurado no PATH). No terminal do *VSCode* (pode ser o *Git Bash* ou *CMD*), navegue até o diretório do projeto:

   cd codeCortes
   
2. Compile o código agendamento.c usando o *GCC*:

   gcc -o agendamento agendamento.c
   
3. Após a compilação, execute o programa no terminal:

   agendamento.exe

Esses são os passos diretos para compilar e executar o código em C no *VSCode, tanto para **Linux* quanto para *Windows*, utilizando o terminal integrado do editor
