#include<iostream>
using namespace std;

int pjx=9, pjy=9, p1ax=2, p1ay=2, p1bx=5, p1by=5, p2ax , p2ay, p2bx, p2by, p3ax=7, p3ay=7, p3bx=9, p3by=9,p4ax , p4ay, p4bx, p4by,p5ax, p5ay, p5bx, p5by , p6ax , p6ay, p6bx, p6by , p7ax , p7ay, p7bx, p7by , p8ax , p8ay, p8bx, p8by , p9ax , p9ay, p9bx, p9by , p10ax , p10ay, p10bx, p10by ;
bool p=false;

void portales(int &pjx, int &pjy, int p1ax, int p1ay, int p1bx, int p1by, int p2ax, int p2ay,int p2bx, int p2by, int p3ax, int p3ay,int p3bx, int p3by, int p4ax, int p4ay,int p4bx, int p4by, int p5ax, int p5ay,int p5bx, int p5by, int p6ax, int p6ay,int p6bx, int p6by, int p7ax, int p7ay,int p7bx, int p7by, int p8ax, int p8ay,int p8bx, int p8by, int p9ax, int p9ay,int p9bx, int p9by, int p10ax, int p10ay,int p10bx, int p10by , bool &p)
{
    // a -> b
    if(pjx == p1ax && pjy == p1ay && p == false)
    {pjx = p1bx; pjy = p1by; p = true;}

    else if(pjx == p2ax && pjy == p2ay && p == false)
    {pjx = p2bx; pjy = p2by; p = true;}

    else if(pjx == p3ax && pjy == p3ay && p == false)
    {pjx = p3bx; pjy = p3by; p = true;}

    else if(pjx == p4ax && pjy == p4ay && p == false)
    {pjx = p4bx; pjy = p4by; p = true;}

    else if(pjx == p5ax && pjy == p5ay && p == false)
    {pjx = p5bx; pjy = p5by; p = true;}

    else if(pjx == p6ax && pjy == p6ay && p == false)
    {pjx = p6bx; pjy = p6by; p = true;}

    else if(pjx == p7ax && pjy == p7ay && p == false)
    {pjx = p7bx; pjy = p7by; p = true;}

    else if(pjx == p8ax && pjy == p8ay && p == false)
    {pjx = p8bx; pjy = p8by; p = true;}

    else if(pjx == p9ax && pjy == p9ay && p == false)
    {pjx = p9bx; pjy = p9by; p = true;}

    else if(pjx == p10ax && pjy == p10ay && p == false)
    {pjx = p10bx; pjy = p10by; p = true;}
    

    // b ->a
    else if(pjx == p1bx && pjy == p1by && p == false)
    {pjx =p1ax; pjy = p1ay;p = true;} 
    
    else if(pjx == p2bx && pjy == p2by && p == false)
    {pjx =p2ax; pjy = p2ay;p = true;} 
    
    else if(pjx == p3bx && pjy == p3by && p == false)
    {pjx =p3ax; pjy = p3ay;p = true;} 
    
    else if(pjx == p4bx && pjy == p4by && p == false)
    {pjx =p4ax; pjy = p4ay;p = true;} 
    
    else if(pjx == p5bx && pjy == p5by && p == false)
    {pjx =p5ax; pjy = p5ay;p = true;} 
    
    else if(pjx == p6bx && pjy == p6by && p == false)
    {pjx =p6ax; pjy = p6ay;p = true;} 
    
    else if(pjx == p7bx && pjy == p7by && p == false)
    {pjx =p7ax; pjy = p7ay;p = true;} 
    
    else if(pjx == p8bx && pjy == p8by && p == false)
    {pjx =p8ax; pjy = p8ay;p = true;} 
    
    else if(pjx == p9bx && pjy == p9by && p == false)
    {pjx =p9ax; pjy = p9ay;p = true;} 
    
    else if(pjx == p10bx && pjy == p10by && p == false)
    {pjx =p10ax; pjy = p10ay;p = true;}

}

int main()
{
    portales(pjx, pjy, p1ax, p1ay, p1bx, p1by, p2ax, p2ay, p2bx, p2by, p3ax, p3ay, p3bx, p3by, p4ax, p4ay, p4bx, p4by, p5ax, p5ay, p5bx, p5by, p6ax , p6ay, p6bx, p6by , p7ax , p7ay, p7bx, p7by , p8ax , p8ay, p8bx, p8by , p9ax , p9ay, p9bx, p9by , p10ax , p10ay, p10bx, p10by, p);
    //cout<<p;
    cout<< pjx <<endl <<pjy;

    return 0;
}