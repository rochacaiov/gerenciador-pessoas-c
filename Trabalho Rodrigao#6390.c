#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

#define MAX_SIZE 1000

// Flags
int opcao;
char result;
char isVacinado, isSexo;

// Pessoa
char nome[MAX_SIZE][50], email[MAX_SIZE][50], endereco[MAX_SIZE][120], sexo[MAX_SIZE][50];
bool vacinado[MAX_SIZE];
double altura[MAX_SIZE];
int id[MAX_SIZE];

// Procedimentos & Funções
bool existsUserByEmail(char _email[]) ;
bool existsUserById(int _id);
int getUserIndiceByEmail(char _email[]);
int getUserIndiceById(int _id);
void findUserByEmail(char _email[]);
void findUserById(int _id);
void deleteUserById(int _id);
void editUserById(int _id);
void showInformation(int linha) ;
void showAllInformation();
void cadastro();

int main(void) {
	setlocale(LC_ALL, "portuguese");    
    
    do {
    	system("cls");
    	
		printf("\n   #---------------  GERENCIADOR DE USUÁRIOS ---------------#");
	    printf("\n   |                                                        |");
    	printf("\n   |                                                        |");
    	printf("\n   |                      MENU PRINCIPAL                    |");
    	printf("\n   |                                                        |");
    	printf("\n   |        1 – Cadastrar Usuário                           |");
    	printf("\n   |        2 – Buscar Usuário por ID                       |");
    	printf("\n   |        3 – Buscar Usuário por EMAIL                    |");
    	printf("\n   |        4 – Listar Usuários                             |");
    	printf("\n   |        5 – Excluir Usuário por ID                      |");
    	printf("\n   |        6 – Edite um Usuário por ID                     |");
    	printf("\n   |                                                        |");
    	printf("\n   |        0 – Sair                                        |");
    	printf("\n   |                                                        |");
		printf("\n   |   Programador:                                         |");
		printf("\n   |   	Caio Villar Rocha                                 |");
		printf("\n   #________________________________________________________#\n");
		printf("\n\n   > Escolha uma opção: ");
    	scanf("%i", &opcao);
    	
    	switch(opcao) {
    		case 1: {
    			system("cls");fflush(stdin);
    			cadastro();
				break;
			}
			
			case 2: {
				int inputId;
				
				system("cls");fflush(stdin);
				puts("Digite o id do usuário: ");
				scanf("%d", &inputId);
				
				findUserById(inputId);
				break;
			}
			
			case 3: {
				char inputEmail[50];
				
				system("cls");fflush(stdin);
				puts("Digite o email do usuário: ");
				scanf("%s", &inputEmail);
				
				findUserByEmail(inputEmail);
				break;
			}
			
			case 4: {
				showAllInformation();
				break;
			}
			
			case 5: {
				char inputId;
				
				system("cls");fflush(stdin);
				puts("Digite o id do usuário: ");
				scanf("%d", &inputId);
				
				deleteUserById(inputId);
				break;
			}
			
			case 6: {
				char inputId;
				
				system("cls");fflush(stdin);
				puts("Digite o id do usuário: ");
				scanf("%d", &inputId);
				
				editUserById(inputId);
				break;
			}
		}
	} while(opcao != 0);
    
    
}

bool existsUserByEmail(char _email[]) {
	int i;
	for(i = 0; i < MAX_SIZE; i++) {
		if (strcmp(_email, email[i]) == 0) {
			return true;
		}
	}
	return false;
}

bool existsUserById(int _id) {
	int i;
	for(i = 0; i < MAX_SIZE; i++) {
		if (_id == id[i]) {
			return true;
		}
	}
	return false;
}

int getUserIndiceByEmail(char _email[]) {
	int i;
	for(i=0; i < MAX_SIZE; i++) {
		if (strcmp(_email, email[i]) == 0) {
			return i;
		}
	}
	return -1;
}

