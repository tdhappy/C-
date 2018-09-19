/*
 * Element.cpp
 *
 *  Created on: Apr 26, 2018
 *      Author: admin
 */

#include <iostream>
#include "Element.h"

using namespace std;

/***** Complete this class. *****/
long Element::copy_count;
long Element::destructor_count;

/**
 * Default constructor.
 */
Element::Element() :
		value(0) {
}

/**
 * Constructor.
 * @param val the element's value.
 */
Element::Element(long val) :
		value(val) {
}

/**
 * Copy constructor.
 * @param other the other element to be copied.
 */
Element::Element(const Element& other) {
	/***** Complete this class. *****/
	value = other.get_value();
	Element::copy_count++;
}

/**
 * Destructor.
 */
Element::~Element() {
	/***** Complete this class. *****/
	Element::destructor_count++;
}

/**
 * Getter.
 * @return the value.
 */
long Element::get_value() const {
	return value;
}

void Element::reset() {
	Element::copy_count = 0;
	Element::destructor_count = 0;
}
long Element::get_copy_count() {
	return Element::copy_count;
}

long Element::get_destructor_count() {
	return Element::destructor_count;
}

bool operator<(const Element& other) const {
	return (value < other.get_value());
}
bool operator>(const Element& other) const {
	return (value > other.get_value());
}

bool operator<=(const Element& other) const {
	return (value <= other.get_value());
}

bool operator>=(const Element& other) const {
	return (value >= other.get_value());
}

ostream& operator<<(ostream& out_stream, const Element& other) {
	out_stream << other.get_value();
	return out_stream;
}
