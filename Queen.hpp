#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "Piece.hpp"

class Queen : public Piece{
  bool move(const string &start, const string &end, const map<string, Piece*> &theBoard) const;
  vector<string> allMoves(const string &given, const map<string, Piece*> &board) const;
public:
  Queen();
};

#endif
