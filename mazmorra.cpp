#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <chrono> 
#include <string>

#define color SetConsoleTextAttribute

using namespace std;

//int x, y;
const int tam = 21;
const int tampx = 25; 
const int tampy=25;
string tablero[tam][tam];
string jefe[tampy][tampx];
bool gameOver=false, turn=true, pblock=false , pdodge=false, eblock=false , edodge=false;
int px=tam/2,py=tam/2, pv=100, ex, ey, ev=100;
string action=" ";
int ox1= 4,oy1= 1,  ox2= 8,oy2= tam-2,  ox3= 14, oy3=1  ,ox4=13, oy4=tam-2;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
int min=1, max=4;
int c=7,map=0,op=0;
string text=" ";
string ptext=" "; 
string sf=" ", sa=" ", st=" "; 
//int tablero[tam][tam]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};

void mostrar()
{
    system("cls");
    
    color(hConsole,4);
    cout<< sf<< " ";
    color(hConsole,9);
    cout<<sa << " ";
    color(hConsole,6); 
    cout<<st <<endl;
    color(hConsole,c);
    for (int i=1,x=0,y=0;i<=tam*tam;i++,x++)
    {
        if (tablero[y][x]=="+")
        {
            color(hConsole,7);
            cout<<tablero[y][x]<<" ";
            color(hConsole,c);
        }
        else if (tablero[y][x]=="!")
        {
            color(hConsole,6);
            cout<<tablero[y][x]<<" ";
            color(hConsole,c);
        }
        else if (tablero[y][x]=="o")
        {
            color(hConsole,10);
            cout<<tablero[y][x]<<" ";
            color(hConsole,c);
        }
        else if (tablero[y][x]=="#" && map==1)
        {
            color(hConsole,79);
            cout<<tablero[y][x]<<" ";
            color(hConsole,c);
        }
        else if (tablero[y][x]=="#" && map==3)
        {
            color(hConsole,191);
            cout<<tablero[y][x]<<" ";
            color(hConsole,c);
        }
        else if (tablero[y][x]=="#" && map==5)
        {
            color(hConsole,111);
            cout<<tablero[y][x]<<" ";
            color(hConsole,c);
        }
        else if (tablero[y][x]=="*" && map==5 && sf!=" " )
        {
            color(hConsole,79);
            cout<<" ";
            color(hConsole,c);
            cout<<" ";
        }
        else if (tablero[y][x]=="/" && map==5 && sa!=" " )
        {
            color(hConsole,63);
            cout<<" ";
            color(hConsole,c);
            cout<<" ";
        }
        else if (tablero[y][x]=="*" && map==5)
        {
            
            cout<<" ";
            color(hConsole,c);
            cout<<" ";
        }
        else if (tablero[y][x]=="/" && map==5)
        {
            
            cout<<" ";
            color(hConsole,c);
            cout<<" ";
        }
        else if (tablero[y][x]=="/" && map==9)
        {
            
            color(hConsole,11);
            cout<<"+"<<" ";
            color(hConsole,c);
        }
        else if (tablero[y][x]=="M" && map==9)
        {
            
            color(hConsole,10);
            cout<<tablero[y][x]<<" ";
            color(hConsole,c);
        }
        else if (tablero[y][x]=="x" && map==9 && (y>6 && y<14))
        {
            
            color(hConsole,0);
            cout<<tablero[y][x]<<" ";
            color(hConsole,c);
        }
        else if (tablero[y][x]=="x" && map==9 && (y>=0 && y<7 || y>13 && y<=tam-1))
        {
            
            color(hConsole,10);
            cout<<"M"<<" ";
            color(hConsole,c);
        }
        
        
        
        else {cout<<tablero[y][x]<<" ";}
        if (i%tam==0 && i!=0) {cout<<endl; x=-1; y++ ;}
        
    }
    color(hConsole,7);
    cout<< " "<<text <<" " <<endl;
}

