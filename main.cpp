#include <iostream>
#include <conio.h>
#include "Notepad.h"

using namespace std;

int main() {
    Notepad notepad;

    notepad.initialise();

    cout << "Notepad Version 0.1" << endl << endl;
    cout << "Supported controls are:" << endl;
    cout << "Basic input, like a normal notepad." << endl;
    cout << "\"Ctrl + L\" to load from a file." << endl;
    cout << "\"Backspace\" to delete a character." << endl;
    cout << "\"Ctrl + S\" to save to a file."<< endl;
    cout << "\"Esc\" to quit." << endl;

    return 0;
}
