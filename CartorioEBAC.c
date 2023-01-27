#include <stdio.h> //Biblioteca para comunica��o com o usu�rio
#include <stdlib.h> //Aloca��o de espa�o na mem�ria (por exemplo, vari�veis)
#include <locale.h> //Define o texto por regi�o para caracteres especiais
#include <string.h> //Biblioteca das string

int cadastro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Cadastro de usu�rio! \n\n ");
	printf("Digite o CPF do usu�rio: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Comando para copiar os valores das string (copiamos o valor de CPF para o ARQUIVO
	
	FILE *file; //Criamos o arquivo no banco de daods
	file = fopen(arquivo, "w"); //cria um arquivo com o nome do que tem armazenado em arquivo e tem o tipo write
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	//inicio de abertura de arquivo para melhorar a leitura dos aquivos
	file = fopen(arquivo, "a"); //abrimos o arquivo novamente e vamos atualizar ("a)
	fprintf(file, ",");
	fclose(file);
	//final de abertura de arquivo para melhorar a leitura dos aquivos
	
	printf("Digite o nome do usu�rio: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //abrimos o arquivo novamente e vamos atualizar ("a)
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome do usu�rio: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo do usu�rio: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	char cpf[40];
	char conteudo[200];
	
	setlocale(LC_ALL, "Portuguese");//defini��o de idioma
	
	
	printf("Consulta de usu�rio!\n\n");
	printf("Digite o CPF que deseja consultar: ");
	scanf("%s", cpf);
	
	FILE *file;//Consultando o arquivo
	file = fopen(cpf, "r");//abertura do arquivo e pedindo para ler (r = ler)
	
	if(file == NULL)
	{
		printf("O arquivo n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)//fgets - 1 variavel onde guarda o resultado da fun��o - 2 n�mero de caracteres que l� no loop - 3 referencia do arquivo (tipo file)
	{
		printf("\nInforma��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	
	system ("pause");
}

int excluir()
{
	char cpf[40];
	int confirmaExclusao;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o CPF do usu�rio para excluir o cadastro: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O arquivo n�o localizado!\n");
	}
	
	else
	{
		printf("cpf: %s", cpf);
		printf("\nConfirmar exclus�o do usu�rio?\n");
		printf("1-) Sim.\n");
		printf("2-) N�o.\n");
		printf("op��o: ");
		scanf("%d", &confirmaExclusao);
		
		switch(confirmaExclusao)
		{
			case 1:
			fclose(file);//Precisamos fechar o file pra poder excluir
			remove(cpf);
			printf("Usu�rio excluido com sucesso!\n\n");
			break;
			
			case 2:
			printf("Cancelado!\n\n");
			break;
			
			default:
			printf("Op��o inv�lida!\n");
			break;
		}
	}
	system("pause");
}

int main()
{
	int opcoes=0;//Delcara��o de vari�veis
	int loopMenu=1;//Vari�vel de loop do menu
	
	for(loopMenu=1;loopMenu=1;)//Loop do menu
	{
		system("cls");//comando para limpar a tela
		
		setlocale(LC_ALL, "Portuguese");//defini��o de idioma
	
		printf("#### Bem vindo � consulta de alunos da EBAC ####\n\n");//inicio do menu
		printf("\tSelecione a op��o desejada no menu\n");
		printf("\t1- Cadastro de usu�rio.\n");
		printf("\t2- Consulta de usu�rio.\n");
		printf("\t3- Excluir usu�rio.\n");
		printf("Op��o: ");//final do menu
		
		scanf("%d", &opcoes);//recebe op��o do usu�rio
		
		system("cls");
		
		switch(opcoes)//inicio de sele��o de op��es
		{
			case 1:
			cadastro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			excluir();
			break;
			
			default:
			printf("Op��o inv�lida\n");
			system("pause");
			break;
		}//final da sele��o de op��es
	}
}