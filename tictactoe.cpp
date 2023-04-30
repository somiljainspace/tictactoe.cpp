#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void printboard(char arr[9])
{
    cout << "   |   |   \n";
    cout << " " << arr[0] << " | " << arr[1] << " | " << arr[2] << endl;
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << arr[3] << " | " << arr[4] << " | " << arr[5] << endl;
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << arr[6] << " | " << arr[7] << " | " << arr[8] << endl;
    cout << "   |   |   \n";
};

void toenter(int row, int coloumn, int choice, char arr[9])
{
    switch (choice)
    {
    case 1:
        arr[0] = 'X';
        break;

    default:
        break;
    }
}

int win(char arr[9])
{
    if (arr[0] == arr[1] && arr[2] == arr[1])
    {
        return 1;
    }
    if (arr[0] == arr[3] && arr[3] == arr[6])
    {
        return 1;
    }
    if (arr[0] == arr[4] && arr[4] == arr[8])
    {
        return 1;
    }
    if (arr[6] == arr[4] && arr[4] == arr[2])
    {
        return 1;
    }
    if (arr[1] == arr[4] && arr[4] == arr[7])
    {
        return 1;
    }
    if (arr[3] == arr[4] && arr[4] == arr[5])
    {
        return 1;
    }
    if (arr[6] == arr[7] && arr[7] == arr[8])
    {
        return 1;
    }
    if (arr[2] == arr[5] && arr[5] == arr[8])
    {
        return 1;
    }

    return 0;
}

int main()
{
    cout << "enter the name of first player";
    string n1;
    string n2;
    getline(cin, n1);
    cout << "enter the name of second player";
    getline(cin, n2);
    cout << "player 1 " << n1 << " will play first\n";
    cout << "player 2 " << n1 << " will play second\n";
    char arr[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
    int row;
    int coloumn;

    char choiceP1;
    char choiceP2;

    int turn = 0;

    printboard(arr);
    cout << "choose  x or o which you wanna play" << endl;
    cin >> choiceP1;
    if (choiceP1 == 'x')
    {
        choiceP2 = 'o';
        int enter;
        bool flag = false;

        for (int i = 0; i < 9; i++)
        {
            if(!turn) cout << "Player 1 to move\n";
            else cout << "Player 2 to move\n";

            cout << "enter  the position u wanna play";
            cin >> enter;
            
            if (arr[enter] == 'x' || arr[enter] == 'o')
            {
                return 1;
            }
            
            if(0 <= enter && enter <= 8) {
                if(!turn) {
                    arr[enter] = choiceP1;
                } else {
                    arr[enter] = choiceP2;
                }
            } else {
                cout << "Invalid input\n";
                return 1;
            }

            // switch (enter)
            // {
            // case 0:
            //     arr[0] = 'x';
            //     break;
            // case 1:
            //     arr[1] = 'x';
            //     break;
            // case 2:
            //     arr[2] = 'x';
            //     break;
            // case 3:
            //     arr[3] = 'x';
            //     break;
            // case 4:
            //     arr[4] = 'x';
            //     break;
            // case 5:
            //     arr[5] = 'x';
            //     break;
            // case 6:
            //     arr[6] = 'x';
            //     break;
            // case 7:
            //     arr[7] = 'x';
            //     break;
            // case 8:
            //     arr[8] = 'x';
            //     break;
            // default:
            //     break;
            // }



            printboard(arr);

            if(win(arr) == 1) {
                if(!turn) {
                    cout << "Player 1 wins!\n";
                } else {
                    cout << "Player 2 wins\n";
                }
                return 0;
            }

            turn = !turn;
        }
    }
}