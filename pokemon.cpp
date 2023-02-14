#include "pokemon.h"


//comparison operators:
bool Pokemon::operator==(const Pokemon& other) const {
    return stats == other.stats && number == other.number;
}

bool Pokemon::operator<(const Pokemon& other) const {
    if(stats != other.stats)
        return stats < other.stats;

    if(number != other.number)
        return number < other.number;

    return false;
}

bool Pokemon::operator<=(const Pokemon& other) const {
    return *this < other || *this == other;
}

bool Pokemon::operator>(const Pokemon& other) const {
    return !(*this <= other);
}

bool Pokemon::operator>=(const Pokemon& other) const {
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const Pokemon& pokemon){
    os << "Pokemon #: " << pokemon.number << ", Stats: " << pokemon.stats;
    return os;
}

//getters
double Pokemon::getNumber() { return number; }
double Pokemon::getStats() { return stats; }

//setters
void Pokemon::setNumber(double num) { number = num; }
void Pokemon::setStats(double stat) { stats = stat; }
