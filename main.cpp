#include <iostream>

class Square {
public:
    std::string text;
};

class Board {
public:
    Square board[3][3];
    Board() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j].text = " ";
            }
        }
    }

    void printBoard() {
        std::cout << board[0][0].text << " | " << board[0][1].text <<" |  " << board[0][2].text << std::endl;
        std::cout << "__|___|__" << std::endl;
        std::cout << board[1][0].text << " | " << board[1][1].text << " | " << board[1][2].text << std::endl;
        std::cout << "__|___|__" << std::endl;
        std::cout << board[2][0].text << " | " << board[2][1].text << " | " << board[2][2].text << std::endl;
    }

    bool updateSquare(int x, int y, std::string player) {
        if (board[x][y].text != " ") {
            return false;
        }
        board[x][y].text = player;
        return true;
    }

    std::string checkWin() {
        // Top down
        for (int i = 0; i < 3; i++) {
            // top down
            if (board[i][0].text == board[i][1].text && board[i][1].text == board[i][2].text) {
                return board[i][0].text;
            }
            // side to side
            if (board[0][i].text == board[1][i].text && board[1][i].text == board[2][i].text) {
                return board[0][i].text;
            }
            // first diagonal
            if (board[0][0].text == board[1][1].text && board[1][1].text == board[2][2].text) {
                return board[0][0].text;
            }
            // second diagonal
            if (board[0][2].text == board[1][1].text && board[1][1].text == board[2][0].text) {
                return board[0][2].text;
            }
        }
        return "";
    }

    bool turn(std::string player) {
        std::string moveS;
        printBoard();
        std::cout << "Enter your move in x,y" << std::endl;
        std::cin >> moveS;
        if (moveS.length() != 3) {
            std::cout << "Error. Please enter in x,y" << std::endl;
            return turn(player);
        }
        int x = moveS[2] - '0';
        int y = moveS[0] - '0';
        if (!updateSquare(x, y, player)) {
            std::cout << "Someone already on there" << std::endl;
            return turn(player);
        }
        std::string winRes = checkWin();
        if (!winRes.empty() && winRes != " ") {
            std::cout << "Congratulations! " << winRes << " won!" << std::endl;
            return true;
        }

        return false;
    }
};

int main() {
    std::cout << "Welcome to Tic Tac Toe" << std::endl;
    Board board;
    std::string player = "X";
    while (true) {
        if (board.turn(player)) {
            return 0;
        }

        switch (player[0]) {
            case 'X':
                player[0] = 'O';
                break;
            case 'O':
                player[0] = 'X';
                break;
            default:
                return 1;
        }
    }
    return 0;
}