#include <vector>
#include <string>
using namespace std;

#include "Rook.hpp"

Rook :: Rook() : Piece(){
  type = rook;
}

bool Rook :: move(const string &start, const string &end, const map<string, Piece*> &theBoard) const{
  vector<string> journey;
  if(!inLine(start, end))
    return false;
  else
    journey = path(start,end);
  if(!clearPath(journey, theBoard))
    return false;
  return true;
}

vector<string> Rook :: allMoves(const string &given, const map<string, Piece*> &board) const{
  vector<string> moves;
  creepInLine(given, moves, board);
  return moves;
}
