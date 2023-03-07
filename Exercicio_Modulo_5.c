#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memoria
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h>
int Opcao = 0; // definindo a variavel Opcao com numero inteiro

int main()
{ 
	char Nome [5]; // definindo a variavel Nome com letras usando char
	int laco = 1; // definindo a vairavel Laço com numero inteiro
	
	setlocale(LC_ALL, "Portuguese"); // Permite a utilização da biblioteca locale.h, podendo usar acentos
	
	for (laco = 1; laco = 1;) // Laço de repetição For.
	{
		system("cls"); // limpa a tela.
		
		menu();
	
		system ("cls");

		// inicio Switch-Case
		switch (Opcao)
		{
			case 1: // opção adicionar Nome
				registro();
				break;
				
			case 2: // opção consultar Nome
				consultar();
				break;										
	
			case 3: // opção deletar nome
				deletar();
				break;
	
			default: // qualquer valor que for digitado pelo usuario que nao tenha sido declarado.
				printf("A opção %i é invalida.\n\n", Opcao);
				system ("pause");
				break;
			
		// fim do Switch-Case
		
		}
	}

printf("Deus é bom, o tempo todo Deus é .......");	
}

//Variaveis secundarias
int menu()
{
		printf("\n  ***** CADASTRO DE NOMES *****\n\n");
		printf("SELECIONE UMA OPÇÃO PARA CONTINUAR\n\n");
		printf("\t1. ADICIONAR NOMES\n");
		printf("\t2. CONSULTAR NOMES\n");
		printf("\t3. DELETAR NOMES\n\n\n");
	
		printf("Qual opção você quer: 1, 2 ou 3\n\n");
		scanf("%d", &Opcao);
		printf("\n Você escolheu: %d\n\n", Opcao);
}

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF que será cadastrado: \n");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // strcpy copia o arquivo do cpf para arquivo, nesse caso
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, cpf); // salva o valor de cpf dentro do arquivo
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abrir o arquivo e alterar com o "a" o aquivo. 
	fprintf(file, ","); //Acresenta "," depois do cpf que foi salvo anteriormente
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome para cadastar. \n");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome para cadastrar: \n");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo para cadastrar: \n");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	printf("\n\n\nDados cadastrado: \n\nCPF: %s \nNOME: %s \nSOBRENOME: %s \nCARGO: %s \n\n\n\n", cpf, nome, sobrenome, cargo);
	system("pause");
	
}

int consultar()
{
	char cpf[40];
	char conteudo[200];
	
	setlocale(LC_ALL, "Portuguese"); // Permite a utilização da biblioteca locale.h, podendo usar acentos
	
	printf ("Qual o numero do CPF que quer consultar? \n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("O CPF digitado não foi encontrado.");
	}
	
	while (fgets(conteudo, 200, file) != NULL)
		printf("\nEssas são as informações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
		
		system("pause");
	
}
int deletar()
{
	char cpf[11];

	setlocale(LC_ALL, "Portuguese"); // Permite a utilização da biblioteca locale.h, podendo usar acentos
	
	printf("Qual o numero do CPF que deseja deletar\n?");
	scanf("%s", cpf);
	remove(cpf);

	FILE *file;
	file = fopen(cpf, "r");

	if(file == NULL)
	{
		printf("Usuario não encontrado. \n\n");
		system("pause");
	}
	


	
}
