#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Caixa
{
    int numeracao;
    Caixa * proximo;
    Caixa * Anterior;
};

void AdicionarCaixaNaPilha(Caixa ** ultimaCaixa, Caixa ** InicioPilha)
{
    //Criei a caixa em memoria mas ainda não coloquei na pilha
     struct Caixa * novaCaixa;
     novaCaixa = (struct Caixa*)malloc(sizeof(struct Caixa));

     //Preenchendo informações da caixa
      printf("Numeração da Caixa \n");
      scanf("%d", &novaCaixa->numeracao);
        novaCaixa->proximo = NULL;


     if(*ultimaCaixa == NULL)
     {
            *ultimaCaixa = novaCaixa;
            *InicioPilha = novaCaixa;
     }
     else
     {
        (*ultimaCaixa)->proximo = novaCaixa;
        *ultimaCaixa = novaCaixa;
     }


}

void Remover(Caixa ** InicioPilha, Caixa ** FimPilha )
 {
     struct Caixa * AuxiliarExibicao;
        AuxiliarExibicao = *InicioPilha;
     while ( AuxiliarExibicao != NULL) {
       if(AuxiliarExibicao->proximo == *FimPilha)
       {
            printf("\n Igual Numeracao: %d | Endereco Memoria: %p | Proximo: %p | FimPilha: %p ", AuxiliarExibicao->numeracao, AuxiliarExibicao, AuxiliarExibicao->proximo, *FimPilha);
            *FimPilha = AuxiliarExibicao;
            (*FimPilha)->proximo = NULL;
            AuxiliarExibicao = NULL;
       }
       else
       {
           printf("\nNumeracao: %d | Endereco Memoria: %p | Proximo: %p | FimPilha: %p ", AuxiliarExibicao->numeracao, AuxiliarExibicao, AuxiliarExibicao->proximo, *FimPilha);
           AuxiliarExibicao = AuxiliarExibicao->proximo;
       }
    }
 }

void ExibirPilha(Caixa * InicioPilha)
{
    struct Caixa * AuxiliarExibicao;

    AuxiliarExibicao = InicioPilha;

    printf("\ ******** PILHA ******* \n");
    while ( AuxiliarExibicao != NULL) {
        printf("\n Numeracao: %d | Endereco Memoria: %p", AuxiliarExibicao->numeracao, AuxiliarExibicao);
        AuxiliarExibicao =  AuxiliarExibicao->proximo;
    }

}

int main()
{
    struct Caixa * FimPilha = NULL;
    struct Caixa * InicioPilha = NULL;

    int escolha = 0;
    while (escolha != 5)
    {
        printf("\n1-Inserir Caixa \n2-Listar Caixas \n3-Remover Caixas \n");
        scanf("%d", &escolha);

        switch(escolha){
            case 1: AdicionarCaixaNaPilha(&FimPilha, &InicioPilha);break;
            case 2: ExibirPilha(InicioPilha); break;
            case 3: Remover(&InicioPilha, &FimPilha);break;
        }


    }



    return 0;
}
