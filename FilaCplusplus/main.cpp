#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Pessoa {
    int cpf;
    char nome[200];
    char pago[3];
    struct Pessoa * proximo;

};
void InserirFila(struct Pessoa ** inicioFila, struct Pessoa ** fimFila) {

    struct Pessoa * novo;

    novo = (struct Pessoa*)malloc(sizeof(struct Pessoa));

    if (novo == NULL)
    {
        printf("Sem espaço de memoria \n");
        exit(0);
    }
    else
    {
        printf("Digite o CPF \n");
        scanf("%d", &novo->cpf);
        //printf("\n %d \n", novo->cpf);
        novo->proximo = NULL;
        if (*inicioFila == NULL) {
             *inicioFila = novo;
             *fimFila = novo;
        }
        else
        {
            (*fimFila)->proximo = novo;
        }
        *fimFila = novo;
    }
}

void Listar(struct Pessoa * inicioFila){

    struct Pessoa * exibir;

    exibir = inicioFila;

    printf("\ ********Fila******* \n");
    while ( exibir != NULL) {
        printf("\n%d | %p", exibir->cpf, exibir);
        exibir =  exibir->proximo;
    }


 }

 void Remover(Pessoa ** inicioFila )
 {
    Pessoa * aux = * inicioFila;
    *inicioFila = aux->proximo;
 }

int main()
{
    struct Pessoa * inicioFila = NULL;
    struct Pessoa * fimFila = NULL;



    int escolha = 0;
    while (escolha != 5)
    {
        printf("\n1-Inserir \n2-Listar \n3-Remover \n");
        scanf("%d", &escolha);

        switch(escolha){
            case 1: InserirFila(&inicioFila, &fimFila);break;
            case 2: Listar(inicioFila); break;
            case 3: Remover(&inicioFila);break;
        }


    }



    printf("\n\n\n\n\n\nHello world!\n");
    return 0;
}
