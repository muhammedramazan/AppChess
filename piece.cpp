#include "piece.h"
Piece::Piece()
{
    name = "";
    posX = -1;
    posY = -1;
    inDanger = false;
}
Piece::Piece(std::string _name, Color _color, short int _y, short int _x)
{
    name = _name;
    color = _color;
    posX = _x;
    posY = _y;
    inDanger = false;
}
void Piece::checkPosition(Piece *table[8][8]) {}
float Piece::getPoint() { return (inDanger ? point / 2. : point); }
bool Piece::sameColor(Piece *p) { return (color == p->color); }
void Piece::attacked()
{
    if (Debug::getDebug())
    {
        pos();
        std::cout << "\n";
    }
    inDanger = true;
}
void Piece::beSafe() { inDanger = false; }
void Piece::preAttack(Piece *p)
{
    if (p != nullptr)
    {
        if (!sameColor(p))
        {
            if (Debug::getDebug())
            {
                pos();
                std::cout << "  ->  ";
            }
            p->attacked();
        }
    }
}
void Piece::pos() { std::cout << color << " : " << name << " : " << posY << " : " << posX; }