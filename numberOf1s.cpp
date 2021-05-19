#include <iostream>
#include <string>
//Problem: Given a number, calculate how many 1s are in the decimal representations of all numbers up to and including the given number

//Challenge: Figure out when f(x) = x
int digits(int number) {
    //Returns the number of digits in a number
    int digits = 0;
    while (number != 0) {
        number /= 10;
        digits++;
    }
    return digits;
}
int numberOf1s(int number) {
    //This function returns the number of 1s that are in the number supplied as an arg
    //Pseudo code:
    //For every power of ten less than number:
    //If number % powerOfTen == 1 then that digit is a 1
    //so increment the return number
    int powerOfTen = 1;
    int numberOf1s = 0;
    while(powerOfTen <= number) {
        int temp = number / powerOfTen;
        if (temp % 10 == 1) {
            numberOf1s++;
        }
        powerOfTen *= 10;
    }
    return numberOf1s;
}
bool isNumber(std::string input) {
    for (int i = 0; i < input.length(); i++) {
        if (!isdigit(input[i])) {
            return false;
        }
    }
    return true;
}
int main() {
    std::string input;
    while (1) {
        int number = 0;
        std::cout << "What number do you want to calculate?\n";
        std::cin >> input;
        if (isNumber(input)) {
            number = std::stoi(input);
        } else {
            break;
        }
        int output = numberOf1s(number);
        std::cout << "The answer is: " << output << "\n";
    }
    return 0;
}