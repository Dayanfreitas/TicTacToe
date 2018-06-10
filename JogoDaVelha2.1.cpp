#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
#define MAQUINA 2

char matriz[10]={'0','1','2','3','4','5','6','7','8','9'};
char marcadores[2] = {'X','O'};
void limparTudo();
void tela();
void telaDeApresentacao();
bool conferir(int jogador);
void JogoDaVelha();
void JogoDaVelha_maquina_facil();
void JogoDaVelha_medio();
void menuParaJogoDaMaquina();
void ajustes();
void ligando();
void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

int main(){

	srand(time(NULL));
	char op=' ';
	ligando();
do{
	
	telaDeApresentacao();
	printf("\n");
	printf("\ta.>> Jogo da velha 2 players");
	printf("\tb.>> Jogo da velha 1 player \n");
	printf("\tc.>> Ajustes");
	printf("\t\t\td.>> Sair");
	op = getch();
	switch (op){
		case 'a':
			do
			{
				JogoDaVelha();
				printf("\nPara continuar jogando [S]im /[N]ao");
				op =getch();
			}	while(op == 's' || op == 'S');
			break;
		case 'b':
			gotoxy(60,12);
			printf(" =========");
		    menuParaJogoDaMaquina();
			op = getch();	
			switch (op)
			{
				case 'a':
					do
					{
						JogoDaVelha_maquina_facil();
						printf("\nPara continuar jogando [S]im /[N]ao");
						op =getch();
					}while(op == 's' || op == 'S');
					break;
				case 'b':
					do
					{
						JogoDaVelha_medio();
						printf("\nPara continuar jogando [S]im /[N]ao");
						op =getch();
					}while(op == 's' || op == 'S');
					break;	
				case 'c':
					break;				
			}
			break;
		case 'c':
			ajustes();
		    break;
		}
	}while(op != 'd');
	system("cls");
	printf("\n");
	printf("Bye\n bye!!");
}

void tela(){
	system("cls");
	printf("Jogador1<%c>\t\t\tJogador2<%c>",marcadores[0],marcadores[1]);
	for (int i = 0 ; i < 3 ; i++){
		printf("\n");
	}
	printf("\t%c \t%c \t%c \t%c \t%c\n",matriz[7],179,matriz[8],179,matriz[9]);
	printf("\t%c \t%c \t%c \t%c \t%c\n",32,179,32,179,32);
	printf("\t%c \t%c \t%c \t%c \t%c\n",45,43,45,43,45);
	printf("\t%c \t%c \t%c \t%c \t%c\n",32,179,32,179,32);
	printf("\t%c \t%c \t%c \t%c \t%c\n",matriz[4],179,matriz[5],179,matriz[6]);
	printf("\t%c \t%c \t%c \t%c \t%c\n",32,179,32,179,32);
	printf("\t%c \t%c \t%c \t%c \t%c\n",45,43,45,43,45);
	printf("\t%c \t%c \t%c \t%c \t%c\n",32,179,32,179,32);
	printf("\t%c \t%c \t%c \t%c \t%c\n",matriz[1],179,matriz[2],179,matriz[3]);
}
bool conferir(int jogador){
	
	for (int i = 1; i <=7; i=i+3){
		//linhas 
		if (matriz[i] == matriz[i+1] && matriz[i+1] == matriz[i+2])
		{
	 		printf("\n\nO JOGADOR %d GANHOOU!!!",jogador);
			limparTudo();
			return true;
		}
	}
	for (int i = 1; i<=3;i++){
		//colunas
		 if (matriz[i] == matriz[i+3] && matriz[i+3] == matriz[i+6])
		 {
		 	printf("\n\nO JOGADOR %d GANHOOU!!!",jogador);
		 	limparTudo();
        	return true ;
		}
	}
	//diagonal
    if (matriz[1] == matriz[5] && matriz[5] == matriz[9] ||
		matriz[3] == matriz[5] && matriz[5] == matriz[7])
	{
		printf("\n\nO JOGADOR %d GANHOOU!!!",jogador);
		limparTudo();
        return true;
	}
	else if (matriz[1] != '1' && matriz[2] != '2' && matriz[3] != '3' &&
        matriz[4] != '4' && matriz[5] != '5' && matriz[6] != '6' && matriz[7] 
        != '7' && matriz[8] != '8' && matriz[9] != '9')
		{
			printf("\n\nJOGO DEU EMPATE!!");
			limparTudo();
			return true;
		}
}

