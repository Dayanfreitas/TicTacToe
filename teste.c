#include <stdio.h>

char board3[3][3] = {{'1','2','3'}, 
                    {'4','5','6'}, 
                    {'7','8','9'}};
                    
char board9[9] = {'1','2','3', 
                    '4','5','6', 
                    '7','8','9'};
                    
void teste(char *board);

int main() {
    // char n = 'X';
    
    // printf("%d",(int) n);

    // for (int l=0;l<3;l++) {
    //     printf("l->%d\n", l);

    //     for (int c=0; c<3; c++) {
    //         printf("c-> %d\n", c);
    //     }
    // }

    if(0) {
        printf("Verdario");
    }
    if(1) {
        // printf("Verdario 1");
        teste(board9);
    }

}

void teste(char *board) {
    for (int i=0;i<9;i++) {
        printf("%c", board[i]);
    }
    
}