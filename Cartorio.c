#include <stdio.h> //Biblioteca para comunica��o com o usu�rio.
#include <stdlib.h> //Biblioteca para caracteres especiais (para aloca��o de espa�o de mem�ria). 
#include <locale.h> //Biblioteca para aloca��es de texto por regi�o.
#include <string.h> //Biblioteca respons�vel por cuidar das strings.

int registro () // Fun��o respons�vel por cadastrar usu�rio no sistema
{
	//inicio cria��o de vari�veis/string []
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de cria��o de vari�veis
	
	printf("Digite o  CPF a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string - salvar
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings.
	
	FILE *file; // Acessa o file e cria o file
	file = fopen(arquivo, "w"); //abre o arquivo, sendo ele novo (w). criando o arquivo, onde foi criado o projeto.
	fprintf(file,cpf); // salvo o valor da v�riavel
	fclose(file); // Fecho o arquivo
	
	file = fopen(arquivo, "a"); // a para atualizar o arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o soberenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");	
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");

}

int consultar ()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf [40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // r para ler o arquivo em busca do cpf.
	
	if(file == NULL)
	{
		printf("\nN�o foi poss�vel abrir o arquivo. Arquivo n�o encontrado!\n\n");
		
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar ()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf); // o s significa string. Pois, temos que receber a string.
	
	remove(cpf);
	
	FILE * file; // Entrar nos arquivos e puxar o arquivo
	file = fopen(cpf, "r"); //r de ler o cpf
	
	if (file == NULL) // null para caso n�o encontre nada (== - igual)
	{
		printf("Usu�rio n�o se encontra no sistema! \n");
		system("pause"); // para o usuario ter tempo de ler a mensagem.
		
	} 
	
	
	
}

int main()
{
	int opcao=0; // Definindo as vari�veis.
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	setlocale(LC_ALL, "Portuguese");
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Bem-vindo ao terminal de cadastros e consultas.\n\n");
	printf("Digite a sua senha de administrador: ");
	
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin"); // us�ario salva valor na vari�vel. precisando assim da compara��o.
	
	if(comparacao == 0)
	{
		system("cls");
		
		for(laco=1;laco=1;)
		{
			
			setlocale(LC_ALL, "Portuguese");
	
			printf("### Cart�rio da EBAC ###\n\n"); // inicio do menu.
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n\n");
			printf("Op��o: "); // Fim do menu.
	
			scanf("%d" , &opcao); // Armazenando a escolha do us�ario.
	
			system("cls"); //respons�vel por limpar a tela
	
				switch(opcao)
			{
				case 1: // inicio da sele��o do munu
				registro(); // chamada de fun��es
				break;
			
				case 2:
				consultar();			
				break; 
						
				case 3:
				deletar();			
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
				default: // Fim da sele��o
				printf("Essa op��o n�o est� dispon�vel!\n\n");
				system("pause");
				break;
			}	
		}
	}
	
	else 
		printf("Senha incorreta!");
}



//\n - respons�vel por pular linhas.
//\t - Respons�vel por dar um espa�o na linha
