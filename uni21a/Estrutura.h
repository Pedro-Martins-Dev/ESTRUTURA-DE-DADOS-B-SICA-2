#ifndef ESTRUTURA_H
#define ESTRUTURA_H

typedef struct estruturaNo {

    int valor; // Para árvores balanceadas
    struct estruturaNo* esq;
    struct estruturaNo* dir;
} No;

typedef struct estruturaLivro
{
//esse estruturalivro é o nome da estrutura
    int codigo;
    char titulo[100];
    char autor[100];
    char genero[50];
    int ano;
    char editora[100];
    int nPaginas;
} Livro;
//esse livro de baixo é para criarmos o novo livro

// Funções para manipular a árvore
No* criarNo(int* livro);
void inserir(No** raiz, Livro* livro);
No* buscar(No* raiz, int codigo);
void remover(No** raiz, int codigo);
void exibirEmOrdem(No* raiz);
int altura(No* raiz);
Livro criarLivro(int codigo, char* titulo, char* autor, char* genero, int ano, char* editora, int nPaginas);
void inicializarLivro();
// ... outras funções

#endif // ESTRUTURA_H