#ifndef RANK_H
#define RANK_H

#include <iostream>

class Rank {
    private: 
        unsigned short level;
        unsigned int expToNext;
        unsigned int totalEXP;
        unsigned int difference;
    public:
        Rank();
        Rank(unsigned short newLevel, unsigned int newExpToNext, unsigned int newTotal, unsigned int newDiff);

        unsigned short get_level() const;
        unsigned int get_expToNext() const;
        unsigned int get_totalExp() const;
        unsigned int get_difference() const;

        void set_level(unsigned short newLevel);
        void set_expToNext(unsigned int newExpToNext);
        void set_totalExp(unsigned int newTotal);
        void set_difference(unsigned int newDiff);

        bool operator<(const Rank &r) const;
        bool operator==(const Rank &r) const;

        friend std::ostream& operator<<(std::ostream& outs, const Rank &r);
        friend std::istream& operator>>(std::istream& ins, Rank &r);

};
namespace std {
    template<>
        struct hash<Rank> {
            auto operator()(const Rank &otherRank) const -> size_t { return hash<unsigned int>()(otherRank.get_level()); }
        };
}

#endif
