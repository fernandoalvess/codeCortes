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
        printf("2 - Vizualizar agendamento\n");
        printf("3 - Deletar agendamento\n");
        printf("4 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            /* code */
            break;
        
        default:
            break;
        }
    } while (opcao =! 4);
    
}