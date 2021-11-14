#include "Encyclopedia.h"
#include <iostream>

// Define functions declared in Encyclopedia.h
void Encyclopedia::SetEdition(string edition)
{
   Encyclopedia::edition = edition;
}

void Encyclopedia::SetNumVolumes(int numVolumes)
{
   Encyclopedia::numVolumes = numVolumes;
}

string Encyclopedia::GetEdition()
{
   return edition;
}
int Encyclopedia::GetNumVolumes()
{
   return numVolumes;   
}

void Encyclopedia::PrintInfo()
{
   Book::PrintInfo();
   cout << "   Edition: " << edition << endl << "   Number of Volumes: " << numVolumes << endl;   
}