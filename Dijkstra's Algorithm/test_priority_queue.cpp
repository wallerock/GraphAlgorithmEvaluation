#include"priority_queue.h"
#include <iostream>

using namespace std;

int main(){
PriorityQueue q;

int temp2[3]={6,6,8};
int temp3[3]={8,10,0};
int temp[3]={0,1,2};
int temp1[3]={2,5,6};


q.insert(temp);
q.insert(temp1);
q.insert(temp2);
q.insert(temp3);

int* temp5=q.top();

for(int i=0;i<3;i++)
    cout<<temp5[i]<<endl;

int u=q.get_priority(8); 
cout<<u<<endl;

bool y=q.contains(2);
if(y==1) cout<<"yes"<<endl;

q.minPrioirty();  
cout<< q.size()<<endl;
return 0;

}
