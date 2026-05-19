#include <iostream>
#include <vector>
#include <string>
using namespace std;
char board[3][3];
char currentPlayer;
void initBoard() {
    int num = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = '0' + num++;
    currentPlayer = 'X';
}

void displayBoard() {
    cout << "\n";
    cout << "  +-----------+\n";
    for (int i = 0; i < 3; i++) {
        cout << "  | ";
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X')
                cout << "X";
            else if (board[i][j] == 'O')
                cout << "O";
            else
                cout << board[i][j];
            cout << " | ";
        }
        cout << "\n  +-----------+\n";
    }
    cout << "\n";
}


bool makeMove(int choice) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}


bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer() {
    if (currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

int main() {
    string playAgain;

    cout << "================================\n";
    cout << "   Welcome to Tic-Tac-Toe!\n";
    cout << "================================\n";
    cout << "Tip: Use numbers 1-9 to pick a cell.\n";
    cout << "  1 | 2 | 3\n";
    cout << "  4 | 5 | 6\n";
    cout << "  7 | 8 | 9\n";

    do {
        initBoard();
        bool gameOver = false;
        int move;
        int totalMoves = 0;

        while (!gameOver) {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            if (move < 1 || move > 9) {
                cout << "[!] Invalid input. Choose a number between 1 and 9.\n";
                continue;
            }

            if (!makeMove(move)) {
                cout << "[!] Cell already taken! Try another one.\n";
                continue;
            }

            totalMoves++;

            if (checkWin()) {
                displayBoard();
                cout << "*** Player " << currentPlayer << " wins! Congratulations! ***\n";
                gameOver = true;
            } else if (checkDraw()) {
                displayBoard();
                cout << "*** It's a draw! Good game! ***\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        }

        cout << "\nPlay again? (yes/no): ";
        cin >> playAgain;

    } while (playAgain == "yes" || playAgain == "y");

    cout << "\nThanks for playing! Goodbye!\n";
    return 0;
}
