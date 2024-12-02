// TIC TAC TOE  

#include <iostream> 

using namespace std; 

 

const int SIZE = 3; 

char board[SIZE][SIZE]; 

char currentMarker; 

int currentPlayer; 

 

void drawBoard() { 

    cout << "  0 1 2\n"; 

    for (int i = 0; i < SIZE; ++i) { 

        cout << i << " "; 

        for (int j = 0; j < SIZE; ++j) { 

            cout << board[i][j] << " "; 

        } 

        cout << endl; 

    } 

} 

 

bool placeMarker(int row, int col) { 

    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == '.') { 

        board[row][col] = currentMarker; 

        return true; 

    } 

    return false; 

} 

 

bool checkWin() { 

    // Check rows and columns 

    for (int i = 0; i < SIZE; ++i) { 

        if (board[i][0] == currentMarker && board[i][1] == currentMarker && board[i][2] == currentMarker) { 

            return true; 

        } 

        if (board[0][i] == currentMarker && board[1][i] == currentMarker && board[2][i] == currentMarker) { 

            return true; 

        } 

    } 

    // Check diagonals 

    if (board[0][0] == currentMarker && board[1][1] == currentMarker && board[2][2] == currentMarker) { 

        return true; 

    } 

    if (board[0][2] == currentMarker && board[1][1] == currentMarker && board[2][0] == currentMarker) { 

        return true; 

    } 

    return false; 

} 

 

void switchPlayer() { 

    if (currentPlayer == 1) { 

        currentPlayer = 2; 

        currentMarker = 'O'; 

    } else { 

        currentPlayer = 1; 

        currentMarker = 'X'; 

    } 

} 

 

int main() { 

    // Initialize the board 

    for (int i = 0; i < SIZE; ++i) { 

        for (int j = 0; j < SIZE; ++j) { 

            board[i][j] = '.'; 

        } 

    } 
}
