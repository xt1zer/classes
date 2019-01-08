#pragma once
#include <cstring>

class String {

private:

    size_t m_len;
    char * m_str;

    void copy(const char *, const size_t &);
    String* divide(const char *, const size_t &) const;

public:

    String();

    String(const char *);

    String(const String &);

    ~String();


    const size_t length() const;
    void print() const;

    void append(const String &);
    void append(const char *);
    String substr(const unsigned int &, const unsigned int &) const;
    String* split(const char &) const;
    void replace(const char *, const char *);
};
