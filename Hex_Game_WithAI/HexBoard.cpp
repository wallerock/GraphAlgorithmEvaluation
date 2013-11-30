#include "HexBoard.h"
#include "math.h"

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


    board_connect_human = new bool*[size];
	for (int i = 0; i < size; i++) {
		board_connect_human[i] = new bool[size];
	}
    
    board_connect_computer = new bool*[size];
	for (int i = 0; i < size; i++) {
		board_connect_computer[i] = new bool[size];
	}

    //put ".' in board
   for(int a=0; a<size; a++)
     for(int b=0; b<size; b++){
      board_render[a][b]='.';
      board_trace[a][b]=0;
      board_connect_human[a][b]=false;
      board_connect_computer[a][b]=false;
     }
   

}

int HexBoard::add_move(int x, int y, Player p){
    if(x<0||x>>size-1||y<0||y>size-1){
       cout<<" Invalid position!"<<endl;
       return -1;
    }
    
    if(board_trace[x][y]==0){
       if(p==Player::Human){
         board_trace[x][y]=1;
         board_render[x][y]='X';
         if(y==0){//there is first column
            board_connect_human[x][y]=true;
         }
        
         update_connect(Player::Human);

   
         return 1;
         
       }
       else if(p==Player::Computer){
         board_trace[x][y]=-1;
         board_render[x][y]='O';
           if(x==0){//there is first column
            board_connect_computer[x][y]=true;
         }
        
         update_connect(Player::Computer);
         
         return 1;
       }
       else{
         cout<<"not a player or computer!"<<endl;
       return -1;
       }
    }
     
    cout<<"ERROR - Location already occupied!"<<endl;
    return -1;

}


int* HexBoard::AI_move(){
    int a[2]={0,0};
    int x=0;
    int y=0;
    while(1){
    x=rand()%size;
    y=rand()%size;
    //cout<<x<<" "<<y<<endl;
     if(board_trace[x][y]==0){
      a[0]=x;
      a[1]=y;
      //cout<<a[0]<<" "<<a[1]<<endl;
      return a;
     }
    }
 
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

void HexBoard::update_connect(Player p){
     if(p==Player::Human){
         for(int x=0; x<size; x++){
             for(int y=1; y<size; y++){
                if(board_trace[x][y]==1){
                   find_connect(x,y,p);
                }
             }
         }
     }else if(p==Player::Computer){
         for(int x=1; x<size; x++){
             for(int y=0; y<size; y++){
                if(board_trace[x][y]==-1){
                   find_connect(x,y,p);
                }
             }
         }

     }else{
      cout<<"the player is wrong!"<<endl;
     }
}


void HexBoard::find_connect(int x,int y, Player p){
    if(p==Player::Human){
         if(x==0){
            if(y==size-1){
              if(board_connect_human[x][y-1]==true||board_connect_human[x+1][y-1]==true||
                 board_connect_human[x+1][y]==true)
                 board_connect_human[x][y]=true;
                 
            }else{ 
              if(board_connect_human[x][y-1]==true||board_connect_human[x+1][y-1]==true||
                 board_connect_human[x+1][y]==true||board_connect_human[x][y+1]==true||
                 board_connect_human[x+1][y+1]==true)
                 board_connect_human[x][y]=true;
                 
            }
         }else if(x==size-1){
            if(y==size-1){
                 if(board_connect_human[x][y-1]==true||board_connect_human[x-1][y-1]==true||
                 board_connect_human[x-1][y]==true)
                 board_connect_human[x][y]=true;
                 
            }else{
                 if(board_connect_human[x][y-1]==true||board_connect_human[x-1][y-1]==true||
                 board_connect_human[x-1][y]==true||board_connect_human[x][y+1]==true||
                 board_connect_human[x-1][y+1]==true)
                 board_connect_human[x][y]=true;
                
            }
         }else{
                 if(x==size-1){
                 if(board_connect_computer[x-1][y-1]==true||board_connect_computer[x][y-1]==true||
                 board_connect_computer[x-1][y]==true||board_connect_computer[x][y+1]==true||
                 board_connect_computer[x-1][y+1]==true)
                 board_connect_computer[x][y]=true;}
                 else{
                 if(board_connect_human[x][y-1]==true||board_connect_human[x-1][y-1]==true||
                 board_connect_human[x-1][y]==true||board_connect_human[x][y+1]==true||
                 board_connect_human[x-1][y+1]==true||board_connect_human[x+1][y-1]==true||
                  board_connect_human[x+1][y]==true||board_connect_human[x+1][y+1]==true)
                 board_connect_human[x][y]=true;}
                 
         }
     }else if(p==Player::Computer){
         if(y==0){
           if(x==size-1){
                if(board_connect_computer[x-1][y]==true||board_connect_computer[x-1][y+1]==true||
                 board_connect_computer[x][y+1]==true)
                 board_connect_computer[x][y]=true;
                 
           }else{
                if(board_connect_computer[x-1][y]==true||board_connect_computer[x-1][y+1]==true||
                 board_connect_computer[x][y+1]==true||board_connect_computer[x+1][y]==true||
                 board_connect_computer[x+1][y+1]==true)
                 board_connect_computer[x][y]=true;
           }

         }else if(y==size-1){
           if(x==size-1){
               
                 if(board_connect_computer[x-1][y-1]==true||board_connect_computer[x][y-1]==true||
                 board_connect_computer[x-1][y]==true)
                 board_connect_computer[x][y]=true;
           
           }else{
                 if(board_connect_computer[x-1][y-1]==true||board_connect_computer[x][y-1]==true||
                 board_connect_computer[x-1][y]==true||board_connect_computer[x+1][y-1]==true||
                 board_connect_computer[x+1][y]==true)
                 board_connect_computer[x][y]=true;
           }
          
         }else{
                 if(x==size-1){
                 if(board_connect_computer[x-1][y-1]==true||board_connect_computer[x][y-1]==true||
                 board_connect_computer[x-1][y]==true||board_connect_computer[x][y+1]==true||
                 board_connect_computer[x-1][y+1]==true)
                 board_connect_computer[x][y]=true;}
                 else{
                 if(board_connect_computer[x-1][y-1]==true||board_connect_computer[x][y-1]==true||
                 board_connect_computer[x-1][y]==true||board_connect_computer[x+1][y-1]==true||
                 board_connect_computer[x+1][y]==true||board_connect_computer[x+1][y+1]==true||
                 board_connect_computer[x][y+1]==true||board_connect_computer[x-1][y+1]==true)
                 board_connect_computer[x][y]=true;
                 }
         }

         

     }else{
      cout<<"the player is wrong!"<<endl;
     }
}


int HexBoard::find_winner(){
     for(int x=0;x<size;x++){
         if(board_connect_human[x][size-1]==true){
          return 1; 
         }
     }

     for(int y=0;y<size;y++){
         if(board_connect_computer[size-1][y]==true){
          return -1; 
         }
     }
     
     return 0;
}








