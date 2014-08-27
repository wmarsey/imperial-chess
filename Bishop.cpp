#include <vector>
#include <string>
using namespace std;

#include "Bishop.hpp"

Bishop :: Bishop() : Piece(){
  type = bishop;
}

//checks if move is possible, asks clearpath to check if pieces are in the way
bool Bishop :: move(const string &start, const string &end, const map<string, Piece*> &theBoard) const{
  vector<string> journey;
  
  if(onDiagonal(start, end)){
    journey = path(start,end); 
    if(clearPath(journey, theBoard))
      return true;
  }
  
  return false;
}

vector<string> Bishop :: allMoves(const string &given, const map<string, Piece*> &board) const{
  vector<string>moves;
  creepDiagonal(given, moves, board);
  return moves;
}
