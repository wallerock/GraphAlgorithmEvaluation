#include "HexBoard.h"
#include "string.h"
#include "math.h"
#include "time.h"

//constructor
HexBoard::HexBoard(){

}

HexBoard::HexBoard(int s)
{
    size=s;  //set board size
    srand(time(0)); //set random's seed 

    //malloc the boardmatrix and copy board;
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


    board_copy= new int*[size];
       
	for (int i = 0; i < size; i++) {
		board_copy[i] = new int[size];
	}  

    board_connect_human_copy = new bool*[size];
	for (int i = 0; i < size; i++) {
		board_connect_human_copy[i] = new bool[size];
	}
    
    board_connect_computer_copy = new bool*[size];
	for (int i = 0; i < size; i++) {
		board_connect_computer_copy[i] = new bool[size];
	}

    //put ".' in board (initalize board)
   for(int a=0; a<size; a++)
     for(int b=0; b<size; b++){
      board_render[a][b]='.';
      board_trace[a][b]=0;
      board_copy[a][b]=0;
      board_connect_human[a][b]=false;
      board_connect_computer[a][b]=false;
      board_connect_human_copy[a][b]=false;
      board_connect_computer_copy[a][b]=false;
     }
}


int HexBoard::add_move(int x, int y, Player p){

    //check the x and y's valid or not
    if(x<0||x>size-1||y<0||y>size-1){
       cout<<" Invalid position!"<<endl;
       return -1;
    }
    
    if(board_trace[x][y]==0){
       if(p==Player::Human){
         board_trace[x][y]=1;
         board_render[x][y]='X';
         
         if(y==0){//it is first column
            board_connect_human[x][y]=true;
         }
         
         //update human connection board
         update_connect(Player::Human); 
         
         return 1;
       }
       else if(p==Player::Computer){
         board_trace[x][y]=-1;
         board_render[x][y]='O';

         if(x==0){//it is first row
            board_connect_computer[x][y]=true;
         }
         
         //update computer connection board
         update_connect(Player::Computer);
         
         return 1;
       }
       else{  //just for debug, I don't think code will reach this path 
         cout<<"not a player or computer!"<<endl;
       return -1;
       }
    }
    
    //add move failed...
    cout<<"ERROR - Location already occupied!"<<endl;
    return -1;

}


//update connection board, for tracing player's path
void HexBoard::update_connect(Player p){
     if(p==Player::Human){
         for(int x=0; x<size; x++){
             for(int y=1; y<size; y++){
                //if this positon is ocuppied by human
                if(board_trace[x][y]==1){
                   //verify its' connection.
                   find_connect(x,y,p);
                }
             }
         }
     }else if(p==Player::Computer){
         for(int y=0; y<size; y++){
             for(int x=1; x<size; x++){
                //if this position is ocuppied by computer
                if(board_trace[x][y]==-1){
                   //verify its' connection
                   find_connect(x,y,p);
                }
             }
         }

     }else{  //for debug, code should not reach here.
      cout<<"the player is wrong!"<<endl;
     }
}

// verfy is position should be connection or not, using 
// union-find concept in algorithm:
// http://algs4.cs.princeton.edu/15uf/
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
                 if(y==size-1){
                 if(board_connect_human[x-1][y-1]==true||board_connect_human[x][y-1]==true||
                 board_connect_human[x-1][y]==true||board_connect_human[x+1][y-1]==true||
                 board_connect_human[x+1][y]==true)
                 board_connect_human[x][y]=true;
                 }
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

     }else{ //debug function, code should NOT be here
      cout<<"the player is wrong!"<<endl;
     }
}

//find this game has winner or not.
int HexBoard::find_winner(){
     //traversal last column in human connection board
     for(int x=0;x<size;x++){
         //if any position is connected(true), human win! 
         if(board_connect_human[x][size-1]==true){
          return 1; 
         }
     }
     
     //traversal last row in computer connection board
     for(int y=0;y<size;y++){
         //if any position is connected(true), computer win!
         if(board_connect_computer[size-1][y]==true){
          return -1; 
         }
     }

     //return nobody win
     return 0;
}



//make AI Move
int* HexBoard::AI_move(){
    int a[2]={0,0};
    int x,y;
    double win_probility=-1.0;
    double max_win_probility=-1.0;
    
    //for each empty position, try MonteCarlo on it
    //find which position has highest win rate
    for(x=0;x<size;x++)
       for(y=0;y<size;y++){
          if(board_trace[x][y]==0){
              win_probility=DoMonteCarlo(x,y);
              //keep max win rate and update their position
              if(win_probility>max_win_probility){
                 max_win_probility=win_probility;
                 a[0]=x;
                 a[1]=y;  
              }
          }
      }
    
    return a;
}
    
