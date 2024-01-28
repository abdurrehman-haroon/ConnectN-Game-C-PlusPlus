#include <iostream>
#include <fstream>
#include<string>

using namespace std;


const int MaxRows = 14;
const int MaxCols = 14;

struct Player {
    string Name;
    char Mark;

    Player(char mark = 'o', string PlayerName = "Player Name") {
        Mark = mark;
        Name = PlayerName;
    }

    void setPlayerName(string PlayerName) {
        Name = PlayerName;
        return;
    }

    void setPlayerMark(char PlayerMark) {
        Mark = PlayerMark;
        return;
    }
};

struct GameBoard {
    char Board[MaxRows][MaxCols];

    GameBoard(char FILL = '.') {
        for (int r = 0; r < MaxRows; r++)
            for (int c = 0; c < MaxCols; c++)
                Board[r][c] = FILL;
        return;
    }
};

struct Connect_N {

    GameBoard Board; // Game board to hold move data
    int Rows, Columns; // Game board size
    int ConnectLimit;// How many Marks to connect to win

    Player Players[2];// list of players
    int TurningPlayer; // index of turning player

    int GameEndState;
    // GameEndState 0 means game is not over
    // GameEndState 1 means first player has won it
    // GameEndState 2 means second player has won it

    int Moves_Made[MaxCols];
    // An array to hold the count of moves made in each
    // column. It will help us determine the row for
    // each move in an efficient way.

    Connect_N(int R = 6, int C = 7, int Limit = 4) {
        if (R < 0 || R > MaxRows)
            R = 6;

        if (C < 0 || C > MaxCols)
            C = 7;

        if (Limit < 0)
            Limit = 4;

        Rows = R;
        Columns = C;
        ConnectLimit = Limit;
        TurningPlayer = 0;
        GameEndState = 0;

        for (int i = 0; i < MaxCols; i++)
            Moves_Made[i] = 0;
    }

    bool MakeMove(int Col) {
        /**
            This function must validate the move and if
            possible make that move and update the entire
            state like board, turning player, GameEndState
            etc.

            It will return false if the move is not
            possible for some reason and true if
            move is valid and done successfully.

            An incomplete definition of this function is given
            below. You must update and complete it in all
            respects.
        */

        // Your updated code goes here

        int R = Moves_Made[Col];

        if (R > Rows)
        {
            return false;
        }

        Board.Board[Rows - 1 - R][Col] = Players[TurningPlayer].Mark;

        TurningPlayer = (TurningPlayer + 1) % 2;

        Moves_Made[Col]++;

        return true;
    }

    bool vertical()
    {
        int connect = 1;

        for (int r = 0; r < Rows; r++)
        {
            for (int c = 0; c < Columns - 1; c++)
            {
                if (Board.Board[c][r] == Board.Board[c + 1][r] && Board.Board[r][c] != '.')
                {
                    connect++;
                }
                else
                {
                    connect = 1;
                }

            }

            if (connect >= ConnectLimit)
            {
                return false;
            }

        }

        return true;

    }

    bool horizontal()
    {

        int connect = 1;

        for (int r = 0; r < Rows; r++)
        {
            for (int c = 0; c < Columns - 1; c++)
            {
                if (Board.Board[r][c] == Board.Board[r][c + 1] && Board.Board[r][c] != '.')
                {
                    connect++;
                }
                else
                {
                    connect = 1;
                }

            }

            if (connect >= ConnectLimit)
            {
                cout << "somebody won";
                return false;
            }

        }

        return true;

    }

    bool diagonal()
    {
        int connect = 1;


        for (int r = 0; r < Rows-1; r++)
        {
            for (int c = 0; c < Columns-1; c++)
            {
                for (int i = 0; i < Rows - 2; i++)
                {
                    if (Board.Board[r + i][c + i] == Board.Board[i + r + 1][i + c + 1] && Board.Board[r][c] != '.')
                    {
                        connect++;
                    }
                    else
                    {
                        connect = 1;
                    }

                }

                if (connect >= ConnectLimit)
                {
                    return false;
                }
            }

        }

        return true;
    }

    int GameisOn() {


        if (horizontal())
            return false;
        else if (vertical())
            return false;
        else if (diagonal())
            return false;


        return true;


    }

