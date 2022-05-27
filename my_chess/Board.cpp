#include <iostream>
#include "Board.h"
#include <math.h>
using namespace std;

Board::Board()
{
}

void Board::Initialize_Board()
{
    white_pieces[0] = new Piece(true,'R',1,1);
    white_pieces[1] = new Piece(true,'R',8,1);
    white_pieces[2] = new Piece(true,'N',2,1);
    white_pieces[3] = new Piece(true,'N',7,1);
    white_pieces[4] = new Piece(true,'B',3,1);
    white_pieces[5] = new Piece(true,'B',6,1);
    white_pieces[6] = new Piece(true,'Q',4,1);
    white_pieces[7] = new Piece(true,'K',5,1);
    white_pieces[8] = new Piece(true,'P',1,2);
    white_pieces[9] = new Piece(true,'P',2,2);
    white_pieces[10] = new Piece(true,'P',3,2);
    white_pieces[11] = new Piece(true,'P',4,2);
    white_pieces[12] = new Piece(true,'P',5,2);
    white_pieces[13] = new Piece(true,'P',6,2);
    white_pieces[14] = new Piece(true,'P',7,2);
    white_pieces[15] = new Piece(true,'P',8,2);

    black_pieces[0] = new Piece(false,'r',1,8);
    black_pieces[1] = new Piece(false,'r',8,8);
    black_pieces[2] = new Piece(false,'n',2,8);
    black_pieces[3] = new Piece(false,'n',7,8);
    black_pieces[4] = new Piece(false,'b',3,8);
    black_pieces[5] = new Piece(false,'b',6,8);
    black_pieces[6] = new Piece(false,'q',4,8);
    black_pieces[7] = new Piece(false,'k',5,8);
    black_pieces[8] = new Piece(false,'p',1,7);
    black_pieces[9] = new Piece(false,'p',2,7);
    black_pieces[10] = new Piece(false,'p',3,7);
    black_pieces[11] = new Piece(false,'p',4,7);
    black_pieces[12] = new Piece(false,'p',5,7);
    black_pieces[13] = new Piece(false,'p',6,7);
    black_pieces[14] = new Piece(false,'p',7,7);
    black_pieces[15] = new Piece(false,'p',8,7);
}

//Returns a pointer to a piece at a x,y coordinate on the board if it exists
Piece* Board::GetPieceAt(int x, int y)
{
    for(int i=0;i<16;i++)
    {
        if(this->white_pieces[i]->x_loc == x && this->white_pieces[i]->y_loc == y)
        {
            return this->white_pieces[i];
        }
        if(this->black_pieces[i]->x_loc == x && this->black_pieces[i]->y_loc == y)
        {
            return this->black_pieces[i];
        }
    }
    return 0;        
}

//works
void Board::Display_Board()
{
    Piece* piece;

    for(int row=8;row>=1;row--)
    {
        cout << row << " ";
        for(int column=1;column<=8;column++)
        {
            if(piece=this->GetPieceAt(column,row))
            {
                cout << piece->piece_symbol << " ";
            }
            else
            {
                cout << "* ";
            }
        }
        cout << endl;
    }
    cout << "  a b c d e f g h" << endl << endl;
}

bool Board::MovePiece(int x_current,int y_current, int x_dest, int y_dest)
{
    Piece* piece = GetPieceAt(x_current,y_current);
    Piece* piece_at_dest;
    int x_delta = x_dest - x_current;
    int y_delta = y_dest - y_current;

    

    if(this->Check_Move_Legal(piece,x_dest,y_dest) == true)
    {
        //Check if we are capturing a piece
        if(piece_at_dest = this->GetPieceAt(x_dest,y_dest))
        {
            Piece* piece_holder;
            //Explode the pieces
            piece->x_loc = 999;
            piece->y_loc = 999;
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    if(piece_holder = this->GetPieceAt(x_dest+i,y_dest+j))
                    {
                        if((GetPieceAt(x_dest+i,y_dest+j)->piece_symbol != 'P') && (GetPieceAt(x_dest+i,y_dest+j)->piece_symbol != 'p'))
                        {
                        piece_holder->x_loc = 999;
                        piece_holder->y_loc = 999;
                        }
                    }
                }
            }
            piece_holder = this->GetPieceAt(x_dest,y_dest);
            piece_holder->x_loc = 999;
            piece_holder->y_loc = 999;
            cout << "kaboom" << endl;
            return true;
        }
        //If not capturing a piece, update the piece's location
        else
        {
        piece->x_loc = x_dest;
        piece->y_loc = y_dest;

        piece->has_moved = true;
        return true;
        }
    }
    else
    //Return false if piece move can't be made
    {
        return false;
    }
}

