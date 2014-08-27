#include <iostream>

using namespace std;

#include "ChessBoard.hpp"

int main() {


    cout << "===========================" << endl;
    cout << "Testing the Chess Engine" << endl;
    cout << "===========================" << endl;
    cout << endl;

    ChessBoard cb;
    cout << endl;

    cb.submitMove("D7", "D6");
    cout << endl;

    cb.submitMove("D4", "H6");
    cout << endl;

    cb.submitMove("D2", "D4");
    cout << endl;

    cb.submitMove("F8", "B4");
    cout << endl;

    cb.submitMove("g3", "ER");
    cout << endl;

    cb.submitMove("A4", "A4");
    cout << endl;

    cb.submitMove("A9", "A6");
    cout << endl;

    cb.submitMove("D7","D6");
    cb.submitMove("E2","E3");
    cout << endl;

    cb.submitMove("D6","D7");
    cout << endl;

    cb.submitMove("D3","G6");
    cout << endl;

    cb.submitMove("","G6");
    cout << endl;


    cb.submitMove("F","G6");
    cout << endl;

    cout << "===========================" << endl;
    cout << "A game that should end in stalemate!" << endl;
    cout << "===========================" << endl;
    cout << endl;

    cb.resetBoard();
    cout << endl;

    cb.submitMove("C2","C4");
    cb.submitMove("H7","H5");
    cout << endl;
    
    cb.submitMove("H2","H4");
    cb.submitMove("A7","A5");
    cout << endl;
    
    cb.submitMove("D1","A4");
    cb.submitMove("A8","A6");
    cout << endl;
    
    cb.submitMove("A4","A5");
    cb.submitMove("A6","H6");
    cout << endl;
    
    cb.submitMove("A5","C7");
    cb.submitMove("F7","F6");
    cout << endl;
    
    cb.submitMove("C7","D7");
    cb.submitMove("E8","F7");
    cout << endl;
    
    cb.submitMove("D7","B7");
    cb.submitMove("D8","D3");
    cout << endl;
    
    cb.submitMove("B7","B8");
    cb.submitMove("D3","H7");
    cout << endl;
    
    cb.submitMove("B8","C8");
    cb.submitMove("F7","G6");
    cout << endl;
    
    cb.submitMove("C8","E6");
    cout << endl;
    

    cout << "===========================" << endl;
    cout << "A game that should end with black in checkmate!" << endl;
    cout << "===========================" << endl;
    cout << endl;

    cb.resetBoard();
    cout << endl;

    cb.submitMove("B1","C3");
    cb.submitMove("B8","C6");
    cout << endl;
    
    cb.submitMove("D2","D3");
    cb.submitMove("G8","F6");
    cout << endl;
    
    cb.submitMove("C1","G5");
    cb.submitMove("F6","G4");
    cout << endl;
    
    cb.submitMove("E2","E3");
    cb.submitMove("G4","E3");
    cout << endl;
    
    cb.submitMove("F2","E3");
    cb.submitMove("B7","B5");
    cout << endl;
    
    cb.submitMove("D1","H5");
    cb.submitMove("G7","G6");
    cout << endl;
    
    cb.submitMove("H5","H4");
    cb.submitMove("H7","H6");
    cout << endl;
    
    cb.submitMove("G5","H6");
    cb.submitMove("H8","H6");
    cout << endl;
    
    cb.submitMove("H4","H6");
    cb.submitMove("F8","H6");
    cout << endl;
    
    cb.submitMove("G1","F3");
    cb.submitMove("H6","E3");
    cout << endl;
    
    cb.submitMove("H2","H4");
    cb.submitMove("G6","G5");
    cout << endl;
    
    cb.submitMove("H4","G5");
    cb.submitMove("A8","B8");
    cout << endl;
    
    cb.submitMove("H1","H8");


    cout << "===========================" << endl;
    cout << "A game that should end with white in checkmate!" << endl;
    cout << "===========================" << endl;
    cout << endl;
    
    cb.resetBoard();
    cout << endl;
    
    cb.submitMove("C2","C4");
    cb.submitMove("B7","B5");
    cout << endl;
    
    cb.submitMove("C4","B5");
    cb.submitMove("G7","G5");
    cout << endl;
    
    cb.submitMove("E2","E3");
    cb.submitMove("H7","H5");
    cout << endl;
    
    cb.submitMove("F1","E2");
    cb.submitMove("G8","F6");
    cout << endl;
    
    cb.submitMove("B2","B3");
    cb.submitMove("F8","G7");
    cout << endl;
    
    cb.submitMove("C1","B2");
    cb.submitMove("G5","G4");
    cout << endl;
    
    cb.submitMove("H2","H3");
    cb.submitMove("C8","B7");
    cout << endl;
    
    cb.submitMove("H1","H2");
    cb.submitMove("A7","A6");
    cout << endl;
    
    cb.submitMove("B5","A6");
    cb.submitMove("B8","A6");
    cout << endl;
    
    cb.submitMove("B1","C3");
    cb.submitMove("D8","B8");
    cout << endl;
    
    cb.submitMove("H3","G4");
    cb.submitMove("C7","C5");
    cout << endl;
    
    cb.submitMove("G2","G3");
    cb.submitMove("H5","H4");
    cout << endl;
    
    cb.submitMove("F2","F4");
    cb.submitMove("H4","G3");
    cout << endl;
    
    cb.submitMove("H2","H8");
    cb.submitMove("G7","H8");
    cout << endl;
    
    cb.submitMove("G4","G5");
    cb.submitMove("F6","E4");
    cout << endl;
    
    cb.submitMove("D1","C2");
    cb.submitMove("A6","B4");
    cout << endl;
    
    cb.submitMove("C2","B1");
    cb.submitMove("E4","F2");
    cout << endl;
    
    cb.submitMove("B1","H7");
    cb.submitMove("D7","D6");
    cout << endl;
    
    cb.submitMove("H7","H8");
    cb.submitMove("E8","D7");
    cout << endl;
    
    cb.submitMove("H8","B8");
    cb.submitMove("A8","B8");
    cout << endl;
    
    cb.submitMove("A1","B1");
    cb.submitMove("B8","H8");
    cout << endl;
    
    cb.submitMove("E2","F3");
    cb.submitMove("B4","C2");
    cout << endl;
    
    cb.submitMove("E1","E2");
    cb.submitMove("B7","A6");
    cout << endl;
    
    cb.submitMove("D2","D3");
    cb.submitMove("H8","H2");
    cout << endl;
    
    cb.submitMove("F3","G4");
    cb.submitMove("F2","G4");
    cout << endl;
    
    cb.submitMove("E2","F3");
    cb.submitMove("C2","E3");
    cout << endl;
    
    cb.submitMove("B2","C1");
    cb.submitMove("A6","B7");
    cout << endl;
    
    cb.submitMove("F3","G3");
    cb.submitMove("H2","G2");
    cout << endl;
    
    cb.submitMove("G3","H3");
    cb.submitMove("G4","F2");
    cout << endl;
    
    cb.submitMove("H3","H4");
    cb.submitMove("E3","F5");
    cout << endl;
    
    cb.submitMove("H4","H5");
    cb.submitMove("G2","H2");
    cout << endl;
 
    cb.submitMove("G1","H3");
    cb.submitMove("H2","H3");
    cout << endl;
    
    cout << "===========================" << endl;
    cout << "Don't understand" << endl;
    cout << "===========================" << endl;
    cout << endl;

    cb.resetBoard();
    cout << endl;
    
    cb.submitMove("E2","E4");
    cb.submitMove("B7","B6");
    cout << endl;
    
    cb.submitMove("D2","D4");
    cb.submitMove("C8","B7");
    cout << endl;
    
    cb.submitMove("F1","D3");
    cb.submitMove("F7","F5");
    cout << endl;
    
    cb.submitMove("E4","F5");
    cb.submitMove("B7","G2");
    cout << endl;
    
    cb.submitMove("D1","H5");
    cb.submitMove("G7","G6");
    cout << endl;
    
    cb.submitMove("F5","G6");
    cb.submitMove("G8","F6");
    cout << endl;
    
    cb.submitMove("G6","H7");
    cb.submitMove("F6","H5");
    cout << endl;
    
    cb.submitMove("D3","G6");
    cout << endl;
    cb.submitMove("D3","G6");
    cout << endl;

    cout << "===========================" << endl;
    cout << "stalemate at the end?" << endl;
    cout << "===========================" << endl;
    cout << endl;
    
    cb.resetBoard();
    cout << endl;

    cb.submitMove("D2","D4");
    cb.submitMove("E7","E5");
    cout << endl;
    
    cb.submitMove("D1","D2");
    cb.submitMove("E5","E4");
    cout << endl;
    
    cb.submitMove("D2","F4");
    cb.submitMove("F7","F5");
    cout << endl;

    cb.submitMove("H2","H3");
    cb.submitMove("F8","B4");
    cout << endl;

    cb.submitMove("B1","D2");
    cb.submitMove("D7","D6");
    cout << endl;
    
    cb.submitMove("F4","H2");
    cb.submitMove("C8","E6");
    cout << endl;
    
    cb.submitMove("A2","A4");
    cb.submitMove("D8","H4");
    cout << endl;
    
    cb.submitMove("A1","A3");
    cb.submitMove("C7","C5");
    cout << endl;
    
    cb.submitMove("A3","G3");
    cb.submitMove("F5","F4");
    cout << endl;
    
    cb.submitMove("F2","F3");
    cb.submitMove("E6","B3");
    cout << endl;
    
    cb.submitMove("D4","D5");
    cb.submitMove("B4","A5");
    cout << endl;
    
    cb.submitMove("C2","C4");
    cb.submitMove("E4","E3");
    cout << endl;

    cb.submitMove("D3","G6");
    cout << endl;

    cout << "===========================" << endl;
    cout << "Alekhine vs. Vasic (1931)" << endl;
    cout << "===========================" << endl;
    cout << endl;

    cb.resetBoard();
    cout << endl;

    cb.submitMove("E2", "E4");
    cb.submitMove("E7", "E6");
    cout << endl;

    cb.submitMove("D2", "D4");
    cb.submitMove("D7", "D5");
    cout << endl;

    cb.submitMove("B1", "C3");
    cb.submitMove("F8", "B4");
    cout << endl;

    cb.submitMove("F1", "D3");
    cb.submitMove("B4", "C3");
    cout << endl;

    cb.submitMove("B2", "C3");
    cb.submitMove("H7", "H6");
    cout << endl;

    cb.submitMove("C1", "A3");
    cb.submitMove("B8", "D7");
    cout << endl;

    cb.submitMove("D1", "E2");
    cb.submitMove("D5", "E4");
    cout << endl;

    cb.submitMove("D3", "E4");
    cb.submitMove("G8", "F6");
    cout << endl;

    cb.submitMove("E4", "D3");
    cb.submitMove("B7", "B6");
    cout << endl;

    cb.submitMove("E2", "E6");
    cb.submitMove("F7", "E6");
    cout << endl;

    cb.submitMove("D3", "G6");
    cout << endl;

    cb.submitMove("D3","G6");
    cout << endl;

    return 0;
}
