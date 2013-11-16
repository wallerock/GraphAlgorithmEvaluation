#include "HexBoard.h"

//constructor
HexBoard::HexBoard(){

}

HexBoard::HexBoard(int s)
{
    size=s;
    
    //initial the boardmatrix;
    board_render = new char*[size];
	for (int i = 0; i < size; i++) {
		board_render[i] = new char[size];
	}
    
    board_trace = new int*[size];
	for (int i = 0; i < size; i++) {
		board_trace[i] = new int[size];
	}

    //put ".' in board
   for(int a=0; a<size; a++)
     for(int b=0; b<size; b++){
      board_render[a][b]='.';
      board_trace[a][b]=0;
     }
   

}

int HexBoard::add_move(int x, int y, Player p){
    if(x<0||x>>size-1||y<0||y>size-1){
       cout<<"input is illegal !!"<<endl;
       return -1;
    }
    
    if(board_trace[x][y]==0){
       if(p==Player::Human){
         board_trace[x][y]=1;
         board_render[x][y]='X';
         return 1;
       }
       else if(p==Player::Computer){
         board_trace[x][y]=-1;
         board_render[x][y]='O';
         return 1;
       }
       else{
         cout<<"not a player or computer!"<<endl;
       return -1;
       }
    }
     
    cout<<"this position is occupied"<<endl;
    return -1;

}

void HexBoard::printBoard(){

    cout<<endl<<endl;
    int space=1,num=1;
    char a;
    
    cout<<"  ";
    for(a=65;a<=size+64;++a)
        cout<<a<<" ";
    cout<<endl;

    
    for(int i=0;i<size;++i)
    {
        for(int k=1;k<space;++k)

        cout<<" ";
        if(num<=9) cout<<" ";
        space++;
        cout<<num<<" ";
        for(int j=0;j<size;++j)
            cout<<board_render[i][j]<<" ";

        cout<<num++<<endl;
    }

    for(int k=1;k<space;++k)
            cout<<" ";

    cout<<"  ";
    for(char a=65;a<=size+64;++a)
        cout<<a<<" ";

    cout <<endl<<endl;

}

void HexBoard::printBoard_trace(){

    cout<<endl<<endl;
    int space=1,num=1;
    char a;
    
    cout<<"  ";
    for(a=65;a<=size+64;++a)
        cout<<a<<" ";
    cout<<endl;

    
    for(int i=0;i<size;++i)
    {
        for(int k=1;k<space;++k)

        cout<<" ";
        if(num<=9) cout<<" ";
        space++;
        cout<<num<<" ";
        for(int j=0;j<size;++j)
            cout<<board_trace[i][j]<<" ";

        cout<<num++<<endl;
    }

    for(int k=1;k<space;++k)
            cout<<" ";

    cout<<"  ";
    for(char a=65;a<=size+64;++a)
        cout<<a<<" ";

    cout <<endl<<endl;

}

void HexBoard::find_winner(){


}








