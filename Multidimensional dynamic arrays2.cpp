#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;




//2
void showGrid(const vector<char>& grid) {
    cout << "\n " << grid[0] << " | " << grid[1] << " | " << grid[2] << " \n"
        << "---|---|---\n"
        << " " << grid[3] << " | " << grid[4] << " | " << grid[5] << " \n"
        << "---|---|---\n"
        << " " << grid[6] << " | " << grid[7] << " | " << grid[8] << " \n\n";
}

bool hasWinner(const vector<char>& grid, char activePlayer) {
    int winLines[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };

    for (int i = 0; i < 8; ++i) {
        if (grid[winLines[i][0]] == activePlayer &&
            grid[winLines[i][1]] == activePlayer &&
            grid[winLines[i][2]] == activePlayer) {
            return true;
        }
    }
    return false;
}

bool isTie(const vector<char>& grid) {
    for (int i = 0; i < 9; ++i) {
        if (grid[i] != 'X' && grid[i] != 'O') {
            return false;
        }
    }
    return true;
}



int main() {

//1
    srand(time(0));

    string input;
    cout << "Введіть пароль: ";
    cin >> input;

    vector<char> password(input.begin(), input.end());

    int length = password.size();
    bool has_lower = false;
    bool has_upper = false;
    bool has_digit = false;
    bool has_special = false;
    bool all_same = true;

    for (int i = 0; i < length; ++i) {
        if (password[i] != password[0]) {
            all_same = false;
        }

        if (islower(password[i])) has_lower = true;
        else if (isupper(password[i])) has_upper = true;
        else if (isdigit(password[i])) has_digit = true;
        else has_special = true;
    }

    bool is_reliable = true;

    if (length < 6) {
        is_reliable = false;
    }
    else if (all_same) {
        is_reliable = false;
    }
    else if (has_digit && !has_lower && !has_upper && !has_special) {
        is_reliable = false; 
    }
    else if (has_lower && !has_upper && !has_digit && !has_special) {
        is_reliable = false;
    }
    else if (has_upper && !has_lower && !has_digit && !has_special) {
        is_reliable = false; 
    }
    else if (!(has_lower && has_upper && has_digit && has_special)) {
        is_reliable = false;
    }

    if (is_reliable) {
        cout << "Пароль надійний!" << endl;
    }
    else {
        cout << "Пароль ненадійний!" << endl;

        string lowers = "abcdefghijklmnopqrstuvwxyz";
        string uppers = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string digits = "0123456789";
        string specials = "!@#$%^&*()-_=+";

        vector<char> GenPass;

        GenPass.push_back(lowers[rand() % lowers.length()]);
        GenPass.push_back(uppers[rand() % uppers.length()]);
        GenPass.push_back(digits[rand() % digits.length()]);
        GenPass.push_back(specials[rand() % specials.length()]);

        string all_chars = lowers + uppers + digits + specials;
        for (int i = 0; i < 4; ++i) {
            GenPass.push_back(all_chars[rand() % all_chars.length()]);
        }

        cout << "Згенерований надійний пароль: ";
        for (int i = 0; i < GenPass.size(); ++i) {
            cout << GenPass[i];
        }
        cout << endl;
    }




    //2
    char keepPlaying = 'y';

    while (keepPlaying == 'y' || keepPlaying == 'Y') {
        vector<char> grid = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        char activePlayer = 'X';
        bool isFinished = false;

        while (!isFinished) {
            showGrid(grid);
            int slot;
            cout << "Player " << activePlayer << ", enter cell number (1-9): ";
            cin >> slot;

            int idx = slot - 1;

            if (slot < 1 || slot > 9 || grid[idx] == 'X' || grid[idx] == 'O') {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            grid[idx] = activePlayer;

            if (hasWinner(grid, activePlayer)) {
                showGrid(grid);
                cout << "Congratulations! Player " << activePlayer << " wins!\n";
                isFinished = true;
            }
            else if (isTie(grid)) {
                showGrid(grid);
                cout << "It's a tie!\n";
                isFinished = true;
            }
            else {
                if (activePlayer == 'X') {
                    activePlayer = 'O';
                }
                else {
                    activePlayer = 'X';
                }
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> keepPlaying;
    }

    cout << "Thank you for playing!" << endl;

    return 0;
}