//works
bool Board::IsPieceBetween(int x_current,int y_current, int x_delta,int y_delta)
{
    //Finds signs for the x/y direction of movement
    //x_step=-1:left, x_step=1:right, x_step=0: no x movement

    int x_step;
    int y_step;

    if(x_delta == 0)
    {
        x_step = x_delta/fabs(x_delta);
    }
    else
    {
        x_step = x_delta/fabs(x_delta);
    }
    if(y_delta == 0)
    {
        y_step = x_delta/fabs(x_delta);
    }
    else
    {
        y_step = 0;
    }
    int larger_delta;

    if(x_delta>=y_delta)
    {
        larger_delta = x_delta; 
    }
    else
    {
        larger_delta = y_delta;
    }

    for(int steps=1;steps<fabs(larger_delta)-1;steps++)
    {
        if(this->GetPieceAt(x_current+x_step*steps,y_current+y_step*steps))
        {
            cout << "There is a piece in the way!" << endl;
            return true;
        }
    }
    return false;
}

//works
int Board::IsFriendlyPieceAt(Piece* piece,int x_dest,int y_dest)
{
    Piece* piece_holder;
    //Check if there is a piece there, if so, store the piece in piece_holder
    if(piece_holder = this->GetPieceAt(x_dest,y_dest))
    {
        piece_holder = this->GetPieceAt(x_dest,y_dest);
        //Compare colors of pieces
        if(piece->is_white == piece_holder->is_white)
        {
            return 1;
        }
        else if(piece->is_white != piece_holder->is_white)
        {
            return -1;
        }
    }
    return 0;
}

