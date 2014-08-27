#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#include "King.hpp"

King :: King() : Piece(){
  type = king;
}

//checks if move is possible
bool King :: move(const string &start, const string &end, const map<string, Piece*> &theBoard) const{
  if(!adjacent(start, end))
    return false;
  return true;
}

vector<string> King :: allMoves(const string &given, const map<string, Piece*> &board) const{
  string coord = given;
  vector<string> moves;
  --coord[0];
  --coord[1];
  for( ; coord[0] <= given[0]+1; ++coord[0])
    for(coord[1] = given[1]-1; coord[1] <= given[1]+1; ++coord[1])
      if(onBoard(coord))
	if(find(moves.begin(), moves.end(), coord) == moves.end() && canMoveTo(given, coord, board))
	    moves.push_back(coord);
  return moves;
}
