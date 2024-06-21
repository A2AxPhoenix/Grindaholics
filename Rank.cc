#include "Rank.h"
#include <limits>
#include <stdexcept>
#include <iostream>
#include <limits.h>
#include <string>

Rank::Rank() {
    level = 0;
    expToNext = 0;
    totalEXP = 0;
    difference = 0;
}
Rank::Rank(unsigned short newLevel, unsigned int newExpToNext, unsigned int newTotal, unsigned int newDiff) : level(newLevel), expToNext(newExpToNext), totalEXP(newTotal), difference(newDiff) {
    if (newLevel >= std::numeric_limits<unsigned short>::max() - 1) throw std::overflow_error("Overflow detected. Values must be between 0 and " + std::to_string(std::numeric_limits<unsigned short>::max() - 1) + ".\n");
    if (newExpToNext >= std::numeric_limits<unsigned int>::max() - 1) throw std::overflow_error("Overflow Error. Values must be between 0 and " + std::to_string(std::numeric_limits<unsigned int>::max() - 1) + ".\n");
    if (newTotal >= std::numeric_limits<unsigned int>::max() - 1) throw std::overflow_error("Overflow Error. Values must be between 0 and " + std::to_string(std::numeric_limits<unsigned int>::max() - 1) + ".\n");
    if (newDiff >= std::numeric_limits<unsigned int>::max() - 1) throw std::overflow_error("Overflow Error. Values must be between 0 and " + std::to_string(std::numeric_limits<unsigned int>::max() - 1) + ".\n");
}

unsigned short Rank::get_level() const { return level; } 
unsigned int Rank::get_expToNext() const { return expToNext; }
unsigned int Rank::get_totalExp() const { return totalEXP; }
unsigned int Rank::get_difference() const { return difference; }

void Rank::set_level(unsigned short newLevel) { 
    if (newLevel >= std::numeric_limits<unsigned short>::max() - 1) throw std::overflow_error("Overflow detected. Values must be between 0 and " + std::to_string(std::numeric_limits<unsigned short>::max() - 1) + ".\n");
    level = newLevel;
}
void Rank::set_expToNext(unsigned int newExpToNext) { 
    if (newExpToNext >= std::numeric_limits<unsigned int>::max() - 1) throw std::overflow_error("Overflow Error. Values must be between 0 and " + std::to_string(std::numeric_limits<unsigned int>::max() - 1) + ".\n");
    expToNext = newExpToNext; 
}
void Rank::set_totalExp(unsigned int newTotal) { 
    if (newTotal >= std::numeric_limits<unsigned int>::max() - 1) throw std::overflow_error("Overflow Error. Values must be between 0 and " + std::to_string(std::numeric_limits<unsigned int>::max() - 1) + ".\n");
    totalEXP = newTotal; 
}
void Rank::set_difference(unsigned int newDiff) { 
    if (newDiff >= std::numeric_limits<unsigned int>::max() - 1) throw std::overflow_error("Overflow Error. Values must be between 0 and " + std::to_string(std::numeric_limits<unsigned int>::max() - 1) + ".\n");
    difference = newDiff; 
}

bool Rank::operator<(const Rank &r) const { return level < r.level; }
bool Rank::operator==(const Rank &r) const { return level == r.level; }

std::ostream& operator<<(std::ostream& outs, const Rank &r) { 
    return outs << r.level << ", " << r.expToNext << ", " << r.totalEXP << ", " << r.difference << std::endl;
}
std::istream& operator>>(std::istream& ins, Rank &r) {
    return ins >> r.level >> r.expToNext >> r.totalEXP >> r.difference;
}
