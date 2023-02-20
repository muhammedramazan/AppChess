#ifndef _Piece
#define _Piece
#include <string>
#include <vector>
#include <iostream>
#include "debug.h"
enum Color
{
    White,
    Black
};
/**
 * @brief her bir taşın adı, bulunduğu kordinat bilgileri, rengi, puanı ve tehlikede olup olmadığını belirten bayrak bulunur.
 * checkPosition functionu bu sınıftan türetilmiş sınıf için özel olacağından virtual keywordu ile override yapılmasına imkan sağlıyor.
 * Diğer functionlar temel işlemleri sağlıyor.
 *
 */
class Piece
{
public:
    short int posX, posY;
    bool inDanger;
    float point;
    // if color is false , to mean it is white;
    Color color;
    std::string name;

public:
    Piece();
    Piece(std::string _name, Color _color, short int _y, short int _x);
    void virtual checkPosition(Piece *table[8][8]);
    float getPoint();
    bool sameColor(Piece *p);
    void attacked();
    void beSafe();
    void preAttack(Piece *p);
    void pos();
};
#endif