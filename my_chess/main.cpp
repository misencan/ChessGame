#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "Piece.h"
#include "Board.h"
#include <stdlib.h> 
#include "Timer.h"
using namespace std;

int main()
{



    //Default settings
    char playGame;
    string player1 = "Player 1";
    string player2 = "Player 2";
    char startGame;
    bool whitesTurn = true; //playersTurn == true means whites turn, = false means blacks turn to play
    char pieceInputX;
    int pieceInputY;
    char pieceMoveX;
    int pieceMoveY;
    int pieceInputNum;
    int pieceMoveNum;
    bool inputMoves = false;
    bool gameOn = true;
    bool legalMove = true;
    Board board;
    unsigned long gameclock; //you would change gameclock to reflect the amount of time per player
    timer t1;
    timer t2;
    unsigned long t1secsremaining, t1mins, t1secs, t2secsremaining, t2mins, t2secs;
    bool valid2 = true;


    do
    {

        cout << "Do you want to play a game? (y/n) "; //turn it into a big if else to quit game
        cin >> playGame;

        if (playGame == 'y')
        {
            /* GAME CODE */
            cout << "Enter Player 1 name: ";
            cin >> player1;
            cout << "Enter Player 2 name: ";
            cin >> player2;

            cout << "Enter time limit: ";
            cin >> gameclock;

            cout << "   " << endl;
            cout << "Welcome to Atomic Chess!!!" << endl;
            cout << "In atomic chess goal is to kill opponents king" << endl;
            cout << "When you capture an opponents piece, all the adjacent pieces are captured except pawns." << endl;
            cout << "Moves of pieces are idential to traditional chess." << endl;
            cout << "-----------------------------------------" << endl;
            cout << "Game Instructions & Rules: " << endl;
            cout << "First pair of x,y(letter number) coordiantes are which piece you want to move" << endl;
            cout << "Second pair of x,y(letter number) coordinates are where you want to move the piece" << endl;
            cout << "Upper case is for " << player1 <<", lower case is for " << player2 << endl;
            cout << player1 <<" (Upper case) starts the game! " << endl;
            cout << "If you want to quit game while playing, type (q 1) when coordinates asked" << endl;
            cout << "-----------------------------------------" << endl;
            cout << "Ready to start? (y/n) ";
            cin >> startGame;
            cout << "  " << endl;

            board.Initialize_Board();
            whitesTurn = true; //whites/upper case start
            board.Display_Board();

            do
            {

                do // this loop is collecting validating input moves of pieces
                {
                    inputMoves = true;

                    if (whitesTurn == true)
                    {
                        t2.stop();
                        t2secsremaining = gameclock * 60 - t2.getTime() / 10;
                        if (t2secsremaining > 100000000000){
                            cout << "Time’s up, " << player2 << "!" << endl; //end the game here if we are doing that.
                            cout << player1 << " (upper case) wins!!!" << endl;
                            exit(0);
                        }
                        t2secs = t2secsremaining % 60;
                        t2mins = t2secsremaining / 60;
                        cout << player2 << " has " << t2mins << " minutes and " << t2secs << " seconds remaining." << endl;
                        t1secsremaining = gameclock * 60 - t1.getTime() / 10;
                        t1secs = t1secsremaining % 60;
                        t1mins = t1secsremaining / 60;
                        cout << player1 << " has " << t1mins << " minutes and " << t1secs << " seconds remaining." << endl;
                        t1.start();
                    }
                    else
                    {
                        t1.stop();
                        t1secsremaining = gameclock * 60 - t1.getTime() / 10;
                        if (t1secsremaining > 100000000000){
                            cout << "Time’s up, " << player1 << "!" << endl; //end the game here if we are doing that.
                            cout << player2 << " (lower case) wins!!!" << endl;
                            exit(0);
                        }
                        t1secs = t1secsremaining % 60;
                        t1mins = t1secsremaining / 60;
                        cout << player1 << " has " << t1mins << " minutes and " << t1secs << " seconds remaining." << endl;
                        t2secsremaining = gameclock * 60 - t2.getTime() / 10;
                        t2secs = t2secsremaining % 60;
                        t2mins = t2secsremaining / 60;
                        cout << player2 << " has " << t2mins << " minutes and " << t2secs << " seconds remaining." << endl;
                        t2.start();
                    }
                    cout << "  " << endl;
                    if (whitesTurn == true)
                    {
                        cout << player1 << " is playing." << endl;
                    }
                    else if (whitesTurn == false)
                    {
                        cout << player2 << " is playing." << endl;
                    }
                    cout << "  " << endl;

                    cout << "Enter piece coordinates (letter number): ";
                    cin >> pieceInputX; //char value
                    cin >> pieceInputY; //int value

                    cout << "Enter where you want to move (letter number): ";
                    cin >> pieceMoveX; //char value
                    cin >> pieceMoveY; //int value
                    valid2 = true;

                    if (pieceInputY <= 8 && pieceInputY >= 0)
                    {
                        if (pieceMoveY <= 8 && pieceMoveY >= 0)
                        {
                            inputMoves = true;
                        }
                        else
                        {
                            inputMoves = false;
                            valid2 = false;
                        }
                    }
                    else
                    {
                        inputMoves = false;
                        valid2 = false;
                    }



                    switch (pieceInputX)
                    {
                    case 'a':
                    case 'A':
                        pieceInputNum = 1;
                        break;
                    case 'b':
                    case 'B':
                        pieceInputNum = 2;
                        break;
                    case 'c':
                    case 'C':
                        pieceInputNum = 3;
                        break;
                    case 'd':
                    case 'D':
                        pieceInputNum = 4;
                        break;
                    case 'e':
                    case 'E':
                        pieceInputNum = 5;
                        break;
                    case 'f':
                    case 'F':
                        pieceInputNum = 6;
                        break;
                    case 'g':
                    case 'G':
                        pieceInputNum = 7;
                        break;
                    case 'h':
                    case 'H':
                        pieceInputNum = 8;
                        break;
                    case 'q':
                    case 'Q':
                        valid2 = false;
                        exit(0);
                        break;

                    default:
                        inputMoves = false;
                        valid2 = false;
                        //cout << "  " << endl;
                        //cout << "Invalid Entry" << endl;
                        break;
                    }

                    switch (pieceMoveX)
                    {
                    case 'a':
                    case 'A':
                        pieceMoveNum = 1;
                        break;
                    case 'b':
                    case 'B':
                        pieceMoveNum = 2;
                        break;
                    case 'c':
                    case 'C':
                        pieceMoveNum = 3;
                        break;
                    case 'd':
                    case 'D':
                        pieceMoveNum = 4;
                        break;
                    case 'e':
                    case 'E':
                        pieceMoveNum = 5;
                        break;
                    case 'f':
                    case 'F':
                        pieceMoveNum = 6;
                        break;
                    case 'g':
                    case 'G':
                        pieceMoveNum = 7;
                        break;
                    case 'h':
                    case 'H':
                        pieceMoveNum = 8;
                        break;
                    case 'q':
                    case 'Q':
                        valid2 = false;
                        exit(0);
                        break;

                    default:
                        inputMoves = false;
                        valid2 = false;
                        //cout << "  " << endl;
                        //cout << "Invalid Entry" << endl;
                        break;
                    }

                    if (valid2 == true)
                    {
                        if (board.GetPieceAt(pieceInputNum, pieceInputY)->is_white != whitesTurn)
                        {
                            inputMoves = false;
                            //cout << "  " << endl;
                            //cout << "Invalid Entry" << endl;
                        }
                    }
                    else
                    {
                        inputMoves = false;
                    }

                    if (inputMoves == false)
                    {
                        cout << "  " << endl;
                        cout << "Invalid Entry" << endl;
                        cout << "  " << endl;
                    }
                    

                } while (inputMoves == false);

                //add a bool white or black
                // Piece* Board::GetPieceAt(int x, int y)


                cout << "    " << endl;
                legalMove = board.MovePiece(pieceInputNum, pieceInputY, pieceMoveNum, pieceMoveY);
                if (legalMove == true)
                {
                    if (whitesTurn == true)
                    {
                        whitesTurn = false;
                    }
                    else if (whitesTurn == false)
                    {
                        whitesTurn = true;
                    }
                }
                else {
                    cout << "  " << endl;
                }

                board.Promote_Pawns();

                board.Display_Board();
                cout << "    " << endl;





                switch (board.King_Exists())
                {
                case 0:
                    gameOn = true;
                    break;
                case 1:
                    cout << "   " << endl;
                    //wineer Player 1 wins
                    cout << player1 << " (upper case) wins!!!" << endl;
                    gameOn = false;
                    playGame ='o';
                    break;
                case 2:
                    cout << "   " << endl;
                    //wineer Player 2 wins
                    cout << player2 << " (lower case) wins!!!" << endl;
                    gameOn = false;
                    playGame ='o';
                    break;
                case 3:
                    cout << "   " << endl;
                    cout << "It's a draw, both kings dead!!!" << endl;
                    gameOn = false;
                    playGame ='o';
                    break;
                default:
                    break;
                }


            } while (gameOn == true);
        }
        else if (playGame == 'n')
        {
            cout << "Okay bye!" << endl;
            playGame = 'n';
        }
        else if (playGame =='o'){
            cout << "Game is over!" << endl;
            cout << "   " << endl;
            playGame = 'y';
        }
        else
        {
            cout << "Your entry was invalid!" << endl;
            cout << "   " << endl;
            playGame = 'y';
        }

    } while (playGame == 'y');
}