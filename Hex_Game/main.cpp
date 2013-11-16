#include <iostream>
#include "HexBoard.h"
using namespace std;

int main( ) {

HexBoard hb(11);

hb.printBoard();

hb.add_move(3, 3, Player::Human);
hb.add_move(4, 4, Player::Computer);

hb.printBoard();

return 0;
}
