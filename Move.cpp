#include <iostream>
using namespace std;

#include "Move.hpp"
#include "Piece.hpp"

Move :: Move(){
  movingPiece = none;
  taking = false;
  takenPiece = none;
  inCheck = false;
  mate = false;
  fail = false;
  stale = false;
  friendlyFire = false;
}

//configuration for any move
void Move :: config(string givenStart, string givenEnd, PieceType givenMover, bool givenBlackness){
  start = givenStart;
  end = givenEnd;
  movingPiece = givenMover;
  movingPieceBlack = givenBlackness;
}

//extra configuration needed for a move that takes another piece
void Move :: takingConfig(PieceType givenTaken, bool givenBlackness){
  taking = true;
  takenPiece = givenTaken;
  takenPieceBlack = givenBlackness; 
}

//stalemate config
void Move :: staleMate(){
  stale = true;
  mate = true;
}

//check config
void Move :: check(){
  inCheck = true;
}

//checkmate config
void Move :: checkMate(){
  inCheck = true;
  mate = true;  
}

//ACCESS FUNCTIONS
bool Move :: isTaking() const{
  return taking;
}

bool Move :: isMovingPieceBlack() const{
  return movingPieceBlack;
}

bool Move :: isTakenPieceBlack() const{
  return takenPieceBlack;
}

//friendly fire is when a piece is trying to take one of its own colour
void Move :: setFriendlyFire(){
  friendlyFire = true;
  fail = true;
}

void Move :: setFail(){
  fail = true;
}

//prints out the 'move' qualities in a human-readable form
ostream & operator << (ostream &out, const Move &move){
  string colour = "White";

  if (move.fail) out << "Cannot move "; 
  
  (move.movingPieceBlack) ? cout << "Black" : cout << "White";
  out << "'s " << move.movingPiece;

  if (!move.fail) out << " moves from " << move.start;

  out << " to " << move.end;

  if (move.friendlyFire) cout << " because you cannot take a piece of your own colour";
  if (move.fail) {
    out << "!" << endl;
    return out;
  }
  
  if(move.taking) {
    if (move.takenPieceBlack) colour = "Black";
    else colour = "White";
    out << " taking " << colour << "'s " << move.takenPiece;
  }
  
  out << endl;

  if(move.inCheck || move.stale){
    (move.movingPieceBlack) ? cout << "White" : cout << "Black";
    if (move.stale) cout << " is in stale";
    if (move.inCheck) cout << " is in check";
    if (move.mate) cout << "mate";
    cout << endl;
  }

  return out;
} 
