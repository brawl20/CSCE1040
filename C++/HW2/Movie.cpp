#include "Movie.h"
#include <iostream>
#include <string>

using namespace std;

//Default Constructor
Movie::Movie()
{
    Movie::movieID = 000000;
    for(int i = 0; i < 40; i++)
    {
        Movie::movieTitle[i] = ' ';
    }
    Movie::releaseDate = "00/0000";
    for(int i = 0; i < 20; i++)
    {
        Movie::rating[i] = ' ';
    }
    Movie::duration = "00:00";
    Movie::rentalCost = "$0.00";
    Movie::replacementCost = "$0.00";
}

//Parameterized Constructor
//Movie::Movie(int movieID, char movieTitle, string releaseDate, char rating, string duration, string rentalCost, string replacementCost);

//Accessors
// int Movie::GetmovieID();
// char Movie::GetmovieTitle();
// string Movie::GetreleaseDate();
// char Movie::Getrating();
// string Movie::Getduration();
// string Movie::GetrentalCost();
// string Movie::GetreplacementCost();

// //Mutators
// void Movie::SetmovieID(int movieID);
// void Movie::SetmovieTitle(char movieTitle);
// void Movie::SetreleaseDate(string releaseDate);
// void Movie::Setrating(char rating[]);
// void Movie::Setduration(string duration);
// void Movie::SetrentalCost(string rentalCost);
// void Movie::SetreplacementCost(string replacementCost);