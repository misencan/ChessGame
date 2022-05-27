#ifndef PIECE_H
#define PIECE_H


//Declaration of Piece class
class Piece
{
public:

//constructor that includes color, symbol, x/y coordinates
Piece(bool, char, int, int);
Piece();

//public member variables
bool has_moved;
bool is_white;
char piece_symbol;
int x_loc,y_loc;
bool en_passantable;

//Function to display information
void DisplayInfo();

//

};

#endif