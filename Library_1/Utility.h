
/**
 * @file UtilityLibrary.h
 * @author Abdulrahman Faisal
 * @brief A comprehensive, flexible C++ Utility Library for common programming tasks.
 *
 * @details
 * This library is designed to provide a collection of reusable functions covering:
 * - Advanced Math Operations (Perfect numbers, Palindromes, Prime checks).
 * - Array Manipulation (Shuffling, Copying, Filtering, Statistics).
 * - String & Text Processing (Caesar Cipher Encryption/Decryption).
 * - Random Generation (Numbers, Characters, and Secure-style Keys).
 *
 * @note
 * FLEXIBILITY: This library was built with a modular and flexible approach.
 * Each function is independent, making it very easy to modify, extend, or
 * integrate into any C++ project. You can easily adapt the logic to fit
 * specific requirements.
 *
 * @version 1.0
 * @date 2026-05-03
 */





#pragma once

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/**
 * @namespace utility
 * @brief A collection of helper functions for math, array manipulation, and text processing.
 */
namespace utility
{

    /**
     * @brief Prompts the user to enter a positive number and validates the input.
     * @param Message The string message to display to the user.
     * @return int A validated positive integer.
     */
    int ReadPositiveNumber(string Message)
    {
        int Number = 0;
        do
        {
            cout << Message;
            cin >> Number;
        } while (Number <= 0);
        return Number;
    }

    /**
     * @brief Checks if a number is a "Perfect Number" (sum of divisors equals the number).
     * @param Number The integer to check.
     * @return bool True if perfect, false otherwise.
     */
    bool isPerfectNumber(int Number)
    {
        int Sum = 0;
        for (int i = 1; i < Number; i++)
        {
            if (Number % i == 0)
            {
                Sum += i;
            }
        }
        return Number == Sum;
    }

    /**
     * @brief Iterates from 1 to the given limit and prints all perfect numbers found.
     * @param number The upper limit for the search.
     */
    void PrintResults(int number)
    {
        for (int i = 1; i <= number; i++)
        {
            if (isPerfectNumber(i))
                cout << i << " is Perfect Number\n";
        }
    }

