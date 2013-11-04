#include <iostream>
#include <cstring>
#include <cstdlib>
#include "shortest_path.h"

using namespace std;

int main(int argc, char *argv[]) {
        if(argc!=2){
          cout<<"usage: ./exe density" <<endl;
         
          return -1;
        }
        float f=atof(argv[1]);
        if(f<0.0||f>1.0) { 
          cout<<"density is a float number between 0.0 to 1.0"<<endl;
          return -1;
        }
	const int vertices = 50;
	const float density = f;
	const int max_cost = 10;
        int target=1;
        int path_sum=0;
        int path_num=0;
        double path_average=0.0;
        vector<int> path;

        //for(int i=0 ; i<100;i++){  //100 times
	    Graph g(vertices, density, max_cost);
	    ShortestPath sp(g);
    
            while(target< vertices){
           
	        path = sp.path(target);

	        if (sp.path_size(path) == 0)
	       	  cout << "There is no path!!!" << endl;
	        else {
                  path_num++;
		  cout << "Path: ";
		      for (int i = 0; i < path.size(); i++) {
			   if (path[i] == target)
				  cout << path[i];			
			   else					
				  cout << path[i] << "->";
		      }
		  cout << endl;
                  cout << "Path Size: " << sp.path_size(path) << endl;
                  path_sum=path_sum+sp.path_size(path);
                  target++;
	          }
            }
        
        target=1;
        
        //}
        path_average=double(path_sum)/double(path_num);  
        cout << "Average Path Size: " << path_average<< endl;
        
	return 0;
}
