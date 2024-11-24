#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

void initializeBoard(char board[SIZE][SIZE]) 
{
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard(char board[SIZE][SIZE]) 
{
    printf("\n");
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) 
            printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---+---+---\n");
    }
    printf("\n");
}

bool checkWin(char board[SIZE][SIZE], char symbol) 
{
    // for rows and columns
    for (int i = 0; i < SIZE; i++) 
    {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) 
            {
            return true;
        }
    }
    // for diagonals
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) 
        {
        return true;
    }
    return false;
}

bool isDraw(char board[SIZE][SIZE]) 
{
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            if (board[i][j] == ' ') 
            return false;
        }
    }
    return true;
}

void playGame() 
{
    char board[SIZE][SIZE];
    initializeBoard(board);

    char currentPlayer = 'O';
    while (true) 
    {
        printBoard(board);
        int row, col;

        printf("Player %c, enter your move (row and column: 1-3): ", currentPlayer);
        scanf("%d %d", &row, &col);
        row--; col--; 
        // Adjust for 0 index

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') 
        {
            printf("Invalid move\n Try again\n");
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(board, currentPlayer)) 
        {
            printBoard(board);
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        if (isDraw(board)) 
        {
            printBoard(board);
            printf("It's a draw!\n");
            break;
        }

        currentPlayer = (currentPlayer == 'O') ? 'X' : 'O';
    }
}

int main() 
{
    printf("welcome to Tic Tac Toe:\n");
    playGame();
    return 0;
}
