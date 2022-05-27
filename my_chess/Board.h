#ifndef BOARD_H
#define BOARD_H
#include "Piece.h"

//Declaration of board class, which is represents the board using a 2d array of piece pointers

class Board
{
    public:

    //Default constructor
    Board();

    //Bool representing who's turn it is
    bool white_turn;

    //Sets up beginning position of game board
    void Initialize_Board();

    //Displays the current game position
    void Display_Board();

    //Gets pointer to a pieces in the position square
    //Returns a pointer to a piece at a x,y coordinate on the board
    Piece* GetPieceAt(int, int);


    //Moves piece's location
    //Returns true if the inputed move is made
    bool MovePiece(int,int,int,int);

    //Checks if there is a piece in between current square and (x_delta,y_delta) spaces from there
    //Doesn't include destination square
    bool IsPieceBetween(int,int,int x_delta,int y_delta);

    //Checks if there is a piece at the location square and if it is on the same team as the Piece*
    //Returns 0 for no piece there, -1 for enemy piece, and +1 for friendly piece
    int IsFriendlyPieceAt(Piece*,int,int);

    //Checks if move is legal
    //Returns true if legal and false if not legal
    bool Check_Move_Legal(Piece*, int, int);

    //Checks board for any pawns on the back rank
    void Promote_Pawns(); //Check for pawn promotion
    void Queen_Pawns(); //Promote into queens
    void Knight_Pawns(); //Promote into knights
    void Bishop_Pawns(); //Promote into Bishops
    void Rook_Pawns(); //Promote into rooks

    //Checks the status of the kings
    //Returns 1 if only the black king is captured, returns 2 if only the white king is captured
    //Returns 3 if both are captured, returns 0 if none captured
    int King_Exists();

    //Arrays containing the pointers to pieces
    Piece* white_pieces[16];
    Piece* black_pieces[16];


};

#endif