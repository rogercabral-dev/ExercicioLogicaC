#include <stdio.h>
#include <string.h>

struct ListaAlunos{
  char nome [30];
  float notas [3];
  float media;
  float maior;
  float menor;
};

int main(){

int i, j, c;
float soma;

struct ListaAlunos alunos[3];

printf("\n=== CADASTRO DE ALUNOS ===\n\n");

for (i = 0; i < 3; i++){
  printf("Digite o nome do Aluno(a) %d: ", i+1);
  fgets(alunos[i].nome, 30, stdin);
  alunos[i].nome [strcspn(alunos[i].nome, "\n")] = '\0';
}

printf("\n");

for (i = 0; i < 3; i++){
  soma = 0;
  alunos[i].maior = 0;
  alunos[i].menor = 10;
 for (j = 0; j < 3; j++){
  printf("%da nota do(a) aluno(a) %s - ", j+1, alunos[i].nome);
  scanf("%f", &alunos[i].notas[j]);
  soma += alunos[i].notas[j];
      
  if(alunos[i].notas[j] > alunos[i].maior){
    alunos[i].maior = alunos[i].notas[j];
  }
  if( alunos[i].notas[j] <  alunos[i].menor){
     alunos[i].menor =  alunos[i].notas[j];
  } while((c = getchar()) != '\n' && c != EOF);
 } //Fechando for j
  alunos[i].media = soma / 3;
  printf("\n");
}  //Fechamento do for i

FILE *arquivo;
 arquivo = fopen("alunos.txt", "w"); // Abrindo arquivo / Escrevendo.
 if(arquivo == NULL){
    printf("Erro ao abrir o arquivo.\n");
    return 1; // Teste de abertura do arquivo.
 }

printf("\n== ANALISE DOS ALUNOS ==\n\n");

for(i = 0; i < 3; i++){
  printf("A media do aluno %s eh %.2f\n",  alunos[i].nome,  alunos[i].media);
  fprintf(arquivo, "Nome: %s | Media: %.2f\n", alunos[i].nome, alunos[i].media);//Armazenando no arquivo.
  printf("A maior nota do aluno %s eh %.2f\n",  alunos[i].nome,  alunos[i].maior);
  printf("A menor nota do aluno %s eh %.2f\n",  alunos[i].nome,  alunos[i].menor);
  printf("\n");
}

return 0;
}
