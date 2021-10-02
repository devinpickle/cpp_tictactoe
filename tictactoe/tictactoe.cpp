// tictactoe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <fstream>
#include "Board.h"
using namespace std;

bool valid_move(int position);
Board b;

int main()
{
    // Introduce how the board works
    std::cout << "Use the number keys to select a space on the board." << endl;
    std::cout << " 1 | 2 | 3" << endl;
    std::cout << "---+---+---" << endl;
    std::cout << " 4 | 5 | 6" << endl;
    std::cout << "---+---+---" << endl;
    std::cout << " 7 | 8 | 9" << endl << endl << endl;

// The characters used in the tictactoe board
char X = 'X';
char O = 'O';
bool x_turn = false;
char board[] = {
        ' ', ' ', ' ',
            ' ', ' ', ' ',
            ' ', ' ', ' ',
};

// Start game loop
bool end_game = false;
while (end_game == false) {

    x_turn = b.is_x_turn(board);
    // Get X's input
    int selected;
    if (x_turn) {
        bool possible_move = false;
        while (possible_move == false) {
            std::cout << "X> ";
            char character = X;
            cin >> selected; // Get user input for board space
            if (valid_move(selected) == true) {
                if (b.valid_space(board, selected)) {
                    board[selected - 1] = character;
                    possible_move = true;
                }
                else {
                    std::cout << "That space is already taken" << endl;
                }
            }
            
        }
    }
    // Get O's input
    else {
        bool possible_move = false;
        while (possible_move == false) {
            std::cout << "O> ";
            char character = O;
            cin >> selected;
            if (valid_move(selected) == true) {
                if (b.valid_space(board, selected)) {
                    board[selected - 1] = character;
                    possible_move = true;
                }
                else {
                    std::cout << "That space is already taken" << endl;
                }
            }
        }
    }
    b.display_board(board);
    if (end_game = b.game_done(board)) {
        //Writing to a file
        ofstream myfile;
        myfile.open("finished_board.txt");
        myfile << board;
        myfile.close();
    }
}
return 0;
}

bool valid_move(int position) {
    if (position >= 1 && position <= 9) {
        return true;
    }
    else {
        std::cout << "Please enter a number (1-9)" << endl;
        return false;
    }
}