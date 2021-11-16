#ifndef MOUSEH
#define MOUSEH

#include <string>

using namespace std;
class Mouse 
{
    private:
    string Breed;
    float Weight;
    string Name;
    char Gender;
    string FavoriteFood;
    string ColorDescription;
    string OtherComments;

    public:
    // Constructors
    Mouse();
    Mouse(string breed, float weight, string name, char gender, string favoriteFood, string colorDescription, string otherComments);
    
    //Get fucntions
    string GetBreed();
    float GetWeight();
    string GetName();
    char GetGender();
    string GetFavoriteFood();
    string GetColorDescription();
    string GetOtherComments();

    //Set Functions
    void SetBreed(string breed);
    void SetWeight(float weight);
    void SetName(string name);
    void SetGender(char gender);
    void SetFavoriteFood(string favoriteFood);
    void SetColorDescription(string colorDescription);
    void SetOtherComments(string otherComments);
    void printInfo();
};
#endif