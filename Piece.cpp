#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

#include "Piece.hpp" 

Piece :: Piece(){
  type = none;
  black = false;
  firstMove = false;
}

void Piece :: blacken(){
  black = true;
}

bool Piece :: blackness() const{
  return black;
}

PieceType Piece :: getType() const{
  return type;
}

//this will populate a vector with coordinates of the squares between two 
//points (as long as those two points are in-line or diagonal to one another)
vector<string> Piece :: path(const string &start, const string &end) const{
  vector<string> thePath;
  string current;
  
  current = start;
  thePath.push_back(current);
  do{
    if(start[0] < end[0]) ++current[0];
    else if(start[0] > end[0]) --current[0];

    if(start[1] < end[1]) ++current[1];
    else if(start[1] > end[1]) --current[1];

    thePath.push_back(current);
  } 
  while (current != end);
  return thePath;
}

//fails if there is a piece between two squares, or if the piece on the second square is of the same colour
bool Piece :: clearPath(const vector<string> &journey, const map<string, Piece*> &theBoard) const{
  map<string, Piece*> :: const_iterator iterator;
  if(!journey.size())
    return true;
  iterator = theBoard.find(journey[0]);
  if(iterator->second->getType() == knight || iterator->second->getType() == king) 
    return true;
  //does not check the first (origin) or last squares (the destination)
  for(unsigned int i = 1; i+1 < journey.size(); ++i)
    if(theBoard.find(journey[i]) != theBoard.end()) return false;
  return true;
}

//checks if two squares are diagonal to one another
bool Piece :: onDiagonal(const string &start, const string &end) const{
  if(start[0]-end[0] == start[1]-end[1] || start[0]-end[0] == -1*(start[1]-end[1])) return true;
  return false;
}

//checks if two squares are inline with one another (assumes that start != end)
bool Piece :: inLine(const string &start, const string &end) const{
  if(start[0] == end[0] || start[1] == end[1]) return true;
  return false;
}

//checks if two squares are adjacent to one another
bool Piece :: adjacent(const string &start, const string &end) const{
  if(
     (start[0] - end[0] <= 1 && start[0] - end[0] >= -1)
     &&
     (start[1] - end[1] <= 1 && start[1] - end[1] >= -1)
     )
    return true;
  return false;
}

//checks if a piece is on the board
bool Piece :: onBoard(const string &given) const{
  if(given[0] >= 'A' && given[0] <= 'H' && given[1] >= '1' && given[1] <= '8')
    return true;
  return false;
}

//checks if the piece at 'orig' can legally take or occupy the 'dest' square
//returns 0 for illgal move, returns >0 for move valid, returns 2 for taking the piece at dest
int Piece :: canMoveTo(const string &orig, const string &dest, const map<string, Piece*> &board) const{
  map<string, Piece*> :: const_iterator origIt, destIt;
  origIt = board.find(orig);
  destIt = board.find(dest);
  //if there is a piece on the 'dest' square,
  if(destIt != board.end()){
    if(origIt->second->blackness() == destIt->second->blackness()){
      return 0;
    } else if(origIt->second->blackness() != destIt->second->blackness()){
      return 2;
    }
  }
  return 1;
}

//function to crawl across board in all four diagonal directions until move is invalid, adding each square to 'moves'
void Piece :: creepDiagonal(const string &given, vector<string> &moves, const map<string, Piece*> &board) const{
  string coord; 
  for(int i = 0; i < 4; ++i){
    coord = given;
    
    //direction choosing
    if (i%2) ++coord[0];
    else --coord[0];
    if (i<2) ++coord[1];
    else --coord[1];
    
    //each loop moves in one diagonal direction
    while(onBoard(coord)){
      //if square hasn't already been put into array, and if the piece can move there
      if(find(moves.begin(), moves.end(), coord) == moves.end() && canMoveTo(given, coord, board))
	moves.push_back(coord);
      if(!canMoveTo(given, coord, board) || canMoveTo(given, coord, board) == 2) 
	break;

      if (i%2) ++coord[0];
      else --coord[0];
      if (i<=2) ++coord[1];
      else --coord[1];

    }
  }
}

//function to crawl across board in all four in-line directions until move is invalid, adding each square to 'moves'
void Piece :: creepInLine(const string &given, vector<string> &moves, const map<string, Piece*> &board) const{
  string coord = given;

  for(int a = 0; a<2; ++a)
    for(int b = 0; b<2; ++b){
      coord = given;
      
      //direction choosing
      if(a) ++coord[b];
      else --coord[b];
      
      //each loop moves in one in-line direction      
      while(onBoard(coord)){
  	if(find(moves.begin(), moves.end(), coord) == moves.end() && canMoveTo(given, coord, board))
  	  moves.push_back(coord);
  	if(!canMoveTo(given, coord, board) || canMoveTo(given, coord, board) == 2)
  	  break;

  	if(a) ++coord[b];
  	else --coord[b];
      }
    }

}

//print PieceType in human-readable form
ostream & operator << (ostream &out, const PieceType &type){
  switch(type){
  case 0: break; //shouldn't be called...
    break;
  case 1: out << "King";
    break;
  case 2: out << "Queen";
    break;
  case 3: out << "Knight";
    break;
  case 4: out << "Bishop";
    break;
  case 5: out << "Rook";
    break;
  case 6: out << "Pawn";
    break;
  default: break;
  }
  return out;
}