//using MonteCarlo to find the win rate of this position
double HexBoard::DoMonteCarlo(int x, int y){
    int NumberOfWIns=0;
    
    //do 1000 trials
    for(int n=0;n<1000;n++){
        
        //copy now board and connection board's
        //situation into copy board
        for(int i = 0; i<size; i++)
          for(int j = 0; j<size; j++)
        {
          board_copy[i][j]=board_trace[i][j];
          board_connect_human_copy[i][j]=board_connect_human[i][j];
          board_connect_computer_copy[i][j]=board_connect_computer[i][j];
        }
        
       //make computer move this step
        board_copy[x][y]=-1;

        if(x==0){//there is first column
            board_connect_computer_copy[x][y]=true;
        }
        
        //update its connection
        update_connect_copy(Player::Computer);

        //make random move for human and computer 
        //on copy board, until generate a winners 
        while(find_winner_copy()==0){
            make_random_move(Player::Human);
            if(find_winner_copy()!=0) break;
            make_random_move(Player::Computer);
            update_connect_copy(Player::Human);
            update_connect_copy(Player::Computer);
           
        }
        
        //if computer win, incerease Number Of wins
        if(find_winner_copy()==-1){
           NumberOfWIns++;
        }

      } //end of 1000 trials
    
        //return win rate 
        return (double) NumberOfWIns/1000;
}

//make a random move 
void HexBoard::make_random_move(Player p){
     
     //check winner
     if(find_winner_copy()!=0) return;
     
     int count=0;
     int loc[121][2];
     for(int a = 0; a<size; a++)
        for(int b = 0; b<size; b++){
           if(board_copy[a][b]==0){
              //collect empty position:a and b
              loc[count][0]=a;
              loc[count][1]=b;
              count++;
           }
        }
     
     if(count==0){  //if count is zero, board is full
       // we need to find a winner.
       while(find_winner_copy()==0){
         update_connect_copy(Player::Human);
         update_connect_copy(Player::Computer);
       }
     return;
     }
     
     //make a random choice in loc[][]
     //and give to x and y
     int r=rand()%count;

     int x=loc[r][0];
     int y=loc[r][1];
   
     //debug, code should not reach here
     if(board_copy[x][y]!=0){   
     cout<<"error!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
     exit(1);
     }
     
     //just like regular move
     if(p==Player::Human){
          board_copy[x][y]=1;

          if(y==0){//there is first column
            board_connect_human_copy[x][y]=true;
            update_connect_copy(Player::Human);
          }
        
          update_connect_copy(Player::Human);
          return;
      }else if(p==Player::Computer){
          board_copy[x][y]=-1;
           
          if(x==0){//there is first row
           board_connect_computer_copy[x][y]=true;
           update_connect_copy(Player::Computer);
          }
        
          update_connect_copy(Player::Computer);
          return;
      }
 
}

//like update_connect....just it operate on copy board.
void HexBoard::update_connect_copy(Player p){
     if(p==Player::Human){
         for(int x=0; x<size; x++){
             for(int y=1; y<size; y++){
                if(board_copy[x][y]==1){
                   find_connect_copy(x,y,p);
                }
             }
         }
     }else if(p==Player::Computer){
         for(int x=1; x<size; x++){
             for(int y=0; y<size; y++){
                if(board_copy[x][y]==-1){
                   find_connect_copy(x,y,p);
                }
             }
         }

     }else{
      cout<<"the player is wrong!"<<endl;
     }
}

