#include <iostream>

int main() {
    const int MAX_MOVEMENTS = 9;

    int targetColumn = -1;
    int targetRow = -1;

    const char PLAYER_X = 'X';
    const char PLAYER_O = 'O';

    char currentPlayer = PLAYER_X;

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
        
        std::cout << "Where do you want to make your move? (1 - 3) " << std::endl;

        while(true) {
            std::cout << "Row number? ";
            std::cin >> targetRow;

            std::cout << "Column number? ";
            std::cin >> targetColumn;

            if(targetRow < 0 || targetRow > 2 || targetColumn < 0 || targetColumn > 2) {
                std::cout << "Invalid input, try again: " << std::endl;
            } else if(grid[targetRow][targetColumn] != ' ') {
                std::cout << "Cell is not empty, try again: " << std::endl;
            } else {
                break;
            }

            targetRow = -1;
            targetColumn = -1;
        }


        grid[targetRow][targetColumn] = currentPlayer;

        // If currentPlayer is X then the next turn will be O 
        currentPlayer = (currentPlayer == PLAYER_X)? PLAYER_O : PLAYER_X;
    }
}