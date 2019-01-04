#include "Map.h"

const size_t Map::hash(const size_t& key) const {
    return key % m_capacity;
}

Map::Map(const size_t &capacity) : m_capacity(capacity) { m_table = new List<Pair>[capacity](); }

Map::~Map() { delete[] m_table; }

void Map::insert(const size_t &key, const string &val) {
    m_table[hash(key)].push_back(Pair(key, val));
}

Pair* Map::find(const size_t &key) const {
    if(is_empty())
        return nullptr;

    return &m_table[hash(key)].find_node(Pair(key))->m_data;
}

void Map::print() const {
    if(!is_empty())
        return;

    for (size_t i(0); i < m_capacity; ++i) {
        if (!m_table[i].is_empty())
            m_table[i].print();
    }
}

const bool Map::is_empty() const {
    size_t i(0);
    bool empty(true);

    while(empty && i < m_capacity)
        if(!m_table[i++].is_empty())
            empty = false;

    return empty;
}