void mosPJ()
{
    system("cls");
    
    cout<< endl;
    for (int i=1,x=0,y=0;i<=tampx*tampy;i++ , x++ )
    {
        if ((jefe[y][x]=="x" || jefe[y][x]=="#" )&& map==2)
        {
            color(hConsole,4);
            cout<<jefe[y][x]<<" ";
            color(hConsole,c);
        }
        else if ((jefe[y][x]=="x" || jefe[y][x]=="#" )&& map==4)
        {
            color(hConsole,9);
            cout<<jefe[y][x]<<" ";
            color(hConsole,c);
        }
        else if ((jefe[y][x]=="x" || jefe[y][x]=="#" )&& map==6)
        {
            color(hConsole,6);
            cout<<jefe[y][x]<<" ";
            color(hConsole,c);
        }
        else if ((jefe[y][x]=="x")&& map==8 && y==0 || ((x>8 && x<=16) && y==tampy-7) )
        {
            color(hConsole,6);
            cout<<jefe[y][x]<<" ";
            color(hConsole,c);
        }
        
        else if ((jefe[y][x]=="x")&& map==8 && (x==0 || ( x<=8 && y==tampy-7)))
        {
            color(hConsole,4);
            cout<<jefe[y][x]<<" ";
            color(hConsole,c);
        }
        
        else if ((jefe[y][x]=="x")&& map==8 && (x==tampx-1 || ((x>16 && x<tampx-1) && y==tampy-7)))
        {
            color(hConsole,9);
            cout<<jefe[y][x]<<" ";
            color(hConsole,c);
        }
        

        else {cout<<jefe[y][x]<<" ";}
        //else {cout<<x <<" ";}
        if (i%tampx==0 && i!=0) {cout<<endl; x=-1; y++ ;}
        
        
    }
    color(hConsole,7);

    cout<< "+ Hp"<< pv << "   # Hp" <<ev <<endl;
    //cout<< "text " << text << "  turn  "<< turn;
    
    cout<< ptext  <<endl << text;
    
}

void sprincipal()
{
    dir = STOP;
    int x=0,y=0;
    for (int i=1;i<=tam*tam;i++)
    {
        if (x==0 && (y>=(tam/2)-1 && y<=(tam/2)+1) && sa==" "){tablero[y][x]=" ";}
        else if (x==tam-1 && (y>=(tam/2)-1 && y<=(tam/2)+1) && sf==" "){tablero[y][x]=" ";}
        else if(y==0 && (x>=(tam/2)-1 && x<=(tam/2)+1) && st==" "){tablero[y][x]=" ";}
        else if(y==tam-1 && (x>=(tam/2)-1 && x<=(tam/2)+1) && st=="+" && sa=="+" && sf=="+"){tablero[y][x]=" ";}
        else if(y==0 || y==tam-1) {tablero[y][x]="x";}
        else if (x==0 || x==tam-1){tablero[y][x]="x";}
        else {tablero[y][x]=" ";}
        if (x==tam-1) {x=0;y++;}
        else {x++;}
    }

    tablero[py][px]="+";

}

void salida()
{
    dir = STOP;
    int x=0,y=0;
    ey=tam/2; ex=16;

    for (int i=1;i<=tam*tam;i++)
    {
        color(hConsole,9);
        if (y==0 || y==tam-1){tablero[y][x]="x";}
        else if (x==0 || x==tam-1){tablero[y][x]="x";}
        else if((y>=0 & y<7) || y>=14 ) {tablero[y][x]="M";}

        else if((y==9 && x==18) || (y==11 && x==18)) {tablero[y][x]="N";}
        else if((y==8 && x==17) || (y==12 && x==17)) {tablero[y][x]="N";}
        else if((y==7 && x==16) || (y==13 && x==16)) {tablero[y][x]="N";}
        else if((y==10 && x==13) || (y==10 && x==19)) {tablero[y][x]="N";}
        else if((y==8 && x==15) || (y==12 && x==15)) {tablero[y][x]="N";}
        else if((y==9 && x==14) || (y==11 && x==14)) {tablero[y][x]="N";}

        else if (tablero[y][x]=="+"){tablero[y][x]=" ";}
        else {tablero[y][x]==" ";}
        if (x==tam-1) {x=0;y++;}
        else {x++;}

    }
    
   
    tablero[py][px]="+";
    tablero[ey][ex]="/";

    //if (tablero[py][px]=="/"){text="sexoooo"; gameOver=true;}
    if (tablero[py][px]=="/"){ptext=" "; text="Felicidades ahora eres libre, escapaste de la dungeon"; sa=" "; st=" "; sf=" "; gameOver=true;}   

}

