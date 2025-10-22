//Tic Tac Toe c++
#include <iostream>
//#include <conio.h> //doar in codeblocks/windows
//#include <windows.h> //doar in codeblocks/windows

using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int moves[10][2], k = 0;

char current_marker;
int current_player;

void drawmoves()
{
    cout << '\n' << "MOVES" << '\n';
    for(int i = 0; i < k; i++)
        cout << "Player " << moves[i][0] << " : " << moves[i][1] << '\n';
}

void drawBoard()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

void resetBoard()
{
    char val = '1';
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            board[i][j] = val, val++;
}

bool placeMarker(int slot)
{
    int row = 0;
    if(slot % 3 == 0) row = (slot / 3) - 1;
    else row = slot / 3;

    int col = 0;
    if(slot % 3 == 0) col = 2;
    else col = slot % 3 - 1;

    if(board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = current_marker;
        return true;
    }
    else return false;
}

int winner()
{
    for(int i = 0; i < 3; i++)
    {
        // rows
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) return current_player;

        // columns
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) return current_player;

    }

    // diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return current_player;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return current_player;

    return 0;
}

void swap_player_and_marker()
{
    if(current_marker == 'X') current_marker = 'O';
    else current_marker = 'X';

    if(current_player == 1) current_player = 2;
    else current_player = 1;
}

void game()
{
    int player_won = 0;
    while(player_won == 0)
    {
        resetBoard();

        for(int i = 0; i < 9; i++)
        {
            if(i == 0)
            {
                cout << "Player one, choose your marker (X or O) : ";
                char marker_p1;
                cin >> marker_p1;

                if(marker_p1 != 'X' && marker_p1 != 'O')
                {
                    cout << "Marker invalid, please try again!" << '\n';
                    cout << '\n' << "Press S if you want to start a new game or C if you do not want!" << '\n';
                    char S;
                    cin >> S;
                    if(S == 'S')
                    {
                        //system("cls"); - pe windows
                        system("clear"); //pe mac
                        i = -1;
                        continue;

                    }
                    else if(S == 'C')
                        return;
                    else
                    {
                        cout << "You did not press S or C, the game has stopped!";
                        return;
                    }
                }

                current_player = 1;
                current_marker = marker_p1;

                drawBoard();
            }

            cout << "It's player " << current_player << "'s turn. Enter your slot : ";
            int slot = 0;
            cin >> slot;
            //system("cls"); - pe windows
            system("clear"); //pe mac
            if(slot < 1 || slot > 9)
            {
                cout << "That slot is invalid! Try another slot!" << endl;
                drawBoard();
                i--;
                continue;
            }
            if(!placeMarker(slot))
            {
                cout << "That slot is occupied! Try another slot!" << endl;
                drawBoard();
                i--;
                continue;
            }
            moves[k][0] = current_player, moves[k++][1] = slot;
            drawBoard();
            player_won = winner();
            if(player_won == 1)
            {
                cout << '\n' << "PLAYER ONE WON! CONGRATULATIONS!" << '\n';
                drawmoves();
                cout << '\n' << "Press S if you want to start a new game or C if you do not want!" << '\n';
                char S;
                cin >> S;
                if(S == 'S')
                {
                    resetBoard();
                    k = 0;
                    //system("cls"); - pe windows
                    system("clear"); //pe mac
                    i = -1;
                    continue;

                }
                else if(S == 'C')
                    break;
                else
                {
                    cout << "You did not press S or C, the game has stopped!";
                    break;
                }
            }
            if(player_won == 2)
            {
                cout << '\n' << "PLAYER TWO WON! CONGRATULATIONS!" << '\n';
                drawmoves();
                cout << '\n' << "Press S if you want to start a new game or C if you do not want!" << '\n';
                char S;
                cin >> S;
                if(S == 'S')
                {
                    resetBoard();
                    k = 0;
                    //system("cls"); - pe windows
                    system("clear"); //pe mac
                    i = -1;
                    continue;

                }
                else if(S == 'C')
                    break;
                else
                {
                    cout << "You did not press S or C, the game has stopped!";
                    break;
                }
            }

            swap_player_and_marker();
        }
        if(player_won == 0)
        {
            cout << "That is a tie game!" << '\n';
            drawmoves();
            cout << '\n' << "Press S if you want to start a new game or C if you do not want!" << '\n';
            char S;
            cin >> S;
            if(S == 'S')
            {
                resetBoard();
                k = 0;
                //system("cls"); - pe windows
                system("clear"); //pe mac
            }
            else if(S == 'C')
                break;
            else
            {
                cout << "You did not press S or C, the game has stopped!";
                break;
            }
        }
    }
}

int main()
{
    game();
    return 0;
}