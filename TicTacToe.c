#include<stdio.h>
#include<stdlib.h>

void drawBoard(char *board){
	
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[1], board[2], board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[4], board[5], board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[7], board[8], board[9]);
    printf("     |     |     \n\n");
}
int validMove(char *board, char choose){
	if(choose!=board[choose-48]){
		return 0;
	} 
	return 1;
}
void move(char *board, int turn){
	int player;
	char choose;
	if(turn%2==0){
		player = 2;
	} else player = 1;
	printf("Player %d\n", player);
	do{
		printf("Enter a number: ");
		scanf("%c", &choose);
		fflush(stdin);
		if(choose<49 || choose>57){
			printf("Entered wrong character, please re-enter!!!\n");
		} else{
			if(validMove(board, choose)){
				board[choose-48] = (player==1)? 'X':'O';
				break;
			} else printf("Number was used, please re-enter!!!\n");
		}
	}while(1);
}
int checkWin(char *board, int turn){
	char player;
	if(turn%2==0){
		player = 'O';
	} else player = 'X';
	if(board[1] == board[2] && board[1] == board[3]){
		return (player == 'X')? 1:2;
	}
	if(board[4] == board[5] && board[4] == board[6]){
		return (player == 'X')? 1:2;
	}
	if(board[7] == board[8] && board[7] == board[9]){
		return (player == 'X')? 1:2;
	}
	if(board[1] == board[5] && board[1] == board[9]){
		return (player == 'X')? 1:2;
	}
	if(board[3] == board[5] && board[3] == board[7]){
		return (player == 'X')? 1:2;
	}
	if(board[1] == board[4] && board[1] == board[7]){
		return (player == 'X')? 1:2;
	}
	if(board[2] == board[5] && board[2] == board[8]){
		return (player == 'X')? 1:2;
	}
	if(board[3] == board[6] && board[3]== board[9]){
		return (player == 'X')? 1:2;
	}
	return 0;
}
int main(){
	int turn = 1, result;
	char board[] = {' ','1','2','3','4','5','6','7','8','9'};
	do{
		drawBoard(board);
		result = checkWin(board, turn);
		if(result){
			printf("RESULT\n");
			printf("Player %d Win!!!", (turn%2==0)? 1:2);
			break;
		} else {
			if(turn == 10){
				printf("Draw!!!");
				break;
			}
		}
		move(board, turn);
		turn++;
	}while (result==0);
	
}
