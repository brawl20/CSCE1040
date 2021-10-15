#include <iostream>
#include <vector>
using namespace std;

int inputNum;

//Function for printing out the current roster
void printRoster(vector<int> jerseyNum, vector<int> playerRating)
{
   cout << "ROSTER" << endl;
   for (int i = 0; i < jerseyNum.size(); ++i){
      cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNum.at(i) << ", Rating: " << playerRating.at(i) << endl;
   }
}

// Add player function
void addPlayer(vector<int> &jerseyNum, vector<int> &playerRating)
{
      cout << "Enter a new player's jersey number:" << endl;
      cin >> inputNum;
      jerseyNum.push_back(inputNum);
      cout << "Enter the player's rating:" << endl;
      cin >> inputNum;
      playerRating.push_back(inputNum);
}

//Remove player function
void removePlayer(vector<int> &jerseyNum, vector<int> &playerRating){
      cout << "Enter a jersey number:" << endl;
      cin >> inputNum;
      for (int i = 0; i < jerseyNum.size(); ++i)
      {
         if (inputNum == jerseyNum.at(i))
         {
            jerseyNum.erase(jerseyNum.begin() + i);
            playerRating.erase(playerRating.begin() + i);
         }   
      }
}

// Update player rating function.
void updatePlayerRating(vector<int> &jerseyNum, vector<int> &playerRating){
   cout << "Enter a jersey number:" << endl;
   cin >> inputNum;
   for (int i = 0; i < jerseyNum.size(); ++i)
   {
      if(jerseyNum.at(i) == inputNum)
      {
         cout << "Enter a new rating for player:" << endl;
         cin >> inputNum;
         playerRating.at(i) = inputNum;
      }   
   } 
}

//Output players above a rating function
void outputAboveRating(vector<int> &jerseyNum, vector<int> &playerRating){
   cout << "Enter a rating:" << endl;
   cin >> inputNum;
   cout << endl << "ABOVE " << inputNum << endl;
   for (int i = 0; i < jerseyNum.size(); ++i)
   {
      if(playerRating.at(i) > inputNum)
      {
         cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNum.at(i) << ", Rating: " << playerRating.at(i) << endl;
      }
   }
}


int main() {
   
   vector<int> jerseyNum, playerRating;
   char menuChoice;
   bool loop;
   //Gather roster info
   for (int i = 0; i < 5; ++i){
      cout << "Enter player " << i + 1 << "'s jersey number:" << endl;
      cin >> inputNum;
      jerseyNum.push_back(inputNum);
      cout << "Enter player "<< i + 1 << "'s rating:" << endl;
      cin >> inputNum;
      playerRating.push_back(inputNum);
      cout << endl;
   }
   
   //Print roster out
   printRoster(jerseyNum, playerRating);
   
   cout << endl;
   // Menu
   do {
        cout << "MENU\na - Add player\nd - Remove player\nu - Update player rating\nr - Output players above a rating\no - Output roster\nq - Quit\n\nChoose an option:\n";
        cin.ignore();
        cin >> menuChoice;
        switch (menuChoice)
        {
            case 'a':
            addPlayer(jerseyNum, playerRating);
            cout << endl;
            loop = true;
            break;
            case 'd':
            removePlayer(jerseyNum, playerRating);
            cout << endl;
            loop = true;
            break;
            case 'u':
            updatePlayerRating(jerseyNum, playerRating);
            cout << endl;
            loop = true;
            break;
            case 'r':
            outputAboveRating(jerseyNum, playerRating);
            cout << endl;
            loop = true;
            break;
            case 'o':
            printRoster(jerseyNum, playerRating);
            cout << endl;
            loop = true;
            break;
            case 'q':
            loop = false;
            break;
            default:
            cout << "Try again with a vaild response: " << endl;
            loop = true;
            cout << endl;
            break;
        }
    }while (loop);
   
   return 0;
}