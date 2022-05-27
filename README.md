# EC327_Team_Success

Only Necessary files to run the game are Board.h, Board.cpp Piece.h, Piece.cpp, makefile
Currently doing testing in testing.cpp

Our code is in my_chess folder; the src folder contains code we got from prior sources to use as a starting point for our project.

To test commands on testing.cpp, type make which creates an executable called test

Couldn't get IsPieceBetween member of board class to work, so currently all pieces can jump over eachother.

To play the game create a board object and then initialize the board by calling method
Board::Initialize_Board()
This also uses the Piece class to create all the pieces and places them on the board.

To make a move use the Board::Move_Piece(int x_current,int y_current,int x_dest,int y_dest) method
The first 2 arguments are the x and y coordinates of the 8x8 board which represents the piece you would
like to move. The second 2 arguments are the x and y coordinates of where you would like to move the piece.
This method returns a bool of whether or not the inputted move is legal, which can be used in the main file
to ask for another move.

To display the current position of the board, use method Board::Display();

To check if the game is over, call the Board::King_Exists() method. This checks the board to see if the 
kings are alive and returns an int depending on the status of them. This method should be used in the 
main function to check if the current game is over. The return values are as follows
0: neither king captured
1: only black king captured
2: only white king captured
3: both kings captured

To promote pawns we call Promote_Pawns() which checks the board for a pawn that can be promoted and asks
the user for the piece they want to promote into. Promote_Pawns() then calls Queen_Pawns(), Rook_Pawns(),
Bishop_Pawns(), or Knight_Pawns() depending on the users choice.

Main function stuff:
Before each turn call Display_Board() to display the game
Main function should ask user for an 4 ints for the Move_Piece method, but before we do that we will use 
Get_Piece_At(int x, int y)->Is_White to check if they are allowed to move the piece. If they can't, ask
for another move. Also, if the Move_Peice method returns false, main should ask for another move since the 
move was not allowed. At the end of each turn call King_Exists() to check if the game should be over and
Promote_Pawns() to promote any pawns.

NOTE: All the codes were written from scratch. The files in SRC folder were used for inspiration and understanding
what kind of classs we can need. We still uploaded the codes we used as a inspiration and our initial understanding.
