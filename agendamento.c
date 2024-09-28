#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
    Agendamento *novoAgendamento = (Agendamento*)malloc(sizeof(Agendamento));

    //para alocar nome e horario
    novoAgendamento->nome = (char *)malloc(50 * sizeof (char));
    novoAgendamento->horario = (char *)malloc(6 * sizeof (char));

    //variavel temporaria
    char nomeTemp[50];
    char horarioTemp[6];

    printf("AGENDE SEU MOMENTO\n");
    printf("Nome: ");
    scanf("%49s", nomeTemp);
    printf("Horario: ");
    scanf("%5s", horarioTemp);

    // para verificar se o hoarario esta livre
    if ( verificarAgenda(horarioTemp)){
        //copia para as pocições corretas
        strcpy(novoAgendamento->nome, nomeTemp);
        strcpy(novoAgendamento->horario, horarioTemp);

        novoAgendamento->proximo = cliente; //vai inserir novo agendamento
        cliente = novoAgendamento; // atualiza a lista encadeada
        totalAgendamento++;
        printf("Agendamento foi realizado!\n");
    } else {
        printf("Ops! Esse horario nao esta disponivel :(\n");
        free(novoAgendamento->nome);
        free(novoAgendamento->horario);
        free(novoAgendamento);
    }

}

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

void alterarHorario() {
    if (totalAgendamento == 0) {
        printf("Sem agendamentos para alterar!\n");
        return;
    }

    char nome[50];
    char novoHorario[6];

    printf("Digite o nome do cliente: ");
    scanf("%s", nome);

    Agendamento *agenda = cliente;

    while (agenda != NULL) {
        if(strcmp(agenda->nome, nome) == 0) { //nome encontrado, pede novo horario
            printf("Digite o novo horario:\n");
            scanf("%5s", novoHorario);

            if(verificarAgenda(novoHorario))  {
                free(agenda->horario); //libera o antigo horario
                agenda->horario = (char *)malloc(6 * sizeof(char));
                strcpy(agenda->horario, novoHorario);
                printf("O horario foi alterado!\n");
            } else {
                printf("Ops! Esse horario nao esta disponivel :(\n");
            }
            return;
        }
        agenda = agenda->proximo;
    }
    printf("Nenhum agendamento encontrado com esse nome!\n");
}

void cancelarAgendamento() {
    if (totalAgendamento == 0) {
        printf("Sem agendamentos para cancelar!\n");
        return;
    }

    char nome[50];
    printf("Digite nome do cliente para cancelar o agendamento:\n");
    scanf("%s", nome);

    Agendamento *agenda = cliente;
    Agendamento *auxiliar = NULL;

    while (agenda != NULL)
    {
        if (strcmp(agenda->nome, nome) == 0) {
            //encontrou o nome, agora vai remover
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
            printf("Agendamento foi cancelado!\n");
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

    return 0;
    
}