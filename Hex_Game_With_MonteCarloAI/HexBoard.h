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
                int**  board_copy; 
                bool** board_connect_human_copy;
                bool** board_connect_computer_copy;  
	 public:
		HexBoard();
                HexBoard(int s);    //constructor
                int add_move(int x, int y, Player p);
                int* AI_move();
                double DoMonteCarlo(int x, int y);
                void make_random_move(Player p);
                void setfirstPlayer(int f);
                void printBoard();  //print this board
                void printBoard_trace();
                void printBoard_copy();
                void printBoard_connect_computer();
                void printBoard_connect_human();
                void update_connect(Player p);
                void find_connect(int x, int y, Player p);
                int find_winner();
                void update_connect_copy(Player p);
                void find_connect_copy(int x, int y, Player p);
                int find_winner_copy();
};

