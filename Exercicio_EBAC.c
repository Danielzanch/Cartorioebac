#include <stdio.h> //Biblioteca de comunica??o com o usu?rio
#include <stdlib.h> //Biblioteca de aloca??o de espa?o em memoria
#include <locale.h> //Biblioteca de aloca??es de texto por regi?o
#include <string.h>
int Opcao = 0; // definindo a variavel Opcao com numero inteiro

int main()
{ 
	login();
	menu();


printf("\n\n\n\n\nDeus é bom, o tempo todo Deus é bom");	
}


int login()
{
	char senha [10] = "admin"; // a senha que vai ser cadastrada do usuario
	char senha1 [10]; // a senha digitada para comparação da senha cadastrada
	char user [10] = "Daniel"; // o nome do usuario cadastrado
	
	printf("\n *** EBAC - Registro de Nomes ***");
	printf("\n\n--------------------------------\n\n");
	printf("Digite a senha de acesso!\n");
	scanf("%s", senha1);
	printf("\n");
	
	if (strcmp(senha1, senha)==0)
	{
		printf("A senha esta correta seja bem vindo: %s\n\n\n\n", user);
		system("pause");
		system("cls");
	}
	
	else
	{
		printf("Senha errada, tente outra vez!\n\n\n\n");
		system("pause");
		system("cls");
		login();
	}
	
}
int menu()
{
	int laco = 1; // definindo a vairavel Laço com numero inteiro
	int simnao = 0;
	char Nome [5]; // definindo a variavel Nome com letras usando char
	
	setlocale(LC_ALL, "Portuguese"); // Permite a utiliza??o da biblioteca locale.h, podendo usar acentos
	
		printf("\n  ***** CADASTRO DE NOMES *****\n\n");
		printf("SELECIONE UMA OPÇÃO PARA CONTINUAR\n\n");
		printf("\t1. ADICIONAR NOMES\n");
		printf("\t2. CONSULTAR NOMES\n");
		printf("\t3. DELETAR NOMES\n");
		printf("\t4. SAIR DO SISTEMA. \n\n\n");
	
		printf("Qual opção você quer: 1, 2, 3 ou 4\n\n");
		scanf("%d", &Opcao);
		printf("\n Você escolheu: %d\n\n", Opcao);
		
	
	for (laco = 1; laco = 1;) // La?o de repeti??o For.
	{

		
		system("cls"); // limpa a tela.

		// inicio Switch-Case
		switch (Opcao)
		{
			case 1: // op??o adicionar Nome
				registro();
				break;
				
			case 2: // op??o consultar Nome
				consultar();
				break;										
	
			case 3: // op??o deletar nome
				deletar();
				break;
			
			// come?o da decisao de saida
			case 4: // fecha o sistema
				fechar();
		// fim do Switch-Case
		}
	}
}

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char sair[10];
	
	printf("Digite o CPF que ser? cadastrado: \n");
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

	
	printf("Deseja cadastrar ou sair?\n\n");
	printf("(1) para SAIR ou (2) para cadastrar outro usuario.\n\n\n");
	scanf("%s", sair);
	system("cls");
	
	if (strcmp(sair, "1")==0)
	{
		printf("voltando para a tela de Opções!\n\n");
		system("pause");
		system("cls");
		menu();
	}
	
	if (strcmp(sair, "2")==0)
	{
		registro();
	}
}

int consultar()
{
	char cpf[40];
	char conteudo[200];
	char sair[10];
	
	setlocale(LC_ALL, "Portuguese"); // Permite a utiliza??o da biblioteca locale.h, podendo usar acentos
	
	printf ("Qual o numero do CPF que quer consultar? \n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("O CPF digitado n?o foi encontrado.");
	}
	
	while (fgets(conteudo, 200, file) != NULL)
		printf("\nEssas s?o as informa??es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
		
		system("pause");
	fclose (file);
	
	printf("Deseja cadastrar ou sair?\n\n");
	printf("(1) para SAIR ou (2) para consultar outro usuario.\n\n\n");
	scanf("%s", sair);
	system("cls");
	
	if (strcmp(sair, "1")==0)
	{
		printf("voltando para a tela de Opções!\n\n");
		system("cls");
		menu();
	}
	
	if (strcmp(sair, "2")==0)
	{
		consultar();
	}
	
	else 
	{
		printf("Opção invalida, vamos consultar outra pessoa!");
		system("pause");
	}
	
}
int deletar()
{
	char cpf[11];
	char sair [10];

	setlocale(LC_ALL, "Portuguese"); // Permite a utiliza??o da biblioteca locale.h, podendo usar acentos
	
	printf("Qual o numero do CPF que deseja deletar\n?");
	scanf("%s", cpf);
	remove(cpf);

	FILE *file;
	file = fopen(cpf, "r");

	if(file == NULL)
	{
		printf("Usuario não encontrado. \n\n");

	}
	
	printf("Deseja deletar outro cadastro ou sair?\n\n");
	printf("(1) para SAIR ou (2) para deletar outro usuario.\n\n\n");
	scanf("%s", sair);
	system("cls");
	
	if (strcmp(sair, "1")==0)
	{
		printf("voltando para a tela de Opções!\n\n");
		system("cls");
		menu();
	}
	
	if (strcmp(sair, "2")==0)
	{
		deletar();
	}
	
	else 
	{
		printf("Opção invalida, vamos deletar outra pessoa!");
		system("pause");
		
	}


	
}

int fechar()
{
	char decis [3];
	 
	printf("\n ** EBAC - Registro de Nomes **");
	printf("\n\n\n --------------------------------\n\n");
	printf("Tem certeza que deseja sair do programa?\n");
	scanf("%s", decis);
	
	if (strcmp(decis, "1")==0)
	{
		printf("Obrigaado por usar o sistema de cadastrado da EBAC!\n\n\n");
	 	system("pause");
	    return 0;
	}
	
	if (strcmp(decis, "2")==0)
	{
		printf("Voltar ao menu principal\n\n");
		system("pause");
		system("cls");
		main();
	}
	
	else
	{
		printf("Valor digitado invalido!\n");
		system ("cls");
		fechar();
	}
	
	return 0;
	
	
}
