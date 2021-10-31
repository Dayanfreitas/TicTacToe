#include "display.h"
#include <stdio.h>

void presentationScreen() {
    printf("\n");
	printf("\t*********************************************\n");
	printf("\t**              TIC TAC TOE                **\n");
	printf("\t**                                         **\n");
    printf("\t*********************************************\n");
	printf("\t**        Your Terminal Tic Tac Toe        **\n");
    printf("\t*********************************************\n");
	printf("\t*************************************%s*\n",VERSION);
	printf("\t*********************************************\n");    
}

void about() {
	printf("\t**   O jogo da velha eh uma atividade     **\n");
    printf("\t**   da faculdade, feita no dia 06/06/2019 **\n");
   	printf("\t**   pelo estudante Dayan O. De Freitas  **\n");
}

void menu() {
	puts("");
	puts("\ta.>> Single player");
	puts("\tb.>> Multiplayers");
	puts("\t[E]exit");
	puts("");
	// printf("\ta.>>  1 Players");
	// printf("\n");
	// printf("\tb.>>  2 Player");
	// printf("\tc.>> Ajustes");
	// printf("\t\t\td.>> Sair");
}


// int funcao() {
// 	return 1;
// }