#include<bits/stdc++.h>
using namespace std;

void Board(char board[3][3]) {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool Win(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool Draw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}


int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char player = 'X';
    int row, col;
    bool game_Won = false;

    cout << "Welcome to Tic Tac Toe!\n";

    for (int turn = 0; turn < 9; turn++) {
        Board(board);
        cout << "Player " << player << ", enter row (0-2) and column (0-2): ";
        cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move. Try again.\n";
            turn--;
            continue;
        }

        board[row][col] = player;

        if (Win(board, player)) {
            Board(board);
            cout << "Player " << player << " wins!\n";
            game_Won = true;
            break;
        }
        
        if (Draw(board)) {
            Board(board);
            cout << "It's a draw!\n";
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    if (!game_Won) {
        Board(board);
        cout << "Game over!\n";
    }

    return 0;
}