int getUserIndiceById(int _id) {
	int i;
	for(i=0; i < MAX_SIZE; i++) {
		if (_id == id[i]) {
			return i;
		}
	}
	return -1;
}

void findUserByEmail(char _email[]) {
	printf("%s", _email);
	if (existsUserByEmail(_email)) {
		int linha = getUserIndiceByEmail(_email);
		
		showInformation(linha);
	}else {
		puts("[ERRO] Usuário inexistente!");
		puts("Pressione qualquer tecla para continuar...");
		getch();
	}
	puts("\n\n\nPressione qualquer tecla para continuar...");
	getch();
}

void findUserById(int _id) {	
	if (existsUserById(_id)) {
		int linha = getUserIndiceById(_id);
		
		showInformation(linha);
	} else {
		puts("[ERRO] Usuário inexistente!");
		puts("Pressione qualquer tecla para continuar...");
		getch();
	}
	puts("\n\n\nPressione qualquer tecla para continuar...");
	getch();
}

void deleteUserById(int _id) {
	system("cls");fflush(stdin);
	if (existsUserById(_id)) {
		int userIndice = getUserIndiceById(_id);

		id[userIndice] = 0;
		strcpy(nome[userIndice], "\0");
		strcpy(email[userIndice], "\0");
		strcpy(sexo[userIndice], "\0");
		strcpy(endereco[userIndice], "\0");
		altura[userIndice] = 0;
		vacinado[userIndice] = NULL;
	} else {
		puts("[ERRO] Usuário inexistente!");
		puts("Pressione qualquer tecla para continuar...");
		getch();
	}
	system("cls");fflush(stdin);
	puts("Usuário deletado com sucesso!");
	puts("\n\n\nPressione qualquer tecla para continuar...");
	getch();
}

void showInformation(int linha) {
	system("cls");fflush(stdin);
	printf("\nID: %d" , id[linha]);
	printf("\nNOME COMPLETO: %s", nome[linha]);
	printf("\nEMAIL: %s", email[linha]);
	printf("\nSEXO: %s", sexo[linha]);
	printf("\nENDEREÇO: %s", endereco[linha]);
	printf("\nALTURA: %0.2f", altura[linha]);
	printf("\nVACINADO: %s", vacinado[linha] ? "SIM" : "NÃO");
}

void showAllInformation() {
	int i;
	
	system("cls");fflush(stdin);
	for(i=0; i < MAX_SIZE; i++) {
		if (id[i] != NULL) {
			printf("\n#============================#");
			printf("\nID: %d" , id[i]);
			printf("\nNOME COMPLETO: %s", nome[i]);
			printf("\nEMAIL: %s", email[i]);
			printf("\nSEXO: %s", sexo[i]);
			printf("\nENDEREÇO: %s", endereco[i]);
			printf("\nALTURA: %0.2f", altura[i]);
			printf("\nVACINADO: %s", vacinado[i] ? "SIM" : "NÃO");
		}
	}
	puts("\n\n\nPressione qualquer tecla para continuar...");
	getch();
}

void editUserById(int _id) {
	int linha = getUserIndiceById(_id);
	
	do {
		system("cls");fflush(stdin);
		puts("Digite um novo nome completo: ");
		gets(nome[linha]);
	} while (strlen(nome[linha]) <= 10);
	
	do {
		system("cls");fflush(stdin);
		puts("Digite um novo email: ");
		gets(email[linha]);
		result = strstr(email[linha], "@");
		if (result == NULL) {
				system("cls");fflush(stdin);
				puts("[ERRO] Seu email deve conter um: @");
				puts("\n\nPressione enter para continuar...");
				getch();
			}
	} while (result == NULL);
	
	system("cls");fflush(stdin);
	puts("Digite um novo endereço: ");
	gets(endereco[linha]);
	
	system("cls");fflush(stdin);
	puts("Digite uma nova altura: ");
	scanf("%lf", &altura[linha]);
	
	system("cls");fflush(stdin);
	puts("Usuário alterado com sucesso");
	puts("Pressione qualquer tecla para continuar...");
	getch();
}

