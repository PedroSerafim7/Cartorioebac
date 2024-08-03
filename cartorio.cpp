#include <stdio.h>      //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>     //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>     //biblioteca de aloca��es de texto por regi�o
#include <string.h>     //biblioteca respons�vel por cuidas das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//�nicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("\n\n\tDigite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf);  // "%s" refere-se a string
	
	strcpy(arquivo, cpf);        //Respons�vel por copiar os valores das string
	
	FILE *file;                  //cria o arquivo 
	file = fopen(arquivo, "w");  //cria o arquivo e a "w" � de "write" ou "escrever" em portugu�s
	fprintf(file,cpf);           //salvo o valor da var�avel 
	fclose(file);                //fecha o arquivo
	
	file = fopen(arquivo, "a"); //respons�vel por abrir o arquivo criado
	fprintf(file,", ");
	fclose(file);
	
	
	printf("\n\tDigite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("\n\tDigite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("\n\tDigite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,".\n");
	fclose(file);
	
	system("pause");
	
}

int consulta() //realizar a consulta informa��es sobre o usu�rio
{
	setlocale(LC_ALL, "Portuguese"); //difinindo a linguagem
	
	char cpf[40]; //string para coletar o cpf
	char conteudo[200]; //string para informar o conte�do consultado
	
	printf("\n\n\tDigite o CPF a ser consultado: "); //coletando qual o cpf desejado
	scanf("%s",cpf); //consultando a string do cpf
	
	FILE *file; 
	file = fopen(cpf,"r");
	
	if(file == NULL) //para caso n�o encontrar o cpf informado
	{
		printf("\nN�o foi possivel localizar pois n�o consta no banco de dados!\n\n"); //mensagem de volta 
		system("pause");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //para apresentar as informa��es
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause"); //para pausar o sistema
}

int deletar() //deletar o usu�rio informado
{
	
	char cpf[40]; //string do cpf
	
	printf("\n\n\tDigite o CPF do usu�rio a ser deletado: ");  //solicitar o cpf a ser deletado
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen (cpf, "r"); //para realizar a leitura do arquivo "r" significa "read" ou "ler" no portugu�s
	fclose(file);
	
	if(file == NULL)
	{
		printf("\n\tO usu�rio n�o se encontra no sistema!\n\n");   //informa caso nao encontre o cpf
		system("pause");
	}
	else
	{
		remove(cpf);
		printf("\n\tUsu�rio deletado com sucesso!\n\n");  //informa que foi deletado do sistema
		system("pause");
	}
	
	
			
}

	

int main()
{
	int opcao=0;    //Definindo vari�veis
	int x=1;
	
	for(x=1;x=1;) //para gerar looping do programa voltando sempre para o menu
	{
		
		system("cls"); //Respons�vel por limpar a tela

		setlocale(LC_ALL, "Portuguese");        //Definindo a linguagem
	
		printf("     ### Cart�rio da EBAC ###\n\n"); //�nicio do menu
		printf("  Escolha a op��o desejada do menu \n\n");
		printf("\t1 - Registrar nomes\n"); 
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("  Op��o: ");                       //fim do menu

		scanf("%d", &opcao);                    //Armazenando a escolha do usu�rio

		system("cls");
	
		switch(opcao)  //�nicio da sele��o do menu
		{
			case 1:   
			registro(); //chamada da fun��o do registo
			break;
			
			case 2:
			consulta(); //chamada da fun��o de consulta
			break;
			
			case 3:
			deletar();  //chamada da fun��o de deletar
			break;
			
			default:
			printf("\n\n\tEssa op��o n�o est� disponivel\n\n");   
			system("pause;");
			break;		                                               //Fim da Sele��o
		} 
		
		
			
	} 
		    
}		
