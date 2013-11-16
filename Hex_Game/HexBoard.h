#include <vector>
#include <iostream>

using namespace std;

enum class Player{Human, Computer};

class HexBoard {
	private:
		int size;
                //vector< vector<char> > board;
                char** board_render;
                int** board_trace;    
                int firstPlayer;  
	 public:
		HexBoard();
                HexBoard(int s);    //constructor
                int add_move(int x, int y, Player p); 
                void printBoard();  //print this board
                void printBoard_trace();
                void find_winner();
                
                
};

