#ifndef _Board
#define _Board
#define Y 8 // vertical
#define X 8 // horizontal

#include <vector>
#include <string>
#include "piece.h"
#include "roles.h"

/**
 * @brief Taşların oluşturul ve 2 boyutlu arrayde yerlerini ayarlıyor.
 * her bir grup(beyaz yada siyah) kendi içinde refaransları ayriyetten tutuluyor. 
 * new ile oluturulduğu için destructor da delete işlemi yapılıyor
 */
class Board
{
public:
    std::vector<Piece *> blackPiece;
    std::vector<Piece *> whitePiece;

    Piece *table[8][8];

public:
    Board() {}
    Board(std::string[Y][X]);
    ~Board();
    void reset();

private:
    void CreatePiece(std::string, short int, short int);
    Piece *matcher(char, Color, short int, short int);
};

#endif