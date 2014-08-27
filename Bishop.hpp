#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "Piece.hpp"

class Bishop : public Piece{
  bool move(const string &start, const string &end, const map<string, Piece*> &theBoard) const;
  vector<string> allMoves(const string &given, const map<string, Piece*> &board) const;
public:
  Bishop();
};

#endif
