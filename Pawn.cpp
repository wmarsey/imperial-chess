#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#include "Pawn.hpp"

Pawn :: Pawn() : Piece(){
  type = pawn;
  firstMove = true;
}

//check if a square is in front of a piece
bool Pawn :: inFront(const string &start, const string &end) const{
  if(start[1] < end[1] && !black) return true;
  else if(start[1] > end[1] && black) return true;
  return false;
}

//checks for Pawn's special first move case
bool Pawn :: specialMove(const string &start, const string &end) const{
  if(firstMove)
    if(start[0] == end[0]){
      if(start[1]-end[1] == 2 && blackness()) return true;
      if(start[1]-end[1] == -2 && !blackness()) return true;
    }
  return false;
}

//checks if move is possible, asks clearpath to check if pieces are in the way
bool Pawn :: move(const string &start, const string &end, const map<string, Piece*> &theBoard) const{
  vector<string> journey;
  if(!(inFront(start,end) && (adjacent(start, end))) && !specialMove(start, end))
    return false;
  if(inLine(start,end) && !specialMove(start, end)){
    if(theBoard.find(end) != theBoard.end())
      return false;
  }else if(onDiagonal(start,end)){
    if(theBoard.find(end) == theBoard.end())
      return false;
  }else if(specialMove(start, end)){
    journey = path(start, end);
    if(!clearPath(journey, theBoard))
      return false;
  }
  return true;
}

vector<string> Pawn :: allMoves(const string &given, const map<string, Piece*> &board) const{  
  vector<string> journey, moves;
  string coord = "A1";
  for( ; coord[0] <= 'H'; ++coord[0])
    for(coord[1] = '1'; coord[1] <= '8'; ++coord[1])
      if(move(given, coord, board))
	if(find(moves.begin(), moves.end(), coord) == moves.end() && canMoveTo(given, coord, board))
	  moves.push_back(coord);
  return moves;
}
