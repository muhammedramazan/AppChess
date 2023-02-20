#include "roles.h"

Pawn::Pawn(Color _color, short int _y, short int _x) : Piece("Pawn", _color, _y, _x)
{
    point = 1.;
}
void Pawn::checkPosition(Piece *table[8][8])
{
    int _x1, _x2, _y;
    _x1 = _x2 = posX, _y = posY;
    if (color == White)
    {
        _x1--, _x2++, _y--;
        if (_y >= 0)
        {
            if (_x1 >= 0)
            {
                preAttack(table[_y][_x1]);
            }
            if (_x2 >= 0)
            {
                preAttack(table[_y][_x2]);
            }
        }
    }
    else if (color == Black)
    {
        _x1--, _x2++, _y++;
        if (_y <= 7)
        {
            if (_x1 >= 0)
            {
                preAttack(table[_y][_x1]);
            }
            if (_x2 >= 0)
            {
                preAttack(table[_y][_x2]);
            }
        }
    }
}
Bishop::Bishop(Color _color, short int _y, short int _x) : Piece("Bishop", _color, _y, _x)
{
    point = 3.;
}
void Bishop::checkPosition(Piece *table[8][8])
{
    int _x = 0, _y = 0;

    _x = posX + 1, _y = posY + 1;
    while (_x <= 7 && _y <= 7)
    {
        if (table[_y][_x] != nullptr)
        {
            preAttack(table[_y][_x]);
            break;
        }
        _x++, _y++;
    }

    _x = posX - 1, _y = posY + 1;
    while (_x >= 0 && _y <= 7)
    {

        if (table[_y][_x] != nullptr)
        {
            preAttack(table[_y][_x]);
            break;
        }
        _x--, _y++;
    }

    _x = posX - 1, _y = posY - 1;
    while (_x >= 0 && _y >= 0)
    {

        if (table[_y][_x] != nullptr)
        {
            preAttack(table[_y][_x]);
            break;
        }
        _x--, _y--;
    }

    _x = posX + 1, _y = posY - 1;
    while (_x <= 7 && _y >= 0)
    {

        if (table[_y][_x] != nullptr)
        {
            preAttack(table[_y][_x]);
            break;
        }
        _x++, _y--;
    }
}
Knight::Knight(Color _color, short int _y, short int _x) : Piece("Knight", _color, _y, _x)
{
    point = 3.;
}
void Knight::checkPosition(Piece *table[8][8])
{
    int _x[8], _y[8];
    _x[0] = posX + 2, _y[0] = posY - 1;
    _x[1] = posX + 2, _y[1] = posY + 1;
    _x[2] = posX + 1, _y[2] = posY - 2;
    _x[3] = posX + 1, _y[3] = posY - 2;
    _x[4] = posX - 2, _y[4] = posY + 1;
    _x[5] = posX - 2, _y[5] = posY - 1;
    _x[6] = posX - 1, _y[6] = posY + 2;
    _x[7] = posX - 1, _y[7] = posY - 1;
    for (int i = 0; i <= 7; i++)
    {
        if (_x[i] >= 0 && _x[i] <= 7 && _y[i] >= 0 && _y[i] <= 7)
        {
            preAttack(table[_y[i]][_x[i]]);
        }
    }
}
Rook::Rook(Color _color, short int _y, short int _x) : Piece("Rook", _color, _y, _x)
{
    point = 5.;
}
void Rook::checkPosition(Piece *table[8][8])
{
    int _x = 0, _y = 0;

    _x = posX + 1, _y = posY;
    while (_x <= 7)
    {
        if (table[_y][_x] != nullptr)
        {
            preAttack(table[_y][_x]);
            break;
        }
        _x++;
    }

    _x = posX - 1, _y = posY;
    while (_x >= 0)
    {
        if (table[_y][_x] != nullptr)
        {
            preAttack(table[_y][_x]);
            break;
        }
        _x--;
    }

    _y = posY - 1, _x = posX;
    while (_y >= 0)
    {
        if (table[_y][_x] != nullptr)
        {
            preAttack(table[_y][_x]);
            break;
        }
        _y--;
    }

    _y = posY + 1, _x = posX;
    while (_y <= 7)
    {
        if (table[_y][_x] != nullptr)
        {
            preAttack(table[_y][_x]);
            break;
        }
        _y++;
    }
}
Queen::Queen(Color _color, short int _y, short int _x) : Piece("Queen", _color, _y, _x)
{
    point = 9.;
}
void Queen::checkPosition(Piece *table[8][8])
{

    int _x = 0, _y = 0;

    _x = posX + 1, _y = posY;
    ;
    while (_x <= 7)
    {
        if (table[_y][_x] != nullptr)
        {
            preAttack(table[_y][_x]);
            break;
        }
        _x++;
    }

    _x = posX - 1, _y = posY;
    while (_x >= 0)
    {
        if (table[_y][_x] != nullptr)
        {
            preAttack(table[_y][_x]);
            break;
        }
        _x--;
    }

    _y = posY - 1, _x = posX;
    while (_y >= 0)
    {
        if (table[_y][_x] != nullptr)
        {
            preAttack(table[_y][_x]);
            break;
        }
        _y--;
    }

    _y = posY + 1, _x = posX;
    while (_y <= 7)
    {
        if (table[_y][_x] != nullptr)
        {
            preAttack(table[_y][_x]);
            break;
        }
        _y++;
    }

    _x = posX + 1, _y = posY + 1;
    while (_x <= 7 && _y <= 7)
    {
        if (table[_y][_x] != nullptr)
        {
            preAttack(table[_y][_x]);
            break;
        }
        _x++, _y++;
    }

    _x = posX - 1, _y = posY + 1;
    while (_x >= 0 && _y <= 7)
    {

        if (table[_y][_x] != nullptr)
        {
            preAttack(table[_y][_x]);
            break;
        }
        _x--, _y++;
    }

    _x = posX - 1, _y = posY - 1;
    while (_x >= 0 && _y >= 0)
    {

        if (table[_y][_x] != nullptr)
        {
            preAttack(table[_y][_x]);
            break;
        }
        _x--, _y--;
    }

    _x = posX + 1, _y = posY - 1;
    while (_x <= 7 && _y >= 0)
    {

        if (table[_y][_x] != nullptr)
        {
            preAttack(table[_y][_x]);
            break;
        }
        _x++, _y--;
    }
}
King::King(Color _color, short int _y, short int _x) : Piece("King", _color, _y, _x)
{
    point = 100.;
}
void King::checkPosition(Piece *table[8][8])
{
    int _x[8], _y[8];
    _x[0] = posX - 1, _y[0] = posY - 1;
    _x[1] = posX - 1, _y[1] = posY + 0;
    _x[2] = posX - 1, _y[2] = posY + 1;
    _x[3] = posX + 0, _y[3] = posY - 1;
    _x[4] = posX + 0, _y[4] = posY + 1;
    _x[5] = posX + 1, _y[5] = posY - 1;
    _x[6] = posX + 1, _y[6] = posY + 0;
    _x[7] = posX + 1, _y[7] = posY + 1;
    for (int i = 0; i < 8; i++)
    {
        if (_y[i] >= 0 && _y[i] <= 7 && _x[i] >= 0 && _x[i] <= 7)
            preAttack(table[_y[i]][_x[i]]);
    }
}