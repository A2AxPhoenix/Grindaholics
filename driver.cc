#include "Rank.h"
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <unordered_set>
using namespace std;

int main() {
    set<Rank> ranks;
    ifstream file("levels.csv");
    if (!file) throw -1;
    string trash;
    getline(file, trash);
    string line;
    Rank r;
    while (file) {
        getline(file, line);
        if (!file) break;
        istringstream iss(line);
        while (iss) {
            string stuff;
            getline(iss, stuff, ',');
            if (!iss) break;
            r.set_level(stoi(stuff));
            getline(iss, stuff, ',');
            r.set_expToNext(stoi(stuff));
            getline(iss, stuff, ',');
            r.set_totalExp(stoi(stuff));
            getline(iss, stuff, ',');
            r.set_difference(stoi(stuff));

            ranks.insert(r);
        }
    }
    for (auto x : ranks) cout << "Level: " << x.get_level() << " -- TOTAL XP: " << x.get_totalExp() << endl;
}
