// TODO: Doplňte potřebné hlavičky
#include <iostream>
// Vypište obdélník o zadaných parametrech
// Vraťte 0 pokud vše v pořádku, -1 pokud nastala chyba
int hollow_rect(int x, int y, int thickness) {
    //! vrsek a spodek
    if((x-2*thickness)<=0||(y-2*thickness)<=0)
    {
        return -1;
    }
    for(int i=0;i<thickness;i++)
    {
         for(int i=0;i<x;i++)
         {
              std::cout<<"*";
         }
         std::cout<< " "<<std::endl;
    }

    for(int i=0;i<y-thickness*2;i++)
    {
        //! jeden radek
        for(int i =0;i<thickness;i++)
        {
            std::cout<<"*";
        }

        for(int i =0;i<x-thickness*2;i++)
        {
            std::cout<<" ";
        }

        for(int i =0;i<thickness;i++)
        {
            std::cout<<"*";
        }
        std::cout<<" "<<std::endl;
    }

    for(int i=0;i<thickness;i++)
    {
         for(int i=0;i<x;i++)
         {
              std::cout<<"*";
         }
         std::cout<< " "<<std::endl;
    }

    return 0;
    
}

// Vraťte a na n
int power(int a, int n) {
    int vysledek =1;

    for(int i = 0; i<n;i++)
    {
        vysledek = vysledek*a;
    }
    return vysledek;
}

// Vraťte idx-té fibonacciho číslo
int fibonacci(int idx) {
    int a,b;
    int vysledek = 1;
    for(int i =0; i<idx;i++)
    {
        a = vysledek;
       vysledek = a+b;
       b= a;
    

    }
    return vysledek;
}

int main() {
    std::cout << fibonacci(5);
}
