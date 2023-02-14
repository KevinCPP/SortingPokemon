#ifndef pokemon_h
#define pokemon_h

#include <iostream>

class Pokemon{
private:
    double number;
    double stats;
public:
    //constructor
    Pokemon(double num, double stat) : number(num), stats(stat) {}

    //comparison operators:
    bool operator==(const Pokemon& other) const;
    bool operator<(const Pokemon& other) const;
    bool operator<=(const Pokemon& other) const;
    bool operator>(const Pokemon& other) const;
    bool operator>=(const Pokemon& other) const;

    //overload for << operator so this can be printed with cout
    friend std::ostream& operator<<(std::ostream& os, const Pokemon& pokemon);

    //getters
    double getNumber();
    double getStats();
    
    //setters
    void setNumber(double num);
    void setStats(double stat);
};



#endif
