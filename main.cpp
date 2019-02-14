#include <iostream>
#include<cstdlib>
using namespace std;

bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);

bool isWon(char a, char board[][3]) {

    for (int i = 0; i<=2; i++){
       if (board[i][0] == a && board[i][1] == a && board[i][2] == a)
          return true;
       else if (board[0][i] == a && board[1][i] == a && board[2][i] == a)
          return true;
   }
   if (board[0][0] == a && board[1][1] == a && board[2][2] == a)
      return true;
   else if(board[0][2] == a && board[1][1] == a && board[2][0] == a)
      return true;
      else
   return false;
}



bool isDraw(char board[][3]) {

    int count = 0;
    for (int i = 0; i <=2; i++) {
        for (int j = 0; j <=2; j++) {
            if (board[i][j] == 'X' || board[i][j] == 'O')
                count++;
        }
    }
    if (count != 9)
        return false;
    if (!isWon('X', board) && !isWon('O', board))
        return true;
}

void displayBoard(char board[][3]) {

    cout << "-------------\n";
    for (int i = 0; i <=2; i++) {
        cout << "| ";
        for (int j = 0; j <=2; j++) {
            cout << board[i][j] << " | ";
        }

        cout << endl;
        cout << "-------------\n";

    }
}

void makeAMove(char board[][3], char a) {

    while (true) {
        cout << "Enter a row (0,1,2) for player " << a << " :";
        int x;
        cin >> x;
        int y;
        cout << "Enter a column (0,1,2) for player " << a << ":";
        cin >> y;
        if (x < 0 || y < 0 || x > 2 || y > 2) {
            cout << "Invalid Move. Try Again\n";
        } else {
            if (board[x][y] != 'X' && board[x][y] != 'O') {
                board[x][y] = a;
                break;
            } else {
                cout << "This cell is already occupied.Try a different cell\n";
            }
        }
    }
}

int main() {
    //
    //	PLEASE DO NOT CHANGE function main
    //
    char board[3][3] = {
        { ' ', ' ', ' '},
        { ' ', ' ', ' '},
        { ' ', ' ', ' '}
    };
    displayBoard(board);


    while (true) {
        // The first player makes a move
        makeAMove(board, 'X');
        displayBoard(board);
        if (isWon('X', board)) {
            cout << "X player won" << endl;
            exit(0);
        } else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }

        // The second player makes a move
        makeAMove(board, 'O');
        displayBoard(board);

        if (isWon('O', board)) {
            cout << "O player won" << endl;
            exit(0);
        } else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }
    }

    return 0;



}