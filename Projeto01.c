#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�os em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar dos strings

int cadastro() //fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings
	
	printf("digite o CPF a ser cadastrado: "); //coletando informa��o do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria��o de arquivo
	file = fopen(arquivo,"w"); //cria��o de arquivo
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza��o de arquivo existente
	fprintf(file,",");
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
		printf("Arquivo n�o existente!.\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		fclose(file);
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("usu�rio n�o existente!.\n");
		system("pause");
	}

}


int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int opcao=0; //definindo variaveis
	int x=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("Cart�rio EBAC\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	
	if(comparacao == 0)
	{
	
	    for(x=1;x=1;)
	    {
	    
		
		    system ("cls");
	    
    	    setlocale(LC_ALL, "Portuguese"); //definindo linguagem
    	
    	    printf("Cart�rio EBAC\n\n"); //inicio do menu
        	printf("Escolha a op��o desejada:\n\n");
    	    printf("\t1 - Cadastrar nome\n");
            printf("\t2 - Consultar nomes\n");
    	    printf("\t3 - Excluir registros\n");
    	    printf("\t4 - Sair do sistema\n\n");
    	    printf("op��o: ");   //fim do menu
	
    	    scanf("%d", &opcao); //armazenando escolha do usu�rio
	
    	    system("cls");
    	
    	
    	    switch(opcao) //inicio da sele��o do menu
    	    {
    	    	case 1:
    	    	cadastro(); //chamada de fun��o
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
    	    	printf("op��o indisponivel!\n");
    	    	system("pause");
    	    	break;
			} //fim da sele��o do menu
    	
        }
    }
    
    else
        printf("Senha incorreta!");
}
