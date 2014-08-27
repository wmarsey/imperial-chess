#ifndef PIECE_HPP
#define PIECE_HPP

#include <vector>
#include <map>
#include <string>
using namespace std;

enum PieceType{
  none,
  king,
  queen,
  knight,
  bishop,
  rook,
  pawn
};

class Piece{
protected:
  bool black;
  PieceType type;
  Piece();

  //helper checks for square relations / square validity
  bool onDiagonal(const string &start, const string &end) const;
  bool inLine(const string &start, const string &end) const;
  bool adjacent(const string &start, const string &end) const;
  bool onBoard(const string &given) const;
  bool coordValid(const string &given) const;

  //functions for that check against the board for move validity
  bool clearPath(const vector<string> &journey, const map<string, Piece*> &theBoard) const;
  void creepDiagonal(const string &given, vector<string> &moves, const map<string, Piece*> &board) const;
  void creepInLine(const string &given, vector<string> &moves, const map<string, Piece*> &board) const;
  int canMoveTo(const string &orig, const string &dest, const map<string, Piece*> &board) const;

  //function that works out a straight line between to square coordinates
  vector<string> path(const string &start, const string &end) const;
public:
  //firstMove default: true
  bool firstMove;

  //access functions
  void blacken();
  bool blackness() const;
  PieceType getType() const;
  virtual vector<string> allMoves(const string &given, const map<string, Piece*> &board) const = 0;
  virtual bool move(const string &start, const string &end, const map<string, Piece*> &theBoard) const = 0;
  virtual ~Piece(){};
};

//for printing the enumerated PieceType piece in human-readable form 
ostream & operator << (ostream &out, const PieceType &type);

#endif
