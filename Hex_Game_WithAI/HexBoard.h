#include <vector>
#include <iostream>

using namespace std;

enum class Player{Human, Computer};

class HexBoard {
	private:
		int size;
                char** board_render;
                int**  board_trace; 
                bool** board_connect_human;
                bool** board_connect_computer;    
	 public:
		HexBoard();
                HexBoard(int s);    //constructor
                int add_move(int x, int y, Player p);
                int* AI_move(); 
                void setfirstPlayer(int f);
                void printBoard();  //print this board
                void printBoard_trace();
                void update_connect(Player p);
                void find_connect(int x, int y, Player p);
                int find_winner();
};

