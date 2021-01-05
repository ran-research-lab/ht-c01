
#include "HashTable.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;


unsigned int HashTable::h(const string &key) const {
    unsigned int total = 0 ;
    for (auto c: key) total += c;
    return total % table.size();
}

void HashTable::insert(const string &key, int value) {
    uint idx = h(key);
    table[idx].push_back(psu(key,value));
    count++;
    if (count > (table.size() * 2)) rehash(table.size() * 2);
}

void HashTable::remove(const string &key) {
    uint idx = h(key);
    for (auto it = table[idx].begin(); it != table[idx].end(); it++) {
        if (it->first == key) {
            table[idx].erase(it);
            count--;
            return;
        }
    }
}

void HashTable::rehash(uint newSize) {
    // Copy all pairs to a list
    list<psu> tmp;
    for (auto &bucket: table) {
        while (!bucket.empty()) {
            tmp.push_back(bucket.front());
            bucket.pop_front();
        }
    }

    // Resize the table and copy the items to the resized table
    table.resize(newSize);
    count = 0;
    while(!tmp.empty()) {
        insert(tmp.front().first, tmp.front().second);
        tmp.pop_front();
    }
}

int HashTable::find(const string &key) const {
    uint idx = h(key);
    for (auto it = table[idx].begin(); it != table[idx].end(); it++) {
        if (it->first == key) {
            return it->second;
        }
    }
    return -1;
}

string HashTable::toString() const {
    string st;

    st = "Count: " + to_string(count) + "\n";
    for (int i = 0; i < table.size(); i++) {
        st = st + "[" + to_string(i) + "]: ";
        for (auto it: table[i]) {
            st = st + "<" + it.first + "," +  to_string(it.second) + "> ";
        }
        st = st + "\n";
    }
    return st;
}
