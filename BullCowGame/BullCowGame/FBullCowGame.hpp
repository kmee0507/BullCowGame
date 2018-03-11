//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by kc mee on 3/5/18.
//  Copyright © 2018 kc mee. All rights reserved.
//
#pragma once
#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>
#include <string>

#endif /* FBullCowGame_hpp */

using FString = std::string;
using int32 = int;

// all values initialized to zero
struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EGuessStatus
{
    Invalid_Status,
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase
};


class FBullCowGame
{
public:
    FBullCowGame(); // constructor
    
    int32 GetMaxTries() const; // const after every getter!!!!
    int32 GetCurrentTry() const;
    int32 GetWordLength() const;
    bool IsGameWon() const; // if is question use const
    EGuessStatus CheckGuessValidity(FString) const;

    void Reset();
    FBullCowCount SubmitValidGuess(FString);
    

private:
    // see constructor for initialization
    int32 MyCurrentTry;
    FString MyHiddenWord;
    bool bGameIsWon;
    
    bool IsIsogram(FString) const;
    bool IsLowercase(FString) const;
    
};