void JogoDaVelha(){
	int escolha,player = 1;
	bool final=false;
	char marcador;

	tela();
	do{	
		if (player == 1){
			marcador = marcadores[0];
		}else if(player == 2){
			marcador = marcadores[1];
		}
		printf("\n\n");
		printf("|========================================\n");
		printf("|====>>");
		printf("\t Jogador %d sua vez<%c>:",player,marcadores[player-1]);
		scanf("%d",&escolha);
		if (escolha == 1 && matriz[1] == '1'){
			matriz[1] = marcador;
		}else if(escolha == 2 && matriz[2] == '2'){
			matriz[2] = marcador;
		}else if(escolha == 3 && matriz[3] == '3'){
			matriz[3] = marcador;
		}else if(escolha == 4 && matriz[4] == '4'){
			matriz[4] = marcador;
		}else if(escolha == 5 && matriz[5] == '5'){
			matriz[5] = marcador;
		}else if(escolha == 6 && matriz[6] == '6'){
			matriz[6] = marcador;
		}else if(escolha == 7 && matriz[7] == '7'){
			matriz[7] = marcador;
		}else if(escolha == 8 && matriz[8] == '8'){
			matriz[8] = marcador;
		}else if(escolha == 9 && matriz[9] == '9'){
			matriz[9] = marcador;
		}
		else{
			printf("Entrada invalida!!");
			getch();
			player--;
		}
		tela();
		
		final = conferir(player);
	
		if(player == 1 || player == 0){
			player = player+1;
		}
		else if (player == 2){
			player = player-1;
		}	
	}while(final == false);
}
void JogoDaVelha_maquina_facil(){
	int escolha,player=1;
	bool final=false;
	char marcador;
	
	tela();
	
	do{	
		if (player == 1){
			marcador = marcadores[0];
			printf("\n\n");
			printf("|========================================\n");
			printf("|====>>");
			printf("\t Jogador %d sua vez<%c>:",player,marcadores[player-1]);
			scanf("%d",&escolha);
		}else if(player ==  MAQUINA){
			marcador = marcadores[1];
			escolha = 1 + ( rand() % 10 );//sorteio de 1 a 10
		}
		
		
		if (escolha == 1 && matriz[1] == '1'){
			matriz[1] = marcador;
		}else if(escolha == 2 && matriz[2] == '2'){
			matriz[2] = marcador;
		}else if(escolha == 3 && matriz[3] == '3'){
			matriz[3] = marcador;
		}else if(escolha == 4 && matriz[4] == '4'){
			matriz[4] = marcador;
		}else if(escolha == 5 && matriz[5] == '5'){
			matriz[5] = marcador;
		}else if(escolha == 6 && matriz[6] == '6'){
			matriz[6] = marcador;
		}else if(escolha == 7 && matriz[7] == '7'){
			matriz[7] = marcador;
		}else if(escolha == 8 && matriz[8] == '8'){
			matriz[8] = marcador;
		}else if(escolha == 9 && matriz[9] == '9'){
			matriz[9] = marcador;
		}
		else{
			if (player == 1){
				printf("Entrada invalida!!");
				getch();
				player--;// player = 0
			}
			else if(player == MAQUINA){
				player--;
			}
		}
		
		tela();
		final = conferir(player);
		
		if(player == 1 || player == 0){
			player = player+1;
		}
		else if (player == MAQUINA){
			player = player-1;
		}	
	}while(final == false);
}

