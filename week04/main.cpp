#include <iostream> // std::cout
#include <cstddef> // std::size_t
#include <string> // std::string

// =====
//! Výpis
// =====

void vypis() {
    std::cout << "Hello world!" << std::endl;
    std::cout << "druhy radek" << std::endl << "treti" << "radek" << std::endl;
}

/*
 * Připomenutí:
 *
 * 4 základní datové typy:
 *     - int - celé číslo se znaménkem
 *     - float - číslo s desetionou částí
 *     - bool - pravda/nepravda
 *     - char - znak
 */

// ========
//! Proměnné
// ========

 /* Způsob jak si v programu něco pamatovat
  * Každá proměnná má typ a jméno
  * Definice proměnné má tvar:
  * <typ> <jméno> = <počíteční hodnota>
  */

void promenne() {
    int cele_cislo = -1;

    unsigned int cele_nezaporne_cislo = 1;

    std::size_t index_v_poli = 0; // někdy jindy

    float desetinne_cislo = 3.14;

    double presnejsi_desetinne_cislo = 1.0 / desetinne_cislo;

    char znak = 'a';

    bool pravda_nebo_nepravda = true;

    std::string retezec = "Ahoj";
}


// ======
//! Funkce
// ======

/* Podprogram
 * <návratový typ> <jméno>(<argumenty...>) {
 *     <tělo>
 * }
 */

 int sum(int a, int b) {
     return a+b;
 }

// =====
//! Scope       oblast působení -> precedenc závorek (jejich použití a způsob volání)
// =====

int a = 0;

void scope() {
    int a = 5; 

    a = 3;

    std::cout << a << std::endl; // 3
    
    {
        int a = 4;
        std::cout << a << std::endl; // 4
        a = 6;
        std::cout << a << std::endl; // 6
    }

    std::cout << a << std::endl; // 3
}

// =====
//! Cykly
// =====

void cykly() {
    for (int i = 0; i < 10; i++) {
        std::cout << i << std::endl;
    }

    int i = 0;
    while (i < 10) {
        std::cout << i << std::endl;
        i++;
    }

    i = 0;
    do {                                //! prvně provede následně kontroluje hodnotu
        std::cout << i << std::endl;
        i++;
    } while (i < 10);
}

int main() {
    std::cout << a << std::endl;
    scope();
    std::cout << a << std::endl;
    return 0;
}

