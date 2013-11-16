#include <iostream>
#include "HexBoard.h"
using namespace std;

int main( ) {
     int size;
     char YoN;
     int firstPlayer;
     int moveCount=1;
     char input_loc;
     int input_loc_x;
     int input_loc_y;
     cout<<"Application start..."<<endl;
     cout<<"-----------------------------------------------------------------------"<<endl;
     cout<<"Enter number of hexes on 1 side:";
     cin>>size;
     HexBoard hb(size);
     cout<<"-----------------------------------------------------------------------"<<endl;
     cout<<"Playing with "<<size<<"X"<<size<<" board."<<endl;
     cout<<"Human, do you want to go first (Y or N)?";
     cin>>YoN;
     if(YoN=='Y'||YoN=='y') firstPlayer=0;
     else firstPlayer=1;
     cout<<"-----------------------------------------------------------------------"<<endl; 
     cout<<"************************************************************"<<endl;
     cout<<"* KEY                                                      *"<<endl;
     cout<<"************************************************************"<<endl;
     cout<<"*      ITEM      * SYMBOL  *             NOTES             *"<<endl;
     cout<<"************************************************************"<<endl;
     cout<<"* Empty Location *    .    *                               *"<<endl;
     cout<<"*   Human Piece  *    X    * connects West-East            *"<<endl;
     cout<<"* Computer Piece *    0    * connects North-South          *"<<endl;
     cout<<"************************************************************"<<endl;
     cout<<"-----------------------------------------------------------------------"<<endl;
     cout<<"Board(no move)"<<endl;
     hb.printBoard();
     cout<<"-----------------------------------------------------------------------"<<endl;
     while(1){
         if(firstPlayer==0)
            cout<<"Move "<< moveCount <<": Human(X)"<<endl;
         else
            cout<<"Move "<< moveCount <<": Computer"<<endl;
         
         cout<<"Enter location: ";
         cin>>input_loc>>input_loc_x;
         input_loc_y=static_cast<int>(input_loc)-65;
         if(firstPlayer==0)
           hb.add_move(input_loc_x-1, input_loc_y, Player::Human);
         else
           hb.add_move(input_loc_x-1, input_loc_y, Player::Computer);
         
         cout<<"-----------------------------------------------------------------------"<<endl;
         cout<<"Board(after Move "<<moveCount<<")"<<endl;
         hb.printBoard();
         cout<<"-----------------------------------------------------------------------"<<endl;
         firstPlayer=(firstPlayer+1)%2;
         moveCount++;   
      
     }

     return 0;
}
