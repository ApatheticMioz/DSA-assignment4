#include <iostream>
#include <conio.h>
#include "Notepad.h"

using namespace std;

int main() {
    Notepad notepad;

    notepad.initialiseDict();

    while (true) {
        cout << "Notepad Version 0.1" << endl << endl;
        cout << "Supported controls are:" << endl;
        cout << "Basic input, like a normal notepad." << endl;
        cout << "\"Ctrl + L\" to load from a file." << endl;
        cout << "\"Backspace\" to delete a character." << endl;
        cout << "\"Ctrl + S\" to save to a file."<< endl;
        cout << "\"Ctrl + Z\" to undo." << endl; // TODO
        cout << "\"Esc\" to quit." << endl << endl;

        notepad.display();

        int ch = _getch();

        switch (ch) {
            case 27:

            case 23: {
                // ESC
                // CTRL + W
                cout << "Exiting." << endl;
                exit(0);
            }

            case 12: {
                // LOAD
                // CTRL + L
                cout << "\nCurrent file has been saved to \"save.txt\"" << endl;
                notepad.saveFile(); // TODO

                string filename;
                cout << "Choose file to load text from. Enter nothing to load \"save.txt\"" << endl;
                cout << "Enter file name: " << endl;
                cin >> filename;

                filename = (filename.empty() ? "save.txt" : filename);
                notepad.loadFile(filename); // TODO

                cout << "Press any key to continue" << endl;
                getch();

                break;
            }

            case 19: {
                // SAVE
                // CTRL + S
                cout << "\nCurrent notepad is being saved to \"save.txt\"" << endl;
                notepad.saveFile(); // TODO

                cout << "Press any key to continue" << endl;
                getch();

                break;
            }

            case 8: {
                // BACKSPACE
                notepad.deleteLast(); // TODO
                break;
            }

            case 26: {
                // UNDO
                notepad.undo(); // TODO
                break;
            }

            case 13: {
                // ENTER
                ch = '\n';
            }

            default: {
                if (isprint(ch) || ch == '\n') {
                    // WRITE CHARACTER
                    notepad.writeCh(ch); // TODO
                }
                break;
            }
        }

        system("cls");
    }
}
