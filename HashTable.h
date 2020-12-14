/*
Created 12-2020
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>

using namespace std;
typedef unsigned int uing;
typedef pair<string,uint> psu;

class HashTable {
private:
    vector< list < psu> > table;
    int count;

    unsigned int h(const string &key) const;
    void rehash(uint newSize);
public:
    HashTable() {
        table.resize(7);
        count = 0;
    }

    void insert(const string &key, int value);
    void remove(const string &key);
    int find(const string &key) const;

    string toString() const;

};




#endif

