// RomanNumConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>

using namespace std;

int RomanToInt(string s);
bool isValidRoman(string s);
string IntToRoman(int decimal);

int main()
{
    cout << "Welcome to the Roman Numeral converter!\n" <<
        "Please input an integer greater than 0 or a valid Roman Numeral\n" <<
        "To exit program type 0\n";

    while (true) {
        cout << endl;
        string input;
        cin >> input;

        int decimal = 0;
        //if input is in integer convert to Roman numeral
        try {
            decimal = stoi(input);
            //if input number is less than 1 we cannot convert
            if (decimal == 0) {
                cout << "Have a nice day!\n";
                return 0;
            }
            else if (decimal < 0) {
                cout << "Error integer must be larger than 0\nEnter 0 to quit";
            }
            else {
                cout << IntToRoman(decimal);
            }
        }
        //if input isn't decimal catch the exception and try converting from Roman to integer
        catch (invalid_argument const &e) {

            if (!isValidRoman(input)) {
                //if input isn't valid display error message
                cout << "Error, input is not a valid roman numeral according to our rules (see README)\nEnter 0 to quit.";
            }
            else {
                cout << RomanToInt(input);
            }
        }
    }

}

//method to convert Roman numeral to integer
int RomanToInt(string s) {
    int total = 0;
    //loop through each character of the string to convert each part of the roman numeral to integer
    for (int i = 0; i < s.length(); i++) {
        //Switch each character and check if next character is less than current.  If yes subtract, if no add.
        switch (s[i]) {
        case 'I':
            if (i < s.length() - 1 && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                total -= 1;
            }
            else {
                total += 1;
            }
            break;
        case 'V':
            if (i < s.length() - 1 && s[i + 1] == 'X') {
                total -= 5;
            }
            else {
                total += 5;
            }
            break;
        case 'X':
            if (i < s.length() - 1 && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                total -= 10;
            }
            else {
                total += 10;
            }
            break;
        case 'L':
            total += 50;
            break;
        case 'C':
            if (i < s.length() - 1 && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                total -= 100;
            }
            else {
                total += 100;
            }
            break;
        case 'D':
            total += 500;
            break;
        case 'M':
            total += 1000;
            break;
        }
    }
    return total;
}

//method to validate Roman numeral before converting (uses rules found online)
bool isValidRoman(string s) {
    int repeatCounter = 0;
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
        case 'I':
            /* rules for I
                * 'I' cannot repeat more than 3 times
                * 'I' can come before X, V, or I but nothing else
                */
            repeatCounter++;
            if (repeatCounter > 3) {
                return false;
            }
            if (i < s.length() - 1 && (s[i + 1] != 'I' && s[i + 1] != 'V' && s[i + 1] != 'X')) {
                return false;
            }
            break;
        case 'V':
            /* rules for V
                * 'V' cannot be repeated
                * 'V' can come before I but nothing else
                */
            repeatCounter++;
            if (repeatCounter > 1) {
                return false;
            }
            if (i < s.length() - 1 && s[i + 1] != 'I') {
                return false;
            }
            break;
        case 'X':
            /* rules for X
                * 'X' cannot repeat more than 3 times
                * 'X' can come before I, V, L, or C but not M or D
                */
            repeatCounter++;
            if (repeatCounter > 3) {
                return false;
            }
            if (i < s.length() - 1 && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                return false;
            }
            break;
        case 'L':
            /* rules for L
                * 'L' cannot repeat
                * 'L' can come before I, V, or X, but not C, D, or M
                */
            repeatCounter++;
            if (repeatCounter > 1) {
                return false;
            }
            if (i < s.length() - 1 && (s[i + 1] != 'I' && s[i + 1] != 'V' && s[i + 1] != 'X')) {
                return false;
            }
            break;
        case 'C':
            /* rules for C
                * 'C' cannot repeat more than 3 times
                * 'C' can come before anything
                */
            repeatCounter++;
            if (repeatCounter > 3) {
                return false;
            }
            break;
        case 'D':
            /* rules for D
                * 'D' cannot repeat
                * 'D' can come before I, V, X, or L, but not M
                */
            repeatCounter++;
            if (repeatCounter > 1) {
                return false;
            }
            if (i < s.length() - 1 && s[i + 1] == 'M') {
                return false;
            }
            break;
        case 'M':
            //Here we could add rules for M, but in order to include larger numbers we are allowing M to
            //be repeated more than 3 times, so it is an exception.  However the case needs to remain so
            //as to not trigger the default and return false
            break;
        case ' ':
            break;
        default:
            //any other letter is invalid
            return false;
        }

        //reset repeatCounter if need be
        if (i < s.length() - 1 && s[i] != s[i + 1]) {
            repeatCounter = 0;
        }
    }

    //if we made it here then roman numeral is valid return true
    return true;
}

//method to convert integer to Roman numeral
string IntToRoman(int input) {
    string rNum = "";

    //parse any 'M's out of the 1000 place
    for (int i = 0; i < input / 1000;) {
        rNum.append("M");
        input -= 1000;
    }
    //check for 900 case
    if (input / 900 == 1) {
        rNum.append("CM");
        input -= 900;
    }
    //check for 500 or 'D'
    if (input / 500 == 1) {
        rNum.append("D");
        input -= 500;
    }
    //check 400 case
    if (input / 400 == 1) {
        rNum.append("CD");
        input -= 400;
    }
    //parse any 'C's out of 100 place
    for (int i = 0; i < input / 100;) {
        rNum.append("C");
        input -= 100;
    }
    //check 90 case
    if (input / 90 == 1) {
        rNum.append("XC");
        input -= 90;
    }
    //check for 50 or 'L'
    if (input / 50 == 1) {
        rNum.append("L");
        input -= 50;
    }
    //check 40 case
    if (input / 40 == 1) {
        rNum.append("XL");
        input -= 40;
    }
    //parse 'X's out of 10 place
    for (int i = 0; i < input / 10;) {
        rNum.append("X");
        input -= 10;
    }
    //check 9 case
    if (input / 9 == 1) {
        rNum.append("IX");
        input -= 9;
    }
    //check for 5 or 'V'
    if (input / 5 == 1) {
        rNum.append("V");
        input -= 5;
    }
    //check 4 case
    if (input / 4 == 1) {
        rNum.append("IV");
        input -= 4;
    }
    //parse 'I's out of 1 place
    for (; input != 0; input--) {
        rNum.append("I");
    }

    return rNum;
}

