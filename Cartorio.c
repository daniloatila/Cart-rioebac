#include <stdio.h> //Biblioteca para comunicação com o usuário.
#include <stdlib.h> //Biblioteca para caracteres especiais (para alocação de espaço de memória). 
#include <locale.h> //Biblioteca para alocações de texto por região.
#include <string.h> //Biblioteca responsável por cuidar das strings.

int registro () // Função responsável por cadastrar usuário no sistema
{
	//inicio criação de variáveis/string []
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de criação de variáveis
	
	printf("Digite o  CPF a ser cadastrado: "); // coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string - salvar
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das strings.
	
	FILE *file; // Acessa o file e cria o file
	file = fopen(arquivo, "w"); //abre o arquivo, sendo ele novo (w). criando o arquivo, onde foi criado o projeto.
	fprintf(file,cpf); // salvo o valor da váriavel
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
		printf("\nNão foi possível abrir o arquivo. Arquivo não encontrado!\n\n");
		
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar ()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf); // o s significa string. Pois, temos que receber a string.
	
	remove(cpf);
	
	FILE * file; // Entrar nos arquivos e puxar o arquivo
	file = fopen(cpf, "r"); //r de ler o cpf
	
	if (file == NULL) // null para caso não encontre nada (== - igual)
	{
		printf("Usuário não se encontra no sistema! \n");
		system("pause"); // para o usuario ter tempo de ler a mensagem.
		
	} 
	
	
	
}

int main()
{
	int opcao=0; // Definindo as variáveis.
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	setlocale(LC_ALL, "Portuguese");
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Bem-vindo ao terminal de cadastros e consultas.\n\n");
	printf("Digite a sua senha de administrador: ");
	
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin"); // usúario salva valor na variável. precisando assim da comparação.
	
	if(comparacao == 0)
	{
		system("cls");
		
		for(laco=1;laco=1;)
		{
			
			setlocale(LC_ALL, "Portuguese");
	
			printf("### Cartório da EBAC ###\n\n"); // inicio do menu.
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n\n");
			printf("Opção: "); // Fim do menu.
	
			scanf("%d" , &opcao); // Armazenando a escolha do usúario.
	
			system("cls"); //responsável por limpar a tela
	
				switch(opcao)
			{
				case 1: // inicio da seleção do munu
				registro(); // chamada de funções
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
			
				default: // Fim da seleção
				printf("Essa opção não está disponível!\n\n");
				system("pause");
				break;
			}	
		}
	}
	
	else 
		printf("Senha incorreta!");
}



//\n - responsável por pular linhas.
//\t - Responsável por dar um espaço na linha
