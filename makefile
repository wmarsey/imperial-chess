comp = g++ -g -Wall
parentObj = ChessMain.o ChessBoard.o Piece.o Move.o GameState.o
childObj = King.o Queen.o Knight.o Bishop.o Rook.o Pawn.o
allObj = $(parentObj) $(childObj)

chess : $(allObj)
	$(comp) $^ -o chess

ChessMain.o : ChessMain.cpp ChessBoard.o Piece.o
	$(comp) $< -c

ChessBoard.o : ChessBoard.cpp ChessBoard.hpp Piece.o Move.o GameState.o
	$(comp) $< -c

Piece.o : Piece.cpp Piece.hpp $(childObj)
	$(comp) $< -c

#generic for other .o files
%.o : %.cpp %.hpp Piece.hpp
	$(comp) $< -c

clean:
	rm *.o