void cadastro() {
	static int linha;
	char op;
	// Pessoa
	
	do {
		
		do {
			system("cls");fflush(stdin);
			puts("Digite o nome completo: ");
			gets(nome[linha]);
			if (strlen(nome[linha]) <= 10) {
				system("cls");fflush(stdin);
				puts("[ERRO] Você deve inserir seu nome completo");
				puts("\n\nPressione enter para continuar...");
				getch();
			}
		} while(strlen(nome[linha]) <= 10);
		
		do {
			system("cls");fflush(stdin);
			puts("Digite o email: ");
			scanf("%s", &email[linha]);
			result = strstr(email[linha], "@");
			if (result == NULL) {
				system("cls");fflush(stdin);
				puts("[ERRO] Seu email deve conter um: @");
				puts("\n\nPressione enter para continuar...");
				getch();
			}
		} while(result == NULL);
		
		do {
			system("cls");fflush(stdin);
			puts("Digite o endereço: ");
			scanf("%s", &endereco[linha]);
			if (strcmp(endereco, "") == 0) {
				system("cls");fflush(stdin);
				puts("[ERRO] Esse campo é obrigatório!");
				puts("\n\nPressione enter para continuar...");
				getch();
			}
		} while(strcmp(endereco, "") == 0);
		do {
			system("cls");fflush(stdin);
			puts("Digite a sua altura: ");
			scanf("%lf", &altura[linha]);
			
			if ((altura[linha] < 1.0) == 0 && (altura[linha] > 2.0) == 0) {
				system("cls");fflush(stdin);
				puts("[ERRO] Altura deve estar entre 1 e 2 metros!");
				puts("\n\nPressione enter para continuar...");
				getch();
			}
		} while(altura[linha] < 1.0 && altura[linha] > 2.0);
		
		do {
			system("cls");fflush(stdin);
			puts("Você foi vacinado? ");
			puts("Pressione [S] para SIM ou [N] para NÃO");
			isVacinado = getche();
			
			if (isVacinado == 'N' || isVacinado == 'n') {
				vacinado[linha] = false;
			} else if (isVacinado == 'S' || isVacinado == 's') {
				vacinado[linha] = true;
			} else {
				system("cls");fflush(stdin);
				puts("[ERRO] Você deve pressionar S para SIM e N para NÃO!");
				puts("\n\nPressione enter para continuar...");
				getch();
			}
		} while(vacinado[linha] == NULL && vacinado[linha] != false);
		
		do {
			system("cls");fflush(stdin);
			puts("Informe seu gênero sexual: ");
			puts("Pressione [M] para MASCULINO, [F] para FEMININO ou [-] para NÃO DECLARAR");
			isSexo = getche();
			
			if (isSexo == 'M' || isSexo == 'm') {
				strcpy(sexo[linha], "MASCULINO");
			} else if (isSexo == 'F' || isSexo == 'f') {
				strcpy(sexo[linha], "FEMININO");
			} else if (isSexo == '-') {
				strcpy(sexo[linha], "NÃO-INFORMADO");
			} else {
				system("cls");fflush(stdin);
				puts("[ERRO] Você deve pressionar [M] para MASCULINO, [F] para FEMININO ou [-] para NÃO DECLARAR");
				puts("\n\nPressione enter para continuar...");
				getch();
			}
		} while(sexo[linha] == NULL);
		
		id[linha] = generateRandomId();
		
		linha++;
		system("cls");fflush(stdin);
		puts("Você deseja cadastrar uma nova pessoa?");
		op = getch();
	} while(op == 'S' || op == 's');
}

int generateRandomId() {
	int randomId;
	do {
		randomId = (rand() % (MAX_SIZE + 1));
	} while(existsUserById(randomId) == true);
	return randomId;
}
