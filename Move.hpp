#ifndef MOVE_HPP		
#define MOVE_HPP

#include <string>
using namespace std;

#include "Piece.hpp"

class Move{
private:
  string start, end;  
  PieceType movingPiece, takenPiece;
  bool takenPieceBlack, movingPieceBlack, taking, inCheck, mate, fail, stale, friendlyFire;
  friend ostream & operator << (ostream &out, const Move &move);
public:
  void config(string givenStart, string givenEnd, PieceType givenMover, bool givenBlackness);
  void takingConfig(PieceType givenTaken, bool givenBlackness);
  void check();
  void checkMate();
  void staleMate();
  bool isTaking() const;
  bool isMovingPieceBlack() const;
  bool isTakenPieceBlack() const;
  void setFriendlyFire();
  void setFail();
  Move();
};

//prints out the move qualities in a human-readable form


#endif
