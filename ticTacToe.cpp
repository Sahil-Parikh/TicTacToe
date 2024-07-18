#include <iostream>
#include <string>

using namespace std;

// int board [9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
char xo [9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
bool win = false;
bool draw = false;
int turnCounter;

void gameStatus (string player, char c);
bool isDraw ();
void getUserInput (string player, char c);
void getBestMove(int &row, int &col);
void aiPlayer();
void onePlayer (string p1);
void twoPlayers (string p1, string p2);
void printBoard ();
bool checkIfValid (int x, int y);


int main()
{
    int gameMode = 0; //1 for vs AI, 2 for vs Player
    string p1;
    int temp;
    cout << "Welcome to TicTacToe!\nWill there be 1 or 2 players? (Enter 1 or 2): ";
    cin >> gameMode;
    
    while (gameMode != 1 && gameMode != 2)
    {
        cout << "Enter 1 or 2 please: ";
        cin >> gameMode;
    }
    cout << "\nThis is your board, enter the number for the spot you want to place on the board when it is your turn.\n\n";
    printBoard();
    
    /*
    cout << "     |     |     \n";
    cout << "  0  |  1  |  2  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  3  |  4  |  5  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  6  |  7  |  8  \n";
    cout << "     |     |     \n";
    */
    cout << "\n\nEnter your name: ";
    cin >> p1;
    if (gameMode == 1)
    {
        cout << p1 << " you go first!\n";
        onePlayer(p1);
    }
    else
    {
        string p2;
        cout << "Player 2, enter your name: ";
        cin >> p2;
        temp = rand () % 2;
        if (temp == 0){
            cout << p2 << " goes first! ";
            twoPlayers(p2, p1);
        }
        else 
        {
            cout << p1 << " goes first! ";
            twoPlayers(p1, p2);
        }
    }
    return 0;
}
void onePlayer (string p1)
{
    char input; //x or o
    int location; //0-8
    
        for (int i = 0; i < 9; i++)
        {
            if (win == true){
                break;
            }
            getUserInput(p1, 'x');
            i++;
            if (i >= 9 || win == true){
                break;
            }
            aiPlayer();
        }
        if (win == false)
            cout << "\nDraw\n";

}
void aiPlayer() {

    int row, col;
    /*
    do
    {
        row = rand() % 3;
        col = rand() % 3;
    } while (!checkIfValid(row, col));
    */
   do
    {
        row = rand() % 3;
        col = rand() % 3;
    } while (!checkIfValid(row, col));
    cout <<"\n";
    getBestMove(row, col);
    board[row][col] = 'o';
    printBoard();
    gameStatus("CPU", 'o');

}
void getBestMove(int &row, int &col)
{
    int hor = 0;
    int vert = 0;
    int hDub = 0;
    int vDub = 0;
    int c = 0;
   
    

     for(int i = 0; i < 3; i++)
    {
        hor = 0;
        vert = 0;
        hDub = 0;
        vDub = 0;
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 'o')
            {
                hDub++;
            } //horizontal
            else if (board[j][i] == 'o')
            {
                vDub++;
            } //vert

           
        }
        
        if (hDub == 2)
        {
            c = 0;
            for (int p = 0; p < 3; p++)
            {
                if (checkIfValid(i, p) == true)
                {
                row = i;
                col = p;
                return;
                }
            
            } 
        }
        if (vDub == 2)
        {
            c = 0;
            for (int p = 0; p < 3; p++)
            {
                if (checkIfValid(p, i) == true)
                {
                row = p;
                col = i;
                return;
                }
            }
        }

        
        
        
    }


    
    for(int i = 0; i < 3; i++)
    {
        hor = 0;
        vert = 0;
        for (int j = 0; j < 3; j++)
        {
         /*
            if (board[i][j] == 'o')
            {
                hDub++;
            } //horizontal
            else if (board[j][i] == 'o')
            {
                vDub++;
            } //vert
            */

            if (board[i][j] == 'x')
            {
                hor++;
            } //horizontal
            if (board[j][i] == 'x')
            {
                vert++;
            } //vert
        }
        /*
        if (hDub == 2)
        {
            c = 0;
            for (int p = 0; p < 3; p++)
            {
                if (checkIfValid(i, p) == true)
                {
                row = i;
                col = p;
                }
            
            } 
        }
        else if (vDub == 2)
        {
            c = 0;
            for (int p = 0; p < 3; p++)
            {
                if (checkIfValid(p, i) == true)
                {
                row = p;
                col = i;
                }
            }
        }
        */

        if (hor == 2)
        {
            c = 0;
            for (int p = 0; p < 3; p++)
            {
                if (checkIfValid(i, p) == true)
                {
                row = i;
                col = p;
                return;
                }
            
            } 
        }
        if (vert == 2)
        {
            c = 0;
            for (int p = 0; p < 3; p++)
            {
                if (checkIfValid(p, i) == true)
                {
                row = p;
                col = i;
                return;
                }
            }
        }
        
    }
   

} 

