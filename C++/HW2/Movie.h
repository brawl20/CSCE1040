#ifndef MOVIE_H
#define MOVIE_H

/*
	Author:			Micheal Landsbaum (MichealLandsbaum@my.unt.edu)
	Date:			11/16/2021
	Course:         CSCE1040
	Assignment:     Homework 3
*/

#include <string>
#include <iostream>

using namespace std;

class Movie
{
    public:

    //Default Constructor
    Movie();
    
    //Parameterized Constructor
    Movie(int movieID, string movieTitle, string releaseDate, string rating, string duration, string rentalCost, string replacementCost);

    //Accessors
    int GetmovieID();
    string GetmovieTitle();
    string GetreleaseDate();
    string Getrating();
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
    string movieTitle;
    string releaseDate;
    string rating;
    string duration;
    string rentalCost;
    string replacementCost;
};

#endif