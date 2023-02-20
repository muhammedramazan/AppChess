#include "game.h"

void Game::play(Board &myBoard)
{
    float whiteScore = 0., blackScore = 0.;
    /**
     * @brief tüm siyah taşların hedef konumları kontrl edliyor
     *
     */
    for (int i = 0; i < myBoard.blackPiece.size(); i++)
    {
        Piece *p = myBoard.blackPiece[i];
        p->checkPosition(myBoard.table);
    }

    // tüm beyaz taşların hedef konumları tesbit ediliyor
    for (int i = 0; i < myBoard.whitePiece.size(); i++)
    {
        Piece *p = myBoard.whitePiece[i];
        p->checkPosition(myBoard.table);
    }

    // tüm siyah taşarın puanları toplanıyor tehdit edilmeleri getPoint içinde kontrol edilyor
    for (int i = 0; i < myBoard.blackPiece.size(); i++)
    {
        Piece *p = myBoard.blackPiece[i];

        blackScore += p->getPoint();
    }
    // tüm beyaz taşarın puanları toplanıyor tehdit edilmeleri getPoint içinde kontrol edilyor

    for (int i = 0; i < myBoard.whitePiece.size(); i++)
    {
        Piece *p = myBoard.whitePiece[i];
        whiteScore += p->getPoint();
    }

    // Burada debug yapıldığı zaman tahtanın görserli tehdit edilen taşları belirtecek şekilde consola yazılıyor.
    if (Debug::getDebug())
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (myBoard.table[i][j] != nullptr)
                {
                    std::cout << (myBoard.table[i][j]->inDanger ? "**" : "//") << std::setw(6) << std::setfill(' ') << myBoard.table[i][j]->name << "||";
                }
                else
                {
                    std::cout << std::setw(10) << "||";
                }
            }
            std::cout << "\n";
        }
    }
    // Sonuçlar ekrana yazılıyor
    std::cout << "Beyaz :: " << whiteScore << "\n";
    std::cout << "Siyah :: " << blackScore << "\n";
}