void twoPlayers (string p1, string p2){
    char input; //x or o
    int location; //0-8
    /*
    cout << p1 << " you're up, which slot would you like to place your 'x': ";
            cin >> location;
           
        while (checkIfValid (location) == false) {
            cout << p1 << " you're up, which slot would you like to place your 'x': ";
            cin >> location;
            cout << "\n" << turnCounter << "\n";
            
        } 
        */
        for (int i = 0; i < 9; i++)
        {
            if (win == true){
                break;
            }
            getUserInput(p1, 'x');
            i++;
            if (i >= 9 || win == true){
                break;
            }
            getUserInput(p2, 'o');
        }
        if (win == false)
            cout << "\nDraw\n";
    /*
    while (win == false && draw == false)
    {
        gameStatus(p1, 'x');
        draw = isDraw();
        cout << p1 << " you're up, which slot would you like to place your 'x': ";
            cin >> location;
            if (turnCounter > 11 || draw == true)
        {
            break;
        }
        while (checkIfValid (location) == false && turnCounter < 10) {
            cout << p1 << " you're up, which slot would you like to place your 'x': ";
            cin >> location;
            cout << "\n" << turnCounter << "\n";
            
        } 
        xo [location] = 'x';
        printBoard();
        gameStatus(p1, 'x');
        if (win == true || draw == true)
        {
            break;
        }
        cout << p2 << " you're next, which slot would you like to place 'o' in?: ";
        cin >> location;
        if (turnCounter > 11|| draw == true)
        {
            break;

        }
        while (checkIfValid (location) == false && turnCounter < 10){
        cout << p2 << " you're next, which slot would you like to place 'o' in?: ";
        cin >> location;
        }
        xo [location] = 'o';
        printBoard();
        gameStatus(p2, 'o');
        if (win == true || draw == true)
        {
            break;
        }
        

        

    }
    */

}
void getUserInput (string player, char c){
    int row, col;
    do {
        cout << player << ", which slot would you like to place your '" << c << "' in rwo column notation: ";
        cin >> row >> col;; 
    } while (checkIfValid (row, col) == false); 
    board[row][col] = c;
    printBoard();
    gameStatus(player, c);

}
void printBoard (){

    /*
    cout << "  1   2   3\n";
    cout << "-------------\n";
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "  " << i + 1 << "\n";
        cout << "-------------\n";
    }
    */
    turnCounter++;
    cout << "\n\n" << turnCounter << "\n\n";
    /*
    cout << "     |     |     \n";
    cout << "  " << xo[0] << "  |  " << xo[1] << "  |  " << xo[2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << xo[3] << "  |  " << xo[4] << "  |  " << xo[5] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << xo[6] << "  |  " << xo[7] << "  |  " << xo[8] << "  \n";
    cout << "     |     |     \n";
    */
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
    cout << "     |     |     \n";
    
}
bool checkIfValid (int x, int y){
    //if (xo[i] != 'x' && xo[i] != 'o')
    if (board [x][y] != 'x' && board [x][y] != 'o' )
    {
        return true;
    }
    else{
        return false;
    }
}

bool isDraw ()
{
    
    if (turnCounter == 11)
    {
        cout << "\nDrwaw\n";
        return true;
    }
    else 
    {
        return false;
    }
    
}
void gameStatus (string player, char c) // inputs are one player name, either p1 or p2, and x or o depending on who is calling function.
{
    
    if (win == true)
    {
        return;
    }
    if (board[1][1] == c)
    {
        if (board [0][1] == c && board [2][1] == c)
        {
            win = true;
            cout << player << " is the winner\n";
            return;
        }
        else if (board [1][0] == c && board [1][2] == c)
        {
            win = true;
            cout << player << " is the winner\n";
            return;
        }
        else if (board [0][0] == c && board [2][2] == c)
        {
            win = true;
            cout << player << " is the winner\n";
            return;
        }
        else if (board [0][2] == c && board [2][0] == c)
        {
            win = true;
            cout << player << " is the winner\n";
            return;
        }
    }
    else if (board[0][0])
    {
        if (board [1][0] == c && board [2][0] == c)
        {
            win = true;
            cout << player << " is the winner\n";
            return;
        }
        else if (board [0][1] == c && board [0][2] == c)
        {
            win = true;
            cout << player << " is the winner\n";
            return;
        }
    }
    else if (board[2][2])
    {
        if (board [2][1] == c && board [2][0] == c)
        {
            win = true;
            cout << player << " is the winner\n";
            return;
        }
        else if (board [0][2] == c && board [1][2] == c)
        {
            win = true;
            cout << player << " is the winner\n";
            return;
        }
    }
    /*
    if (xo[4] == c)
    {
        if (xo[3] == c && xo[5] == c){
            win = true;
            cout << player << " is the winner\n";
            return;
        }
        else if (xo[1] == c && xo[7] == c){
            win = true;
            cout << player << " is the winner\n";
            return;
        }
        else if (xo[2] == c && xo[6] == c){
            win = true;
            cout << player << " is the winner\n";
            return;
        }
        else if (xo[0] == c && xo[8] == c){
            win = true;
            cout << player << " is the winner\n";
            return;
        }
    }
    else if (xo[0] == c)
    {
        if (xo[1] == c && xo[2] == c){
            win = true;
            cout << player << " is the winner\n";
            return;
        }
        else if (xo[3] == c && xo[6] == c){
            win = true;
            cout << player << " is the winner\n";
            return;
        }

    }
    else if (xo[8] == c)
    {
        if (xo[6] == c && xo[7] == c){
            win = true;
            cout << player << " is the winner\n";
            return;
        }
        else if (xo[2] == c && xo[5] == c){
            win = true;
            cout << player << " is the winner\n";
            return;
        }
    }
    */
    
    

}
