# Connect-N Game

This C++ program implements a simplified version of the Connect-N game, a classic two-player connection game where the players take turns dropping colored discs from the top into a vertically suspended grid. The goal is to connect a set number of their own discs in a row horizontally, vertically, or diagonally before the opponent.

## Structures

### Player
- Represents a player with a name and a mark (disc color). Defaults to 'o' (Player 1) and 'x' (Player 2).

### GameBoard
- Defines the game board as a 2D array with dimensions `MaxRows` and `MaxCols`. Initialized with a specified fill character, defaulting to '.'.

### Connect_N
- The main structure that manages the Connect-N game.
- Holds a game board, player information, and game state.
- Provides functions for making moves, checking for wins horizontally, vertically, and diagonally, saving and loading the game, and displaying the game board.

## Functions

### `MakeMove(int Col)`
- Validates and makes a move for the current player. Updates the game state accordingly.

### `horizontal()`, `vertical()`, `diagonal()`
- Check for a winning condition in the horizontal, vertical, and diagonal directions, respectively.

### `GameisOn()`
- Checks if the game is still in progress by verifying if any player has won horizontally, vertically, or diagonally.

### `SaveGame()`
- Saves the current game state, including board size, connect limit, moves made in each column, and the board itself, into a user-specified file.

### `LoadSavedGame()`
- Loads a saved game from a user-specified file into memory, allowing players to continue the game.

### `display()`
- Displays the current state of the game board.

### `ShowGame()`
- Shows the game board on the screen and prompts the current player for their move.

### `Play()`
- Executes the game loop, allowing players to take turns making moves until a win or a draw occurs.

### `Menu()`
- Displays a simple menu for the user to choose between playing, saving, loading, or exiting the game.

### `initNewGame(Connect_N& C)`
- Initializes a new game by prompting the user for the number of rows, columns, and the connectivity limit. Also, prompts for the names of both players.

### `main()`
- The main function that initializes the game and runs the game loop based on user input.

## How to Use

1. Run the program.
2. Choose options from the menu:
   - **Play (1):** Starts a new game or continues the existing game.
   - **Save Game (2):** Saves the current game state to a file.
   - **Load Game (3):** Loads a saved game from a file.
   - **Exit (4):** Exits the program.

## Note
- The game has some issues and unresolved errors.
- The game state is not saved automatically; the user must choose to save the game explicitly.
- Ensure the program has write access to the specified file paths when saving.
- The game continues until a player wins or the user chooses to exit.

## Future Improvements
- Enhance error handling and user input validation.
- Implement better graphics or a graphical user interface (GUI) for a more visually appealing gaming experience.
- Add more advanced features, such as AI opponents or networked multiplayer functionality.
