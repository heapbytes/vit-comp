#include <stdio.h>

void display_board(char board[3][3]){
  printf("\n-------------\n");
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("| %c ", board[i][j]);
    }
    printf("|\n-------------\n");
  }
}
void display_board1(int board[3][3]){
  printf("\n-------------\n");
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("| %d ", board[i][j]);
    }
    printf("|\n-------------\n");
  }
}

int check_winner(char board[3][3], char player){
  // Check rows and columns
  for (int i = 0; i < 3; i++)
  {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
      return 1;
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
      return 1;
  }

  // Check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    return 1;
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    return 1;

  return 0;
}

int main(){

  char board[3][3];
  int board1[3][3];
  int row, col, pos;
  char player = 'X', ok;
  int moves = 0, n = 1;

  // Initialize the board
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      board[i][j] = '-';
      board1[i][j] = n;
      n++;
    }
  }

  printf("\n----Board positions----\n");
  display_board1(board1);

  printf("Start?: (Press y or n) : ");
  scanf("%c", &ok);

  if (ok == 'Y' || ok == 'y'){
    display_board(board);

    while (1){

      printf("\nPlayer %c's turn.: ", player);
      scanf("%d", &pos);


      if (pos > 9 || pos < 0){
        printf("Invalid move. Try again.\n");
        continue;
      }

      if (pos == 1) {
        if (board[0][0] != '-') {
          printf("Already played on this position\n");
          continue;
        }
      }

      if (pos == 2) {
        if (board[0][1] != '-') {
          printf("Already played on this position\n");
          continue;
        }
      }

      if (pos == 3) {
        if (board[0][2] != '-') {
          printf("Already played on this position\n");
          continue;
        }
      }

      if (pos == 4) {
        if (board[1][0] != '-') {
          printf("Already played on this position\n");
          continue;
        }
      }

      if (pos == 5) {
        if (board[1][1] != '-') {
          printf("Already played on this position\n");
          continue;
        }
      }

      if (pos == 6) {
        if (board[1][2] != '-') {
          printf("Already played on this position\n");
          continue;
        }
      }

      if (pos == 7) {
        if (board[2][0] != '-') {
          printf("Already played on this position\n");
          continue;
        }
      }

      if (pos == 8) {
        if (board[2][1] != '-') {
          printf("Already played on this position\n");
          continue;
        }
      }

      if (pos == 9) {
        if (board[2][2] != '-') {
          printf("Already played on this position\n");
          continue;
        }
      }

      //update board 
      if (pos == 1) {
        board[0][0] = player;
      }

      if (pos == 2) {
        board[0][1] = player;
      }

      if (pos == 3) {
        board[0][2] = player;
      }

      if (pos == 4) {
        board[1][0] = player;
      }

      if (pos == 5) {
        board[1][1] = player;
      }

      if (pos == 6) {
        board[1][2] = player;
      }

      if (pos == 7) {
        board[2][0] = player;
      }

      if (pos == 8) {
        board[2][1] = player;
      }

      if (pos == 9) {
        board[2][2] = player;
      }

      moves++;
      display_board(board);

      // Check if the current player has won
      if (check_winner(board, player)){
        printf("Player %c wins!\n", player);
        break;
      }

      // Check if it's a tie
      if (moves == 9){
        printf("It's a tie!\n");
        break;
      }

      // Switch players
      player = (player == 'X') ? 'O' : 'X';
    }
  }
  else
  {
    return 0;
  }

  return 0;
}