////like find_connect....just it operate on copy board.
void HexBoard::find_connect_copy(int x,int y, Player p){
    if(p==Player::Human){
         if(x==0){
            if(y==size-1){
              if(board_connect_human_copy[x][y-1]==true||board_connect_human_copy[x+1][y-1]==true||
                 board_connect_human_copy[x+1][y]==true)
                 board_connect_human_copy[x][y]=true;
                 
            }else{ 
              if(board_connect_human_copy[x][y-1]==true||board_connect_human_copy[x+1][y-1]==true||
                 board_connect_human_copy[x+1][y]==true||board_connect_human_copy[x][y+1]==true||
                 board_connect_human_copy[x+1][y+1]==true)
                 board_connect_human_copy[x][y]=true;
                 
            }
         }else if(x==size-1){
            if(y==size-1){
                 if(board_connect_human_copy[x][y-1]==true||board_connect_human_copy[x-1][y-1]==true||
                 board_connect_human_copy[x-1][y]==true)
                 board_connect_human_copy[x][y]=true;
                 
            }else{
                 if(board_connect_human_copy[x][y-1]==true||board_connect_human_copy[x-1][y-1]==true||
                 board_connect_human_copy[x-1][y]==true||board_connect_human_copy[x][y+1]==true||
                 board_connect_human_copy[x-1][y+1]==true)
                 board_connect_human_copy[x][y]=true;
                
            }
         }else{
                 if(y==size-1){
                 if(board_connect_human_copy[x-1][y-1]==true||board_connect_human_copy[x][y-1]==true||
                 board_connect_human_copy[x-1][y]==true||board_connect_human_copy[x+1][y-1]==true||
                 board_connect_human_copy[x+1][y]==true)
                 board_connect_human_copy[x][y]=true;
                 }
                 else{
                 if(board_connect_human_copy[x][y-1]==true||board_connect_human_copy[x-1][y-1]==true||
                 board_connect_human_copy[x-1][y]==true||board_connect_human_copy[x][y+1]==true||
                 board_connect_human_copy[x-1][y+1]==true||board_connect_human_copy[x+1][y-1]==true||
                  board_connect_human_copy[x+1][y]==true||board_connect_human_copy[x+1][y+1]==true)
                 board_connect_human_copy[x][y]=true;
                 }
                 
         }
     }else if(p==Player::Computer){
         if(y==0){
           if(x==size-1){
                if(board_connect_computer_copy[x-1][y]==true||board_connect_computer_copy[x-1][y+1]==true||
                 board_connect_computer_copy[x][y+1]==true)
                 board_connect_computer_copy[x][y]=true;
                 
           }else{
                if(board_connect_computer_copy[x-1][y]==true||board_connect_computer_copy[x-1][y+1]==true||
                 board_connect_computer_copy[x][y+1]==true||board_connect_computer_copy[x+1][y]==true||
                 board_connect_computer_copy[x+1][y+1]==true)
                 board_connect_computer_copy[x][y]=true;
           }

         }else if(y==size-1){
           if(x==size-1){
               
                 if(board_connect_computer_copy[x-1][y-1]==true||board_connect_computer_copy[x][y-1]==true||
                 board_connect_computer_copy[x-1][y]==true)
                 board_connect_computer_copy[x][y]=true;
           
           }else{
                 if(board_connect_computer_copy[x-1][y-1]==true||board_connect_computer_copy[x][y-1]==true||
                 board_connect_computer_copy[x-1][y]==true||board_connect_computer_copy[x+1][y-1]==true||
                 board_connect_computer_copy[x+1][y]==true)
                 board_connect_computer_copy[x][y]=true;
           }
          
         }else{
                 if(x==size-1){
                 if(board_connect_computer_copy[x-1][y-1]==true||board_connect_computer_copy[x][y-1]==true||
                 board_connect_computer_copy[x-1][y]==true||board_connect_computer_copy[x][y+1]==true||
                 board_connect_computer_copy[x-1][y+1]==true)
                 board_connect_computer_copy[x][y]=true;}
                 else{
                 if(board_connect_computer_copy[x-1][y-1]==true||board_connect_computer_copy[x][y-1]==true||
                 board_connect_computer_copy[x-1][y]==true||board_connect_computer_copy[x+1][y-1]==true||
                 board_connect_computer_copy[x+1][y]==true||board_connect_computer_copy[x+1][y+1]==true||
                 board_connect_computer_copy[x][y+1]==true||board_connect_computer_copy[x-1][y+1]==true)
                 board_connect_computer_copy[x][y]=true;
                 }
         }    

     }else{//for debug 
          cout<<"the player is wrong!"<<endl;
     }
}

//like find winner....just it operate on copy board.
int HexBoard::find_winner_copy(){
     for(int x=0;x<size;x++){
         if(board_connect_human_copy[x][size-1]==true){
          return 1; 
         }
     }

     for(int y=0;y<size;y++){
         if(board_connect_computer_copy[size-1][y]==true){
          return -1; 
         }
     }
     
     return 0;
}


//PRINT render board on console 
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


//these print method is for debug....not is no use
//they are same as print board.......
//just print other boards for debug.
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

void HexBoard::printBoard_copy(){

    cout<<endl;
    cout<<"********************broad copy**********************"<<endl;
    cout<<endl;
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
            cout<<board_copy[i][j]<<" ";

        cout<<num++<<endl;
    }

    for(int k=1;k<space;++k)
            cout<<" ";

    cout<<"  ";
    for(char a=65;a<=size+64;++a)
        cout<<a<<" ";

    cout <<endl<<endl;

}

void HexBoard::printBoard_connect_human(){

    cout<<endl;
    cout<<"********************huamn connect**********************"<<endl;
    cout<<endl;
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
            cout<<board_connect_human_copy[i][j]<<" ";

        cout<<num++<<endl;
    }

    for(int k=1;k<space;++k)
            cout<<" ";

    cout<<"  ";
    for(char a=65;a<=size+64;++a)
        cout<<a<<" ";

    cout <<endl<<endl;

}


void HexBoard::printBoard_connect_computer(){

    cout<<endl;
    cout<<"********************computer connect**********************"<<endl;
    cout<<endl;
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
            cout<<board_connect_computer_copy[i][j]<<" ";

        cout<<num++<<endl;
    }

    for(int k=1;k<space;++k)
            cout<<" ";

    cout<<"  ";
    for(char a=65;a<=size+64;++a)
        cout<<a<<" ";

    cout <<endl<<endl;

}