void sfinal()
{
    dir = STOP;
    int x=0,y=0;
    c=7;
    ey=2; ex=tam/2;

    for (int i=1;i<=tam*tam;i++)
    {
        color(hConsole,9);
        if(y==0 || y==tam-1) {tablero[y][x]="x";}
        else if (x==0 || x==tam-1){tablero[y][x]="x";}
        else if (tablero[y][x]=="+"){tablero[y][x]=" ";}
        if (x==tam-1) {x=0;y++;}
        else {x++;}

    }
    
    tablero[py][px]="+";
    tablero[ey][ex]="#";

    if (tablero[py][px]=="#"){map=8;px=2;py=tampy-5;c=7;}    

}
void jfinal()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);
    int min=1, max=4;
    int randnum = min + rand() % (max - min + 1);
    int x=0,y=0;
    for (int i=1;i<=tampx*tampy;i++)
    {
        if(y==0 || y==tampy-1||y==tampy-7) {jefe[y][x]="x";}
        else if (x==0 || x==tampx-1){jefe[y][x]="x";}

        else if (y==tampy-5 && x==3){jefe[y][x]="a";}
        else if (y==tampy-5 && x==4){jefe[y][x]="t";}
        else if (y==tampy-5 && x==5){jefe[y][x]="t";}
        else if (y==tampy-5 && x==6){jefe[y][x]="a";}
        else if (y==tampy-5 && x==7){jefe[y][x]="c";}
        else if (y==tampy-5 && x==8){jefe[y][x]="k";}

        else if (y==tampy-5 && x==tampx-8){jefe[y][x]="b";}
        else if (y==tampy-5 && x==tampx-7){jefe[y][x]="l";}
        else if (y==tampy-5 && x==tampx-6){jefe[y][x]="o";}
        else if (y==tampy-5 && x==tampx-5){jefe[y][x]="c";}
        else if (y==tampy-5 && x==tampx-4){jefe[y][x]="k";}

        else if (y==tampy-3 && x==3){jefe[y][x]="d";}
        else if (y==tampy-3 && x==4){jefe[y][x]="o";}
        else if (y==tampy-3 && x==5){jefe[y][x]="d";}
        else if (y==tampy-3 && x==6){jefe[y][x]="g";}
        else if (y==tampy-3 && x==7){jefe[y][x]="e";}

        else if (y==tampy-3 && x==tampx-8){jefe[y][x]="s";}
        else if (y==tampy-3 && x==tampx-7){jefe[y][x]="k";}
        else if (y==tampy-3 && x==tampx-6){jefe[y][x]="i";}
        else if (y==tampy-3 && x==tampx-5){jefe[y][x]="l";}
        else if (y==tampy-3 && x==tampx-4){jefe[y][x]="l";}
        else if (y==tampy-3 && x==tampx-3){jefe[y][x]="s";}

        else if ((x>=4 && x<=8) && (y==(tampy-9) || y==(tampy-10) ) ){jefe[y][x]="+";}
        else if ((x>=5 && x<=7) && y==(tampy-11) ){jefe[y][x]="+";}

        else if ((x>=16 && x<=21) && y==3  ){jefe[y][x]="#";}
        else if (((y>=3 && y<=10) && x==15) || ((y>=3 && y<=10) && x==21) ){jefe[y][x]="#";}

        else if ((x>=16 && x<=21) && y==10  ){jefe[y][x]="#";}
        else if ((x>=16 && x<=20) && y==9  ){jefe[y][x]="#";}
        else if ((x>=17 && x<=19) && y==8 ){jefe[y][x]="#";}
        else if ((x==18) && y==7 ){jefe[y][x]="#";}

        else if ((x>=16 && x<=21) && y==3  ){jefe[y][x]="#";}
        else if ((x>=16 && x<=20) && y==4  ){jefe[y][x]="#";}
        else if ((x>=17 && x<=19) && y==5 ){jefe[y][x]="#";}
        else if ((x==18) && y==6 ){jefe[y][x]="#";}

        else if ((x>=16 && x<=21) && y==10  ){jefe[y][x]="#";}
        
        

        else {jefe[y][x]=" ";}
        if (x==tampx-1) {x=0;y++;}
        else {x++;}
    }

    jefe[py][px]="+";
    if (ev <= 0) { map = 9; px=1; py=tam/2 ;text=" "; ptext=" "; c=7;}
    if (pv <= 0) { ptext=" "; text=" "; ptext=" "; text= "perdiste"; ptext=" "; gameOver=true; }

    if (turn==false) 
        {

            //text=text + " " + "randnum " + to_string(randnum);
            if (randnum==1 && pblock==true){pv=pv-5; text= "enemigo no hizo mucho dano";} 
            else if (randnum==1 && pdodge==true) {pdodge=false;text= "enemigo ha atacado pero fallo";}
            else {pv=pv-10; text= "enemigo ha atacado";} 
            if (randnum==2){eblock=true; text= "enemigo se esta protegiendo";}
            if (randnum==3){edodge=true; text= "enemigo va a esquivar";}
            if (randnum==4){pv=pv-40;text= "enemigo hizo mucho dano";}
            turn=true;
        }
    else if (turn==true)
        {
            
            if (action == "at" && eblock== true){ev=ev-5; ptext= "no has hecho mucho dano";}
                else if(action == "at" && edodge== true) {edodge=false; ptext= " has atacado pero fallaste";}
                else if (action == "at") {ev=ev-10; ptext= "has atacado";}
            if (action == "blo"){ pblock=true; ptext= " te estas protegiendo";}
            if (action == "dod" ){ pdodge=true; ptext= "te preparas para esquivar";}
            if (action == "skil" ){ev=ev-25; ptext= "has usado magia";}
            action=" ";
        }
}

