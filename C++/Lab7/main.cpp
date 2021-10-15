#include "PlaylistNode.h"
#include <string>
#include <list>
#include <iostream>

using namespace std;

//Print menu fucntion
void PrintMenu(string playlistTitle)
{
    cout << endl;
    cout << playlistTitle << " PLAYLIST MENU" << endl;
    cout << "a - Add song\nd - Remove song\nc - Change position of song\ns - Output songs by specific artist\nt - Output total time of playlist (in seconds)\no - Output full playlist\nq - Quit\n\n";
    cout << "Choose an option:\n";
}
//Output Full Playlist
void outputFullPlaylist(PlaylistNode* currObj, string playlistTitle)
{
    int index = 1;
    cout << endl;
    cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;

    if (currObj == nullptr)
    {
        cout << "Playlist is empty" << endl;
    }
    else
    {
        while (currObj != nullptr)
        {
            cout << endl;
            cout << index << "." << endl;
            currObj->PrintPlaylistNode();
            currObj = currObj->GetNext();
            ++index;
        }
    }
}
// Add Song Function
void addSong(PlaylistNode* &headObj, PlaylistNode* &lastObj, PlaylistNode* &currObj)
{
    string uniqueID, songName, artistName;
    int songLength;

    cout << "ADD SONG" << endl;
    cout << "Enter song's unique ID:" << endl;
    cin >> uniqueID;
    cout << "Enter song's name:" << endl;
    cin.ignore();
    getline(cin,songName);
    cout << "Enter artist's name:" << endl;
    getline(cin,artistName);
    cout << "Enter song's length (in seconds):" << endl;
    cin >> songLength;
    
    if (headObj == nullptr)
    {
        headObj = new PlaylistNode(uniqueID, songName, artistName, songLength);
        lastObj = headObj;
    }
    else
    {
        currObj = new PlaylistNode(uniqueID,songName,artistName,songLength);
        lastObj->InsertAfter(currObj);
        lastObj = currObj;
    }
}
// Remove Song Fucntion
void removeSong(PlaylistNode* &headObj, PlaylistNode* &currObj)
{
    string uniqueID;
    PlaylistNode* prevObj = nullptr;

    currObj = headObj;
    prevObj = currObj;

    cout << endl;
    cout << "REMOVE SONG" << endl;
    cout << "Enter song's unique ID:" << endl;
    cin >> uniqueID;
    while (currObj != nullptr)
    {

        if(currObj->GetID() == uniqueID)
        {
            // Is song at the start
            if(currObj == headObj)
            {
                // This executes if there is only one song in the playlist
                if(headObj->GetNext() == nullptr)
                {
                    cout << "\"" << currObj->GetSongName() << "\"" << " Removed." << endl;
                    delete currObj;
                    headObj = nullptr;
                    currObj = nullptr;
                }
                // Normal removal
                else
                {
                    headObj = currObj->GetNext();
                    headObj->SetNext(headObj->GetNext());
                    cout << "\"" << currObj->GetSongName() << "\"" << " Removed." << endl;
                    delete currObj;
                    currObj = headObj;
                }
            }
            else
            {
                prevObj->SetNext(currObj->GetNext());
                cout << "\"" << currObj->GetSongName() << "\"" << " Removed." << endl;
                delete currObj;
                currObj = nullptr;
            }
        }
        else
        {
            prevObj = currObj;
            currObj = currObj->GetNext();
        }
    }
}
//Move Song To Another Position
void moveSong(PlaylistNode* &headObj, PlaylistNode* &lastObj, PlaylistNode* &currObj)
{
    int songStartIndex, songPlaceIndex;
    int playlistSize = 0;
    PlaylistNode* prevObj = nullptr;
    PlaylistNode* placementObj = nullptr;

    cout << endl;
    cout << "CHANGE POSITION OF SONG" << endl;
    cout << "Enter song's current position:" << endl;
    cin >> songStartIndex;
    cout << "Enter new position for song:" << endl;
    cin >> songPlaceIndex;

    // Find max number of elements in playlist
    currObj = headObj;
    while (currObj != nullptr)
    {
        ++playlistSize;
        currObj = currObj->GetNext();
    }
    currObj = headObj;
    for (int i = 1; i < songStartIndex; ++i)
    {
        currObj = currObj->GetNext();
    }
    prevObj = headObj;
    for (int i = 1; i < songStartIndex - 1; ++i)
    {
        prevObj = prevObj->GetNext();
    }
    // Move to the front
    if (songPlaceIndex <= 1)
    {
        songPlaceIndex = 1;
        if (currObj != lastObj)
        {
            prevObj->SetNext(currObj->GetNext());
            currObj->SetNext(headObj);
            headObj = currObj;
            cout << "\"" << currObj->GetSongName() << "\" moved to position " << songPlaceIndex << endl;
            currObj = nullptr;
        }
        else
        {
            prevObj->SetNext(nullptr);
            currObj->SetNext(headObj);
            headObj = currObj;
            cout << "\"" << currObj->GetSongName() << "\" moved to position " << songPlaceIndex << endl;
            currObj = nullptr;
        }
        
    }
    // Move to back
    else if(songPlaceIndex >= playlistSize)
    {
        songPlaceIndex = songPlaceIndex;
        if (prevObj != headObj)
        {
            prevObj->SetNext(currObj->GetNext());
            lastObj->SetNext(currObj);
            lastObj = currObj;
            lastObj->SetNext(nullptr);
            cout << "\"" << currObj->GetSongName() << "\" moved to position " << songPlaceIndex << endl;
            currObj = nullptr;
        }
        else
        {
            headObj = currObj->GetNext();
            lastObj->SetNext(currObj);
            lastObj = currObj;
            cout << "\"" << currObj->GetSongName() << "\" moved to position " << songPlaceIndex << endl;
            lastObj->SetNext(nullptr);
            currObj = nullptr;
        }
    }
    // Move elsewhere
    else
    {
        PlaylistNode* placementPrevObj;
        placementObj = headObj;
        placementPrevObj = headObj;
        prevObj->SetNext(currObj->GetNext());
        for (int i = 1; i < songPlaceIndex; ++i)
        {
            placementObj = placementObj->GetNext();
        }
        for (int i = 1; i < songPlaceIndex - 1; ++i)
        {
            placementPrevObj = placementPrevObj->GetNext();
        }
        if(currObj == headObj)
        {
            headObj = currObj->GetNext();
            currObj->SetNext(placementObj->GetNext());
            placementObj->SetNext(currObj);
            cout << "\"" << currObj->GetSongName() << "\" moved to position " << songPlaceIndex << endl;
        }
        else if(currObj == lastObj)
        {
            prevObj->SetNext(nullptr);
            lastObj = prevObj;
            placementPrevObj->SetNext(currObj);
            currObj->SetNext(placementObj);
            cout << "\"" << currObj->GetSongName() << "\" moved to position " << songPlaceIndex << endl;
            placementPrevObj = nullptr;
            currObj = nullptr;
        }
        else
        {
            placementPrevObj->SetNext(currObj);
            currObj->SetNext(placementObj);
            placementObj->SetNext(placementObj->GetNext());
            cout << "\"" << currObj->GetSongName() << "\" moved to position " << songPlaceIndex << endl;
            currObj = nullptr;
            placementObj = nullptr;
            placementPrevObj = nullptr;
        }
    }
}
//Output songs by artist
void artsitSongs(PlaylistNode* &headObj)
{
    PlaylistNode* currObj = nullptr;
    int index = 1;
    bool foundSongs = false;
    string artistSearch;

    currObj = headObj;
    cout << endl;
    cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
    cout << "Enter artist's name:" << endl;
    cin.ignore();
    getline(cin,artistSearch);
    while (currObj != nullptr)
    {
        if(currObj->GetArtistName() == artistSearch)
        {
            cout << endl;
            cout << index << "." << endl;
            currObj->PrintPlaylistNode();
            foundSongs = true;
        }
        currObj = currObj->GetNext();
        ++index;
    }
    if(!foundSongs)
    {
        cout << "\nThere are no songs by that artsit.\n";
    }
}
//Output total time of playlist
void outputTotalTime(PlaylistNode* headObj)
{
    PlaylistNode* currObj = nullptr;
    int totalTime = 0;

    currObj = headObj;
    while(currObj != nullptr)
    {
        totalTime += currObj->GetSongLength();
        currObj = currObj->GetNext();
    }
    cout << "\nOUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)\nTotal time: " << totalTime << "seconds" << endl;
}

int main()
{
    string playlistTitle;
    char menuChoice;
    PlaylistNode* headObj = nullptr;
    PlaylistNode* currObj = nullptr; 
    PlaylistNode* lastObj = nullptr;


    cout << "Enter playlist's title:" << endl;
    getline(cin,playlistTitle);

    while (menuChoice != 'q')
    {
        PrintMenu(playlistTitle);
        cin >> menuChoice;
        switch (menuChoice)
        {
            case 'a':
                addSong(headObj, lastObj, currObj);
            break;

            case 'd':
                removeSong(headObj,currObj);
            break;

            case 'c':
                moveSong(headObj,lastObj,currObj);
            break;

            case 's':
                artsitSongs(headObj);
            break;

            case 't':
                outputTotalTime(headObj);
            break;

            case 'o':
                outputFullPlaylist(headObj, playlistTitle);
            break;

            case 'q':
            break;

            default:
                cout << "You have made an invalid choice. Please try again.\n";
            break;
        }

        //Delete shit
        currObj = headObj;
        PlaylistNode* nextObj;
        while (currObj != nullptr)
        {
            nextObj = currObj->GetNext();
            delete currObj;
            currObj = nextObj;
        }


    }
    return 0;
}