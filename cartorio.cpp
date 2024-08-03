#include <stdio.h>      //biblioteca de comunicação com o usuário
#include <stdlib.h>     //biblioteca de alocação de espaço em memória
#include <locale.h>     //biblioteca de alocações de texto por região
#include <string.h>     //biblioteca responsável por cuidas das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//ínicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("\n\n\tDigite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf);  // "%s" refere-se a string
	
	strcpy(arquivo, cpf);        //Responsável por copiar os valores das string
	
	FILE *file;                  //cria o arquivo 
	file = fopen(arquivo, "w");  //cria o arquivo e a "w" é de "write" ou "escrever" em português
	fprintf(file,cpf);           //salvo o valor da varíavel 
	fclose(file);                //fecha o arquivo
	
	file = fopen(arquivo, "a"); //responsável por abrir o arquivo criado
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

int consulta() //realizar a consulta informações sobre o usuário
{
	setlocale(LC_ALL, "Portuguese"); //difinindo a linguagem
	
	char cpf[40]; //string para coletar o cpf
	char conteudo[200]; //string para informar o conteúdo consultado
	
	printf("\n\n\tDigite o CPF a ser consultado: "); //coletando qual o cpf desejado
	scanf("%s",cpf); //consultando a string do cpf
	
	FILE *file; 
	file = fopen(cpf,"r");
	
	if(file == NULL) //para caso não encontrar o cpf informado
	{
		printf("\nNão foi possivel localizar pois não consta no banco de dados!\n\n"); //mensagem de volta 
		system("pause");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //para apresentar as informações
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause"); //para pausar o sistema
}

int deletar() //deletar o usuário informado
{
	
	char cpf[40]; //string do cpf
	
	printf("\n\n\tDigite o CPF do usuário a ser deletado: ");  //solicitar o cpf a ser deletado
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen (cpf, "r"); //para realizar a leitura do arquivo "r" significa "read" ou "ler" no português
	fclose(file);
	
	if(file == NULL)
	{
		printf("\n\tO usuário não se encontra no sistema!\n\n");   //informa caso nao encontre o cpf
		system("pause");
	}
	else
	{
		remove(cpf);
		printf("\n\tUsuário deletado com sucesso!\n\n");  //informa que foi deletado do sistema
		system("pause");
	}
	
	
			
}

	

int main()
{
	int opcao=0;    //Definindo variáveis
	int x=1;
	
	for(x=1;x=1;) //para gerar looping do programa voltando sempre para o menu
	{
		
		system("cls"); //Responsável por limpar a tela

		setlocale(LC_ALL, "Portuguese");        //Definindo a linguagem
	
		printf("     ### Cartório da EBAC ###\n\n"); //ínicio do menu
		printf("  Escolha a opção desejada do menu \n\n");
		printf("\t1 - Registrar nomes\n"); 
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("  Opção: ");                       //fim do menu

		scanf("%d", &opcao);                    //Armazenando a escolha do usuário

		system("cls");
	
		switch(opcao)  //Ínicio da seleção do menu
		{
			case 1:   
			registro(); //chamada da função do registo
			break;
			
			case 2:
			consulta(); //chamada da função de consulta
			break;
			
			case 3:
			deletar();  //chamada da função de deletar
			break;
			
			default:
			printf("\n\n\tEssa opção não está disponivel\n\n");   
			system("pause;");
			break;		                                               //Fim da Seleção
		} 
		
		
			
	} 
		    
}		