void stierra()
{
    dir = STOP;
    int x=0,y=0;
    c=6;
    ey=(tam/2); ex=tam/2;

    for (int i=1;i<=tam*tam;i++)
    {
        color(hConsole,6); //6 amarillo, 8 gris
        if(y==0 || y==tam-1) {tablero[y][x]="x";}
        else if (x==0 || x==tam-1){tablero[y][x]="x";}

        else if ((x==6 && y== 18) || (x== 14 && y==2)) {tablero[y][x]="*";}
        else if ((x==1 && y== 14) || (x== 19 && y==6)) {tablero[y][x]="/";}

        else if ((x==tam-2 || x==tam-6 || x==5 || x==1) && (y>=6 && y<=tam-7))  {tablero[y][x]=" ";}
        else if ((y==5 || y==2 || y==tam-3 || y==tam-6) && (x>=6 && x<=tam-7))  {tablero[y][x]=" ";}

        else if (y==3 || y==tam-4) {tablero[y][x]="x";}
        else if (x==3 || x==tam-4  ){tablero[y][x]="x";}
        else if (x==6 || x==tam-7){tablero[y][x]="x";}
        else if (y==6 || y==tam-7) {tablero[y][x]="x";}
        
        else {tablero[y][x]=" ";}
        if (x==tam-1) {x=0;y++;}
        else {x++;}
    }
    
    tablero[py][px]="+";
    tablero[ey][ex]="#";

    //principal
    if(px==6 && py==tam-3) {px=tam/2; py=2;}
    if(px==tam-7 && py==2) {px=tam-2; py=tam/2;}
    if(px==tam-2 && py==6) {px=1; py=tam/2;}
    if(px==1 && py==14) {px=13; py=tam/2;}

    //alternativo
    if(px==14 && py==18) {px=tam/2; py=15;}
    if(px==6 && py==15) {px=5; py=10;}
    if(px==5 && py==14) {px=15; py=10;}
    if(px==15 && py==14) {px=10; py=5;}
    if(px==6 && py==5) {px=7; py=13;}

    //retorno
    if((px==14 && py==15) || (px==14 && py==5) || (px==6 && py==2) || (px==5 && py==6)|| (px==1 && py==6)|| (px==15 && py==6) || (px==19 && py==14)) {px=10; py=18;}

    if (tablero[py][px]=="#"){map=6;px=2;py=tampy-5;c=7;}    

}

