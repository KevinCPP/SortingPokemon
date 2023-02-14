#ifndef pokemon_h
#define pokemon_h

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

    //getters
    double getNumber();
    double getStats();
    
    //setters
    void setNumber(double num);
    void setStats(double stat);
};



#endif
