#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

#include "Move.hpp"
#include "Piece.hpp"
#include "King.hpp"
#include "Queen.hpp"
#include "Bishop.hpp"
#include "Knight.hpp"
#include "Rook.hpp"
#include "ChessBoard.hpp"

//constructor shares 'configureBoard' helper with 'resetBoard' function
ChessBoard :: ChessBoard(){
  configureBoard();
}

ChessBoard :: ~ChessBoard(){  
  clearPieces(); 
}

//clears heap memory from board
void ChessBoard :: clearPieces(){
  map<string, Piece*> :: iterator iter;
  for(iter = theBoard.begin(); iter != theBoard.end(); ++iter)
    delete iter->second;
}

//function calls on helper functions to clear heap memory,
void ChessBoard :: resetBoard(){
  clearPieces();
  theBoard.clear();
  configureBoard(); 
}

//function to create and place objects
void ChessBoard :: configureBoard(){
  string coord;
  
  //white pieces (piece default colour is white)
  theBoard["A1"] = new Rook;
  theBoard["H1"] = new Rook;
  theBoard["B1"] = new Knight;
  theBoard["G1"] = new Knight;
  theBoard["C1"] = new Bishop;
  theBoard["F1"] = new Bishop;
  theBoard["D1"] = new Queen;
  theBoard["E1"] = new King;
  for(coord = "A2"; coord[0] <= 'H'; ++coord[0])
    theBoard[coord] = new Pawn;

  //black pieces
  theBoard["A8"] = new Rook;
  theBoard["H8"] = new Rook;
  theBoard["B8"] = new Knight;
  theBoard["G8"] = new Knight;  
  theBoard["C8"] = new Bishop;
  theBoard["F8"] = new Bishop;
  theBoard["D8"] = new Queen;
  theBoard["E8"] = new King;
  for(coord = "A7"; coord[0] <= 'H'; ++coord[0])
    theBoard[coord] = new Pawn;
  //making pieces black:
  for(coord = "A7"; coord[1] <= '8'; ++coord[1])
    for(coord[0] = 'A'; coord[0] <= 'H'; ++coord[0])
      theBoard[coord]->blacken();

  //initialise first play as white
  gameState.config();

  cout << "A new chess game is started!" << endl;
}

//checks the coordinates in detail (see coordinateCheck function)
bool ChessBoard :: coordinateFormat(const string &coord) const{
  int messages = 0;

  //wrong sizes
  if(coord[0] == '\0'){
    cout << "Can't make move - empty coordinate found!" << endl;
    ++messages;
    return false;
  }
  if(coord[2] != '\0'){
    cout << "Coordinate \"" << coord << "\" "
	 << "has too many characters!" << endl;
    ++messages;
    return false;
  } else if(coord[1] == '\0'){
    cout << "Coordinate \"" << coord << "\" "
	 << "has too few characters!" << endl;
    ++messages;
    return false;
  }

  //wrong formatting
  if(!isalpha(coord[0])){
    cout << "Cannot read coordinate \"" << coord << "\" "
	 << "(first character must be a letter)!" << endl;
    ++messages;
  } else if(!isupper(coord[0])){
    cout << "Cannot read coordinate \""<< coord << "\" "
	 << "(first character must be in upper-case)!" << endl;
    ++messages;
  }

  if(coord[2] == '\0' && !isdigit(coord[1])){
    cout << "Cannot read co-ordinate \"" << coord
	 << "\" (second character must be a digit)!" << endl; 
    ++messages;
  } else if(coord[2] == '\0' && (coord[1] == '0' || coord[1] == '9')){
    cout << "Cannot read co-ordinate \"" << coord
	 << "\" (second character needs to be a digit between 1 and 8)!" << endl;
    ++messages;
  }

  return (messages) ? false : true;
}

//checks if the coordinates are correctly formatted
bool ChessBoard :: coordinateCheck(const string &first, const string &second) const{
  int messages = 0;

  if(!coordinateFormat(first))
    ++messages;
  if(!coordinateFormat(second))
    ++messages;

  //if they are correctly formatted, check if they are the same
  if(!messages)
    if(!first.compare(second)){
      cout << "Can't make move - the two coordinates are identical!" << endl;
      ++messages;
    }

  //if error messages have been generated, fail
  return (messages) ? false : true;
}