void jtierra()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);
    int min=1, max=4;
    int randnum = min + rand() % (max - min + 1);
    int x=0,y=0;
    for (int i=1;i<=tampx*tampy;i++)
    {
        if(y==0 || y==tampy-1||y==tampy-7) {jefe[y][x]="x";}
        else if (x==0 || x==tampx-1){jefe[y][x]="x";}

        else if (y==tampy-5 && x==3){jefe[y][x]="a";}
        else if (y==tampy-5 && x==4){jefe[y][x]="t";}
        else if (y==tampy-5 && x==5){jefe[y][x]="t";}
        else if (y==tampy-5 && x==6){jefe[y][x]="a";}
        else if (y==tampy-5 && x==7){jefe[y][x]="c";}
        else if (y==tampy-5 && x==8){jefe[y][x]="k";}

        else if (y==tampy-5 && x==tampx-8){jefe[y][x]="b";}
        else if (y==tampy-5 && x==tampx-7){jefe[y][x]="l";}
        else if (y==tampy-5 && x==tampx-6){jefe[y][x]="o";}
        else if (y==tampy-5 && x==tampx-5){jefe[y][x]="c";}
        else if (y==tampy-5 && x==tampx-4){jefe[y][x]="k";}

        else if (y==tampy-3 && x==3){jefe[y][x]="d";}
        else if (y==tampy-3 && x==4){jefe[y][x]="o";}
        else if (y==tampy-3 && x==5){jefe[y][x]="d";}
        else if (y==tampy-3 && x==6){jefe[y][x]="g";}
        else if (y==tampy-3 && x==7){jefe[y][x]="e";}

        else if (y==tampy-3 && x==tampx-8){jefe[y][x]="s";}
        else if (y==tampy-3 && x==tampx-7){jefe[y][x]="k";}
        else if (y==tampy-3 && x==tampx-6){jefe[y][x]="i";}
        else if (y==tampy-3 && x==tampx-5){jefe[y][x]="l";}
        else if (y==tampy-3 && x==tampx-4){jefe[y][x]="l";}
        else if (y==tampy-3 && x==tampx-3){jefe[y][x]="s";}

        else if ((x>=4 && x<=8) && (y==(tampy-9) || y==(tampy-10) ) ){jefe[y][x]="+";}
        else if ((x>=5 && x<=7) && y==(tampy-11) ){jefe[y][x]="+";}

        else if ((x>=15 && x<=21) && y==3  ){jefe[y][x]="#";}
        else if (((y>=3 && y<=10) && x==14) || ((y>=3 && y<=10) && x==21) ){jefe[y][x]="#";}
        else if ((x>=15 && x<=21) && y==10  ){jefe[y][x]="#";}
        
        

        else {jefe[y][x]=" ";}
        if (x==tampx-1) {x=0;y++;}
        else {x++;}
    }

    jefe[py][px]="+";
    if (ev <= 0) { map = 0; px=tam/2; py=tam/2; st="+";ev=100; pv=100;text=" "; ptext=" ";}
    if (pv <= 0) { ptext=" "; text= "perdiste"; ptext=" "; gameOver=true; }

    if (turn==false) 
        {

            //text=text + " " + "randnum " + to_string(randnum);
            if (randnum==1 && pblock==true){pv=pv-5; text= "enemigo no hizo mucho dano";} 
            else if (randnum==1 && pdodge==true) {pdodge=false;text= "enemigo ha atacado pero fallo";}
            else {pv=pv-10; text= "enemigo ha atacado";} 
            if (randnum==2){eblock=true; text= "enemigo se esta protegiendo";}
            if (randnum==3){edodge=true; text= "enemigo va a esquivar";}
            if (randnum==4){pv=pv-40;text= "enemigo hizo mucho dano";}
            turn=true;
        }
    else if (turn==true)
        {
            
            if (action == "at" && eblock== true){ev=ev-5; ptext= "no has hecho mucho dano";}
                else if(action == "at" && edodge== true) {edodge=false; ptext= " has atacado pero fallaste";}
                else if (action == "at") {ev=ev-10; ptext= "has atacado";}
            if (action == "blo"){ pblock=true; ptext= " te estas protegiendo";}
            if (action == "dod" ){ pdodge=true; ptext= "te preparas para esquivar";}
            if (action == "skil" ){ev=ev-25; ptext= "has usado magia";}
            action=" ";
        }
}

void sagua()
{
    dir = STOP;
    int x=0,y=0;
    c=9;
    ey=tam/2; ex=2;

    for (int i=1;i<=tam*tam;i++)
    {
        color(hConsole,9);
        if(y==0 || y==tam-1) {tablero[y][x]="x";}
        else if (x==0 || x==tam-1){tablero[y][x]="x";}
        else if (x==4 && y!=tam/2){tablero[y][x]="x";}
        else if (tablero[y][x]=="+"){tablero[y][x]=" ";}
        if (x==tam-1) {x=0;y++;}
        else {x++;}

    }
    
    tablero[py][px]="+";
    tablero[ey][ex]="#";

    tablero[oy1][ox1]="o";
    if (tablero[py][px]=="o"){gameOver=true;}

    if (tablero[py][px]=="#"){map=4;px=2;py=tampy-5;c=7;}    

}

