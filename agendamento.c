#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AGENDAMENTO 8

typedef struct {
    char *nome;
    char *horario; //hh:mm
}Agendamento;

Agendamento *agendamentos[MAX_AGENDAMENTO];
int totalAgendamento = 0;

int verificarAgenda(char *horario) {
    for(int  i = 0; i <= totalAgendamento; i++) {
        if( strcmp (agendamentos[i]->horario, horario) == 0) {
            return 0; // horario ocupado
        }
    }

    return 1; // horario disponivel
}
void agendar() {
    if (totalAgendamento >= MAX_AGENDAMENTO){
        printf("Nao tem horario disponivel!\n");
        return;
    }

    Agendamento *novoAgendamento = (Agendamento*)malloc(sizeof(Agendamento));

    novoAgendamento->nome = (char*)malloc(50 * sizeof (char));
    novoAgendamento->horario = (char*)malloc(6 * sizeof (char));

    printf("Nome: ");
    scanf("%s", novoAgendamento->nome);
    printf("Horario: ");
    scanf("%s", novoAgendamento->horario);

    if ( verificarAgenda(novoAgendamento->horario)){
        agendamentos[totalAgendamento++] = novoAgendamento;
        printf("Agendamento realizado!\n");
    } else {
        printf("Ops! Esse horario não esta disponivel :(\n");
    }

    free(novoAgendamento->nome);
    free(novoAgendamento->horario);
    free(novoAgendamento);
}

void cortesAgendados() {
    if (totalAgendamento == 0) {
        printf("Nenhum agendamento para hoje!\n");
        return;
    }

    printf("AGENDAMENTOS DO DIA:\n");
    for (int i = 0; i < totalAgendamento; i++){
        printf("%d - Nome: %s. Horario: %s\n", i+1, agendamentos[i]->nome, agendamentos[i]->horario);
    }
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
            //cancelarAgendamento();
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