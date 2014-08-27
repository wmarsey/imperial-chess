#ifndef CHESSBOARD_HPP
#define CHESSBOARD_HPP

#include <string>
#include <map>
#include <vector>
using namespace std;

#include "GameState.hpp"
#include "Piece.hpp"
#include "King.hpp"
#include "Queen.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"
#include "Rook.hpp"
#include "Pawn.hpp"

class ChessBoard{
  vector <string> journey, threats;
  map <string, Piece*> theBoard;
  GameState gameState;
 
  void configureBoard();
  bool coordinateFormat(const string &coord) const;
  bool coordinateCheck(const string &first, const string &second) const;
  bool check();
  bool stale();
  string scaredKing();
  void findThreats(const string &scaredKing);
  void clearPieces();

public:
  void submitMove(const char* start, const char* end);
  void resetBoard();
  ChessBoard();
  ~ChessBoard();
};

#endif
