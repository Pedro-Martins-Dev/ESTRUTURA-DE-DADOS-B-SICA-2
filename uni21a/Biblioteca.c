#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Estrutura.h"


No* criarNo(int* valor) 
{
  No* novoNo = (No*)malloc(sizeof(No));

  if (novoNo == NULL) 
  {
    printf("Erro ao alocar memória.\n");
    exit(1);
  }
  novoNo->valor = *valor;
  novoNo->esq = NULL;
  novoNo->dir = NULL;
  return novoNo;
}

void inserirLivro(No** raiz, Livro* livro) 
{
  if (raiz == NULL) 
  {
    *raiz = criarNo(&(livro->codigo));
      return;
  }

  if (buscar(*raiz, livro->codigo)) {
    printf("Código já existente.");
  }

  if (livro->codigo < ((*raiz)->valor)) 
  {
    inserirLivro(&(*raiz)->esq, livro);
  } 
  else if ((livro->codigo) > (*raiz)->valor) 
  {
    inserirLivro(&(*raiz)->dir, livro);
  }

}

No *buscar(No *raiz, int valor) {
  if (raiz == NULL || raiz->valor == valor) {
    return raiz;
  }

  if (valor < raiz->valor) {
    return buscar(raiz->esq, valor);
  } 
  else 
  {
    return buscar(raiz->dir, valor);
  }
}

No *encontrar_minimo(No *raiz) {
  while (raiz && raiz->esq != NULL) {
    raiz = raiz->esq;
  }
  return raiz;
}

void exibir_em_ordem(No *raiz) {
  if (raiz != NULL) {
    exibir_em_ordem(raiz->esq);
    printf("%d ", raiz->valor);
    exibir_em_ordem(raiz->dir);
  }
}

Livro livro;

Livro criarLivro(int codigo, char* titulo, char* autor, char* genero, int ano, char* editora, int nPaginas)
{
    livro.codigo = codigo;
    strcpy(livro.titulo, titulo);
    strcpy(livro.autor, autor);
    strcpy(livro.genero, genero);
    livro.ano = ano;
    strcpy(livro.editora, editora);
    livro.nPaginas = nPaginas;

    return livro;
}

void inicializarLivro()
{
    Livro* livro = (Livro*)malloc(sizeof(Livro));
    if (livro == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    printf("Precisamos de algumas informações para cadastrarmos os livros. Seguem a seguir as informações necessárias: \n\n");

    printf("Insira o código do livro: ");
    scanf("%d", &livro->codigo);
    getchar();

    printf("\nInsira o Titulo do livro: ");
    fgets(livro->titulo, sizeof(livro->titulo), stdin);

    printf("\nInsira o autor do livro: ");
    fgets(livro->autor, sizeof(livro->autor), stdin);

    printf("\nInsira o gênero do livro: ");
    fgets(livro->genero, sizeof(livro->genero), stdin); 

    printf("\nInsira o ano do livro: ");
    scanf("%d", &livro->ano);
    getchar();

    printf("\nInsira a editora do livro: ");
    fgets(livro->editora, sizeof(livro->editora), stdin);

    printf("\nInsira o número de páginas: ");
    scanf("%d", &livro->nPaginas);

    criarLivro(livro->codigo, livro->titulo, livro->autor, livro->genero, livro->ano, livro->editora, livro->nPaginas);
}
