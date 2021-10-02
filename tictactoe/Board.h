#pragma once
#include <iostream>
using namespace std;
class Board
{ 
public:

    void display_board(char board[]) {
        // Display the board
        std::cout << endl << endl << endl;
        std::cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
        std::cout << "---+---+---" << endl;
        std::cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
        std::cout << "---+---+---" << endl;
        std::cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
    }
    
    bool valid_space(char board[], int position) {
        // Check if space is already taken
        if (board[position - 1] != ' ') {
            return false;
        }
        else {
            return true;
        }
    }

    bool is_x_turn(char board[]) {
        // Check the spaces in the board to see if it is x's turn
        int x_count = 0;
        int o_count = 0;
        for (int space = 0; space <= 8; space += 1) {
            switch (board[space]) {
            case 'X':
                x_count += 1;
                break;
            case 'O':
                o_count += 1;
                break;
            };
        };
        if (x_count <= o_count) {
            return true;
        }
        else {
            return false;
        };
    }

    bool game_done(char board[]) {
        // Check for a winner or tied game

        // Check for a completed row
        for (int row = 0; row < 3; row += 1) {
            //std::cout << board[row * 3] << board[row * 3 + 1] << board[row * 3 + 2] << endl;
            if (board[row * 3] != ' ' && board[row * 3] == board[(row * 3) + 1] && board[row * 3] == board[(row * 3) + 2]) {
                std::cout << board[row * 3] << " has won!" << endl;
                return true;
            }
        }
        // Check for a completed column
        for (int col = 0; col < 3; col += 1) {
            if (board[col] != ' ' && board[col] == board[3 + col] && board[col] == board[col + 6]) {
                std::cout << board[col] << " has won!" << endl;
                return true;
            }
        }
        // Check for completed diagonal
        if (board[4] != ' ' && (board[0] == board[4] && board[0] == board[8]) | (board[2] == board[4] && board[2] == board[6])) {
            std::cout << board[4] << " has won!" << endl;
            return true;
        }
        // Check for tie
        int empty = 0;
        for (int space = 0; space <= 8; space += 1) {
            if (board[space] == ' ') {
                empty++;
            }
        }
        if (empty == 0) {
            std::cout << "Tied game" << endl;
            return true;
        }

        return false;
    }
};