//Series of tests to see if a move is legal
bool Board::Check_Move_Legal(Piece* piece, int x_dest, int y_dest)
{
    char piece_type = piece->piece_symbol;

    int x_delta = x_dest - piece->x_loc;
    int y_delta = y_dest - piece->y_loc;

    //Piece* piece_holder;

    switch (piece_type)
    {
        case 'B':
        case 'b':
        {
            //Check if bishop is not moving along diagonal
            if(fabs(x_delta) != fabs(y_delta))
            {
                cout << "Bishop must move along diagonal!" << endl;

                return false;
            }
            break;
        }

        case 'R':
        case 'r':
        {
            //Check if rook is not moving straight
            if(x_delta != 0 && y_delta != 0)
            {
                cout << "Rook must move straight" << endl;
                return false;
            }
            break;
        }

        case 'Q':
        case 'q':
        {
            //Queen must move in diagonal or straight
            if((x_delta != 0 && y_delta != 0) && (fabs(x_delta) != fabs(y_delta)))
            {
                return false;
            }
            break;
        }

        case 'K':
        case 'k':
        {
            /*
            //Check conditions for castling
            if(x_delta == 2 && y_delta == 0)
            {
                //King is trying to castle to the right
                if(x_delta>0)
                {
                    //Store the piece to the far right of the king in piece_holder
                    piece_holder = this->GetPieceAt(piece->x_loc+3,piece->y_loc);
                }
                //King is trying to castle to the left
                else
                {
                    //Store the piece to the far left of the king in piece_holder
                    piece_holder = this->GetPieceAt(piece->x_loc-4,piece->y_loc);
                }

                //King can't castle if it moved
                if(piece->has_moved == true)
                {
                    cout << "Can't castle, the king has already moved!" << endl;
                    return false;
                }
                //Check if the piece where rook should be is an enemy piece
                else if(this->IsFriendlyPieceAt(piece, (piece->x_loc)+x_delta,piece->y_loc) == -1)
                {
                    cout << "There is no friendly rook here" << endl;
                    return false;
                }
                //Piece where rook should be is not a rook
                else if(piece_holder->piece_symbol != 'r' && piece_holder->piece_symbol != 'R')
                {
                    cout << "There is no friendly rook here!!" << endl;
                    return false;
                }
                else if(piece_holder->has_moved == true)
                {
                    cout << "The rook has already moved!" << endl;
                    return false;
                }
                else if()

                return true;
            }
            */

            //King must move to adjacent square
            if(fabs(x_delta)>1 || fabs(y_delta)>1)
            {
                cout << "King can only move to adjacent squares!" << endl;
                return false;
            }
            break;
        }

        case 'N':
        case 'n':
        {
            //Knight must move in L shape
            if(((fabs(x_delta) == 1 && fabs(y_delta) == 2) == false) && ((fabs(x_delta) == 2 && fabs(y_delta) == 1) == false))
            {
                cout << "Knights can only move in an L shape!" << endl;
                return false;
            }
            break;
        }

        case 'P':
        case 'p':
        {
            bool possible_pawn_move = false;

            //Check if pawn move is a possible pawn move
            //Includes moving forward once, moving forward twice, and taking diagonally
            if(x_delta == 0 && fabs(y_delta) == 1)
            {
                if(GetPieceAt(piece->x_loc,piece->y_loc+y_delta) == 0)
                {
                    possible_pawn_move = true;
                }
                
            }
            else if(x_delta == 0 && fabs(y_delta) == 2)
            {
                possible_pawn_move = true;
            }
            else if(fabs(x_delta) == 1 && fabs(y_delta) == 1)
            {
                Piece* temp_piece = this->GetPieceAt(x_dest,y_dest);
                if(piece->is_white != temp_piece->is_white)
                {
                    possible_pawn_move = true;
                }
                else
                {
                possible_pawn_move = false;
                }
            }

            //Check if it is a possible pawn move
            if(possible_pawn_move == false)
            {
                cout << "Illegal pawn move" << endl;
                return false;
            }
            //Check if white pawn is moving backwards
            else if(piece->is_white && y_delta < 0)
            {
                cout << "Pawns can't move backwards!" << endl;
                return false;
            }
            //Check if black pawn is moving backwards
            if(piece->is_white == false && y_delta > 0)
            {
                cout << "Pawns can't move backwards!" << endl;
                return false;
            }
            //Check if pawn has moved before if it moving forward twice
            if(fabs(y_delta) == 2 && piece->has_moved == true)
            {
                cout << "This pawn can't move forward twice, it has already moved!" << endl;
                return false;
            }
            break;
        }



    }
    /*
    //Check if there is a piece between the piece moved and its target location
    //Does not apply to knights since they can jump
    if(piece_type!='N' && piece_type!='n')
    {
         if(this->IsPieceBetween(piece->x_loc,piece->y_loc,x_delta,y_delta) == true)
        {
        cout  << "There is a piece in the way!" << endl;

        return false;
        }
    }
    */
    //Check if there is a friendly piece at the target location
    if(this->IsFriendlyPieceAt(piece,x_dest,y_dest) == true)
    {
        cout << "There is a friendly piece at the target square!" << endl;

        return false;
    }
    //Check if the current square and destination square is the same
    else if(piece->x_loc == x_dest && piece->y_loc == y_dest)
    {
        cout << "Illegal move: origin square and destination the same!" << endl;

        return false;
    }
    //Passed all test
    return true;
}

