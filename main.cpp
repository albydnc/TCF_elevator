//main file for Elevator
#include <iostream>
#include <ctime>
#include "ui.h"
#include <ncurses.h>
#include <unistd.h>
#include <string>
using namespace std;
char ui = 'y';
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
  cout << "Si vuole usare un'interfaccia grafica? [y/n]"<<endl;

  cin >> ui;
  if(ui == 'y') uiSetup();
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
       if(ui == 'y') drawElevator(1);
       usleep(100000);
       if(ui == 'y') {
         drawLegend(isFree,floor_curr,floor_dest);
       }else{ cout << "Piano Corrente: "<<floor_curr<<endl;}
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
       if(ui == 'y') {
         drawLegend(isFree,floor_curr,floor_dest);
       }else{ cout << "Piano Corrente: "<<floor_curr<<endl;}
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
  floor_curr = rand() % floors + 1;
  if(ui == 'y') {
    drawElevator(1);
    drawLegend(isFree,floor_curr,floor_dest);
  }else{ cout << "Piano Corrente: "<<floor_curr<<endl;}
  while(true){
    if(ui == 'y'){
     drawLegend(isFree,floor_curr,floor_dest);
     scanw("%d",&floor_call);
    }else{
      cout << "Inserire piano di chiamata:"<<endl;
    cin >> floor_call;
    act();
    }
  callElevator();
  if(ui == 'y') {
    drawElevator(2);
  }else{ cout << "apro le porte..."<<endl;}
  isOpen=true;
  isFree = false;
  sleep(1);
  if(ui == 'y') {
    drawElevator(3);
  }else{ cout << "chiudo le porte..."<<endl;}
  isOpen = false;
  if(ui == 'y'){
   drawLegend(isFree,floor_curr,floor_dest);
   scanw("%d",&floor_dest);
  }else{
    cout << "Inserire piano di destinazione"<<endl;
  cin >> floor_dest;
  act();
  }
  setFloor();
  isFree = true;
}
endwin();
return 0;
}
