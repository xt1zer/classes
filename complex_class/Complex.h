#pragma once

class Complex{

    friend std::ostream& operator<<(std::ostream&, const Complex &);

private:

    double m_re;
    double m_im;

public:

    Complex();
    Complex(const double &, const double &);
    Complex(const Complex &);
    ~Complex();

    const bool operator==(const Complex &) const;
    const bool operator!=(const Complex &) const;
    const bool operator>(const Complex &) const;
    const bool operator<(const Complex &) const;
    const bool operator>=(const Complex &) const;
    const bool operator<=(const Complex &) const;

    Complex& operator=(const Complex &);
    Complex& operator=(const double &);
    Complex operator+(const Complex &) const;
    Complex operator-(const Complex &) const;
    Complex operator-(const double &) const;
    Complex operator+(const double &) const;
    Complex operator*(const Complex &) const;
    Complex operator*(const double &) const;
    Complex& operator+=(const Complex &);
    Complex& operator+=(const double &);
    Complex& operator-=(const Complex &);
    Complex& operator-=(const double &);
    Complex& operator*=(const Complex &);
    Complex& operator*=(const double &);

    void print() const;
    const double abs() const;
    Complex sqrt() const;
};
