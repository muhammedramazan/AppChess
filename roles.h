#ifndef _Roles
#define _Roles
#include "piece.h"
/**
 * @brief 7 tane Piece sınıfından  türetilmiş sınıf var. herbirinin hedef konumu belirlemesi farklı
 *
 */

/**
 * @brief Piyonlar sadece ileri doğru hareket eder bu nedenler beyaz ve siyah için farklı hedef belirleme kullanıldı.
 * tüm hedef noktaların tahta içinde olduğu kontrol edilmeden bir sonraki işlem yaplmıyor.
 *
 */
class Pawn : public Piece
{
public:
    Pawn(Color _color, short int _y, short int _x);
    void checkPosition(Piece *table[8][8]);
};

/**
 * @brief Filler önlerine çıkan ilk hedefi tehdit ettiği ve dost taşın arkasına saldıramayacağı için bu durumlardan sonra yeni hedef araması sonlanıyor
 * 4 çarpraz yöne saldırı yaptığı için  her bir istikamet için ayrı ayrı hedef arıyor.
 *
 */
class Bishop : public Piece
{
public:
    Bishop(Color _color, short int _y, short int _x);
    void checkPosition(Piece *table[8][8]);
};

/**
 * @brief Atlar 8 farklı konumunda bulunan tüm taşları kontrol eder
 * hedef konumların tahtada olduğu kontrol edilir
 *
 */
class Knight : public Piece
{
public:
    Knight(Color _color, short int _y, short int _x);
    void checkPosition(Piece *table[8][8]);
};

/**
 * @brief Kaleler 4 farklı yöne doğrusal hedef arama yapar diğer tüm özellikler filler ile aynı
 * hedef konumların tahtada olduğu kontrol edilir
 *
 */
class Rook : public Piece
{
public:
    Rook(Color _color, short int _y, short int _x);
    void checkPosition(Piece *table[8][8]);
};

/**
 * @brief fil ve kalenin hedef aramalarının birleştirilmiş hali
 * hedef konumın tahtada olup olmadığı kontrol ediliyor
 *
 */
class Queen : public Piece
{
public:
    Queen(Color _color, short int _y, short int _x);
    void checkPosition(Piece *table[8][8]);
};
/**
 * @brief bitişiğindeki çevre noktalar hedef
 * hedef konumun tahtada olup olmadığı kontrol ediliyor
 */
class King : public Piece
{
public:
    King(Color _color, short int _y, short int _x);
    void checkPosition(Piece *table[8][8]);
};

#endif