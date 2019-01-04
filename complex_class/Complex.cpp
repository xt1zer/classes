#include "Complex.h"
#include <iostream>

Complex::Complex() : m_re(0), m_im(0) {}

Complex::Complex(const double &re, const double &im) : m_re(re), m_im(im) {}

Complex::Complex(const Complex &copy) : m_re(copy.m_re), m_im(copy.m_im) {}

Complex::~Complex() = default;


const bool Complex::operator==(const Complex &c) const {
    return m_re == c.m_re && m_im == c.m_im;
}

const bool Complex::operator!=(const Complex &c) const {
    return !(*this == c);
}

const bool Complex::operator>(const Complex &c) const {
    return m_re > c.m_re || m_re == c.m_re && m_im > c.m_im;
}

const bool Complex::operator<(const Complex &c) const {
    return m_re < c.m_re || m_re == c.m_re && m_im < c.m_im;
}

const bool Complex::operator>=(const Complex &c) const {
    return !(*this < c);
}

const bool Complex::operator<=(const Complex &c) const {
    return !(*this > c);
}

Complex &Complex::operator=(const Complex &c) {
    m_re = c.m_re;
    m_im = c.m_im;

    return *this;
}

Complex &Complex::operator=(const double &num) {
    m_re = num;
    m_im = 0;
    return *this;
}

Complex Complex::operator+(const Complex &c) const {
    return Complex(m_re + c.m_re, m_im + c.m_im);
}

Complex Complex::operator+(const double &num) const {
    return Complex(m_re + num, m_im);
}

Complex Complex::operator-(const Complex &c) const {
    return Complex(m_re - c.m_re, m_im - c.m_im);
}

Complex Complex::operator-(const double &num) const {
    return Complex(m_re - num, m_im);
}

Complex &Complex::operator+=(const Complex &c) {
    m_re += c.m_re;
    m_im += c.m_im;
    return *this;
}

Complex &Complex::operator+=(const double &num) {
    m_re += num;
    return *this;
}

Complex &Complex::operator-=(const Complex &c) {
    m_re -= c.m_re;
    m_im -= c.m_im;
    return *this;
}

Complex &Complex::operator-=(const double &num) {
    m_re -= num;
    return *this;
}

Complex Complex::operator*(const Complex &c) const {
    return Complex(m_re * c.m_re - m_im * c.m_im, m_re * c.m_im + m_im * c.m_re);
} //-3

Complex Complex::operator*(const double &num) const {
    return Complex(m_re * num, m_im * num);
}

Complex &Complex::operator*=(const Complex &c) {
    double im = m_re * c.m_im + m_im * c.m_re;
    m_re = m_re * c.m_re - m_im * c.m_im;
    m_im = im;
    return *this;
}

Complex &Complex::operator*=(const double &num) {
    m_re *= num;
    m_im *= num;
    return *this;
}


void Complex::print() const {
    std::cout << m_re << std::showpos << m_im << 'i';
}

const double Complex::abs() const {
    return std::sqrt(m_re * m_re + m_im * m_im);
}

Complex Complex::sqrt() const {
    double re = std::sqrt((m_re + abs()) / 2);
    return Complex(re, m_im / (2 * re));
}


std::ostream &operator<<(std::ostream &cout, const Complex &c) {
    cout << c.m_re << std::showpos << c.m_im << 'i' << std::noshowpos;
    return cout;
}
