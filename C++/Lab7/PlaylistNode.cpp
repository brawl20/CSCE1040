#include "PlaylistNode.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;
   
   // Default constructor
   PlaylistNode::PlaylistNode()
   {
        this->uniqueID = "none";
        this->songName = "none";
        this->artistName = "none";
        this->songLength = 0;
        this->nextNodePtr = 0;
   }
   
   // Perameterized constructor
   PlaylistNode::PlaylistNode(string uniqueID, string songName, string artistName, int songLength, PlaylistNode* nextNodePtr)
   {
        this->uniqueID = uniqueID;
        this->songName = songName;
        this->artistName = artistName;
        this->songLength = songLength;
        this->nextNodePtr = nextNodePtr;
   }
   
   //Accessor fuctions
   string PlaylistNode::GetID()
   {
       return uniqueID;
   }
   string PlaylistNode::GetSongName()
   {
       return songName;
   }
   string PlaylistNode::GetArtistName()
   {
       return artistName;
   }
   int PlaylistNode::GetSongLength()
   {
       return songLength;
   }
   PlaylistNode* PlaylistNode::GetNext()
   {
       return nextNodePtr;
   }
   
   // Mutator Fucntions
   void PlaylistNode::InsertAfter(PlaylistNode* afterObj)
   {
       PlaylistNode* tmpNext = nullptr;
       
       tmpNext = this->nextNodePtr;
       this->nextNodePtr = afterObj;    
       afterObj->nextNodePtr = tmpNext;
       
   }
   void PlaylistNode::SetNext(PlaylistNode* nextObj)
   {
       this->nextNodePtr = nextObj;
   }
   // Print Fucntion
   void PlaylistNode::PrintPlaylistNode()
   {
       cout << "Unique ID: " << GetID() << endl;
       cout << "Song Name: " << GetSongName() << endl;
       cout << "Artist Name: " << GetArtistName() << endl;
       cout << "Song Length (in seconds) : " << GetSongLength() << endl;
   }
   