void jagua()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);
    int min=1, max=4;
    int randnum = min + rand() % (max - min + 1);
    int x=0,y=0;
    for (int i=1;i<=tampx*tampy;i++)
    {
        if(y==0 || y==tampy-1||y==tampy-7) {jefe[y][x]="x";}
        else if (x==0 || x==tampx-1){jefe[y][x]="x";}

        else if (y==tampy-5 && x==3){jefe[y][x]="a";}
        else if (y==tampy-5 && x==4){jefe[y][x]="t";}
        else if (y==tampy-5 && x==5){jefe[y][x]="t";}
        else if (y==tampy-5 && x==6){jefe[y][x]="a";}
        else if (y==tampy-5 && x==7){jefe[y][x]="c";}
        else if (y==tampy-5 && x==8){jefe[y][x]="k";}

        else if (y==tampy-5 && x==tampx-8){jefe[y][x]="b";}
        else if (y==tampy-5 && x==tampx-7){jefe[y][x]="l";}
        else if (y==tampy-5 && x==tampx-6){jefe[y][x]="o";}
        else if (y==tampy-5 && x==tampx-5){jefe[y][x]="c";}
        else if (y==tampy-5 && x==tampx-4){jefe[y][x]="k";}

        else if (y==tampy-3 && x==3){jefe[y][x]="d";}
        else if (y==tampy-3 && x==4){jefe[y][x]="o";}
        else if (y==tampy-3 && x==5){jefe[y][x]="d";}
        else if (y==tampy-3 && x==6){jefe[y][x]="g";}
        else if (y==tampy-3 && x==7){jefe[y][x]="e";}

        else if (y==tampy-3 && x==tampx-8){jefe[y][x]="s";}
        else if (y==tampy-3 && x==tampx-7){jefe[y][x]="k";}
        else if (y==tampy-3 && x==tampx-6){jefe[y][x]="i";}
        else if (y==tampy-3 && x==tampx-5){jefe[y][x]="l";}
        else if (y==tampy-3 && x==tampx-4){jefe[y][x]="l";}
        else if (y==tampy-3 && x==tampx-3){jefe[y][x]="s";}

        else if ((x>=4 && x<=8) && (y==(tampy-9) || y==(tampy-10) ) ){jefe[y][x]="+";}
        else if ((x>=5 && x<=7) && y==(tampy-11) ){jefe[y][x]="+";}

        else if ((x>=15 && x<=21) && y==6  ){jefe[y][x]="#";}
        else if ((x>=16 && x<=20) && y==5  ){jefe[y][x]="#";}
        else if ((x>=17 && x<=19) && y==4 ){jefe[y][x]="#";}
        else if ((x==18) && y==3 ){jefe[y][x]="#";}
        

        else {jefe[y][x]=" ";}
        if (x==tampx-1) {x=0;y++;}
        else {x++;}
    }

    jefe[py][px]="+";
    if (ev <= 0) { map = 0; px=tam/2; py=tam/2; sa="+";ev=100; pv=100;text=" "; ptext=" ";}
    if (pv <= 0) { ptext=" "; text= "perdiste"; ptext=" "; gameOver=true; }

    if (turn==false) 
        {

            //text=text + " " + "randnum " + to_string(randnum);
            if (randnum==1 && pblock==true){pv=pv-5; text= "enemigo no hizo mucho dano";} 
            else if (randnum==1 && pdodge==true) {pdodge=false;text= "enemigo ha atacado pero fallo";}
            else {pv=pv-10; text= "enemigo ha atacado";} 
            if (randnum==2){eblock=true; text= "enemigo se esta protegiendo";}
            if (randnum==3){edodge=true; text= "enemigo va a esquivar";}
            if (randnum==4){pv=pv-40;text= "enemigo hizo mucho dano";}
            turn=true;
        }
    else if (turn==true)
        {
            
            if (action == "at" && eblock== true){ev=ev-5; ptext= "no has hecho mucho dano";}
                else if(action == "at" && edodge== true) {edodge=false; ptext= " has atacado pero fallaste";}
                else if (action == "at") {ev=ev-10; ptext= "has atacado";}
            if (action == "blo"){ pblock=true; ptext= " te estas protegiendo";}
            if (action == "dod" ){ pdodge=true; ptext= "te preparas para esquivar";}
            if (action == "skil" ){ev=ev-25; ptext= "has usado magia";}
            action=" ";
        }
}

void sfuego()
{
    dir = STOP;
    int x=0,y=0;
    c=4;
    ey=tam/2; ex=tam-3;
    if (oy1<tam-2) {oy1=oy1+2;} else {oy1=1;}
    if (oy2>1) {oy2=oy2-2;} else {oy2=tam-2;}
    if (oy3<tam-2) {oy3=oy3+3;} else {oy3=1;}
    if (oy4>1) {oy4=oy4-3;} else {oy4=tam-2;}

    for (int i=1;i<=tam*tam;i++)
    {
        color(hConsole,4);
        if(y==0 || y==tam-1) {tablero[y][x]="x";}
        else if (x==0 || x==tam-1){tablero[y][x]="x";}
        else {tablero[y][x]=" ";}
        if (x==tam-1) {x=0;y++;}
        else {x++;}
    }
    
    tablero[py][px]="+";
    tablero[ey][ex]="#";

    
    tablero[oy1][ox1]="!";
    if(tablero[oy1-1][ox1-1]==" " || tablero[oy1-1][ox1-1]=="+") {tablero[oy1-1][ox1-1]="!";}
    if(tablero[oy1-2][ox1-2]==" " || tablero[oy1-2][ox1-2]=="+") {tablero[oy1-2][ox1-2]="!";}
    
    
    tablero[oy2][ox2]="!";
    if (tablero[oy2+1][ox2]==" "){tablero[oy2+1][ox2]="!";}
    if (tablero[oy2+2][ox2]==" "){tablero[oy2+2][ox2]="!";}
    if (tablero[oy2+3][ox2]==" "){tablero[oy2+3][ox2]="!";}
    if (tablero[oy2+4][ox2]==" "){tablero[oy2+4][ox2]="!";}
    
    
    
    tablero[oy3][ox3]="!";
    if (tablero[oy3-1][ox3]==" "){tablero[oy3-1][ox3]="!";}
    if (tablero[oy3-2][ox3]==" "){tablero[oy3-2][ox3]="!";}
    //if (tablero[oy3-3][ox3]==" "){tablero[oy3-3][ox3]="!";}
    //if (tablero[oy3-4][ox3]==" "){tablero[oy3-4][ox3]="!";}

    tablero[oy4][ox4]="!";
    if (tablero[oy4+1][ox4]==" "){tablero[oy4+1][ox4]="!";}
    if (tablero[oy4+2][ox4]==" "){tablero[oy4+2][ox4]="!";}

    if (tablero[py][px]=="!"){gameOver=true;}
    else if (tablero[py-1][px]=="!"){gameOver=true;}
    else if (tablero[py+1][px]=="!"){gameOver=true;}

    if (tablero[py][px]=="#"){map=2;px=2;py=tampy-5;c=7;}
    

}

