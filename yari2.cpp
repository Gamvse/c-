#include<iostream>
using namespace std;


int pjx, x1x, pjy, x1y, x2x, x2y, t1x,t1y,la,l;
bool t1 = true;
//te volvio a pasar lo de poner t1 cómo bool y cómo int jajaja
 
 void cotras(int &pjx, int x1x,int &pjy,int x1y,int x2x,int x2y,int t1x,int t1y,bool &t1,int la, int l)
 //tenías una , extra al final de la función
 {
 
    if((pjx == x1x && pjy == x1y)||(pjx==x2x && pjy==x2y))
    //te falto un () que abarcara toda la condición 
    {l=l-10;}

    if(pjx == t1x && pjy == t1y && t1 == true && la+20 < l)
    {la = la+20; t1 = false;}
    //estos 2 if se encargan de la lógica de los cofres para que no cura más que la vida máxima del personaje 

    else if(pjx == t1x && pjy == t1y && t1 == true && la+20 < l)
    {la = la+10; t1 = false;}
}
        
int main()
{
	l= 100;
    pjx=2;
    x1x=4;
	x1y= 4;
    pjy=2;
    x2y=3;
    x2x=3;
    t1x=5;
    t1y=6;
    t1=10;
    //pusiste los ; donde no iban
    
    cotras(pjx, x1x, pjy, x1y, x2x, x2y, t1x,t1y,t1,la,l);
    //cuando pases los valores de las variables tienen que estár en el mismo orden que en la línea 9
    //cout<<p;
    cout<< la <<endl;

    return 0;
}