#include <iostream>
#include <string>
#include <vector>
using namespace std;

class List {
public:
    string musicFile;
    string artist;
    string duration;
    string album;
    string genre;
    List* next;
    List* prev;

    List(string file, string Lartist, string Lduration, string Lalbum, string Lgenre)
        : musicFile(file), artist(Lartist), duration(Lduration), album(Lalbum), genre(Lgenre), next(nullptr), prev(nullptr) {
    }
};

class Playlist {
private:
    List* head;
    List* current;

public:
    Playlist() : head(nullptr), current(nullptr) {}

    void insert() {
        string musicFile, artist, duration, album, genre;

        cout << "Enter Music File Name: ";
        cin.ignore();
        getline(cin, musicFile);

        cout << "Enter Artist Name: ";
        getline(cin, artist);

        cout << "Enter Song Duration: ";
        getline(cin, duration);

        cout << "Enter Album Name: ";
        getline(cin, album);

        cout << "Enter Genre: ";
        getline(cin, genre);

        List* newNode = new List(musicFile, artist, duration, album, genre);

        if (!head) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = current = newNode;
        } else {
            List* last = head->prev;
            newNode->prev = last;
            last->next = newNode;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void deleteElement() {
        if (!head) {
            cout << "No Music is there to delete!" << endl;
            return;
        }

        string musicFile;

        cout << "Enter Music File Name to delete: ";
        cin.ignore();
        getline(cin, musicFile);

        List* ptr = head;

        do {
            if (ptr->next == ptr && ptr->musicFile == musicFile) {
                cout << "One file deleted! Playlist is Empty Now!" << endl;
                delete head;
                head = nullptr;
                return;
            } else if (ptr->musicFile == musicFile) {
                List* prev = ptr->prev;
                List* next = ptr->next;
                prev->next = next;
                next->prev = prev;
                if (head == ptr) {
                    head = next;
                }
                delete ptr;
                cout << "Music File Deleted!" << endl;
                return;
            }
            ptr = ptr->next;
        } while (ptr != head);

        cout << "No Music file with that name is found!" << endl;
    }

    void show() {
        if (!head) {
            cout << "Playlist is Empty!" << endl;
            return;
        }

        List* showPtr = head;
        int i = 1;

        cout << "Displaying Playlist:" << endl;
        do {
            cout << "Song " << i << " - Music File: " << showPtr->musicFile << "\n         Artist: " << showPtr->artist
                 << "\n         Duration: " << showPtr->duration << " minutes"
                 << "\n         Album: " << showPtr->album
                 << "\n         Genre: " << showPtr->genre << endl;
            i++;
            showPtr = showPtr->next;
        } while (showPtr != head);
    }

    void nextNode() {
        if (!current) {
            cout << "No Songs in Playlist!" << endl;
        } else {
            current = current->next;
            cout << "Playing Next Song - Music File: " << current->musicFile << "\n                    Artist: " << current->artist
                 << "\n                    Duration: " << current->duration << " minutes"
                 << "\n                    Album: " << current->album
                 << "\n                    Genre: " << current->genre << endl;
        }
    }

    void prevNode() {
        if (!current) {
            cout << "No Songs in Playlist!" << endl;
        } else {
            current = current->prev;
            cout << "Playing Previous Song - Music File: " << current->musicFile << "\n                        Artist: " << current->artist
                 << "\n                        Duration: " << current->duration << " minutes"
                 << "\n                        Album: " << current->album
                 << "\n                        Genre: " << current->genre << endl;
        }
    }

    void firstNode() {
        if (!head) {
            cout << "Playlist is Empty!" << endl;
        } else {
            cout << "Playing First Music - Music File: " << head->musicFile << "\n                      Artist: " << head->artist
                 << "\n                      Duration: " << head->duration << " minutes"
                 << "\n                      Album: " << head->album
                 << "\n                      Genre: " << head->genre << endl;
        }
    }

    void lastNode() {
        if (!head) {
            cout << "Playlist is Empty!" << endl;
        } else {
            cout << "Playing Last Music - Music File: " << head->prev->musicFile << "\n                     Artist: " << head->prev->artist
                 << "\n                     Duration: " << head->prev->duration << " minutes"
                 << "\n                     Album: " << head->prev->album
                 << "\n                     Genre: " << head->prev->genre << endl;
        }
    }

    void specificData() {
        if (!head) {
            cout << "No music files to be searched!" << endl;
            return;
        }

        string musicFile;

        cout << "Enter Music File Name to Search: ";
        cin.ignore();
        getline(cin, musicFile);

        List* ptr = head;
        do {
            if (ptr->musicFile == musicFile) {
                cout << "File is found!" << endl;
                cout << "Playing Music - Music File: " << ptr->musicFile << "\n                Artist: " << ptr->artist
                     << "\n                Duration: " << ptr->duration << " minutes"
                     << "\n                Album: " << ptr->album
                     << "\n                Genre: " << ptr->genre << endl;
                return;
            }
            ptr = ptr->next;
        } while (ptr != head);

        cout << "There is no music file with this name!" << endl;
    }

    void updateMusicFile() {
        if (!head) {
            cout << "Playlist is Empty!" << endl;
            return;
        }

        string musicFile;

        cout << "Enter Music File Name to Update: ";
        cin.ignore();
        getline(cin, musicFile);

        List* ptr = head;
        do {
            if (ptr->musicFile == musicFile) {
                cout << "Enter Updated Music File Name: ";
                getline(cin, ptr->musicFile);

                cout << "Enter Updated Artist Name: ";
                getline(cin, ptr->artist);

                cout << "Enter Updated Song Duration: ";
                getline(cin, ptr->duration);

                cout << "Enter Updated Album Name: ";
                getline(cin, ptr->album);

                cout << "Enter Updated Genre: ";
                getline(cin, ptr->genre);

                cout << "Music File Updated Successfully!" << endl;
                return;
            }
            ptr = ptr->next;
        } while (ptr != head);

        cout << "There is no music file with this name!" << endl;
    }
};

int main() {
    Playlist playlist;
    int choice;

    while (true) {
        cout << "\n-----Menu for Playlist-----\n\n\n";
        cout << "1. Add New Music File\n\n";
        cout << "2. Remove Music File\n\n";
        cout << "3. Show Playlist\n\n";
        cout << "4. Play Next Music File\n\n";
        cout << "5. Play Previous Music File\n\n";
        cout << "6. Play First Music File\n\n";
        cout << "7. Play Last Music File\n\n";
        cout << "8. Play Specific Music File\n\n";
        cout << "9. Update Music File\n\n";
        cout << "10. Exit\n\n\n\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                playlist.insert();
                break;
            case 2:
                playlist.deleteElement();
                break;
            case 3:
                playlist.show();
                break;
            case 4:
                playlist.nextNode();
                break;
            case 5:
                playlist.prevNode();
                break;
            case 6:
                playlist.firstNode();
                break;
            case 7:
                playlist.lastNode();
                break;
            case 8:
                playlist.specificData();
                break;
            case 9:
                playlist.updateMusicFile();
                break;
            case 10:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
