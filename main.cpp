//main file for Elevator
#include <iostream>
using namespace std;
int floors,floor_curr,floor_dest,floor_call; //floors: num piani, floor_curr: piano corrente, floor_dest: piano di destinazione
bool isFree,direction,isOpen;
void setup(){
  cout << "Inserire numero piani del palazzo"<<endl;
  cin >> floors;

  return;
}
bool callElevator(){
  floor_dest=floor_call;
  int dfloor = floor_dest-floor_curr;

  if(dfloor>0){
     direction = true; // sale
   }else{
     direction = false; //pepe
   }
  if(isFree) {
    while(floor_curr != floor_dest){
       floor_curr += ( direction ? 1 : -1 );
       cout <<"piano corrente: " << floor_curr<<endl;
     }
  }
  return isFree;
}
bool setFloor(){
  int dfloor = floor_dest-floor_curr;
  if(dfloor>0){
     direction = true; // sale
   }else{
     direction = false; //pepe
   }
  while(floor_curr != floor_dest){
       floor_curr += ( direction ? 1 : -1 );
       cout <<"piano corrente: " << floor_curr<<endl;
  }
  cout << "apro le porte..."<<endl;
  isOpen = true;
  cout<<"chiudo le porte..."<<endl;
  isOpen = false;
  isFree=true;
  return isFree;
}
int main(){
  setup();
  isFree = true;
  floor_curr = 0;
  while(1){
  cout << "Inserire piano di chiamata"<<endl;
  cin >> floor_call;
  callElevator();
  cout<<"apro le porte..."<<endl;
  isOpen=true;
  isFree = false;
  cout<<"chiudo le porte..."<<endl<<"inserire piano di destinazione"<<endl;
  isOpen = false;
  cin >> floor_dest;
  setFloor();
}
}
