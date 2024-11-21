#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Biblioteca.c"

int main()
{
    No *raiz = NULL;
    
    setlocale(LC_ALL, "Portuguese");

    int opcoes = -1;

    do
    {


        printf("Seja bem vindo(a) a biblioteca Gal Costa\n\n");
        printf("Opções: \n");
        printf("1 - Inserir novo livro\n");
        printf("2 - Buscar por gênero\n");
        printf("Insira o que você deseja fazer: ");
        scanf("%d", &opcoes);

        switch(opcoes)
        {
            case 1: 
                inicializarLivro();
                
                inserirLivro(raiz, &livro);
                break;
        }




    } while (opcoes != 0);
}