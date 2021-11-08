#include <vector>
#include <string>
#include <iostream>

using namespace std;

// TODO: Write method to create and output all permutations of the list of names.
void AllPermutations(const vector<string> &permList, vector<string> &nameList) {
    vector<string> newNameList;
    string temp;

    if (nameList.empty())
    {
        for (int i = 0; i < permList.size(); ++i)
        {
            cout << permList[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < nameList.size(); ++i)
        {
            vector<string> newPermList = permList;
            newPermList.push_back(nameList[i]);
            
            vector<string> newNameList = nameList;
            newNameList.erase(newNameList.begin() + i);
            AllPermutations(newPermList, newNameList);
        }
    }

}

int main(int argc, char* argv[]) {
   vector<string> nameList;
   vector<string> permList;
   string name;

   // TODO: Read in a list of names; stop when -1 is read. Then call recursive method.
   cin >> name;
   while(name != "-1")
   {
      nameList.push_back(name);
      cin >> name;
   }
   AllPermutations(permList, nameList);
   return 0;
}