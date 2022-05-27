#include <iostream>
#include "Piece.h"
using namespace std;

Piece::Piece()
{
}

//Constructor definition
Piece::Piece(bool is_white,char piece_symbol, int x_loc, int y_loc)
{
    this->is_white = is_white;
    this->piece_symbol = piece_symbol;
    this->x_loc = x_loc;
    this->y_loc = y_loc;
    this->has_moved = false;
    this->en_passantable = false;
}

void Piece::DisplayInfo()
{
    cout << "Piece symbol: " << this->piece_symbol << endl;;
    if(this->is_white=true)
    {
        cout << "white" << endl;
    }
    else
    {
        cout << "black" << endl;
    }
    cout << "x_loc: " << this->x_loc << endl;
    cout << "y_loc: " << this->y_loc << endl;
    if(this->has_moved)
    {
        cout << "Has moved" << endl;
    }
    else
    {
        cout << "Has not moved" << endl;
    }
}
