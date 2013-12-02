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
     bool run=true;
     while(run==true){
     cout<<"Application start..."<<endl;
     cout<<"-----------------------------------------------------------------------"<<endl;
     cout<<"Enter number of hexes on 1 side (3-11):";
     cin>>size;
     while(size<3||size>11){
     cout<<"please be 3 to 11"<<endl;
     cout<<"Enter number of hexes on 1 side (3-11):";
     cin>>size;
     }
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
         if(firstPlayer==0){
            cout<<"Move "<< moveCount <<": Human(X)"<<endl;
         
            cout<<"Enter location(upper-case letter + number): ";
            cin>>input_loc>>input_loc_x;
            while(static_cast<int>(input_loc)<65||static_cast<int>(input_loc)>90){
                cout<<"please input \"upper-case letter\" + \"number\"!!"<<endl;
                cout<<"Enter location(upper-case letter + number): ";
                cin>>input_loc>>input_loc_x;
            }

            input_loc_y=static_cast<int>(input_loc)-65;
         }
         else{
            cout<<"Move "<< moveCount <<": Computer"<<endl;
            cout<<"Computer AI Thinking!!!!!"<<endl;
            int* loc;
            loc=hb.AI_move();
            //cout<<loc[0]<<" "<<loc[1]<<endl;
            input_loc_x=loc[0];
            input_loc_y=loc[1];
            //cout<<input_loc_x<<" "<<input_loc_y<<endl;
            
         }

         if(firstPlayer==0)
            while(hb.add_move(input_loc_x-1, input_loc_y, Player::Human)!=1){
                 cout<<"Enter location(upper-case letter + number): ";
                 cin>>input_loc>>input_loc_x;
                 while(static_cast<int>(input_loc)<65||static_cast<int>(input_loc)>90){
                   cout<<"please input \"upper-case letter\" + \"number\"!!"<<endl;
                   cout<<"Enter location(upper-case letter + number): ";
                   cin>>input_loc>>input_loc_x;
                 }
                input_loc_y=static_cast<int>(input_loc)-65;
            }
         else
             hb.add_move(input_loc_x, input_loc_y, Player::Computer);
            
         cout<<"-----------------------------------------------------------------------"<<endl;
         cout<<"Board(after Move "<<moveCount<<")"<<endl;
         hb.printBoard();
         cout<<"-----------------------------------------------------------------------"<<endl;
         firstPlayer=(firstPlayer+1)%2;
         moveCount++;   
         
         if(hb.find_winner()==1){
           cout<<"Argggh! You have beated me, Human! Human Win!!"<<endl;
           cout<<"-----------------------------------------------------------------------"<<endl;
           break;
         }else if(hb.find_winner()==-1){
           cout<<"Haha! I have beated you, Human! Computer Win!"<<endl;
           cout<<"-----------------------------------------------------------------------"<<endl;
           break;
         }
      
     }
     cout<<"Play again (Y or N)?";
     cin>>YoN;
     if(YoN=='Y'||YoN=='y') {
     run=true;
     moveCount=0;
     }else{
     run=false;
     cout<<"...application end."<<endl;
     }
     
     }
     return 0;
}
