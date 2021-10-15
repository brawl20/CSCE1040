#include "Mouse.h"
#include <iostream>

using namespace std;

    Mouse::Mouse()
    {
        Breed = "";
        Weight = 0.00;
        Name = "";
        gender = Unknown;
        Favorite_food = "";
        Color_description = "";
        Other_Comments = "";
    }

    Mouse::Mouse(string Breed, float Weight, string Name, Gender gender, string Favorite_food, string Color_description, string Other_Comments)
    {
        Mouse::Breed = Breed;
        Mouse::Weight = Weight;
        Mouse::Name = Name;
        Mouse::gender = gender;
        Mouse::Favorite_food = Favorite_food;
        Mouse::Color_description = Color_description;
        Mouse::Other_Comments = Other_Comments;
    }

   
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
    void Mouse::SetGender(char userChar)
    {
        switch (userChar)
        {
        case 'f':
        case 'F':
            gender = Female;
        break;
        
        case 'M':
        case 'm':
            gender = Male;
        break;
        default:
            gender = Unknown;
        break;
        }
    }
    void Mouse::SetFavoriteFood(string favoriteFood)
    {
        Favorite_food = favoriteFood;
    }
    void Mouse::SetColorDescription(string colorDescription)
    {
        Color_description = colorDescription;
    }
    void Mouse::SetOtherComments(string otherComments)
    {
        Other_Comments = otherComments;
    }

    // Getters
    string Mouse::GetBreed() const
    {
        return Breed;
    }
    float Mouse::GetWeight() const
    {
        return Weight;
    }
    string Mouse::GetName() const
    {
        return Name;
    }
    char Mouse::GetGender() const
    {
        switch (gender)
        {
        case Female:
            return 'F';
        break;
        case Male:
            return 'M';
        break;
        default:
            return ' ';
        break;
        }
    }
    string Mouse::GetFavoriteFood() const
    {
        return Favorite_food;
    }
    string Mouse::GetColorDescription() const
    {
        return Color_description;
    }
    string Mouse::GetOtherComments() const
    {
        return Other_Comments;
    }

    //print fucntion
    void Mouse::printInfo() const
    {
        cout << "Mouse Name: " << GetName() << endl;
        cout << "Breed: " << GetBreed() << "\tWeight: " << GetWeight() << "\tGender: " << GetGender() << endl;
        cout << "Favorite Food: " << GetFavoriteFood() << "\tColor: " << GetColorDescription() << endl;
        cout << "Comments: " << GetOtherComments() << endl;
    }
