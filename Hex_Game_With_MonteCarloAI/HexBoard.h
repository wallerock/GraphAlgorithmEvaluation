#include <vector>
#include <iostream>

using namespace std;

enum class Player{Human, Computer};

class HexBoard {
	private:
		int size;
                char** board_render;  //for render board
                
                //board for using in game
                int**  board_trace;           //keep board situation
                bool** board_connect_human;   //keep human connection
                bool** board_connect_computer; //keep computer connection

                //AI use copy board for doing MonteCarlo analysis
                int**  board_copy;              
                bool** board_connect_human_copy;
                bool** board_connect_computer_copy;  
	 public:
                //constructor
		HexBoard();    
                HexBoard(int s);  
                
                //interaction for player
                void setfirstPlayer(int f);  //who play first
                int add_move(int x, int y, Player p); //move
                int* AI_move();   //make AI Move
                double DoMonteCarlo(int x, int y);  //using MonteCarlo to find the win rate of this position
                void make_random_move(Player p);    //random move
                
                //update board infomation and game situation.
                void update_connect(Player p);  //update connection board, for tracing player's path
                void find_connect(int x, int y, Player p); // verfy is position should be connection or not,
                int find_winner();              //find this game has winner or not.

                //these are same with above methods, but it using copy board for AI
                void update_connect_copy(Player p);
                void find_connect_copy(int x, int y, Player p);
                int find_winner_copy();
                
                //print out board (copy board) in console.
                void printBoard();
                void printBoard_trace();
                void printBoard_copy();
                void printBoard_connect_computer();
                void printBoard_connect_human();
};

