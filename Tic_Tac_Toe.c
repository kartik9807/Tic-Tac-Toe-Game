#include <stdio.h>
#include <ctype.h>
char board[3][3];
int check_win();
void board_init(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=' ';
        }
    }
}
void template_display(){
    printf(" 1 | 2 | 3 \n");
    printf("---|---|---\n");
    printf(" 4 | 5 | 6 \n");
    printf("---|---|---\n");
    printf(" 7 | 8 | 9 \n");

}
void board_display(){
    printf(" %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",board[2][0],board[2][1],board[2][2]);

}
int board_update(int player,int position){
    char mark = (player == 1) ? 'X' : 'O';
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    if(board[row][col] == ' '){
        board[row][col] = mark;
    }
    else{
        return 0;
    }
    return -1;
}
int main(){
    int i=1,s;
    printf("\nWelcome to my Tic Tac Toe game !\n\n");
    template_display();
    printf("\nPlayer 1 is 'X' and Player 2 is 'O'\n\n");
    board_init();
    while(i<=9){
        printf("Player %d, enter your move (1-9): ",(i%2!=0)?1:2);
        scanf("%d",&s);
        if(s<1 || s>9 || !isdigit(s+'0')){
            printf("\nInvalid move. Try again.\n\n");
            continue;
        }
        if(board_update((i%2!=0)?1:0,s)==0){
            printf("Position already taken. \n");
            continue;
        }
        board_update((i%2!=0)?1:0,s);
        board_display();
        if(i>=3){
            if(check_win()==1){
                printf("Game Over! player 1 win \n");
                break;
            }
            else if(check_win()==2){
                printf("Game Over! player 2 win \n");
                break;
            }
            else{
                if(i==9){
                    printf("Game Over! It's a draw \n");
                    break;
                }
            }
        }
        i++;
    }
    return 0;
}

int check_win(){
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=' '){
            if(board[i][0] == 'X'){
                return 1;
            }else{
                return 2;
            }  
        }
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=' '){
            if(board[0][i] == 'X'){
                return 1;
            }else{
                return 2;
            }  
        }
    }
    if((board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[1][1]!=' ') || (board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=' ')){
        if(board[0][0] == 'X' || board[0][2] == 'X'){
            return 1;
        }else{
            return 2;
        }  
    }
    return 0;
}