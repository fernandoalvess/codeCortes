#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AGENDAMENTO 8

typedef struct {
    char nome[50];
    char horario[6]; //hh:mm
}Agendamento;

Agendamento agendamento[MAX_AGENDAMENTO];
int totalAgendamento = 0;

int verificarAgenda(char *horario, int totalAgendamento) {
    for(int  i = 0; i <= totalAgendamento; i++) {
        if(agendamento[i].horario == 0) {
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

    Agendamento novoAgendamento;

    printf("Nome: ");
    scanf("%[^\n]", novoAgendamento.nome);
    printf("Horario: ");
    scanf("%s", novoAgendamento.horario);

    if ( verificarAgenda(novoAgendamento.horario, totalAgendamento)){
        agendamento[totalAgendamento++] = novoAgendamento;
        printf("Agendamento realizado!\n");
    } else {
        printf("Ops! Esse horario não esta disponivel :(\n");
    }
}



int main() {
    int opcao;

    do
    {
        printf(" Agendamento CodeCortes \n");
        printf("1 - Agendar\n");
        printf("2 - Horarios disponiveis\n");
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
            //horariosDisponiveis();
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