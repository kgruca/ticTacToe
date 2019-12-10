/*
    Author: Krzysztof Gruca
    Title: Tic Tac Toe
    Created: Dec 9th, 2019
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// global constants for size of tic tac toe board
const int ARR_LEN_X = 3;
const int ARR_LEN_Y = 3;

// function declarations
void displayArr(const char[][ARR_LEN_X]);
bool playerMov(char[][ARR_LEN_X]);
bool compMov(char[][ARR_LEN_X]);
bool win(char[][ARR_LEN_X]);

int main() {

    // set seed for random numbers
    unsigned seed = time(0);
    srand(seed);

    // bool win will control while loop below
    bool win = false;
    
    // the tic tac toe board, a 2x2 array
    char arr[3][3] = { {'*', '*', '*'},
                       {'*', '*', '*'},
                       {'*', '*', '*'} };

    // the game itself, will continue until player or program win the game
    while (!win) {

        if (playerMov(arr)) {
            win = true;
            break;
        }
        if (compMov(arr)) {
            win = true;
        }
    }

    //display the final moves
    displayArr(arr);

    return 0;
}

/* 
    The function displayArr() will display the tic tac toe board (the 2x2 array and its values).
    It accepts the 2x2 character array defined in main; each position [x][y] will 
    hold one of 3 possible char values: '*', 'o', or 'x'.
    It's used in main() once at the end, to display the final board after determining the winner, 
    and in the function playerMov(), to give the player a visual representation of the current board.
 */
void displayArr(const char arr[][ARR_LEN_X]) {

    for (int i = 0; i < ARR_LEN_Y; i++) {
        for (int j = 0; j < ARR_LEN_X; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

/*
    The function playerMov() displays the tic tac toe board to the player using displayArr(),
    gathers input from the player as to where they wish to place their move, and checks if
    the player has won the game.
    It accepts the 2x2 array defined in main as its parameter.
    It checks whether the player is setting their piece in a legal position (if there's no
    'o' or 'x' already present in the position.
    Also checks whether the player has won the game with their current turn by calling win(), and 
    returns true or false.
*/
bool playerMov(char arr[][ARR_LEN_X]) {

    int xAxis;
    int yAxis;

    displayArr(arr);

    cout << "X-axis coordinate (1-3): ";
    cin >> xAxis;
    cout << "Y-axis coordinate (1-3): ";
    cin >> yAxis;

    cout << endl;

    while ((arr[yAxis - 1][xAxis - 1] == 'o') || (arr[yAxis - 1][xAxis - 1] == 'x')) {
        cout << "X-axis coordinate (1-3): ";
        cin >> xAxis;
        cout << "Y-axis coordinate (1-3): ";
        cin >> yAxis;
    }
        
    arr[yAxis - 1][xAxis - 1] = 'o';

    return win(arr);
}

/*
    The function compMov() selects a random spot on the board for the program to place its
    piece, checking to see if the selected position is legal.
    It accepts the 2x2 array defined in main as its parameter.
    It calls win() to check whether the program won against the user and returns either true 
    or false to main.
*/
bool compMov(char arr[][ARR_LEN_X]) {
    int x = rand() % 3;
    int y = rand() % 3;

    while ((arr[y][x] == 'o') || (arr[y][x] == 'x')) {
       x = rand() % 3;
       y = rand() % 3;
    }

    arr[y][x] = 'x';

    return win(arr);
}

/*
    The function win() checks whether the user or program have won the game of tic tac toe.
    It accepts the 2x2 array defined in main as its parameter.
    It is used in functions playerMov() and compMov().
*/
bool win(char arr[][ARR_LEN_X]) {
    if ((arr[0][0] == 'o' && arr[0][1] == 'o' && arr[0][2] == 'o') || (arr[1][0] == 'o' && arr[1][1] == 'o' && arr[1][2] == 'o') || (arr[2][0] == 'o' && arr[2][1] == 'o' && arr[2][2] == 'o')
     || (arr[0][0] == 'o' && arr[1][0] == 'o' && arr[2][0] == 'o') || (arr[0][1] == 'o' && arr[1][1] == 'o' && arr[2][1] == 'o') || (arr[0][2] == 'o' && arr[1][2] == 'o' && arr[2][2] == 'o')
     || (arr[0][0] == 'o' && arr[1][1] == 'o' && arr[2][2] == 'o') || (arr[0][2] == 'o' && arr[1][1] == 'o' && arr[2][0] == 'o')) {
        cout << "You win!\n\n";
        return true;
    }
    else if ((arr[0][0] == 'x' && arr[0][1] == 'x' && arr[0][2] == 'x') || (arr[1][0] == 'x' && arr[1][1] == 'x' && arr[1][2] == 'x') || (arr[2][0] == 'x' && arr[2][1] == 'x' && arr[2][2] == 'x')
          || (arr[0][0] == 'x' && arr[1][0] == 'x' && arr[2][0] == 'x') || (arr[0][1] == 'x' && arr[1][1] == 'x' && arr[2][1] == 'x') || (arr[0][2] == 'x' && arr[1][2] == 'x' && arr[2][2] == 'x')
          || (arr[0][0] == 'x' && arr[1][1] == 'x' && arr[2][2] == 'x') || (arr[0][2] == 'x' && arr[1][1] == 'x' && arr[2][0] == 'x')) {
        cout << "You lose!\n\n";
        return true;
    }
    else
        return false;
}
