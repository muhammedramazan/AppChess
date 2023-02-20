#include "board.h"

void Board::reset()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (table[i][j] != nullptr)
            {
                delete table[i][j];
                table[i][j] = nullptr;
            }
        }
    }
    blackPiece.clear();
    whitePiece.clear();
}

Piece *Board::matcher(char in, Color _c, short int _y, short int _x)
{
    Piece *out = nullptr;

    switch (in)
    {
    case 'p':
        out = new Pawn(_c, _y, _x);
        break;
    case 'a':
        out = new Knight(_c, _y, _x);
        break;
    case 'f':
        out = new Bishop(_c, _y, _x);
        break;
    case 'k':
        out = new Rook(_c, _y, _x);
        break;
    case 'v':
        out = new Queen(_c, _y, _x);
        break;
    case 's':
        out = new King(_c, _y, _x);
        break;
    default:
        out = nullptr;
        break;
    }
    return out;
}

void Board::CreatePiece(std::string tmp, short int _y, short int _x)
{

    Piece *_piece = nullptr;

    if (tmp.at(1) != '-')
    {

        if (tmp.at(1) == 's')
        {
            _piece = matcher(tmp.at(0), Black, _y, _x);
            blackPiece.push_back(_piece);
        }
        else if (tmp.at(1) == 'b')
        {
            _piece = matcher(tmp.at(0), White, _y, _x);
            whitePiece.push_back(_piece);
        }
    }
    table[_y][_x] = _piece;
}

Board::Board(std::string _table[X][Y])
{

    whitePiece.clear();
    blackPiece.clear();

    for (short int _y = 0; _y < Y; _y++) // vertical
    {
        for (short int _x = 0; _x < X; _x++) //  horizontal
        {
            CreatePiece(_table[_y][_x], _y, _x);
        }
    }
}

Board::~Board()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (table[i][j] != nullptr)
            {
                delete table[i][j];
                table[i][j] = nullptr;
            }
        }
    }
}