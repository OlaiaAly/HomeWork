#include <stdio.h>
#include <stdlib.h>
#include "cabecario.h"

// Entidades

struct tp_data{ // as trabalha com as datas no geral
	int dia;
	int mes;
	int ano;
};

struct tp_equipa{ // entidade de equipa
	int id;
	char nome[30];
}
    vetEnquipas[50], equipa;

struct tp_jogador{ // Entidade de joagador
	int id;
	int idEquipa;
	char nome[30];

	struct tp_data dataInicio; //data do incio do contracto
	struct tp_data dataFim;   //data do fim do contracto

} jogador;

   int vetIdEquipas[50];



void menuPrincipal(){
    printf("\n\n\t\t_____________Bem vindo_________________\n\n");
	printf("\n1.Criar Equipa \n2. Listar Equipas\n3.Criar Joagador\n");
	printf("\nDigite a sua opcao: ");
};


void criarEquipa(){

  FILE * arquivo;
  arquivo = abrirAquivo('a', "equipas.txt");

  printf("\nEntre com o nome da Equipa que deseja criar....?\n");
  fflush(stdin);
  scanf("%s", &equipa.nome);

   printf("\nEntre com o ID da equipa?\n");
  fflush(stdin);
  scanf("%i", &equipa.id);


  fprintf(arquivo,"%s %i\n" ,equipa.nome, equipa.id);
  system("cls");
  printf("\n\t\t\tEquipe Criada com sucesso! \n\tNome da Equipa: %s \n\tCogigo: %i\n", equipa.nome, equipa.id);
  fecharArquivo(arquivo);
system("pause");

};


void criarJogador(){

    printf("\n Entre com o id da equipa!");
    fflush(stdin);
    scanf("%i", &jogador.idEquipa);

    printf("\nEtre com o id do jogado: ");
    fflush(stdin);
    scanf("%i", &jogador.id);


    printf("\nEntre com o nome jogador: ");
    fflush(stdin);
    scanf("%s", &jogador.nome);

     printf("\nEntre  a data de incio de contracto: ");
    fflush(stdin);
    scanf("%s", &jogador.dataInicio);


     printf("\nEntre  a data de fim de contracto: ");
    fflush(stdin);
    scanf("%s", &jogador.dataFim);


    FILE * arquivo;
    arquivo = abrirAquivo('a', "jogadores.txt");
    fflush(stdin);
    fprintf(arquivo, "%i %id %s %s %s \n", jogador.id, jogador.idEquipa, jogador.nome, jogador.dataFim);

     fecharArquivo(arquivo);

    system("pause");
}


void listarEquipas(){


    //system("cls");
    printf("\n\n\tLista de equipes\nNomes:\n");
    FILE *arquivo;
    int i=0;
    arquivo = abrirAquivo('l', "equipas.txt");

        while(!feof(arquivo)){

        fscanf(arquivo, "%s %i\n", &equipa.nome, &equipa.id);
        fflush(stdin);
        printf("\n %i %s" , equipa.id, equipa.nome);
        vetIdEquipas[i] = equipa.id;
        i++;


        }

    fecharArquivo(arquivo);
    system("pause");

};










void controlo(int opcao){
        switch(opcao){
        case 1:
            criarEquipa();
            break;
        case 2:
             listarEquipas();

            break;
        case 3:
            criarJogador();
            break;

        default: printf("Opcao invalida, tente novamente!");
    }
}




//Manipulando Arquivos

    FILE* abrirAquivo(char modo, char caminho[30]){
         FILE *arquivo;
          switch(modo){
        case 'a':
                arquivo = fopen(caminho, "a");
            break;
        case 'l':
                arquivo = fopen(caminho, "rt");
            break;
        case 'g':
                arquivo = fopen(caminho, "wt");
            break;

          }

        if(arquivo ==NULL){
            system("cls");
            printf("Nao foi possivel abrir o arquivo!");
            exit(0);
        }

    return arquivo;
    }


    void fecharArquivo(FILE *arquivo){
        fclose(arquivo);
    }




















