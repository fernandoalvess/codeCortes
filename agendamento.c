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
    Agendamento *agenda = cliente;
    while (agenda != NULL) {
        if( strcmp (agenda->horario, horario) == 0) {
            return 0; // horario ocupado
        }
        agenda = agenda->proximo;
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

    Agendamento *agenda = cliente;
    printf("AGENDAMENTOS DO DIA:\n");
    int i = 1;
    while (agenda != NULL)
    {
        printf("%d - Nome: %s Horario: %s\n", i++, agenda->nome, agenda->horario);
        agenda = agenda->proximo;
    }
}

void cancelarAgendamento() {
    if (totalAgendamento == 0) {
        printf("Nenhum agendamento para hoje!\n");
        return;
    }

    char nome[50];
    printf("Digite nome do clinete para cancelar o agendamento:\n");
    scanf("%s", nome);

    Agendamento *agenda = cliente;
    Agendamento *auxiliar = NULL;

    while (agenda != NULL)
    {
        if (strcmp(agenda->nome, nome) == 0) {
            //encontrou, agora vai remover
            if (auxiliar == NULL)
            {
                cliente = agenda->proximo; // remove topo da lista
            } else {
                auxiliar->proximo = agenda->proximo; // remove meio ou fim
            }
            free(agenda->nome);
            free(agenda->horario);
            free(agenda);

            totalAgendamento--;
            printf("Agendamento cancelado!\n");
            return;
        }
        auxiliar = agenda;
        agenda = agenda->proximo;
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