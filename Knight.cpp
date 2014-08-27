#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

#include "Knight.hpp"

Knight :: Knight() : Piece(){
  type = knight;
}

//checks if move is possible
bool Knight :: move(const string &start, const string &end, const map<string, Piece*> &theBoard) const{
  int x = start[0] - end[0];
  int y = start[1] - end[1];

  switch(x){
  case -2:
  case 2:
    if (y == -1 || y == 1)
      return true;
    break;
  case -1:
  case 1:
    if (y == -2 || y == 2)
      return true;
    break;
  default: 
    break;
  }
  
  return false;
}

vector<string> Knight :: allMoves(const string &given, const map<string, Piece*> &board) const{  
  vector<string> moves;
  string coord = "A1";
  for( ; coord[0] <= 'H'; ++coord[0])
    for(coord[1] = '1'; coord[1] <= '8'; ++coord[1])
      if(move(given, coord, board))
	if(find(moves.begin(), moves.end(), coord) == moves.end() && canMoveTo(given, coord, board))
	  moves.push_back(coord);
  return moves;
}

