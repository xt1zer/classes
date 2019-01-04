#include "Vector.h"

Vector::Vector() : m_dim(0) {}

Vector::Vector(const List<Complex> l) : m_coords(l), m_dim(l.size()) {}

Vector::Vector(const Vector &copy) : m_dim(copy.m_dim), m_coords(copy.m_coords) {}

Vector::~Vector() = default;


Vector Vector::operator+(const Vector &v) const {
    List<Complex> l1(this->m_coords);
    List<Complex> l2 = v.m_coords;
    List<Complex> newCoords;

    while (!l1.is_empty() && !v.m_coords.is_empty())
        newCoords.push_back(l1.pop_front() + l2.pop_front());

    while (!l1.is_empty())
        newCoords.push_back(l1.pop_front());

    while (!l2.is_empty())
        newCoords.push_back(l2.pop_front());

    return Vector(newCoords);
}

Complex Vector::abs() const {
    Complex result(0, 0);
    List<Complex> coords(m_coords);
    Complex num;

    while (!coords.is_empty()) {
        num = coords.pop_front();
        num *= num;
        result += num;
    }

    return result.sqrt();
}

void Vector::print() {
    m_coords.print();
}

Complex scal_prod(const Vector &v1, const Vector &v2) {
    Complex result(0, 0);
    List<Complex> l1 = v1.m_coords, l2 = v2.m_coords;

    for (int i = 0; i < std::min(v1.m_dim, v2.m_dim); ++i) {
        result += l1.pop_front() * l2.pop_front();
    }

    return result;
}
