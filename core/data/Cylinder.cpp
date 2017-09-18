#include "Cylinder.hpp"

using namespace life;

Cylinder::Cylinder()
    : Cylinder(defaultLength, defaultCircumference, defaultStartAt, defaultCrossAt) { }

Cylinder::Cylinder(float _length, float _diameter, float _startAt, float _crossAt)
    : length(_length), circumference(_diameter * M_PI), startAt(_startAt), crossAt(_crossAt) { }

float Cylinder::getLength() const { return length; }

void Cylinder::setLength(float value) { length = value; }

float Cylinder::getCircumference() const { return circumference; }

void Cylinder::setCircumference(float value) { circumference = value; }

float Cylinder::getStartAt() const { return startAt; }

void Cylinder::setStartAt(float value) { startAt = value; }

float Cylinder::getCrossAt() const { return crossAt; }

void Cylinder::setCrossAt(float value) { crossAt = value; }

float Cylinder::getDiameter() const { return this->circumference / M_PI; }

void Cylinder::setDiameter(float value) { this->circumference = value *M_PI; }
