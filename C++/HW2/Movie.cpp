#include "Movie.h"
#include <iostream>
#include <string>

using namespace std;

//Default Constructor
Movie::Movie()
{
    Movie::movieID = 000000;
    Movie::movieTitle = "None";
    Movie::releaseDate = "00/0000";
    Movie::rating = "None";
    Movie::duration = "00:00";
    Movie::rentalCost = "$0.00";
    Movie::replacementCost = "$0.00";
}

//Parameterized Constructor
Movie::Movie(int movieID, string movieTitle, string releaseDate, string rating, string duration, string rentalCost, string replacementCost)
{
    Movie::movieID = movieID;
    Movie::movieTitle = movieTitle;
    Movie::releaseDate = releaseDate;
    Movie::rating = rating;
    Movie::duration = duration;
    Movie::rentalCost = rentalCost;
    Movie::replacementCost = replacementCost;
}

//Accessors
int Movie::GetmovieID()
{
    return movieID;
}
string Movie::GetmovieTitle()
{
    return movieTitle;
}
string Movie::GetreleaseDate()
{
    return releaseDate;
}
string Movie::Getrating()
{
    return rating;
}
string Movie::Getduration()
{
    return duration;
}
string Movie::GetrentalCost()
{
    return rentalCost;
}
string Movie::GetreplacementCost()
{
    return replacementCost;
}

// //Mutators
void Movie::SetmovieID(int movieID)
{
    Movie::movieID = movieID;
}
void Movie::SetmovieTitle(string movieTitle)
{
    Movie::movieTitle = movieTitle;
}
void Movie::SetreleaseDate(string releaseDate)
{
    Movie::releaseDate = releaseDate;
}
void Movie::Setrating(string rating)
{
    Movie::rating = rating;
}
void Movie::Setduration(string duration)
{
    Movie::duration = duration;
}
void Movie::SetrentalCost(string rentalCost)
{
    Movie::rentalCost = rentalCost;
}
void Movie::SetreplacementCost(string replacementCost)
{
    Movie::replacementCost = replacementCost;
}