    /**
     * @brief Decomposes a number and prints its individual digits in reverse order.
     * @param Number The integer to process.
     */
    void PrintDigits(int Number)
    {
        int Remainder = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            cout << Remainder << endl;
        }
    }

    /**
     * @brief Reverses the order of digits in a given number.
     * @param Number The integer to reverse.
     * @return int The reversed integer result.
     */
    int ReverseNumber(int Number)
    {
        int Remainder = 0, Number2 = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            Number2 = Number2 * 10 + Remainder;
        }
        return Number2;
    }

    /**
     * @brief Counts how many times a specific digit appears within a number.
     * @param DigitToCheck The single digit (0-9) to look for.
     * @param Number The integer to search within.
     * @return int Total frequency of the digit.
     */
    int CountDigitFrequency(short DigitToCheck, int Number)
    {
        int FreqCount = 0, Remainder = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;

            if (DigitToCheck == Remainder)
            {
                FreqCount++;
            }
        }
        return FreqCount;
    }

    /**
     * @brief Prints the frequency of each digit (0-9) found in the given number.
     * @param Number The integer to analyze.
     */
    void PrintAllDigitsNumbrs(int Number)
    {
        for (int i = 0; i < 10; i++)
        {
            short DigitFrequency = 0;
            DigitFrequency = CountDigitFrequency(i, Number);

            if (DigitFrequency > 0)
            {
                cout << "Digit " << i << " Frequency "
                     << DigitFrequency << " Time(s)." << endl;
            }
        }
    }

    /**
     * @brief Checks if a number reads the same forwards and backwards.
     * @param Number The integer to check.
     * @return bool True if it is a palindrome.
     */
    bool IsPalindromeNumber(int Number)
    {
        return Number == ReverseNumber(Number);
    }

    /**
     * @brief Prints a letter pattern (A, BB, CCC...) up to N levels.
     * @param Number Total number of levels in the pattern.
     */
    void PrintPatternLetter(int Number)
    {
        cout << "\n";
        for (int i = 65; i <= 65 + Number - 1; i++)
        {
            for (int j = 1; j <= i - 65 + 1; j++)
            {
                cout << char(i);
            }
            cout << "\n";
        }
    }

    /**
     * @brief Prints an inverted letter pattern starting from a specific depth.
     * @param Number Total levels for the inverted pattern.
     */
    void PrintInvertedLetterPattern(int Number)
    {
        cout << "\n";
        for (int i = 65 + Number - 1; i >= 65; i--)
        {
            for (int j = 1; j <= Number - (65 + Number - 1 - i); j++)
            {
                cout << char(i);
            }
            cout << "\n";
        }
    }

    /**
     * @brief Generates and prints all possible 3-letter combinations from AAA to ZZZ.
     */
    void PrintWordFromAAAtoZZZ()
    {
        string word = "";
        for (int i = 65; i <= 90; i++)
        {
            for (int j = 65; j <= 90; j++)
            {
                for (int k = 65; k <= 90; k++)
                {
                    word = word + char(i);
                    word = word + char(j);
                    word = word + char(k);
                    cout << word << endl;
                    word = "";
                }
            }
            cout << "\n____________________________\n";
        }
    }

    /**
     * @brief Reads a 3-letter capital password from the console.
     * @return string The password entered by the user.
     */
    string ReadPassword()
    {
        string Password;
        cout << "Please enter a 3-Letter Password (all capital)?\n";
        cin >> Password;
        return Password;
    }

    /**
     * @brief Simulates a brute-force attack to guess a 3-letter uppercase password.
     * @param OriginalPassword The password to be cracked.
     * @return bool Returns true when the password is found.
     */
    bool GuessPassword(string OriginalPassword)
    {
        string word = "";
        int Counter = 0;

        for (int i = 65; i <= 90; i++)
        {
            for (int j = 65; j <= 90; j++)
            {
                for (int k = 65; k <= 90; k++)
                {
                    Counter++;
                    word = word + char(i);
                    word = word + char(j);
                    word = word + char(k);

                    cout << "Trial [" << Counter << "] : " << word << endl;

                    if (word == OriginalPassword)
                    {
                        cout << "password is " << word << endl;
                        cout << "Found after " << Counter << " Trail(s)";
                        return true;
                    }

                    word = "";
                }
            }
        }
        return false;
    }

    /**
     * @brief Reads a line of text from the user input.
     * @return string The complete string entered by the user.
     */
    string ReadText()
    {
        string Text;
        cout << "Please enter Text\n";
        getline(cin, Text);
        return Text;
    }

    /**
     * @brief Simple Caesar cipher encryption by shifting character ASCII values.
     * @param Text The original text.
     * @param EncryptionKey Shifting value.
     * @return string The encrypted text.
     */
    string EncryptText(string Text, short EncryptionKey)
    {
        for (int i = 0; i <= Text.length() - 1; i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);
        }
        return Text;
    }

    /**
     * @brief Decrypts text encrypted by the EncryptText function.
     * @param Text The encrypted text.
     * @param EncryptionKey Shifting value used for encryption.
     * @return string The original decrypted text.
     */
    string DecryptText(string Text, short EncryptionKey)
    {
        for (int i = 0; i <= Text.length() - 1; i++)
        {
            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text;
    }

    /**
     * @brief Generates a random integer within a specified range.
     * @param From Lower bound.
     * @param To Upper bound.
     * @return int The random integer result.
     */
    int RandomNumber(int From, int To)
    {
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    /**
     * @brief Prints the header and horizontal line for the multiplication table.
     */
    void PrintTableHeader()
    {
        cout << "\n\n\t\t\t Multiplication Table From 1 to 10\n\n";
        cout << "\t";
        for (int i = 1; i <= 10; i++)
        {
            cout << i << "\t";
        }
        cout << "\n___________________________________________________________________________________\n";
    }

    /**
     * @brief Helper to format the column separator in the multiplication table.
     * @param i The current index.
     * @return string Formatted separator.
     */
    string ColumSperator(int i)
    {
        if (i < 10)
            return "  |";
        else
            return " |";
    }

    /**
     * @brief Generates and prints a full 10x10 multiplication table.
     */
    void TableMultiplication()
    {
        PrintTableHeader();
        for (int i = 1; i <= 10; i++)
        {
            cout << " " << i << ColumSperator(i) << "\t";
            for (int j = 1; j <= 10; j++)
            {
                cout << i * j << "\t";
            }
            cout << endl;
        }
    }

    /**
     * @enum enCharType
     * @brief Categorization of characters for generation purposes.
     */
    enum enCharType
    {
        SamallLetter = 1,
        CapitalLetter = 2,
        SpecialCharacter = 3,
        Digit = 4
    };

    /**
     * @brief Generates a single random character based on the specified type.
     * @param CharType The category of character needed.
     * @return char A random character from that category.
     */
    char GetRandomCharacter(enCharType CharType)
    {
        switch (CharType)
        {
        case enCharType::SamallLetter:
            return char(RandomNumber(97, 122));

        case enCharType::CapitalLetter:
            return char(RandomNumber(65, 90));

        case enCharType::SpecialCharacter:
            return char(RandomNumber(33, 47));

        case enCharType::Digit:
            return char(RandomNumber(48, 57));
        }
        return 0;
    }

    /**
     * @brief Generates a random string (word) of a given length and character type.
     * @param CharType Type of characters to include.
     * @param Length Length of the generated word.
     * @return string The random word.
     */
    string GenerateWord(enCharType CharType, int Length)
    {
        string word;
        for (int i = 1; i <= Length; i++)
        {
            word += GetRandomCharacter(CharType);
        }
        return word;
    }

    /**
     * @brief Generates a formatted license key (XXXX-XXXX-XXXX-XXXX).
     * @return string The generated key.
     */
    string GenerateKey()
    {
        string Key = "";
        Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key += GenerateWord(enCharType::CapitalLetter, 4);
        return Key;
    }

    /**
     * @brief Generates and prints a specified number of unique keys.
     * @param Number Total number of keys to generate.
     */
    void GenerateKeys(short Number)
    {
        for (int i = 1; i <= Number; i++)
        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey() << endl;
        }
    }

    /**
     * @brief Reads array length and elements from user input.
     * @param arr The array to fill.
     * @param arrLength Reference to store the number of elements.
     */
    void ReadArray(int arr[100], int &arrLength)
    {
        cout << "\nPlease Enter Array Length: ";
        cin >> arrLength;
        cout << "\nEnter array elements: \n";
        for (int i = 0; i < arrLength; i++)
        {
            cout << "Element [" << i + 1 << "] : ";
            cin >> arr[i];
        }
    }

    /**
     * @brief Outputs all elements of an integer array.
     * @param arr The array to print.
     * @param arrLength Number of elements.
     */
    void PrintArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            cout << arr[i] << " ";
        }
    }

    /**
     * @brief Counts the occurrence of a specific number in an array.
     * @param Number Value to search for.
     * @param arr The array to search in.
     * @param arrLength Number of elements.
     * @return int Frequency count.
     */
    int TimesRepeated(int Number, int arr[100], int arrLength)
    {
        int Count = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (Number == arr[i])
            {
                Count++;
            }
        }
        return Count;
    }

    /**
     * @brief Populates an array with random integers (1 to 100).
     * @param arr Array to be filled.
     * @param arrLength Reference to the length determined by the user.
     */
    void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
    {
        cout << "Enter number of elements: ";
        cin >> arrLength;

        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = RandomNumber(1, 100);
        }
    }

    /**
     * @brief Finds the largest value in an integer array.
     * @param arr The array to check.
     * @param arrLength Number of elements.
     * @return int The maximum value found.
     */
    int MaxNumberInArray(int arr[100], int arrLength)
    {
        int Max = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] > Max)
                Max = arr[i];
        }
        return Max;
    }

    /**
     * @brief Finds the smallest value in an integer array.
     * @param arr The array to check.
     * @param arrLength Number of elements.
     * @return int The minimum value found.
     */
    int MinNumberInArray(int arr[100], int arrLength)
    {
        int Min = arr[0];
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] < Min)
                Min = arr[i];
        }
        return Min;
    }

    /**
     * @brief Calculates the sum of all elements in an integer array.
     * @param arr The array to sum.
     * @param arrLength Number of elements.
     * @return int Total sum.
     */
    int SumArray(int arr[100], int arrLength)
    {
        int Sum = 0;
        for (int i = 0; i < arrLength; i++)
        {
            Sum += arr[i];
        }
        return Sum;
    }

    /**
     * @brief Calculates the arithmetic average of an integer array.
     * @param arr The array.
     * @param arrLength Number of elements.
     * @return float Calculated average.
     */
    float ArrayAverage(int arr[100], int arrLength)
    {
        return (float)SumArray(arr, arrLength) / arrLength;
    }

    /**
     * @brief Copies elements from one array to another.
     * @param arrSource Original array.
     * @param arrDestination Target array.
     * @param arrLength Number of elements.
     */
    void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arrDestination[i] = arrSource[i];
        }
    }

    /**
     * @enum enPrimeNotPrime
     * @brief Enum for prime number validation.
     */
    enum enPrimeNotPrime
    {
        Prime = 1,
        NotPrime = 2
    };

    /**
     * @brief Validates if a number is prime.
     * @param Number Integer to check.
     * @return enPrimeNotPrime Results as an enum type.
     */
    enPrimeNotPrime CheckPrimeNumber(int Number)
    {
        int halfNumber = round(Number / 2);
        for (int i = 2; i <= halfNumber; i++)
        {
            if (Number % i == 0)
                return enPrimeNotPrime::NotPrime;
        }
        return enPrimeNotPrime::Prime;
    }

    /**
     * @brief Swaps the values of two integers using references.
     * @param A First integer.
     * @param B Second integer.
     */
    void Swap(int &A, int &B)
    {
        int Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    /**
     * @brief Randomly shuffles the elements within an array.
     * @param arr The array to shuffle.
     * @param arrLength Number of elements.
     */
    void ShuffleArry(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }

    /**
     * @brief Copies elements from source to destination in reverse order.
     * @param arrSource Original array.
     * @param arrDestination Reversed copy.
     * @param arrLength Number of elements.
     */
    void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
    {
        int Counter = arrLength;
        for (int i = 0; i < arrLength; i++)
        {
            arrDestination[i] = arrSource[arrLength - 1 - i];
        }
    }

    /**
     * @brief Prints a string array with formatted keys/indices.
     * @param arr String array to print.
     * @param arrLength Number of elements.
     */
    void PrintStringArray(string arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            cout << "Key [" << i << "] : ";
            cout << arr[i] << "\n";
        }
    }

    /**
     * @brief Fills a string array with randomly generated license keys.
     * @param arr String array to fill.
     * @param Number Number of keys to generate.
     */
    void FillArrayWithKeys(string arr[100], short Number)
    {
        for (int i = 0; i < Number; i++)
        {
            arr[i] = GenerateKey();
        }
    }

    /**
     * @brief Searches for a number and returns its index.
     * @param Number Value to find.
     * @param arr Array to search.
     * @param arrLength Number of elements.
     * @return short The index position or -1 if not found.
     */
    short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] == Number)
                return i;
        }
        return -1;
    }

    /**
     * @brief Checks existence of a number in an array.
     * @param Number Value to check.
     * @param arr Array to search.
     * @param arrLength Number of elements.
     * @return bool True if exists.
     */
    bool IsNumberInArray(int Number, int arr[100], int arrLength)
    {
        return FindNumberPositionInArray(Number, arr, arrLength) != -1;
    }

    /**
     * @brief Appends a new element to the end of an array.
     * @param Number Value to add.
     * @param arr The array.
     * @param arrLength Reference to current array length (will be incremented).
     */
    void AddArrayElement(int Number, int arr[100], int &arrLength)
    {
        arrLength++;
        arr[arrLength - 1] = Number;
    }

    /**
     * @brief Interactive loop to allow users to populate an array dynamically.
     * @param arr Array to fill.
     * @param arrLength Reference to length.
     */
    void InputUserNumbersInArray(int arr[100], int &arrLength)
    {
        bool addMore;
        do
        {
            AddArrayElement(ReadPositiveNumber("Do you want to add more numbers?[0]:No,[1]=yes? "), arr, arrLength);
            cin >> addMore;
        } while (addMore);
    }

    /**
     * @brief Copies an array by appending elements one by one.
     */
    void CopyArrayUsingAddArrayElement(int arrSource[100], int arrDestination[100], int arrLength, int &arrDestinationLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
        }
    }

    /**
     * @brief Filters and copies only odd numbers from source to destination.
     */
    void CopyOddNumbers(int arrSource[100], int arrDestination[100], int arrLength, int &arrDestinationLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            if (arrSource[i] % 2 != 0)
                AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
        }
    }

    /**
     * @brief Filters and copies only prime numbers from source to destination.
     */
    void CopyOnlyPrimaryNumbers(int arrSource[100], int arrDestination[100], int arrLength, int &arrDestinationLength)
    {
        int Counter = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (CheckPrimeNumber(arrSource[i]) == enPrimeNotPrime::Prime)
            {
                AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
            }
        }
    }

    /**
     * @brief Counts the number of odd integers in an array.
     * @return int Count of odd numbers.
     */
    int OddCount(int arr[100], int arrLength)
    {
        int Counter = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] % 2 != 0)
            {
                Counter++;
            }
        }
        return Counter;
    }

    /**
     * @brief Counts the number of even integers in an array.
     * @return int Count of even numbers.
     */
    int EvenCount(int arr[100], int arrLength)
    {
        int Counter = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] % 2 == 0)
            {
                Counter++;
            }
        }
        return Counter;
    }

    /**
     * @brief Counts positive integers (> 0) in an array.
     * @return int Count of positive numbers.
     */
    int PositiveCount(int arr[100], int arrLength)
    {
        int Counter = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] > 0)
            {
                Counter++;
            }
        }
        return Counter;
    }

    /**
     * @brief Counts negative integers (< 0) in an array.
     * @return int Count of negative numbers.
     */
    int NegativeCount(int arr[100], int arrLength)
    {
        int Counter = 0;
        for (int i = 0; i < arrLength; i++)
        {

            if (arr[i] < 0)
            {
                Counter++;
            }
        }
        return Counter;
    }

    /**
     * @brief Returns the absolute value of a floating-point number.
     * @param number The input value.
     * @return float The non-negative result.
     */
    float Myabs(float number)
    {
        if (number > 0)
            return number;
        else
            return number * -1;
    }

    /**
     * @brief Extracts the fractional part of a floating-point number.
     * @param Number The input value.
     * @return float Only the digits after the decimal point.
     */
    float GetFractionPart(float Number)
    {
        return Number - (int)Number;
    }

    /**
     * @brief Custom implementation of the round() function.
     * @param number The value to round.
     * @return int The rounded integer.
     */
    int MyRoundMethod1(float number)
    {
        int IntPart;
        IntPart = (int)number;
        float FractionsPart = GetFractionPart(number);
        if (Myabs(FractionsPart) >= 0.5)
        {
            if (number > 0)
                return ++IntPart;
            else
                return --IntPart;
        }
        else
            return IntPart;
    }

    /**
     * @brief Custom implementation of the floor() function.
     * @param number The input value.
     * @return int The greatest integer less than or equal to the number.
     */
    int MyFloor(float number)
    {
        int intPart = (int)number;
        if (number >= 0 || number == intPart)
            return intPart;
        else
            return intPart - 1;
    }

    /**
     * @brief Custom implementation of the ceil() function.
     * @param Number The input value.
     * @return int The smallest integer greater than or equal to the number.
     */
    int MyCeilMethod1(float Number)
    {
        int IntPart = (int)Number;
        if (abs(GetFractionPart(Number)) > 0)
        {
            if (Number > 0)
                return IntPart + 1;
            else
                return IntPart;
        }
        else
            return IntPart;
    }

    /**
     * @brief Calculates the square root using the power function.
     * @param number Input value.
     * @return float Square root result.
     */
    float MySqrt(float number)
    {
        return pow(number, 0.5);
    }

}