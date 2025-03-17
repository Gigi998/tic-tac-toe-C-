#include <iostream>
#include <string>

using namespace std;

void renderBoard(char board[3][3]) {
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      cout << board[row][column];

      if (column < 2) cout << " | ";
    }
    cout << endl;
    if (row < 2) cout << "---------" << endl;
  }
}

bool checkWin(char board[3][3]) {
  // Check rows
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] &&
        board[i][0] != ' ') {
      return true;
    }
  }

  // Check columns
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] &&
        board[0][i] != ' ') {
      return true;
    };
  }

  // Check diagonals
  if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] &&
       board[0][0] != ' ') ||
      (board[0][2] == board[1][1] && board[1][1] == board[2][0] &&
       board[0][2] != ' ')) {
    return true;
  }

  return false;
}

void handleUserInput(char board[3][3], string& currentPlayer) {
  int row, column;

  cout << currentPlayer << endl;
  cout << "Enter the position: ";
  cin >> row >> column;

  char fieldValue = board[row - 1][column - 1];

  if (fieldValue != ' ') {
    cout << "Selected field is already taken, please enter correct position."
         << endl;

    handleUserInput(board, currentPlayer);
  } else {
    board[row - 1][column - 1] = (currentPlayer == "player X") ? 'X' : 'O';
  }
}

int main() {
  char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

  bool isGameGoing = true;
  string currentPlayer = "player X";
  int moveCount = 1;

  while (isGameGoing) {
    renderBoard(board);

    handleUserInput(board, currentPlayer);

    // Check win
    if (checkWin(board)) {
      renderBoard(board);
      cout << currentPlayer << " WIN!" << endl;
      isGameGoing = false;
    }

    // Check draw
    if (moveCount >= 9) {
      renderBoard(board);
      cout << "It's draw!!" << endl;
      isGameGoing = false;
    }

    // Switch players
    currentPlayer = (currentPlayer == "player X") ? "player O" : "player X";

    moveCount += 1;
  }
}