void JogoDaVelha_medio(){
int escolha,player = 1;
	bool final=false;
	char marcador;

	tela();
	
	do{	
		if (player == 1){
			marcador = marcadores[0];
			printf("\n\n");
			printf("|========================================\n");
			printf("|====>>");
			printf("\t Jogador %d sua vez<%c>:",player,marcadores[player-1]);
			scanf("%d",&escolha);
		}else if(player ==  MAQUINA){
			//escolha da maquina
			marcador = marcadores[1];
			 if ((matriz[1] == matriz[2] || 
				matriz[9] == matriz[6]  || 
				matriz[7] == matriz[5]) && 
				(matriz[3] != marcadores[0] && matriz[3] != marcadores[1] )){
				escolha = 3;
			}else if((matriz[2] == matriz[3] || 
					  matriz[7] == matriz[4] ||
					  matriz[5] == matriz[9])&& 
					 (matriz[1] != marcadores[0] && matriz[1] != marcadores[1])){
				escolha = 1; 
			}else if((matriz[1] == matriz[3] || 
					  matriz[5] == matriz[8])&& 
				     (matriz[2] != marcadores[0] && matriz[2] != marcadores[1])){
				escolha = 2;
			}else if((matriz[7] == matriz[1] ||
					  matriz[5] == matriz[6]) && 
					 (matriz[4] != marcadores[0] && matriz[4] != marcadores[1])){
				escolha = 4;
			}else if((matriz[4] == matriz[6] ||
					  matriz[8] == matriz[2] ||
					  matriz[7] == matriz[3] ||
					  matriz[9] == matriz[1])&& 
					 ( matriz[5] != marcadores[0] && matriz[5] != marcadores[1])){
				escolha = 5;
			}else if((matriz[4] == matriz[5] ||
					 matriz[9] == matriz[3]) && 
					(matriz[6] != marcadores[0] && matriz[6] != marcadores[1])){
				escolha = 6;
			}else if((matriz[4] == matriz[1] ||
					 matriz[8] == matriz[9]  || 
					 matriz[5] == matriz[3]) && 
					(matriz[7] != marcadores[0] && matriz[7] != marcadores[1])){
				escolha = 7;
			}else if((matriz[7] == matriz[9] ||
				     matriz[5] == matriz[2]) && 
					 (matriz[8] != marcadores[0] && matriz[8] != marcadores[1])){
				escolha = 8;
			}else if((matriz[7] == matriz[8] ||
					 matriz[5] == matriz[1]  ||
					 matriz[6] == matriz[3] )&& 
					 (matriz[9] != marcadores[0] && matriz[9] != marcadores[1])){
				escolha = 9;
			}else{
				 escolha = 1 + ( rand() % 10 );//sorteio de 1 a 10
			}
		}
		// marcação da maquina 
		if (escolha == 1 && matriz[1] == '1'){
			matriz[1] = marcador;
		}else if(escolha == 2 && matriz[2] == '2'){
			matriz[2] = marcador;
		}else if(escolha == 3 && matriz[3] == '3'){
			matriz[3] = marcador;
		}else if(escolha == 4 && matriz[4] == '4'){
			matriz[4] = marcador;
		}else if(escolha == 5 && matriz[5] == '5'){
			matriz[5] = marcador;
		}else if(escolha == 6 && matriz[6] == '6'){
			matriz[6] = marcador;
		}else if(escolha == 7 && matriz[7] == '7'){
			matriz[7] = marcador;
		}else if(escolha == 8 && matriz[8] == '8'){
			matriz[8] = marcador;
		}else if(escolha == 9 && matriz[9] == '9'){
			matriz[9] = marcador;
		}
		else{
			if (player == 1){
				printf("Entrada invalida!!");
				getch();
				player--;// player = 0
			}
			else if(player == MAQUINA){
				player--;
			}
		}
		
		tela();
		final = conferir(player);
		
		if(player == 1 || player == 0){
			player = player+1;
		}
		else if (player == MAQUINA){
			player = player-1;
		}	
	}while(final == false);
}
void telaDeApresentacao(){
	HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute (hConsole, 5);

	system("cls");
	printf("\n");
	printf("\t\t*********************************************\n");
	printf("\t\t**              JOGO DA VELHA              **\n");
	printf("\t\t**                                         **\n");
    printf("\t\t*********************************************\n");
    printf("\t\t**  /*O jogo da velha eh uma atividade     **\n");
    printf("\t\t**   da faculdade, feita no dia 06/06      **\n");
   	printf("\t\t**   pelo estudante Dayan O. De Freitas*/  **\n");
	printf("\t\t*********************************************\n");
	printf("\t\t*********************************************\n");
	SetConsoleTextAttribute (hConsole, 7);
}
void limparTudo(){

			char numero='0'; 
			for(int i=0;i<10;i++){
				matriz[i]= numero;
				numero++;
		
		}
}
void menuParaJogoDaMaquina(){
			int x=70,y=13;	
			
			printf("***************************\n");
			gotoxy(x,y);
			printf("*  Escolha a dificuldade: *\n");
			gotoxy(x,y+1);
			printf("*  a.>>Facil              *\n");
			gotoxy(x,y+2);
			printf("*  b.>>Medio              *\n");
			gotoxy(x,y+3);
			printf("*  c.>>Voltar             *\n");
			gotoxy(x,y+4);
			printf("***************************\n");
			gotoxy(x,y+5);
			printf("***************************\n");	
}
void ajustes(){
			int inicio;
			char c1;
			char c2;
			system("cls");
			printf("****************\n");
			printf("Ajustes do jogo\n");
			printf("****************\n");
			printf("\n");
			printf("Em ajustes do jogo eh posivel fazer mudanca no caracter de cada jogador!!!\n");
			printf("Personalize e divirta-se!!\n");
			printf(" ____\n");
			printf("|--Caracter Para Jogador 1:");
			do
			{
				c1 = getchar();
				for(int i=0;i<10;i++)
				{
	     			if (c1== matriz[i])
				    {
	     				c1 = getchar();
					}
				 }
			}while(c1 == ' '|| c1 ==  '\n');
			printf("|--Caracter Para jogador 2:");
			do
			{	
	     		c2 = getchar();
	     		for(int i=0;i<10;i++)
				{
	     			if (c2 == matriz[i])
					{
	     				c2 = getchar();
					 }
			    }
	     	}while(c2 == ' '|| c2 ==  '\n');
		    marcadores[0]=c1;
		    marcadores[1]=c2;
}
void ligando(){
	HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	printf("\n");
	for (int i=1;i<30;i++){
		SetConsoleTextAttribute (hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		printf("%c",219);
		Sleep(100);	
	}
	printf("100%%");
	Sleep(100);	
	printf(" Jogo carregado com sucesso\n");
	getch();
	SetConsoleTextAttribute (hConsole, 7);
	
}
