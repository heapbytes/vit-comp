#include <stdio.h>

int is_board_full(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0; 
        }
    }
    return 1; 
}


int check_winner(char player, char board[3][3]) {

    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return 1; 
    }
    

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return 1;
    
    return 0; 
}

int minimax(char board[3][3], int isMaximizing) {
    if (check_winner('X', board)){
      return -10;
    }
    if (check_winner('O', board)){
      return 10;
    }     
    if (is_board_full(board)){
      return 0;
    }

    // Maximizing ai 
    if (isMaximizing) {
        int bestScore = -10;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    int score = minimax(board, 0);
                    board[i][j] = ' '; 
                    bestScore = (score > bestScore) ? score : bestScore;
                }
            }
        }
        return bestScore;
    }

    // Minimizing player
    else {
        int bestScore = 10;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    int score = minimax(board, 1);
                    board[i][j] = ' '; 
                    bestScore = (score < bestScore) ? score : bestScore;
                }
            }
        }
        return bestScore;
    }
}

void find_best_move(char board[3][3]) {
    int bestMoveScore = -11;
    int bestMoveRow = -1;
    int bestMoveCol = -1;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                int moveScore = minimax(board, 0);
                board[i][j] = ' '; 

                if (moveScore > bestMoveScore) {
                    bestMoveScore = moveScore;
                    bestMoveRow = i;
                    bestMoveCol = j;
                }
            }
        }
    }
    
    printf("Computer's move: %d\n", (bestMoveRow * 3) + bestMoveCol + 1);
    board[bestMoveRow][bestMoveCol] = 'O';
}


void print_board(char board[3][3]) {
    printf("-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    
    int currentPlayer = 0;
    int moves = 0;

    printf("Tic Tac Toe\n");
    printf("You are X, and the computer is O. Make your move by entering a number from 1 to 9.\n");

    while (!is_board_full(board)) {
        print_board(board);

        if (currentPlayer == 0) {
            int move;
            printf("Your move: ");
            scanf("%d", &move);

            int row = (move - 1) / 3;
            int col = (move - 1) % 3;

            if (move >= 1 && move <= 9 && board[row][col] == ' ') {
                board[row][col] = 'X';
                currentPlayer = 1;
                moves++;
            } else {
                printf("Invalid move. Try again.\n");
            }
        } else {
            find_best_move(board);
            currentPlayer = 0;
            moves++;
        }

      if(moves > 4){
          if (check_winner('X', board)) {
            print_board(board);
            printf("Congratulations! You won!\n");
            break;
        } else if (check_winner('O', board)) {
            print_board(board);
            printf("The computer won! Better luck next time!\n");
            break;
        }
    }

        if (moves == 9) {
            print_board(board);
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}

