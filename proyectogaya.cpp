#include<iostream>
using namespace std;

int l,la, M, N elem, wall1, cwall, path1, cpath, x1,t1, p1ay, p1ax, p1by,p1bx, p1, Ex, Ey, pjx, pjy, Sx, Sy, mov, ef
char type, input
bool p=false, t1,t2,t3,

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

void datos( int path1)
{
    //entrada del programa
    cin>>l;
    //vida
    cin>>M;
    //ancho
    cin>>N;
    //largo

    cin>>elem;
    //elementos 

    for(int i=0;i<elem; i++)
    //aquí el bucle va de 0 hasta elementos (esa es la condición para que termine el bucle)
    {

        //está parte del codigo es para que al momento de ingresar el tipo de variable la reconozca y la clasifique, y coloque su respectiva posición x, y
      cin>>type;
      if(type == '#' && wall1== o)
      //en está parte puse '#n' pero esa n deberia ser el número de la variable osea que si muro wall1, wall2 y así, aparte corrigo no debería de tener las comitas
      {cin>>wall1x; cin>>wall1y; cwall++;}

      if(type == '#' && wall2== o)
      {cin>>wall2x; cin>>wall2y; cwall++;}

      if(type == '#' && wall3== o)
      {cin>>wall3x; cin>>wall3y; cwall++;}  

        //y así con el resto de variables y elementos, acuerdate el máximo son 10

      else if(type =='.' && path1==0)
      {cin>> path1x; cin>> path1y; path1++;}


      else if(type =='x' && x1==0)
      {cin>>x1x; cin>>x1y; x1++;}


      else if(type =='t' && t1 == 0)
      {cin>> t1x; cin>>t1y; t1++;}


      else if(type == 'p' && pn==0)
      {
        cin>>p1ax; cin>>p1ay;
        cin>>p1bx; cin>>p1by; pn++;
      }

        //estos casos son las entradas que solo tiene 1 valor, osea, solo existe 1 entrada, 1 salida, y 1 personaje
        else if(type =='E')
        {cin>>Ex >>Ey;}

        else if(type =='Pj')
        {cin>>pjx>>pjy;}

        else if(type =='S')
        {cin>>Sx >>Sy;}

    }

    cin mov;
    //este es para introducir la cantidad de movimientos

    for(int=0; i<mov; i++){
     
     cin>>input;
     //aqui registra la entrada del movimiento que si w,a,s,d
     cuerpo();
     //se llama a la función que es la que se encarga de hacer la acciones

    }

}

//esto es lo que hace la función
char cuerpo(char input)
{
    if(input == 'w')
    {
        if(
            pjx == wallx1 && pjy+1 == wally1 || pjx == wallx2 && pjy+1 == wally2 || pjx == wallx3 && pjy+1 == wally3 || pjx == wallx4 && pjy+1 == wally4 || pjx == wallx5 && pjy+1 == wally5 || pjx == wallx6 && pjy+1 == wally6 || pjx == wallx7 && pjy+1 == wally7 || pjx == wallx8 && pjy+1 == wally8  ||pjx == wallx9 && pjy+1 == wally9 || pjx == wallx10 && pjy+1 == wallx10 ||)
            //este if lo que hace es revisar si el valor "x" de pj es igual a algún muro y si al sumarle 1 a "y" de pj es igual al de un muro (eso es porque se está moviendo para arriba)
        {cout<<"Movimiento bloqueado";}
        else if(pjy +1>N){}
        else{pjy = pjy+1;} 
    }

    else if(input =='d')
    {
        if(
            pjy == wally1 && pjx+1 == wallx1 || pjy == wally2 && pjx+1 == wallx2 || pjy == wally3 && pjx+1 ==wallx3 || pjy == wally4 && pjx+1 == wallx4 || pjy == wally5 && pjx+1 == wallx5 || pjy == wally6 && pjx+1 == wallx6 || pjy == wally7 && pjx+1 == wallx7 || pjy == wally8 && pjx+1 == wallx8 ||pjy == wally9 && pjx+1 == wallx9 || pjy == wally10 && pjx+1 == wallx10 ||)
            //este if hace lo mismo que el de la w, pero en vez de moverse en eje y se mueve en eje x, entonces revisa primero si está en el mismo "y" y luego revisa si se suma 1 en "x" de pj es igual a algun muro
        {cout<<"Movimiento bloqueado";}
        else if(pjx+1>M){}
        else{pjx= pjx+1}
    }
    //los if de arriba son los encargados del movimiento, aumentando o disminuyendo los valores x, y de pj 

        portales(pjx, pjy, p1ax, p1ay, p1bx, p1by, p2ax, p2ay, p2bx, p2by, p3ax, p3ay, p3bx, p3by, p4ax, p4ay, p4bx, p4by, p5ax, p5ay, p5bx, p5by, p6ax , p6ay, p6bx, p6by , p7ax , p7ay, p7bx, p7by , p8ax , p8ay, p8bx, p8by , p9ax , p9ay, p9bx, p9by , p10ax , p10ay, p10bx, p10by, p);
        //lógica de los portales

        if(pjx == x1x && pjy == x1y)||(pjx==x2x && pjy==x2y)
        {l=l-10;}

        if(pjx == t1x && pjy == t1y && t1 == true && la+20 < l)
        {la = la+20; t1 = false;}
        //estos 2 if se encargan de la lógica de los cofres para que no cura más que la vida máxima del personaje 

        else if(pjx == t1x && pjy == t1y && t1 == true && la+20 < l)
        {la = la+10; t1 = false;}

        //los 3 if son la lógica del entorno, es decir de los cofres, las trampas

        if(la == 0)
        {ef = 0;}

        else if(pj == sx && pjy == sy && te == tt)
        {ef=2;}

        else if(j+1 == md && pjx != sx && pjy != sy)
        {ef=3;}
        
        else if(pjx == sx && pjy==sy)
        {ef=1;}
        //ef (estado final) esas 4 condiciones dice es la encargada que si de decir si murio, quedo atrapado, etc
}

void imprimir()
//hace lo que dice sú nombre (es decir muestra por pantalla, encargado de la salida )
    {
        cout<<te<<endl;
        cout<<xa<<endl;
        cout<<la<<endl;
        if( ef==0)
        {cout<<"Muerto";}

        else if(ef==1)
        {cout<<"logrado";}

        else if(ef==2)
        {cout<<"Sorprendete";}

        else if(ef==4)
        {cout<<"Atrapado";}
    }

int main()
{
    return 0;
}

