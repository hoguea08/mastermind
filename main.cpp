#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

void playGame();

int main()
{
    playGame();
    return 0;
}

///Implement this function
void playGame()
{
// Create a game where user must guess the correct pattern of random computer-generated numbers

//* Introduce game and basic instructions
cout << "Welcome to Mastermind!\n*************************" << endl << endl;

    //** Ask player to enter a difficulty 1-10 (difficulty indicates amount and range of numbers)
    int difficulty = 0;
    cout << "Enter a difficulty 1 - 10: ";

    //** Take in the difficulty input and tell player what number range to use for guesses
    cin >> difficulty;
    cout << "\nDifficulty = " << difficulty << endl;
    cout << "You will be trying to guess 4 numbers from 1 - " << difficulty << endl << endl;

//* Create a random pattern of numbers the user will guess
    //** Randomly generate numbers based on difficulty input using random number generator
        //*** Store random numbers in an array
        int randNums[difficulty] = {0};
        for (int i = 0; i < difficulty; i++)
        {
            randNums[i] = rand() % difficulty + 1;
        }

//* Ask player to start guessing the pattern
    //** Player gets 10 turns to guess the pattern
    int turn = 0;

    while (turn < 10)
    {
        //*** Print instructions on how to enter guesses (amount of numbers separated by spaces)
        cout << "\n\nTurn " << turn + 1 << " of 10 \n\nPlease enter " << difficulty << " numbers from 1 - " << difficulty << " separated by spaces:" << endl;

        //*** Store the player's guess in an array
        int guess[difficulty] = {0};
        for (int i = 0; i < difficulty; i++)
            {
            cin >> guess[i];
            }
        //*** For each turn, calculate how many guesses are in the correct position
        int correctPos = 0;
        for (int i = 0; i < difficulty; i++)
        {
            if (randNums[i]==guess[i])
                correctPos++;
        }
        //*** For each turn, calculate how many guesses are correct
        int correctGuess = 0;

            //**** Sort equivalent guess and random number arrays to find equivalent numbers
            int temp1, temp2;
            int sortNums[difficulty];
            int sortGuess[difficulty];

                //***** Make equivalent arrays
                for (int i = 0; i < difficulty; i++)
                {
                    sortNums[i] = randNums[i];
                    sortGuess[i] = guess[i];
                }
            //**** Use a sorting loop to arrange guess and random number arrays from smallest to largest
            for (int i = 0; i < difficulty; i++)
            {
                for (int j = 1; j < difficulty; j++)
                {
                    if (sortGuess[i] >= sortGuess[j])
                    {
                    temp1 = sortGuess[j];
                    sortGuess[j] = sortGuess[i];
                    sortGuess[i] = temp1;
                    }
                    if (sortNums[i] >= sortNums[j])
                    {
                    temp2 = sortNums[j];
                    sortNums[j] = sortNums[i];
                    sortNums[i] = temp2;
                    }
                }
            }

                //***** Determine if there are equivalent entries
                for (int i = 0; i < difficulty; i++)
                {
                    if(sortGuess[i] == sortNums[i])
                        correctGuess++;
                }
            //**** Print to screen the number of correct guesses and those in the correct position
            cout << "\n" << correctPos << " = number of guesses correct and in the correct position" << endl;
            cout << correctGuess - correctPos << " = number of guesses correct but in the wrong position" << endl;

        //*** Advance to next turn
        turn++;

        //*** If the pattern is guessed perfectly, print that the player has succeeded
        if (correctGuess == difficulty && correctPos == difficulty)
        {
            cout << "\n\nYou guessed the pattern! Great job!";
            turn = 12;
        }

        //*** If the player does not guess the correct pattern in 10 turns, print the number and that the player has lost
        if (turn == 10 && correctPos != difficulty)
        {
            cout << "\n\nI'm sorry, you lost. The number was: ";
            for (int i = 0; i < difficulty; i++)
                cout << randNums[i] << " ";
        }
    }
}

