#include <cassert>
#include <iostream>

// Napište funckci, která vrátí součin dvou čísel
int multiply(int a, int b) {
    return a*b;
}

// Napište funkci, která rozhodne jestli číslo je sudé
bool is_even(int x) {

    return (x % 2)==0;
}

// Vypište věechny čísla od start do stop (včetně)
void print_numbers(int start, int stop) {
    do
    {
        std::cout << start << std::endl;
        start++;
    } while (start<=stop);
    

}

// Naimplementujte funkci která pořítá faktoriál
// Faktoriál čísla x je definovaný jako součin všech kladných čísel <= x
int factorial(int x) {

    int vysledek =x;
    for(int i =1;i<x;i++)
    {
    vysledek = vysledek*i;
    std::cout << vysledek << std::endl;
    }
    
    return vysledek;
}

// Funkce vypíše count hvězdiček
void print_stars(unsigned int count) {
    for(int i =0;i<count;i++)
    {
    std::cout << "*" ;//<< std::endl;
    }
    std::cout << " "<< std::endl;
}

// Funkce vypíše obdélníček z hvězdiček
void print_rectangle(unsigned int sirka, unsigned int vyska) {
    for(int i =0;i<vyska;i++)
    {
        for(int i =0;i<sirka;i++)
            {
            std::cout << "*" ;//<< std::endl;
            }
            std::cout << " "<< std::endl;
    }
}

// Funkce vypíše takovýto trojúhelník o zadané výšce
// *
// **
// ***
// ****
void print_pyramid_l(unsigned int height) {
    int sirka =1;
    for(int i =0;i<height;i++)
    {
        for(int i =0;i<sirka;i++)
        {
            std::cout << "*" ;//<< std::endl;
            
        }
        std::cout << " "<< std::endl;
        sirka++;
    }
   
}


// Funkce vypíše takovýto trojúhelník o zadané výšce
//    *
//   **
//  ***
// ****
void print_pyramid_r(unsigned int height) {
    int mezera = height-1;
    //for(int i =0;mezera<i;i++)
}

// Funkce vypíše takovýto trojúhelník o zadané výšce
//    *
//   ***
//  *****
// *******
void print_pyramid(unsigned int height) {
}

// Funkce vypíše takovýto trojúhelník o zadané výšce
// *******
//  *****
//   ***
//    *
void print_pyramid_inverse(unsigned int height) {
}

int main() {
    //! musim napsat do terminalu by mi jel program -> make excersises && ./excersises 
   // bool vysledk = is_even(4);
    std::cout << "poved" << std::endl;
    print_pyramid_l(4);
    
}
