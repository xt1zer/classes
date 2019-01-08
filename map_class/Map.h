#pragma once

#include "../List.h"
#include <iostream>
using std::string;
using std::ostream;

class Pair {

public:

    size_t m_key;
    string m_val;

    Pair() = default;

    Pair(const size_t& key): m_key(key), m_val("") {}

    Pair(const size_t& key, const string& val) : m_key(key), m_val(val) {}

    Pair(const Pair& copy) : m_key(copy.m_key), m_val(copy.m_val) {}


    friend ostream& operator<<(ostream& out, const Pair& p){
        out << p.m_val;
        return out;
    }

    const bool operator==(const Pair& p) {
        return m_key == p.m_key;
    }
};

class Map {

private:

    size_t m_capacity;
    List<Pair>* m_table;

    const size_t hash(const size_t& key) const;

public:

//    Map() = default;

    Map(const size_t &);

    ~Map();


    void insert(const size_t &, const string &);
    
    const string get(const size_t &) const;

    Pair* find(const size_t &) const;

    void print() const;

    const bool is_empty() const;

};
