#ifndef SUPEROPENGL_VECTOR_HPP
#define SUPEROPENGL_VECTOR_HPP

#include <iostream>

namespace SuperOpenGL {

class Vertex;

class Vector
{
public:
float x;
float y;
float z;

Vector();   // (0,0,0) par defaut
Vector(const float&, const float&, const float&);
Vector(const Vertex&);
Vector(const Vertex&, const Vertex&);
Vector(const Vector&);
~Vector();

bool operator==(const Vector& op) const;
Vector& operator=(const Vector& op);
Vector& operator=(const Vertex& op);
Vector operator+() const;
Vector operator+(const Vector&) const;
Vector operator+(const Vertex&) const;

Vector& operator+=(const Vector& op);
Vector operator-() const;
Vector operator-(const Vector& op) const;
Vector& operator-=(const Vector& op);
Vector& operator*=(const float op);        // produit par un scalaire
Vector operator*(const float op) const;    // idem
Vector& operator/=(const float op);        // division par un scalaire
Vector operator/(const float op) const;    // idem
float operator*(const Vector& op) const;   // produit scalaire
Vector& operator^=(const Vector& op);            // produit vectoriel
Vector operator^(const Vector& op) const;

Vector normalize(
        const float lg); // normalise un vecteur a la longueur lg
float length() const;   // longueur du vecteur

friend std::ostream& operator<<(std::ostream&, const Vector&);
friend std::istream& operator>>(std::istream&, Vector&);
};

}

#endif
