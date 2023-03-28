// Anaisador Lexico Inicial
// Referencia Apostila item 2.1.1

//Incluindo bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct{
    int tipo;
    int valor;
}Token;

struct lista{
    int tipo;
    int valor;
    int linha;
    int coluna;
    struct lista* next;
};

typedef struct lista Tabela;

Tabela* t;

#define TRUE 1
#define FALSE 0

#define TOK_NUM 0
#define TOK_OP 1
#define TOK_PONT 2

//Operadores
#define SOMA 0
#define SUB 1
#define MULT 2
#define DIV 3

//Pontuacao
#define PARESQ 0
#define PARDIR 1

Tabela* cria(void){
    return NULL;
}

Tabela* add(Tabela* t,Token *tok,int linha, int coluna){
    Tabela* no = (Tabela*) malloc(sizeof(Tabela));
    no->tipo = tok->tipo;
    no->valor = tok->valor;
    no->linha = linha;
    no->coluna = coluna;
    no->next = t;
    return no;
}

// t = add(t,tok,linha,coluna);

int main(void){
    FILE *arqFonte;
    FILE *tabSim;
    FILE *fluxoTokens;

    if((arqFonte=fopen("entrada.txt","r"))==NULL){
        puts("Nao foi possivel abrir o arquivo\n\n");
        exit(1);
    }
    tabSimb=fopen("tabela.txt","w");
    fluxoTokens=fopen("tokens.txt","w");

    print("Grande Analisador Lexico da turma 4ECA\n\n");
    printf("Lendo Arquivo de entrada...\n\n");

    char entrada[200];
    Token tok;

    t=cria();

    printf("\n\n********PROCESSANDO********\n\n");

    fgets(entrada,200,arqFonte);

    inicializa_analise(entrada);

    print("Escrevendo Arquivos...");

    while(proximo_token(&tok)!=NULL){
        imprime_token(&tok,fluxoTokens);
    }

    //Impressao da Tabela de Simbolos

    print(t,tabSim);

    fclose(arqFonte);
    fclose(tabSim);
    fclose(fluxoTokens);

    printf("\n\nAnalise Lexica finalizada com sucesso\n\n")

    return 0;
}


