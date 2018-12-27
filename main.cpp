//main file for Elevator
#include <iostream>
#include <ctime>
#include "ui.h"
#include <ncurses.h>
#include <unistd.h>
#include <string>
using namespace std;

int floors,floor_curr,floor_dest,floor_call; //floors: num piani, floor_curr: piano corrente, floor_dest: piano di destinazione
bool isFree,direction,isOpen;

void act() {
  char action,action2,action3;
  char req[4] =  { '0', '0', '0', '1'},ans[4];
  int i;
  cout<<"Scegli un attività (s/n)? ";
  cin>>action;
  if (action=='s') {
    cout<<"f = Fire"<<endl;
    cout<<"e = Electrical problem"<<endl;
    cout<<"j = Jump"<<endl;


      cin>>action2;
//fire action
 if (action2=='f') {
      cout<<"SPEAKER ASCENSORE: ''Salve,sono Monica Rinero c'è un incendio nel palazzo, verrete portati al primo piano disponibile.''"<<endl<<endl;
       if(direction==true) {floor_dest=floor_curr +1;}
                       else {floor_dest=floor_curr -1;} }
//electrical action
else if (action2=='e') {
  cout<<"SPEAKER ASCENSORE: ''Salve,sono Monica Rinero c'è stato un guasto elettrico nel palazzo, verrete portati al piano terra.''"<<endl<<endl;
    floor_dest=0; }

//ascensorista action
else  { cout<<"L'ascensore è bloccato. Vuoi chiamare l'ascensorista? (s/n)?"<<endl;
cin>>action3; if(action3=='s') { cout<<"SPEAKER ASCENSORE: ''Salve sono Antonio l'ascensorista segua correttamente le mie istruzioni ed andrà tutto bene"<<endl;
                                 cout<<"SPEAKER ASCENSORE: premi tre volte il tasto 0 e poi il tasto 1"<<endl;
                                for (i=0;i<4;i++) { cin>>ans[i];}
                                for (i=0;i<4;i++) { if (ans[i]==req[i]) { cout<<"SPEAKER ASCENSORE: ''Ok, è stato ripristinato il sistema. L'ascensore è ora tornato funzionante."<<endl;}
                              else { cout<<"SPEAKER ASCENSORE: non ha seguito correttamente le mie istruzioni; verrà quindi tolta la corrente e l'ascensore scenderà al piano terra,''"<<endl; floor_dest=0;}}
}} //else + if s ascensorista

} //action activate
} //function act
void setup(){
  cout << "Inserire numero piani del palazzo"<<endl;
  cin >> floors;
  uiSetup();
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
       drawElevator(1);
       usleep(100000);
       drawLegend(isFree,floor_curr,floor_dest);
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
       drawElevator(1);
       usleep(100000);
       drawLegend(isFree,floor_curr,floor_dest);
  }
  drawElevator(2);
  isOpen = true;
  drawElevator(3);
  isOpen = false;
  isFree=true;
  return isFree;
}
int main(){
  setup();
  isFree = true;
  drawElevator(1);
  floor_curr = rand() % floors + 1;
  drawLegend(isFree,floor_curr,floor_dest);
  while(true){
  drawLegend(isFree,floor_curr,floor_dest);
  scanw("%d",&floor_call);
  callElevator();
  drawElevator(2);
  isOpen=true;
  isFree = false;
  sleep(1);
  drawElevator(3);
  isOpen = false;
  drawLegend(isFree,floor_curr,floor_dest);
  scanw("%d",&floor_dest);
  //act();
  setFloor();
  isFree = true;
}
endwin();
return 0;
}
