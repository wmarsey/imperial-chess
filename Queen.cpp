#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#include "Queen.hpp"

Queen :: Queen() : Piece(){
  type = queen;
}

//checks if move is possible, asks clearpath to check if pieces are in the way
bool Queen :: move(const string &start, const string &end, const map<string, Piece*> &theBoard) const{
  vector<string> journey;
  if(!onDiagonal(start, end) && !inLine(start, end))
    return false;
  else
    journey = path(start, end);
  if(!clearPath(journey, theBoard))
    return false;
  return true;
}

//returns all possible moves as a vector of strings
vector<string> Queen :: allMoves(const string &given, const map<string, Piece*> &board) const{  
  vector<string> moves;
  creepInLine(given, moves, board);
  creepDiagonal(given, moves, board);
  return moves;
}
