#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaços em memória
#include <locale.h> //biblioteca de alocações de texto por registro
#include <string.h> //biblioteca responsável por cuidar dos strings

int cadastro() //função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings
	
	printf("digite o CPF a ser cadastrado: "); //coletando informaçõo do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //criação de arquivo
	file = fopen(arquivo,"w"); //criação de arquivo
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualização de arquivo existente
	fprintf(file," ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Arquivo não existente!.\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		fclose(file);
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("usuário não existente!.\n");
		system("pause");
	}

}


int main()
{
	int opcao=0; //definindo variaveis
	int x=1;
	
	for(x=1;x=1;)
	{
	    
	    system ("cls");
	    
    	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
    	
    	printf("Cartório EBAC\n\n"); //inicio do menu
    	printf("Escolha a opção desejada:\n\n");
    	printf("\t1 - Cadastrar nome\n");
        printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Excluir registros\n");
    	printf("\t4 - Sair do sistema\n\n");
    	printf("opção: ");   //fim do menu
	
    	scanf("%d", &opcao); //armazenando escolha do usuário
	
    	system("cls");
    	
    	
    	switch(opcao) //inicio da seleção do menu
    	{
    		case 1:
    		cadastro(); //chamada de função
    		break;
    		
    		case 2:
    		consulta();
    		break;
    		
    		case 3:
    		deletar();
    		break;
    		
    		case 4:
    		printf("Obrigado por utilizar o sistema!\n");
    		return 0;
    		break;
    		
    		default:
    		printf("opção indisponivel!\n");
    		system("pause");
    		break;
        } //fim da seleção do menu
    	
    }
}
