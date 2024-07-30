#include <iostream>

int main() {
    const int MAX_MOVEMENTS = 9;

    int targetColumn = -1;
    int targetRow = -1;

    const char PLAYER_X = 'X';
    const char PLAYER_O = 'O';

    char currentPlayer = PLAYER_X;
    char winner = ' ';
    
    char grid[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    for(int i = 0; i < MAX_MOVEMENTS; i++) {
        std::cout << "Current player: " << currentPlayer << "\n \n";

        std::cout << "     |     |     " << std::endl;
        std::cout << "  " << grid[0][0] << "  |  " << grid[0][1] << "  |  " << grid[0][2] << "  " << std::endl;
        std::cout << "_____|_____|_____" << std::endl;
        std::cout << "     |     |     " << std::endl;
        std::cout << "  " << grid[1][0] << "  |  " << grid[1][1] << "  |  " << grid[1][2] << "  " << std::endl;
        std::cout << "_____|_____|_____" << std::endl;
        std::cout << "     |     |     " << std::endl;
        std::cout << "  " << grid[2][0] << "  |  " << grid[2][1] << "  |  " << grid[2][2] << "  " << std::endl;
        std::cout << "     |     |     " << std::endl;
        
        if(winner != ' ') {
            break;
        }

        std::cout << "Where do you want to make your move? (1 - 3) " << std::endl;

        while(true) {
            std::cout << "Row number? ";
            std::cin >> targetRow;

            std::cout << "Column number? ";
            std::cin >> targetColumn;

            // Check if player enters invalid input 
            if(targetRow < 0 || targetRow > 2 || targetColumn < 0 || targetColumn > 2) {
                std::cout << "Invalid input, try again: " << std::endl;
            } else if(grid[targetRow][targetColumn] != ' ') {
                std::cout << "Cell is not empty, try again: " << std::endl;
            } else {
                break;
            }

            std::cin.clear();
            std::cin.ignore(10000, '\n');

            // Value reset
            targetRow = -1;
            targetColumn = -1;
        }

        grid[targetRow][targetColumn] = currentPlayer;

        // If currentPlayer is X then the next turn will be O 
        currentPlayer = (currentPlayer == PLAYER_X)? PLAYER_O : PLAYER_X;

        for(int i = 0; i < 3; i++) {
            if(grid[i][0] != ' ' && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
                winner = grid[i][0];
                break;
            }
        }

        for(int i = 0; i < 3; i++) {
            if(grid[0][i] != ' ' && grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) {
                winner = grid[0][i];
                break;
            }
        }

        if(grid[0][0] != ' ' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
            winner = grid[0][0];
        } else if(grid[0][2] != ' ' && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
            winner = grid[0][2];
        }
    }

    if(winner != ' ') {
        std::cout << "Player " << winner << " is the winner!" << std::endl;
    } else {
        std::cout << "Tie!" << std::endl;
    }
}