void Board::Promote_Pawns()
{
    for(int i=0;i<16;i++)
    {
        bool can_promote = false;
        char choice;
        //Check white_peices array for a white pawn on the 8th rank 
        if(white_pieces[i]->y_loc == 8 && white_pieces[i]->piece_symbol=='P')
        {
            can_promote = true;
        }
        //Check black_pieces array for a black pawn on the 1st rank
        if(black_pieces[i]->y_loc == 1 && black_pieces[i]->piece_symbol=='p')
        {
            can_promote = true;
        }

        if(can_promote == true)
        {
            while(choice != 'Q' && choice != 'N' && choice != 'R' && choice != 'B')
            {
                cout << "What would you like to promote to?" << endl;
                cout << "(Q)ueen, (R)ook, (B)ishop, or K(N)ight?" << endl;
                cin >> choice;
                switch(choice)
                {
                    case 'Q':
                    {
                        this->Queen_Pawns();
                        break;
                    }
                    case 'B':
                    {
                        this->Bishop_Pawns();
                        break;
                    }
                    case 'N':
                    {
                        this->Knight_Pawns();
                        break;
                    }
                    case 'R':
                    {
                        this->Rook_Pawns();
                        break;
                    }
                }
            }
        }
    }
}
void Board::Queen_Pawns()
{
    for(int i=0;i<16;i++)
    {
        //Check white_peices array for a white pawn on the 8th rank and change them into queens
        if(white_pieces[i]->y_loc == 8 && white_pieces[i]->piece_symbol=='P')
        {
            white_pieces[i]->piece_symbol = 'Q';
        }
        //Check black_pieces array for a black pawn on the 1st rank and change them into queens
        if(black_pieces[i]->y_loc == 1 && black_pieces[i]->piece_symbol=='p')
        {
            black_pieces[i]->piece_symbol = 'q';
        }
    }
}

void Board::Knight_Pawns()
{
    for(int i=0;i<16;i++)
    {
        //Check white_peices array for a white pawn on the 8th rank and change them into queens
        if(white_pieces[i]->y_loc == 8 && white_pieces[i]->piece_symbol=='P')
        {
            white_pieces[i]->piece_symbol = 'N';
        }
        //Check black_pieces array for a black pawn on the 1st rank and change them into queens
        if(black_pieces[i]->y_loc == 1 && black_pieces[i]->piece_symbol=='p')
        {
            black_pieces[i]->piece_symbol = 'n';
        }
    }
}

void Board::Bishop_Pawns()
{
    for(int i=0;i<16;i++)
    {
        //Check white_peices array for a white pawn on the 8th rank and change them into queens
        if(white_pieces[i]->y_loc == 8 && white_pieces[i]->piece_symbol=='P')
        {
            white_pieces[i]->piece_symbol = 'B';
        }
        //Check black_pieces array for a black pawn on the 1st rank and change them into queens
        if(black_pieces[i]->y_loc == 1 && black_pieces[i]->piece_symbol=='p')
        {
            black_pieces[i]->piece_symbol = 'b';
        }
    }
}

void Board::Rook_Pawns()
{
    for(int i=0;i<16;i++)
    {
        //Check white_peices array for a white pawn on the 8th rank and change them into queens
        if(white_pieces[i]->y_loc == 8 && white_pieces[i]->piece_symbol=='P')
        {
            white_pieces[i]->piece_symbol = 'R';
        }
        //Check black_pieces array for a black pawn on the 1st rank and change them into queens
        if(black_pieces[i]->y_loc == 1 && black_pieces[i]->piece_symbol=='p')
        {
            black_pieces[i]->piece_symbol = 'r';
        }
    }
}

int Board::King_Exists()
{
    //Black king captured
    if(white_pieces[7]->x_loc != 999 && black_pieces[7]->x_loc == 999)
    {
        return 1;
    }
    //White king captured
    else if(white_pieces[7]->x_loc == 999 && black_pieces[7]->x_loc != 999)
    {
        return 2;
    }
    //Both dead
    else if(white_pieces[7]->x_loc == 999 && black_pieces[7]->x_loc == 999)
    {
        return 3;
    }
    return 0;
}