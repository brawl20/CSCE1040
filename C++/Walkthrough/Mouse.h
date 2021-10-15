#ifndef MOUSEH
#define MOUSEH

#include <string>

using namespace std;
class Mouse
{
    private:
    enum Gender {Unknown, Female, Male};
    string Breed;
    float Weight;
    string Name;
    Gender gender;
    string Favorite_food; 
    string Color_description; 
    string Other_Comments;

    public:
    //Constructor
    Mouse();

    Mouse(string Breed, float Weight, string Name, Gender gender, string Favorite_food, string Color_description, string Other_Comments);

    // Setters
    void SetBreed(string breed);
    void SetWeight(float weight);
    void SetName(string name);
    void SetGender(char userChar);
    void SetFavoriteFood(string favoriteFood);
    void SetColorDescription(string colorDescription);
    void SetOtherComments(string otherComments);

    // Getters
    string GetBreed() const;
    float GetWeight() const;
    string GetName() const;
    char GetGender() const;
    string GetFavoriteFood() const;
    string GetColorDescription() const;
    string GetOtherComments() const;

    //print fucntion
    void printInfo() const;
};
#endif