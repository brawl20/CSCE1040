#ifndef MOVIECOLLECTION_H
#define MOVIECOLLECTION_H

#include <string>
#include <iostream>
#include "Movie.h"
#include <vector>

using namespace std;

class MovieCollection : public Movie
{
    void addMovie(); // Add a Movie to the collection
    void editMovie(); // Edit Movie information if Movie is in the collection
    void deleteMovie(); // Delete a specific Movie
    void findMovie(); // Search for a specific Movie
    void printMovieInfo(); // Print all the info for a specific Movie
    void printCollectionEntries(); // Print ALL of the Movies.
    void moviesLoaned(); // Print a list of all Loans for a Particular Movie
    void printAllLoans(); // Print a list of all Active (future and current) Loans, all completed Loans and all Overdue or lost Loans
};



#endif