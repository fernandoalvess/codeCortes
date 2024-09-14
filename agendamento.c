#include <stdio.h>

typedef struct {
    char nome[50];
    char data[11];
    char horario[6];
}Agendamento;


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
            horariosDisponiveis();
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