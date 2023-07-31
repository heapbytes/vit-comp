#include <stdio.h>

#define BOARD_SIZE 3

// Function to check if the board is full
int is_board_full(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ')
                return 0; // Board is not full yet
        }
    }
    return 1; // Board is full
}

// Function to check if a player has won
int check_winner(char player, char board[BOARD_SIZE][BOARD_SIZE]) {
    // Check rows and columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return 1; // Player has won
    }
    
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return 1; // Player has won
    
    return 0; // No winner
}

// Minimax function
int minimax(char board[BOARD_SIZE][BOARD_SIZE], int depth, int isMaximizing) {
    // Base cases: check if there is a winner or the board is full
    if (check_winner('X', board)) return -10 + depth;
    if (check_winner('O', board)) return 10 - depth;
    if (is_board_full(board)) return 0;

    // Maximizing player's turn
    if (isMaximizing) {
        int bestScore = -1000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    int score = minimax(board, depth + 1, 0);
                    board[i][j] = ' '; // Undo the move
                    bestScore = (score > bestScore) ? score : bestScore;
                }
            }
        }
        return bestScore;
    }
    // Minimizing player's turn
    else {
        int bestScore = 1000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    int score = minimax(board, depth + 1, 1);
                    board[i][j] = ' '; // Undo the move
                    bestScore = (score < bestScore) ? score : bestScore;
                }
            }
        }
        return bestScore;
    }
}

// Function to find the best move using Minimax
void find_best_move(char board[BOARD_SIZE][BOARD_SIZE]) {
    int bestMoveScore = -1000;
    int bestMoveRow = -1;
    int bestMoveCol = -1;
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                int moveScore = minimax(board, 0, 0);
                board[i][j] = ' '; // Undo the move

                if (moveScore > bestMoveScore) {
                    bestMoveScore = moveScore;
                    bestMoveRow = i;
                    bestMoveCol = j;
                }
            }
        }
    }
    
    printf("Computer's move: %d\n", (bestMoveRow * BOARD_SIZE) + bestMoveCol + 1);
    board[bestMoveRow][bestMoveCol] = 'O';
}

// Function to print the Tic Tac Toe board
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("-------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    
    int currentPlayer = 0; // 0 for X, 1 for O
    int moves = 0;

    printf("Tic Tac Toe\n");
    printf("You are X, and the computer is O. Make your move by entering a number from 1 to 9.\n");

    while (!is_board_full(board)) {
        print_board(board);

        if (currentPlayer == 0) {
            int move;
            printf("Your move: ");
            scanf("%d", &move);

            int row = (move - 1) / BOARD_SIZE;
            int col = (move - 1) % BOARD_SIZE;

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

        if (check_winner('X', board)) {
            print_board(board);
            printf("Congratulations! You won!\n");
            break;
        } else if (check_winner('O', board)) {
            print_board(board);
            printf("The computer won! Better luck next time!\n");
            break;
        }

        if (moves == BOARD_SIZE * BOARD_SIZE) {
            print_board(board);
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}

