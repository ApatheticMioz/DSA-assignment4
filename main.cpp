#include <iostream>
#include <conio.h>
#include "Notepad.h"

using namespace std;

int main() {
    Notepad notepad;

    notepad.initialise();

    while (true) {
        cout << "Notepad Version 0.1" << endl << endl;
        cout << "Supported controls are:" << endl;
        cout << "Basic input, like a normal notepad." << endl;
        cout << "\"Ctrl + L\" to load from a file." << endl;
        cout << "\"Backspace\" to delete a character." << endl;
        cout << "\"Ctrl + S\" to save to a file."<< endl;
        cout << "\"Esc\" to quit." << endl << endl;

        int ch = _getch();

        switch (ch) {
            case 27:

            case 23:
                // ESC
                // CTRL + W
                cout << "Exiting." << endl;
                exit(0);
                break;

            case 12:
                // LOAD
                // CTRL + L
                notepad.load();
                break;

            case 19:
                // SAVE
                // CTRL + S
                notepad.save();
                break;

            case 8:
                // BACKSPACE
                notepad.deleteLast();
                break;

            case 26:
                // UNDO
                notepad.undo();
                break;

            case 13:
                // ENTER
                ch = '\n';

            default:
                if (isprint(ch) || ch == '\n') {
                    // WRITE CHARACTER
                    notepad.write();
                }
                break;
        }

        system("cls");
    }

    return 0;
}
