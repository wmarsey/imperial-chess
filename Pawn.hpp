#ifndef PAWN_HPP
#define PAWN_HPP

#include "Piece.hpp"

class Pawn : public Piece{
  bool specialMove(const string& start, const string& end) const;
  bool move(const string &start, const string &end, const map<string, Piece*> &theBoard) const;
  vector<string> allMoves(const string &given, const map<string, Piece*> &board) const;
  bool inFront(const string &start, const string &end) const;
public:
  bool firstMove;
  Pawn();
};

#endif
