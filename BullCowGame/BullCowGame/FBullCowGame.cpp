//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by kc mee on 3/5/18.
//  Copyright © 2018 kc mee. All rights reserved.
//

#include "FBullCowGame.hpp"
#include <map>
#define TMap std::map

using int32 = int;
using FString = std::string;

FBullCowGame::FBullCowGame() { Reset(); } // default constructor

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const
{
    TMap<int32,int32> WordLengthToMaxTries {{3,4}, {4,7}, {5,10}, {6,15}, {7,20}};
    return WordLengthToMaxTries[MyHiddenWord.length()];
}

void FBullCowGame::Reset()
{
    
    const FString HIDDEN_WORD = "plane";
    MyHiddenWord = HIDDEN_WORD;
    
    MyCurrentTry = 1;
    bGameIsWon = false;
    return;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    if (!IsIsogram(Guess)) // if the guess isn't an isogram
    {
        return EGuessStatus::Not_Isogram;
    }
    else if (!IsLowercase(Guess)) // if the guess isn't all lowercase
    {
        return EGuessStatus::Not_Lowercase;
    }
    else if (Guess.length() != GetWordLength()) // if guess length is wrong
    {
        return EGuessStatus::Wrong_Length;
    }
    else
    {
        return EGuessStatus::OK;
    }
    
}


// receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
    MyCurrentTry++;
    
    FBullCowCount BullCowCount;
    int32 WordLength = MyHiddenWord.length(); // assuming same length as guess
    
    // loop through all letters in the hidden word
    for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
    {
        // compare letters against guess
        for (int32 GChar = 0; GChar < WordLength; GChar++)
        {
            // if they match then
            if (Guess[MHWChar] == MyHiddenWord[GChar])
            {
                if (MHWChar == GChar) //if they're in the same place
                {
                    BullCowCount.Bulls++; // increment bulls
                }
                // else
                else
                {
                    BullCowCount.Cows++; // increment cows
                }
            }
        }
    }
    if (BullCowCount.Bulls == WordLength)
    {
        bGameIsWon = true;
    }
    else
    {
        bGameIsWon = false;
    }
    return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
    // treat 0 and 1 letter words as isograms
    if (Word.length() <= 1) { return true; }
    
    TMap<char, bool> LetterSeen; // setup our map
    for (auto Letter : Word)     // for all letters of the word
    {
        Letter = tolower(Letter); //handle mixed case
        
        // if the letter is in the map
        if (LetterSeen[Letter])
        {
            return false; // we do NOT have an isogram
        }
        else
        {
            LetterSeen[Letter] = true; // add the letter to the map as seen
        }
    }
    
    return true; // for example in case where /0 is entered
}

bool FBullCowGame::IsLowercase(FString Word) const
{
    if (Word.length() <= 1) { return true; }
    
    for (auto Letter : Word)
    {
        if(!islower(Letter))
        {
            return false;
        }
    }
    
    return true;
}




