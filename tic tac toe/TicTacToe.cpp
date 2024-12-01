#include <iostream>
#include <stdlib.h>
using namespace std;
#define R_COUNT 3
char board[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
int r, c = 0;
char turn = 'X';
bool draw = false;

void display_board() {
    system("cls");
    // cout << "Player1 [X]\ Player2 [O] turn\n";
    cout << "\t\t    |     |    \n";
    cout << "\t\t " << board[0][0] << "   |   " << board[0][1] << "  |   " << board[0][2] << endl;
    cout << "\t\t____|_____|____\n";
    cout << "\t\t    |     |    \n";
    cout << "\t\t " << board[1][0] << "   |   " << board[1][1] << "  |   " << board[1][2] << endl;
    cout << "\t\t____|_____|____\n";
    cout << "\t\t    |     |    \n";
    cout << "\t\t " << board[2][0] << "   |   " << board[2][1] << "   |   " << board[2][2] << endl;
    cout << "\t\t    |     |    \n";
}


bool gameover() {
    for (int r = 0;r < R_COUNT;r++) {
        if ((board[r][0] == board[r][1] == board[r][2]) ||
            (board[0][r] == board[1][r] == board[2][r])) {
            return false;
        }
        else if ((board[0][0] == board[1][1] == board[2][2]) ||
            (board[0][2] == board[1][1] == board[2][0])) {
            return false;
        }
    }
    for (int r = 0;r < R_COUNT;r++) {
        for (int c = 0;c < R_COUNT;c++) {
            if (board[r][c] != 'X' && board[r][c] != 'O') {
                return true;
            }
        }
    }
    draw = true;
    return false;
}

void player_turn() {
    if (turn == 'X') {
        cout << "\n\t player1  X turn:";
    }
    else if (turn == 'O') {
        cout << "\n\t player2 O turn:";
        int choice = 0;
    cin >> choice;
    switch (choice) {
    case 1: r = 0; c = 0; break;
    case 2: r = 0; c = 1; break;
    case 3: r = 0; c = 2; break;
    case 4: r = 1; c = 0; break;
    case 5: r = 1; c = 1; break;
    case 6: r = 1; c = 2; break;
    case 7: r = 2; c = 0; break;
    case 8: r = 2; c = 1; break;
    case 9: r = 2; c = 2; break;
    }
    if (turn == 'X' && board[r][c] != 'X' && board[r][c] != 'O') {
        board[r][c] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[r][c] != 'X' && board[r][c] != 'O') {
        board[r][c] = 'O';
        turn = 'X';
    }
    else {
        cout << "Box already filled \n\n";
        player_turn();
    }
   
}

int main() {
        while (gameover()) {
            display_board();
            player_turn();
            gameover();
        }

        if (turn == 'X' && draw == false) {
            cout << "\n\t Player 1 won \t\n";
        }
        else if (turn == 'O' && draw == false) {
            cout << "\n\t P2 won \t\n";
        }
        else {
            cout << "\n\t Game ended in DRAW!!\n\t";
        }
        return 0;
    }
}
