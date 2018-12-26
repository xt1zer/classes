#pragma once

#include "../complex_class/complex.h"
#include "../linked_list.h"

class Vector {

    friend Complex scal_prod(const Vector &, const Vector &);

private:

    int m_dim;
    List<Complex> m_coords;

public:

    Vector();

    Vector(const List<Complex>);

    Vector(const Vector &);

    ~Vector();


    Vector operator+(const Vector & v) const;

    Complex abs() const;

    void print();


};
