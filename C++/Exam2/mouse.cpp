#include "mouse.h"
#include <iostream>

    Mouse::Mouse()
    {
        Breed = "";
        Weight = 0.00;
        Name = "";
        Gender = ' ';
        FavoriteFood = "";
        ColorDescription = "";
        OtherComments = "";
    }

    Mouse::Mouse(string breed, float weight, string name, char gender, string favoriteFood, string colorDescription, string otherComments)
    {
        Breed = breed;
        Weight = weight;
        Gender = gender;
        FavoriteFood = favoriteFood;
        ColorDescription = colorDescription;
        OtherComments = otherComments;
    }
    //Get fucntions
    string Mouse::GetBreed()
    {
        return Breed;
    }
    float Mouse::GetWeight()
    {
        return Weight;
    }
    string Mouse::GetName()
    {
        return Name;
    }
    char Mouse::GetGender()
    {
        return Gender;
    }
    string Mouse::GetFavoriteFood()
    {
        return FavoriteFood;
    }
    string Mouse::GetColorDescription()
    {
        return ColorDescription;
    }
    string Mouse::GetOtherComments()
    {
        return OtherComments;
    }

    //Set Functions
    void Mouse::SetBreed(string breed)
    {
        Breed = breed;
    }
    void Mouse::SetWeight(float weight)
    {
        Weight = weight;
    }
    void Mouse::SetName(string name)
    {
        Name = name;
    }
    void Mouse::SetGender(char gender)
    {
        Gender = gender;
    }
    void Mouse::SetFavoriteFood(string favoriteFood)
    {
        FavoriteFood = favoriteFood;
    }
    void Mouse::SetColorDescription(string colorDescription)
    {
        ColorDescription = colorDescription;
    }
    void Mouse::SetOtherComments(string otherComments)
    {
        OtherComments = otherComments;
    }

    void Mouse::printInfo()
    {
        cout << "Mouse Name: " << GetName() << endl;
        cout << "Gender: " << GetGender() << "\tWeight: " << GetWeight() << endl;
        cout << "Breed: " << GetBreed() << "\tColor Description: " << GetColorDescription() << endl;
        cout << "Favorite Food: " << GetFavoriteFood() << "\tOther Comments: " << GetOtherComments() << endl;
    }
