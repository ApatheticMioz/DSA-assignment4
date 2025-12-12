# Console Notepad Spellchecker

A console-based notepad application with real-time spell checking functionality, built in C++ using custom data structures including AVL trees, linked lists, queues, and stacks.

## Description

This application provides a simple text editor experience in the terminal with integrated spell checking. When you type a word that isn't in the dictionary, the application suggests corrections using four different techniques:

- **Substitution**: Replaces characters to find valid words
- **Omission**: Removes characters to find valid words
- **Insertion**: Adds characters to find valid words
- **Reversal**: Swaps adjacent characters to find valid words

The dictionary is stored in an AVL tree for efficient O(log n) lookups, ensuring fast spell checking even with large dictionaries.

## Project Structure

```
.
├── main.cpp           # Entry point and main application loop
├── Notepad.cpp/h      # Core notepad functionality
├── AVL_tree.cpp/h     # AVL tree implementation for dictionary
├── linked_list.cpp/h  # Linked list for text storage
├── queue.cpp/h        # Queue for word tracking
├── Stack.cpp/h        # Stack for undo functionality
├── Node.cpp/h         # Node class for linked structures
├── NodeStr.cpp/h      # String node class for stack
├── algorithms.cpp/h   # Sorting and spell-check algorithms
└── dictionary.txt     # Dictionary file (required at runtime)
```

## Setup / Installation

### Prerequisites

- C++ compiler with C++11 support (g++, clang++, or MSVC)
- Windows environment (uses `conio.h` for keyboard input)

### Compilation

Using g++:
```bash
g++ -o notepad main.cpp Notepad.cpp AVL_tree.cpp linked_list.cpp queue.cpp Stack.cpp Node.cpp NodeStr.cpp algorithms.cpp
```

Using MSVC:
```cmd
cl /EHsc main.cpp Notepad.cpp AVL_tree.cpp linked_list.cpp queue.cpp Stack.cpp Node.cpp NodeStr.cpp algorithms.cpp /Fe:notepad.exe
```

### Dictionary Setup

Create a `dictionary.txt` file in the same directory as the executable, with one word per line. The dictionary is loaded at startup and used for spell checking.

## Usage

Run the compiled executable:

```bash
./notepad      # Linux/macOS (requires conio.h alternative)
notepad.exe    # Windows
```

### Controls

| Key | Action |
|-----|--------|
| Any printable character | Type text |
| `Enter` | New line |
| `Backspace` | Delete last character |
| `Ctrl + S` | Save to file (`save.txt`) |
| `Ctrl + L` | Load from file |
| `Ctrl + Z` | Undo (up to 20 states) |
| `Ctrl + W` | Save prompt and exit |
| `Esc` | Exit immediately |

### Spell Checking

When you complete a word (by pressing space or enter), the application automatically checks it against the dictionary. If the word isn't found, you'll be presented with suggested corrections to choose from.

## Status

**Archived / Refactored**

This project was originally developed as a Data Structures assignment demonstrating practical applications of AVL trees, linked lists, queues, and stacks in C++.

## Author

Muhammad Abdullah Ali

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
