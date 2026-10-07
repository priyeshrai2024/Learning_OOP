#include <iostream>
#include <string>
/*
the biggest dificulty with struct is that it does not provide class invariance
invariance -> a condition that muxt be true while some component is excecuting 
in context of class types a class invariance is the condition which should be always true else it doesnot get to be valid
*/
struct Pair {
    int first {};
    int second {};
};
//this did not had any but lesse another one
struct fraction {
    int numerator {};
    int denomenator {1}; // here it can never be 0
};

void PrintFraction(fraction & f) {
    std :: cout << f.numerator / f.denomenator << '\n';
}
struct Date {
    int day{};
    int month{};
    int year{};
};

void PrintDate(const Date & date) {
    std::cout << date.day << "/" << date.month << "/" << date.year << '\n';
}
// lets see here some more complex class invariant
struct Employee {
    std::string name {};
    char firstInitials {}; // should always hold first character of `name` (or `0`)
};
// relying on the user of an object to maintain class invariants is likely to result in problematic code.
// like here we need to do some things on our own to have this variance good
/*
ok now lets introduce classes here
a class is a program-defined compound type that can have many member variables with different types
Similar to struct
*/
class c {
    int m_a {};
    double m_b {};
};
int main() {
    Date date{4, 5, 2011}; // initialized using aggregate initialization
    PrintDate(date);
    fraction f { 5, 0 };   // create a Fraction with a zero denominator
    PrintFraction(f); // cause divide by zero error
    
    return 0;
}