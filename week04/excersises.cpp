#include <cassert>
#include <iostream>

// Napište funckci, která vrátí součin dvou čísel
int multiply(int a, int b) {
    return 0;
}

// Napište funkci, která rozhodne jestli číslo je sudé
bool is_even(int x) {
    return false;
}

// Vypište věechny čísla od start do stop (včetně)
void print_numbers(int start, int stop) {
}

// Naimplementujte funkci která pořítá faktoriál
// Faktoriál čísla x je definovaný jako součin všech kladných čísel <= x
int factorial(int x) {
    return 0;
}

// Funkce vypíše count hvězdiček
void print_stars(unsigned int count) {
}

// Funkce vypíše obdélníček z hvězdiček
void print_rectangle(unsigned int sirka, unsigned int vyska) {
}

// Funkce vypíše takovýto trojúhelník o zadané výšce
// *
// **
// ***
// ****
void print_pyramid_l(unsigned int height) {
}

// Funkce vypíše takovýto trojúhelník o zadané výšce
//    *
//   **
//  ***
// ****
void print_pyramid_r(unsigned int height) {
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
    std::cout << "5 * 2:" << multiply(5, 2) << std::endl;
    std::cout << "Číslo 5 je sudé?:" << is_even(5) << std::endl;
    print_numbers(-5, 2);
    std::cout << "Faktoriál 5:" << factorial(5) << std::endl;
    print_stars(5);
    print_rectangle( 10, 20);
    print_pyramid_l(5);
    print_pyramid_r(5);
    print_pyramid(5);
    print_pyramid_inverse(5);
}
