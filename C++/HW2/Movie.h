#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>

using namespace std;

class Movie
{
    public:

    //Default Constructor
    Movie();
    
    //Parameterized Constructor
    Movie(int movieID, char movieTitle, string releaseDate, char rating, string duration, string rentalCost, string replacementCost);

    //Accessors
    int GetmovieID();
    char GetmovieTitle();
    string GetreleaseDate();
    char Getrating();
    string Getduration();
    string GetrentalCost();
    string GetreplacementCost();

    //Mutators
    void SetmovieID(int movieID);
    void SetmovieTitle(string movieTitle);
    void SetreleaseDate(string releaseDate);
    void Setrating(string rating);
    void Setduration(string duration);
    void SetrentalCost(string rentalCost);
    void SetreplacementCost(string replacementCost);

    private:
    int movieID;
    char movieTitle[40];
    string releaseDate;
    char rating[20];
    string duration;
    string rentalCost;
    string replacementCost;
};

#endif