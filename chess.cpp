#ifndef _CHESS
#define _CHESS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "board.h"
#include "game.h"
#include "debug.h"
int main()
{
    // Debug yapmak için bir adet flag oluşturuldu

    std::ifstream MyReadFile;

    std::cout << "if u open debug write debug\n";
    std::string __debug = "";
    std::cin >> __debug;
    Debug::setDebug(false);
    if (__debug == "debug")
        Debug::setDebug(true);

    while (1)
    {
        std::string inputFileTxt = "board1.txt";
        // Dökümanın bulunğu dosyanın yolunu girilceği yer
        std::cout << "Enter your input file name like \"board1.txt\"  for exit enter e\n";
        std::cin >> inputFileTxt;
        if (inputFileTxt == "e")
            break;
        MyReadFile.open(inputFileTxt);

        std::string line;
        std::string table[Y][X];

        int currentY = 0;
        // Satır satır dosya okunuyor
        while (std::getline(MyReadFile, line))
        {
            int sizeText = line.length();
            for (int currentX = 0; currentX < X; currentX++)
            {
                // Tüm taşlar 8'e 8 bir arrayda tutuluyor
                table[currentY][currentX] = line.substr(currentX * 3, 2);
            }
            currentY++;
        }
        // Burada girdi ile parçalar oluşturuluyor.
        Board playBoard(table);

        Game checker;
        //  taşların tehdit durumu ve puan hesaplama burada yapılıyor.
        checker.play(playBoard);
        playBoard.reset();
        MyReadFile.close();
    }

    return 0;
}
#endif