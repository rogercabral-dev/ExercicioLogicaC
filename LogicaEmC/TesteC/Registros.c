#include <stdio.h>
#include <string.h>

struct Carro {
    int ano;
    float preco;
    char placa[10];
};
int main(){
 int i, c;
 struct Carro carros[3];

 for(i = 0; i < 3; i++){
  printf("Informe o ano do %do carro: ", i+1);
  scanf("%d", &carros[i].ano);

  printf("Informe o preco do carro: ");
  scanf("%f", &carros[i].preco);

  printf("Informe a placa do carro: ");
  while((c = getchar()) != '\n' && c != EOF);
  fgets(carros[i].placa, 10, stdin);
  carros[i].placa [strcspn(carros[i].placa, "\n")] = '\0';
  printf("--------------------------------\n");
 }

printf("\n\n == Carros registrados ==\n\n");

 for(i = 0; i < 3; i++){
  printf("Ano do %do carro: %d\n", i+1, carros[i].ano);
  printf("Preco: %f\n", carros[i].preco);
  printf("Placa: %s\n", carros[i].placa);
  printf("\n");
 }

  return 0;
}