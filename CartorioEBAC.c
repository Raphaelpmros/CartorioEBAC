#include <stdio.h> //Biblioteca para comunicação com o usuário
#include <stdlib.h> //Alocação de espaço na memória (por exemplo, variáveis)
#include <locale.h> //Define o texto por região para caracteres especiais
#include <string.h> //Biblioteca das string

int cadastro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int repeticaoLoopCadastro;
	
	do //Loop de repetição para cadastro
	{
		printf("Cadastro de usuário! \n\n ");
		printf("Digite o CPF do usuário: ");
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
		
		printf("Digite o nome do usuário: ");
		scanf("%s", nome);
		
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
		
		file = fopen(arquivo, "a"); //abrimos o arquivo novamente e vamos atualizar ("a)
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o sobrenome do usuário: ");
		scanf("%s", sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
		
		file = fopen(arquivo,"a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o cargo do usuário: ");
		scanf("%s", cargo);
		
		file = fopen(arquivo,"a");
		fprintf(file,cargo);
		fclose(file);
		
		printf("\nDeseja cadastrar outro usuário?\n1-) Sim\n2-) Não\n\n");
		scanf("%d", &repeticaoLoopCadastro);
	}while(repeticaoLoopCadastro == 1);
	system("pause");
}

int consulta()
{
	char cpf[40];
	char conteudo[200];
	int repeticaoLoopConsulta;
	
	setlocale(LC_ALL, "Portuguese");//definição de idioma
	
	do
	{
	
		printf("Consulta de usuário!\n\n");
		printf("Digite o CPF que deseja consultar: ");
		scanf("%s", cpf);
		
		FILE *file;//Consultando o arquivo
		file = fopen(cpf, "r");//abertura do arquivo e pedindo para ler (r = ler)
		
		if(file == NULL)
		{
			printf("O arquivo não localizado!\n");
		}
		
		while(fgets(conteudo, 200, file) !=NULL)//fgets - 1 variavel onde guarda o resultado da função - 2 número de caracteres que lê no loop - 3 referencia do arquivo (tipo file)
		{
			printf("\nInformações do usuário: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		fclose(file);
		
		printf("\n\nDeseja consultar outro usuário?\n1-) Sim\n2-) Não\n\n");
		scanf("%d", &repeticaoLoopConsulta);
	}while(repeticaoLoopConsulta == 1);
	system ("pause");
}

int excluir()
{
	char cpf[40];
	int confirmaExclusao;
	int repeticaoLoopExcluir;
	setlocale(LC_ALL, "Portuguese");
	
	do
	{
		printf("Digite o CPF do usuário para excluir o cadastro: ");
		scanf("%s", cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL)
		{
			printf("O arquivo não localizado!\n");
		}
		
		else
		{
			printf("cpf: %s", cpf);
			printf("\nConfirmar exclusão do usuário?\n");
			printf("1-) Sim.\n");
			printf("2-) Não.\n");
			printf("opção: ");
			scanf("%d", &confirmaExclusao);
			
			switch(confirmaExclusao)
			{
				case 1:
				fclose(file);//Precisamos fechar o file pra poder excluir
				remove(cpf);
				printf("Usuário excluido com sucesso!\n\n");
				break;
				
				case 2:
				printf("Cancelado!\n\n");
				break;
				
				default:
				printf("Opção inválida!\n");
				break;
			}
		}
		printf("Deseja excluir outro usuário?\n1-) Sim\n2-) Não\n\n");
		scanf("%d", &repeticaoLoopExcluir);
	}while(repeticaoLoopExcluir == 1);
	system("pause");
}

int main()
{
	int opcoes=0;//Delcaração de variáveis
	int loopMenu=1;//Variável de loop do menu
	char senhaDigitada[10]="a";
	int retorno;
	
	printf("#### Bem vindo a consulta de alunos da EBAC ####\n\n");
	printf("Digite sua senha:");
	scanf("%s", senhaDigitada);
	
	retorno = strcmp(senhaDigitada, "admin");
	
	if(retorno == 0)
	{	
		for(loopMenu=1;loopMenu=1;)//Loop do menu
		{
			system("cls");//comando para limpar a tela
			
			setlocale(LC_ALL, "Portuguese");//definição de idioma
		
			printf("#### Bem vindo à consulta de alunos da EBAC ####\n\n");//inicio do menu
			printf("\tSelecione a opção desejada no menu\n");
			printf("\t1- Cadastro de usuário.\n");
			printf("\t2- Consulta de usuário.\n");
			printf("\t3- Excluir usuário.\n");
			printf("\t4- Sair do sistema.\n");
			printf("Opção: ");//final do menu
			
			scanf("%d", &opcoes);//recebe opção do usuário
			
			system("cls");
			
			switch(opcoes)//inicio de seleção de opções
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
				
				case 4:
				printf("Obrigado por utilizar nosso sistema!\n");
				system("pause");
				break;
				
				default:
				printf("Opção inválida\n");
				system("pause");
				break;
			}//final da seleção de opções
		}
	}
	else
		printf("senha incorreta");
}
