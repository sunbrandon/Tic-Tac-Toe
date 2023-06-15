#pragma once
#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
 public:

    TicTacToe();
    void play();

 private:
    
    void drawBoard() const;
    bool checkWin(char) const;
    vector<char> board;
    char currPlayer;

};