void jfuego()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);
    int min=1, max=4;
    int randnum = min + rand() % (max - min + 1);
    int x=0,y=0;
    for (int i=1;i<=tampx*tampy;i++)
    {
        if(y==0 || y==tampy-1||y==tampy-7) {jefe[y][x]="x";}
        else if (x==0 || x==tampx-1){jefe[y][x]="x";}

        else if (y==tampy-5 && x==3){jefe[y][x]="a";}
        else if (y==tampy-5 && x==4){jefe[y][x]="t";}
        else if (y==tampy-5 && x==5){jefe[y][x]="t";}
        else if (y==tampy-5 && x==6){jefe[y][x]="a";}
        else if (y==tampy-5 && x==7){jefe[y][x]="c";}
        else if (y==tampy-5 && x==8){jefe[y][x]="k";}

        else if (y==tampy-5 && x==tampx-8){jefe[y][x]="b";}
        else if (y==tampy-5 && x==tampx-7){jefe[y][x]="l";}
        else if (y==tampy-5 && x==tampx-6){jefe[y][x]="o";}
        else if (y==tampy-5 && x==tampx-5){jefe[y][x]="c";}
        else if (y==tampy-5 && x==tampx-4){jefe[y][x]="k";}

        else if (y==tampy-3 && x==3){jefe[y][x]="d";}
        else if (y==tampy-3 && x==4){jefe[y][x]="o";}
        else if (y==tampy-3 && x==5){jefe[y][x]="d";}
        else if (y==tampy-3 && x==6){jefe[y][x]="g";}
        else if (y==tampy-3 && x==7){jefe[y][x]="e";}

        else if (y==tampy-3 && x==tampx-8){jefe[y][x]="s";}
        else if (y==tampy-3 && x==tampx-7){jefe[y][x]="k";}
        else if (y==tampy-3 && x==tampx-6){jefe[y][x]="i";}
        else if (y==tampy-3 && x==tampx-5){jefe[y][x]="l";}
        else if (y==tampy-3 && x==tampx-4){jefe[y][x]="l";}
        else if (y==tampy-3 && x==tampx-3){jefe[y][x]="s";}

        else if ((x>=4 && x<=8) && (y==(tampy-9) || y==(tampy-10) ) ){jefe[y][x]="+";}
        else if ((x>=5 && x<=7) && y==(tampy-11) ){jefe[y][x]="+";}

        else if ((x>=15 && x<=21) && y==3  ){jefe[y][x]="#";}
        else if ((x>=16 && x<=20) && y==4  ){jefe[y][x]="#";}
        else if ((x>=17 && x<=19) && y==5 ){jefe[y][x]="#";}
        else if ((x==18) && y==6 ){jefe[y][x]="#";}
        

        else {jefe[y][x]=" ";}
        if (x==tampx-1) {x=0;y++;}
        else {x++;}
    }

    jefe[py][px]="+";
    if (ev <= 0) { map = 0; px=tam/2; py=tam/2; sf="+"; ev=100; pv=100; text=" "; ptext=" ";}
    if (pv <= 0) { ptext=" "; text= "perdiste"; ptext=" "; gameOver=true; }

    if (turn==false) 
        {

            //text=text + " " + "randnum " + to_string(randnum);
            if (randnum==1 && pblock==true){pv=pv-5; text= "enemigo no hizo mucho dano";} 
            else if (randnum==1 && pdodge==true) {pdodge=false;text= "enemigo ha atacado pero fallo";}
            else {pv=pv-10; text= "enemigo ha atacado";} 
            if (randnum==2){eblock=true; text= "enemigo se esta protegiendo";}
            if (randnum==3){edodge=true; text= "enemigo va a esquivar";}
            if (randnum==4){pv=pv-40;text= "enemigo hizo mucho dano";}
            turn=true;
        }
    else if (turn==true)
        {
            
            if (action == "at" && eblock== true){ev=ev-5; ptext= "no has hecho mucho dano";}
                else if(action == "at" && edodge== true) {edodge=false; ptext= " has atacado pero fallaste";}
                else if (action == "at") {ev=ev-10; ptext= "has atacado";}
            if (action == "blo"){ pblock=true; ptext= " te estas protegiendo";}
            if (action == "dod" ){ pdodge=true; ptext= "te preparas para esquivar";}
            if (action == "skil" ){ev=ev-25; ptext= "has usado magia";}
            action=" ";
        }
}

