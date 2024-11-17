// Muhammad Abdullah Ali
// i23-2523
// Section A
// Department of Data Science
// Data Structures
// Assignment #4

#include <iostream>
#include <conio.h>

#include "Notepad.h"
#include "algorithms.h"

using namespace std;

/*
 * The following program is an implementation of a console based notepad.
 * "conio.h" library is used for input handling, it was required for special inputs like:
 *      Ctrl + S : Save
 *      Ctrl + L : Load
 *      etc.
 *
 * The program walks the user through with the controls and explanation.
 * It is simple to use, just press your buttons and use whichever commands you want to!
 *
 * Further documentation in header files/source files.
 */

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
        cout << "\"Ctrl + Z\" to undo (up to 20 undo supported)." << endl; // TODO
        cout << "\"Esc\" to quit." << endl << endl;

        notepad.display();

        int ch = _getch();

        switch (ch) {
            // QUIT
            // ESC
            // Ctrl + W
            case 27: {
                exit(0);
            }
            case 23: {
                cout << "Do you want to save before exiting?" << endl;
                cout << "1. Save and Exit" << endl;
                cout << "2. Exit without Saving" << endl;
                cout << "3. Cancel" << endl;

                int choice = _getch();

                switch (choice) {
                    case '1': {
                        notepad.saveFile();
                        exit(0);
                    }
                    case '2': {
                        exit(0);
                    }
                    case '3': {
                        break;
                    }
                    default: {
                        cout << "Invalid option. Returning to notepad." << endl;
                        _getch();
                        break;
                    }
                }

                break;
            }

            case 12: {
                // LOAD
                // CTRL + L
                cout << "\nCurrent file has been saved to \"save.txt\"" << endl;
                notepad.saveFile();

                string filename;
                cout << "Choose file to load text from. Enter nothing to load \"save.txt\"" << endl;
                cout << "Enter file name: " << endl;
                cin >> filename;

                filename = (filename.empty() ? "save.txt" : filename);
                notepad.loadFile(filename);

                cout << "Press any key to continue" << endl;
                getch();

                break;
            }

            case 19: {
                // SAVE
                // CTRL + S
                cout << "\nCurrent notepad is being saved to \"save.txt\"" << endl;
                notepad.saveFile();

                cout << "Press any key to continue" << endl;
                getch();

                break;
            }

            case 8: {
                // BACKSPACE
                notepad.deleteLast();
                break;
            }

            case 26: {
                // UNDO
                notepad.undo();
                break;
            }

            case 13: {
                // ENTER
                ch = '\n';
            }

            default: {
                if (isPrint(ch) || ch == '\n') {
                    // WRITE CHARACTER
                    notepad.writeCh(ch);
                }
                break;
            }
        }

        // Clear the screen
        system("cls");
    }
}
