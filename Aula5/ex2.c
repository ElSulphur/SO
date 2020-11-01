#include <stdio.h>
#include <string.h>

#define TAM 1024

int main(){
	char nome[TAM], apelido [TAM];
	int idade;
	printf("diga-me o seu nome \n");
	scanf("%s", &nome);
	//fgets(nome, TAM, stdin);
	//se fizesse fgets ficava com enters
	//isto tira os enters:
	//nome[strlen(nome-1)]='\0';
	printf("diga-me o seu apelido \n");
	//fgets(apelido, TAM, stdin);
	//apelido[strlen(apelido-1)]='\0';
	scanf("%s", &apelido);
	printf("diga-me a sua idade: \n");
	scanf("%i", &idade);

	printf("%s %s %d\n", nome, apelido, idade);
	strcat(nome,"-");
	strcat(nome,apelido);
	printf("%s\n", nome);
	//if (nome = "ISCTE" && apelido= "IUL"){
	if(strcmp(nome,"ISCTE-IUL") == 0)
	printf("Nice :)\n");
		
		
}

