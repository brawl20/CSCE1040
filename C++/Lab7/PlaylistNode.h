#ifndef PLAYLISTNODE
#define PLAYLISTNODE

#include <string>
#include <vector>

using namespace std;

class PlaylistNode
{
   public:
   
   // Default constructor
   PlaylistNode();
   
   // Perameterized constructor
   PlaylistNode(string uniqueID, string songName, string artisitName, int songLength, PlaylistNode* nextNodePtr = nullptr);
   
   //Accessor fuctions
   string GetID();
   string GetSongName();
   string GetArtistName();
   int GetSongLength();
   PlaylistNode* GetNext();
   
   // Mutator Fucntions
   void InsertAfter(PlaylistNode* currObj);
   void SetNext(PlaylistNode* nextObj);
   
   // Print Fucntion
   void PrintPlaylistNode();
   
   private:
   string uniqueID, songName, artistName;
   int songLength;
   PlaylistNode* nextNodePtr;
   
};

#endif