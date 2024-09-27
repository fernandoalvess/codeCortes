#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define MAX_AGENDAMENTO 8

typedef struct {
    char *nome;
    char *horario; //hh:mm
    struct Agendamento *proximo; // ponteiro para prox agendamento
}Agendamento;

Agendamento *cliente = NULL; // ponteiro para o inicio da lista
int totalAgendamento = 0;

int verificarAgenda(char *horario) {
    Agendamento *hora = cliente;
    while (hora != NULL) {
        if( strcmp (hora->horario, horario) == 0) {
            return 0; // horario ocupado
        }
        hora = hora->proximo;
    }

    return 1; // horario disponivel
}
void agendar() {
    if (totalAgendamento >= 8){
        printf("Nao tem horario disponivel!\n");
        return;
    }

    Agendamento *novoAgendamento = (Agendamento*)malloc(sizeof(Agendamento));

    novoAgendamento->nome = (char*)malloc(50 * sizeof (char));
    novoAgendamento->horario = (char*)malloc(6 * sizeof (char));

    printf("Nome: ");
    scanf("%49s", novoAgendamento->nome);
    printf("Horario: ");
    scanf("%5s", novoAgendamento->horario);

    // para verificar se o hoarario esta livre
    if ( verificarAgenda(novoAgendamento->horario)){
        novoAgendamento->proximo = cliente; //vai inserir novo agendamento
        cliente = novoAgendamento; // atualiza a lista encadeada
        totalAgendamento++;
        printf("Agendamento realizado!\n");
    } else {
        printf("Ops! Esse horario nao esta disponivel :(\n");
        free(novoAgendamento->nome);
        free(novoAgendamento->horario);
    }

    
    free(novoAgendamento);

}

void cortesAgendados() {
    if (totalAgendamento == 0) {
        printf("Nenhum agendamento para hoje!\n");
        return;
    }

    Agendamento *hora = cliente;
    printf("AGENDAMENTOS DO DIA:\n");
    int i = 1;
    while (hora != NULL)
    {
        printf("%d - Nome: %s Horario: %s\n", i++, hora->nome, hora->horario);
        hora = hora->proximo;
    }
}

void cancelarAgendamento() {
    char nome[50];

    if (totalAgendamento == 0) {
        printf("Nenhum agendamento para hoje!\n");
        return;
    }
    
    printf("Digite nome do clinete para cancelar o agendamento:\n");
    scanf("%s", nome);

    for (int  i = 0; i < totalAgendamento; i++) {
        if(strcmp(agendamentos[i]->nome, nome) == 0) {
            free(agendamentos[i]->nome);
            free(agendamentos[i]->horario);
            free(agendamentos[i]);

                //realocando os agendamentos
            for (int j = i; j < totalAgendamento -1; j++) {
                agendamentos[j] = agendamentos[j+1];
            }

            totalAgendamento--;
            printf("Agendamento foi cancelado!\n");
            return;
        }
        
    }
    printf("Nenhum agendamento encontrado com esse nome!\n");
    return;
}

int main() {
    int opcao;

    do
    {
        printf(" Agendamento CodeCortes \n");
        printf("1 - Agendar corte\n");
        printf("2 - Agendamentos do dia\n");
        printf("3 - Cancelar agendamento\n");
        printf("4 - Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            agendar();
            break;
        case 2:
            cortesAgendados();
            break;
        case 3:
            cancelarAgendamento();
            break;
        case 4:
            printf("Saindo...\n");
            break;
        
        default:
            printf("Opcao invalida, tente novamente!\n");
        }
    } while (opcao != 4);

    return 0;
    
}