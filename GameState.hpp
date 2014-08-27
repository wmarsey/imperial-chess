#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <iostream>
using namespace std;

enum WinState{
  white,
  black,
  draw
};

class GameState{
private:
  bool blackTurn, gameOn;
public:
  //default is draw
  WinState winState;
  GameState();
  void config();
  void changeTurn();
  void staleMate();
  void checkMate();
  bool getTurn() const;
  bool isGameOn() const;
};


ostream & operator << (ostream &out, const GameState &g);

#endif
