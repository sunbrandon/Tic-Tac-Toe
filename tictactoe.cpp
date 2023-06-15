#include <iostream>
#include <vector>
#include "tictactoe.h"

using namespace std;

TicTacToe::TicTacToe() {
    board = vector<char>(9, ' ');
    currPlayer = 'X';
}

void TicTacToe::drawBoard() const {
    cout << " " << board.at(0) << " | " << board.at(1) << " | " << board.at(2) << endl;
    cout << "-----------" << endl;
    cout << " " << board.at(3) << " | " << board.at(4) << " | " << board.at(5) << endl;
    cout << "-----------" << endl;
    cout << " " << board.at(6) << " | " << board.at(7) << " | " << board.at(8) << endl;
}

bool TicTacToe::checkWin(char player) const {
    for (unsigned i = 0; i < 9; i += 3) {
        if (board.at(i) == player && board.at(i + 1) == player && board.at(i+2) == player) {
            return true;
        }
    }
    for (unsigned i = 0; i < 3; ++i) {
        if (board.at(i) == player && board.at(i+3) == player && board.at(i + 6) == player) {
            return true;
        }
    }
    if (board.at(0) == player && board.at(4) == player && board.at(8) == player) {
        return true;
    }
    if (board.at(2) == player && board.at(4) == player && board.at(6) == player) {
        return true;
    }
    return false;
}

void TicTacToe::play() {
    cout << "Play Tic Tac Toe!" << endl;
    cout << "Player 1 is X" << endl;
    cout << "Player 2 is O" << endl;
    cout << "Enter a number 1-9 to make a move" << endl;
    cout << "Press '0' to quit" << endl;
    cout << endl;

    int move;
    int turns = 0;

    while (true) {
        drawBoard();
        cout << endl;
        
        cout << "Player " << currPlayer << " make your move: ";
        cin >> move;
        cout << endl;
        ++turns;

        if (move == -1) {
            cout << "You quit, thanks for playing" << endl;
            break;
        }
        --move;
        if (move < 0 || move > 9 || board.at(move) != ' ') {
            cout << "Invalid move, please try again" << endl;
            --turns;
            continue;
        }

        board.at(move) = currPlayer;

        if (checkWin(currPlayer)) {
            drawBoard();
            cout << endl;
            cout << "Player " << currPlayer << " Wins!" << endl;
            break;
        }
        if (count(board.begin(), board.end(), ' ') == 0) {
            drawBoard();
            cout << endl;
            cout << "Tie!" << endl;
            break;
        }

        if (turns % 2 == 0) {
            currPlayer = 'X';
        }
        else {
            currPlayer = 'O';
        }
    }
}