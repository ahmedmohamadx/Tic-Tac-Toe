# C++ Tic-Tac-Toe (Command Line)

A classic Tic-Tac-Toe game for two players, built with C++. Simple, clean, and beginner-friendly.

## Features
- 2-player game (X vs O)
- Input validation (no cheating! 😄)
- Detects winner and draw automatically
- Play again option without restarting the program

## How to Run

### Compile
```bash
g++ main.cpp -o tictactoe
```

### Run
**Windows:**
```cmd
tictactoe.exe
```
**Linux/macOS:**
```bash
./tictactoe
```

## How to Play
- The board is numbered 1 to 9 like this:
```
  1 | 2 | 3
  4 | 5 | 6
  7 | 8 | 9
```
- Players take turns entering a number to place their mark (X or O).
- First to get 3 in a row (horizontally, vertically, or diagonally) wins!

## Concepts Used
- 2D Arrays
- Functions
- Game Loop Logic
- Input Validation
- `using namespace std`