    bool SaveGame() {

        string FileName;
        cout << "enter the filename :";
        cin >> FileName;

        ofstream file(FileName);

        if (!file.is_open())
        {
            return false;
        }

        file << Rows << "\t" << Columns <<"\t"<< ConnectLimit<<endl;
        
        for (int r = 0; r < MaxCols; r++)
        {
            file << Moves_Made[r] << "\t";
        }

        file << endl;

        for (int r = 0; r < Rows; r++)
        {
            for (int c = 0; c < Columns; c++)
                file << Board.Board[r][c] << "\t";
            file << endl;
        }


        /**
            This function must save the entire game data
            into a file and return true.

            It will return false if the file can not be
            created or data can not be written for some
            reason
        */
        //Your Code Goes Here
        return true;
    }

    bool LoadSavedGame() {

        string FileName;
        cout << "enter the filename :";
        cin >> FileName;


        ifstream file(FileName);

        file >> Rows >> Columns >>ConnectLimit;

        for (int r = 0; r < MaxCols; r++)
        {
            file >> Moves_Made[r];
        }

        for (int r = 0; r < MaxCols; r++) {

            for (int c = 0; c < MaxRows; c++)
            {
                Board.Board[r][c] = 0;

            }

        }

        for (int r = 0; r < Rows; r++) {

            for (int c = 0; c < Columns; c++)
            {
                file >> Board.Board[r][c];

            }
        }

        /**
            This function must load a saved game
            from a file into memory and must allow users
            to continue playing it.

            It will return false if the file can not be
            opened or data can not be loaded from the file
        */
        return true;
    }

    void display()
    {
        for (int r = 0; r < Rows; r++) {

            for (int c = 0; c < Columns; c++)
            {
                cout << Board.Board[r][c];

            }
        }
    }

    void ShowGame() {
        /**
         This function must show the game on screen and
         if the game is not over take the next move from
         the next player and return that move.

         A very simple implementation is already provided
         to get you started but you better replace it with
         your code to produce a pleasing output
         */

         // Your better replace the following code

        for (int r = 0; r < Rows; r++) {
            for (int c = 0; c < Columns; c++)
                cout << Board.Board[r][c] << "\t";
            cout << endl << endl;
        }
        if (GameisOn())
            cout << endl << Players[TurningPlayer].Name
            << "("
            << Players[TurningPlayer].Mark << ")"
            << "Moving " << endl;
    }

    void Play() {
        int Move;
        do {
            ShowGame();
            cout << "ENTER NEGATIVE NUMBER FOR THE MAIN MENU" << endl;
            cout << "Please Enter Your Move ? (0 - " << Columns << ") ";
            cin >> Move;
            if (Move < 0)
                break;
            MakeMove(Move);
        } while (GameisOn());

    }
};

int Menu() {
    int Choice;
    do {
        cout << "1. Play" << endl
            << "2. Save Game" << endl
            << "3. Load Game" << endl
            << "4. Exit" << endl
            << "Enter You Choice (1 - 4)";
        cin >> Choice;
    } while (Choice < 1 || Choice > 4);
    return Choice;
}

void initNewGame(Connect_N& C) {
    int Rows, Cols, Limit;
    cout << "How Many Rows ?";
    cin >> Rows;
    cout << "How Many Cols ?";
    cin >> Cols;
    cout << "Connectivity Limit ?";
    cin >> Limit;
    C.Rows = Rows;
    C.Columns = Cols;
    C.ConnectLimit = Limit;
    cout << "First Player Name? ";
    string N;
    cin >> N;
    C.Players[0].setPlayerName(N);
    cout << "Second Player Name? ";
    cin >> N;
    C.Players[1].setPlayerMark('x');
    C.Players[1].setPlayerName(N);
}

int main()
{
    int Choice;
    bool GameNotLoaded = true;
   // string filename = "F:\game.text";
   // string filesave = "F:\yrgame.text";

    Connect_N Connect_Game(MaxRows, MaxCols, MaxRows);
    do {
        Choice = Menu();
        switch (Choice)
        {
        case 1:
            if (GameNotLoaded) {
                initNewGame(Connect_Game);
                GameNotLoaded = false;
            }
            Connect_Game.Play();
            break;
        case 2:

            if (Connect_Game.SaveGame())
                cout << "file succesfully saved \n";

            break;

        case 3:

            GameNotLoaded = false;
            if (Connect_Game.LoadSavedGame())
                cout << "file succesfully loaded \n";

            break;
        }

    } while (Choice != 4);
    return 0;
}
