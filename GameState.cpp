#include "GameState.hpp"

GameState :: GameState(){
  config();
}

void GameState :: config(){
  blackTurn = false;
  gameOn = true;
  winState = draw;
}

void GameState :: changeTurn(){
  (blackTurn) ? blackTurn = false : blackTurn = true;
}

void GameState :: staleMate(){
  gameOn = false;
}

void GameState :: checkMate(){
  gameOn = false;
  winState = (WinState) !blackTurn;
}

bool GameState :: isGameOn() const{
  return gameOn;
}

bool GameState :: getTurn() const{
  return blackTurn;
}

//prints out the GameState qualities in human-readable form (only used to explain why a game has ended).
ostream & operator << (ostream &out, const GameState &g){
  if(!g.isGameOn()){
    out << "Cannot accept any more moves. This game has ended ";
    switch(g.winState){
    case draw:
      out << "(in a draw).";
      break;
    case white:
      out << "(with black in checkmate).";
      break;
    case black:
      out << "(with white in checkmate).";
      break;
    }
    out << endl;
  }
  return out;
}