void pinput() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case '1':
            sa="+";
            break;
        case '2':
            sf="+";
            break;
        case '3':
            st="+";
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void inputJ() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            px=2;
            break;
        case 'd':
            px=tampx-9;
            break;
        case 'w':
            py=tampy-5;
            break;
        case 's':
            py=tampy-3;
            break;
        case 'f':
            if (px==2 && py==tampy-5 && turn==true)
            {turn=false; action="at";}
            else if (px==2 && py==tampy-3 && turn==true)
            {turn=false; action="dod";}
            else if (px==tampx-9 && py==tampy-5 && turn==true)
            {turn=false; action="blo";}
            else if (px==tampx-9 && py==tampy-3 && turn==true)
            {turn=false; action="skil";}
            
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void plogic()
{
    switch (dir) {
    case LEFT:
        if (px==0 && (py>=(tam/2)-1 && py<=(tam/2)+1)) 
        {map=3; px=tam-2; py=2;ox1=tam-2; oy1= tam-3;}
        else if (tablero[py][px-1]!="x" && map==3 && tablero[oy1][ox1-1]!="x" && tablero[oy1][ox1-1]!="o" ){px--; ox1--;  }
        else if (tablero[py][px-1]!="x"){px--;}
        break;

    case RIGHT:
        if (px==tam-1 && (py>=(tam/2)-1 && py<=(tam/2)+1)) 
        {map=1; px=2; ox1= 4; oy1= 1;  ox2= 8; oy2= tam-2; ox3= 12; oy3=1;}
        else if (tablero[py][px+1]!="x" && map==3 && tablero[oy1][ox1+1]!="x" &&tablero[oy1][ox1+1]!="o"){px++; ox1++; }
        else if (tablero[py][px+1]!="x"){px++;}
        break;

    case UP:
        if (py==0 && (px>=(tam/2)-1 && px<=(tam/2)+1)) 
        {map=5; py=tam-2;}
        else if (tablero[py-1][px]!="x" && map==3 && tablero[oy1+1][ox1]!="x" && tablero[oy1+1][ox1]!="o"){py--; oy1++;}
        else if (tablero[py-1][px]!="x"){py--;}
        break;

    case DOWN:
        if (py==tam-1 && (px>=(tam/2)-1 && px<=(tam/2)+1)) 
        {map=7; py=10;}
        else if (tablero[py+1][px]!="x" && map==3 && tablero[oy1-1][ox1]!="x" && tablero[oy1-1][ox1]!="o"){py++; oy1--;}
        else if (tablero[py+1][px]!="x"){py++;}
        break;
    default:
        break;
    }
}


int main()
{
while (!gameOver)
{
    if (map==2) {inputJ();}
    else if (map==4) {inputJ();}
    else if (map==6) {inputJ();}
    else if (map==8) {inputJ();}
    else {pinput();}
    //Input();
    plogic();
    if (map==1) {sfuego();}
    else if (map==2) {jfuego();}
    else if (map==3) {sagua();}
    else if (map==4) {jagua();}
    else if (map==5) {stierra();}
    else if (map==6) {jtierra();}
    else if (map==7) {sfinal();}
    else if (map==8) {jfinal();}
    else if (map==9) {salida();}
    else 
    {sprincipal();}
    if (map==2) {mosPJ();}
    else if (map==4) {mosPJ();}
    else if (map==6) {mosPJ();}
    else if (map==8) {mosPJ();}
    else {mostrar();}
    Sleep(60);
}
    return 0;
}