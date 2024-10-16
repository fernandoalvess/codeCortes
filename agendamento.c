#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 100

// estrutura do agendamento
typedef struct Agendamento {
    char *nome;
    char *horario; //hh:mm
    struct Agendamento *proximo; // ponteiro para prox agendamento
    struct Agendamento *esq, *dir; // nós da arvore bionaria de busca
}Agendamento;

//tabela hash
Agendamento *tabelaHash[TAMANHO_TABELA];

// variaveis globais
Agendamento *cliente = NULL; // ponteiro global para o inicio da lista encadeadaa
Agendamento *raiz = NULL; // arvore binaria de busca
int totalAgendamento = 0;

// Função hash para inserir na tabela
int funcaoHash(char *nome) {
    int hash = 0;
    for (int i = 0; nome[i] != '\0'; i++) {
        hash += nome[i];
    }
    return hash % TAMANHO_TABELA;
}

//Função para inserir na tabela hash
void inserirHash(Agendamento *novoAgendamento) {
    int j = funcaoHash(novoAgendamento -> nome);
    tabelaHash[j] = novoAgendamento;
}

// Busca na tabela hash
Agendamento *buscarHash(char *nome) {
    int j = funcaoHash(nome);
    return tabelaHash[j];
}

// Para inserir na arvore binaria de busca por horario
Agendamento *inserirBST(Agendamento *raiz, Agendamento *novoAgendamento) {
    if (raiz == NULL) {
        return novoAgendamento;
    }
    if (strcmp(novoAgendamento->horario, raiz->horario) < 0){
        raiz->esq = inserirBST(raiz->esq, novoAgendamento);
    } else {
        raiz->dir = inserirBST(raiz->dir, novoAgendamento);
    }
    return raiz;
}

// Busca na arvore binaria de busca por horario
Agendamento *buscarBST(Agendamento *raiz, Agendamento *horario) {
    if (raiz == NULL || strcmp(raiz->horario, horario) == 0) {
        return raiz;
    }
    if (strcmp(horario, raiz->horario) < 0){
        return buscarBST(raiz->esq, horario);
    } else {
        return buscarBST(raiz->dir, horario);
    }
}

//Função para verificar se o horario esta ocupado usando BST
int verificarAgenda(char *horario) {
    return buscarBST(raiz, horario) == NULL; // esta disponivel se não encontrar no BST
}

//Função para agendar novo corte
void agendar() {
    Agendamento *novoAgendamento = (Agendamento*)malloc(sizeof(Agendamento));

    //para alocar nome e horario
    novoAgendamento->nome = (char *)malloc(50 * sizeof (char));
    novoAgendamento->horario = (char *)malloc(6 * sizeof (char));
    novoAgendamento->proximo = novoAgendamento->esq = novoAgendamento->dir = NULL;

    //variavel temporaria
    char nomeTemp[50];
    char horarioTemp[6];

    printf("AGENDE SEU MOMENTO\n");
    printf("Nome: ");
    scanf("%49s", nomeTemp);
    printf("Horario: ");
    scanf("%5s", horarioTemp);

    // para verificar se o hoarario esta livre usando BST
    if ( verificarAgenda(horarioTemp)){
        //copia para as pocições corretas
        strcpy(novoAgendamento->nome, nomeTemp);
        strcpy(novoAgendamento->horario, horarioTemp);

        //inserir na lista encadeada
        novoAgendamento->proximo = cliente; //vai inserir novo agendamento
        cliente = novoAgendamento; // atualiza a lista encadeada
        //inserir na arvore binaria de busca
        raiz = inserirBST(raiz, novoAgendamento);
        //inserir na tela hash
        inserirHash(novoAgendamento);
        totalAgendamento++;
        printf("Agendamento foi realizado!\n");
    } else {
        printf("Ops! Esse horario nao esta disponivel :(\n");
        free(novoAgendamento->nome);
        free(novoAgendamento->horario);
        free(novoAgendamento);
    }

}

//Funçaõ para exibir agendamentos
void cortesAgendados() {
    if (totalAgendamento == 0) {
        printf("Por enquanto, todos os horarios estao disponiveis!\n");
        return;
    }

    Agendamento *agenda = cliente;
    printf("AGENDAMENTOS DO DIA:\n");
    int i = 1;
    while (agenda != NULL)
    {
        printf("%d - Nome: %s | Horario: %sh\n", i, agenda->nome, agenda->horario);
        i++;
        agenda = agenda->proximo; // vai para o proximo agendado
    }
}

//Função para alterar horario
void alterarHorario() {
    if (totalAgendamento == 0) {
        printf("Sem agendamentos para alterar!\n");
        return;
    }

    char nome[50];
    char novoHorario[6];

    printf("Digite o nome do cliente: ");
    scanf("%49s", nome);

    //Busca na tabela hash pelo nome
    Agendamento *agenda = buscarHash(nome);

    if(agenda != NULL) {
        printf("Digite o novo horario: \n");
        scanf("%5s", novoHorario);

        if (verificarAgenda(novoHorario)) {
            //altera o horário
            strcpy(agenda->horario, novoHorario);
            printf("O horario foi alterado com sucesso!\n");
        } else {
            printf("Ops! Esse horario nao esta disponivel :(\n");
        }
    } else {
        printf("Nenhum agendamento encontrado com esse nome!\n");
    }
}

//Função para cancelar agendamento
void cancelarAgendamento() {
    if (totalAgendamento == 0) {
        printf("Sem agendamentos para cancelar!\n");
        return;
    }

    char nome[50];
    printf("Digite o nome do cliente para cancelar o agendamento:\n");
    scanf("%49s", nome);

    //Busca na tabela hash pelo nome
    Agendamento *agenda = buscarHash(nome);
    if (agenda != NULL) {
        //Remover da lista encadeada
        Agendamento *atual = cliente, *anterior = NULL;
        while (atual != NULL && strcmp(atual->nome, nome) != 0) {
            anterior = atual;
            atual = atual->proximo;
        }
        if (anterior == NULL) {
            cliente = atual->proximo; // remover do inicio
        } else {
            anterior->proximo = atual->proximo; //remover no meio ou fim
        }
        free(atual->nome);
        free(atual->horario);
        free(atual);
        
        totalAgendamento--;
        printf("Agendamento cancelado com sucesso!\n");
    } else {
        printf("Nenhum agendamento encontrado com esse nome!\n");
    }
}

//Função para garantir a liberação da memória antes de finalizar o programa
void liberarMemoria(){
    Agendamento *agenda = cliente;

    while (agenda != NULL) 
    {
        Agendamento *auxiliar = agenda;
        agenda = agenda->proximo;
        free(auxiliar->nome);
        free(auxiliar->horario);
        free(auxiliar);
    }
    
}

int main() {
    int opcao;

    do
    {
        printf(" Agendamento CodeCortes \n");
        printf("1 - Agendar corte\n");
        printf("2 - Agendamentos do dia\n");
        printf("3 - Alterar agendamento\n");
        printf("4 - Cancelar agendamento\n");
        printf("5 - Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            system("cls");
            agendar();
            break;
        case 2:
            system("cls");
            cortesAgendados();
            break;
        case 3:
            system("cls");
            alterarHorario();
            break;
        case 4:
            system("cls");
            cancelarAgendamento();
            break;
        case 5:
            printf("Saindo...\n");
            break;
        
        default:
            system("cls");
            printf("Opcao invalida, tente novamente!\n");
        }
    } while (opcao != 5);

    liberarMemoria();
    return 0;
    
}