//finds the king of the person who's turn it is
string ChessBoard :: scaredKing(){
  map<string, Piece*> :: iterator iterator;
  for(iterator = theBoard.begin(); iterator != theBoard.end(); ++iterator)
    if(iterator->second->getType() == king) 
      if(gameState.getTurn() == iterator->second->blackness())    
        return iterator->first;
  return ""; //should never happen
}

void ChessBoard :: findThreats(const string &scaredKing){
  string current = "A1";
  threats.clear();
  for(current = "A1"; current[0] <= 'H'; ++current[0])
    for(current[1] = '1'; current[1] <= '8'; ++current[1])
      if(theBoard.find(current) != theBoard.end())
	if(theBoard[current]->blackness() != theBoard[scaredKing]->blackness())
	  if(theBoard[current]->move(current, scaredKing, theBoard))
	    threats.push_back(current);  
}

//goes through all the pieces in the board
bool ChessBoard :: stale(){
  vector<string> moves;
  string current;
  Piece *mover = NULL, *taken = NULL;
  
  for(current = "A1"; current[0] <= 'H'; ++current[0])
    for(current[1] = '1'; current[1] <= '8'; ++current[1])
      
      //if there's a pieces there, and then if that pieces is one of the king's pieces
      if(theBoard.find(current) != theBoard.end())
	if(theBoard[current]->blackness() == theBoard[scaredKing()]->blackness()){
	  //save the moving piece
	  mover = theBoard[current];
	  //ask the piece for all the moves it can make
	  moves = theBoard[current]->allMoves(current, theBoard);
	  //for each of these moves...
	  for(unsigned int i = 0; i < moves.size(); ++i){
	    //move the piece
	    if(theBoard.find(moves[i]) != theBoard.end())
	      taken = theBoard[moves[i]];
	    theBoard[moves[i]] = theBoard[current];
	    theBoard.erase(current);
	    
	    //find squares where there are pieces that threaten appropriate king
	    findThreats(scaredKing());
	    
	    //move piece back
	    if (taken) theBoard[moves[i]] = taken;
	    theBoard[current] = mover;
 	    if (!taken) theBoard.erase(moves[i]);
	    else taken = NULL;

	    //check if there were any threats
	    if (!threats.size()) return false;
	  }
	  moves.clear();
	}
   return true;
 }

 bool ChessBoard :: check(){
   findThreats(scaredKing());
   return (threats.size()) ? true : false;
 }

 void ChessBoard :: submitMove(const char* givenStart, const char* givenEnd){
   string start(givenStart), end(givenEnd);
   Move move;

   //check if game already over
   if(!gameState.isGameOn()){
     cout << gameState;
     return;
   }

   //check format of coordinates
   if(!coordinateCheck(start, end))
     return;

   //no piece on start square check
   if(theBoard.find(start) == theBoard.end()){
     cout << "Can't make move - there is no piece on specified start square!" << endl;
     return;
   } 
   
   //wrong turn check
   if(gameState.getTurn() != theBoard[start]->blackness()){
     cout << "Can't make move - it is not ";
     (gameState.getTurn()) ? cout << "White's turn!" : cout << "Black's turn!";
     cout << endl;;
     return;
   }

   //configure the move object
   move.config(start, end, theBoard[start]->getType(), theBoard[start]->blackness());
   if(theBoard.find(end) != theBoard.end())
     move.takingConfig(theBoard[end]->getType(), theBoard[end]->blackness());    
   //configure move object for taking
   if(move.isTaking() && move.isMovingPieceBlack() == move.isTakenPieceBlack()){
     move.setFriendlyFire();
     cout << move;
     return;
   }

   //ask the piece if the move is valid (let it see the board)
   if(!theBoard[start]->move(start, end, theBoard)){
     move.setFail();
     cout << move;
     return;
   }

   //move piece
   if (move.isTaking()) delete theBoard[end];
   theBoard[end] = theBoard[start];
   theBoard.erase(start);
   //tell a pawn if its had it's first move
   if(theBoard[end]->firstMove) theBoard[end]->firstMove = false;

   //change the turn
   gameState.changeTurn();

   //check if the other player is in check(mate), end game if so
   if(check()){
     move.check();
     if(stale()){
       move.checkMate();
       gameState.checkMate();
       cout << move;
       return;
     }
   }else if(stale()){
     move.staleMate();
     gameState.staleMate();
     cout << move;
     return;
   }

   cout << move;
 }
