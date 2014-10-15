#ifndef Rational_H
#define Rational_H

#include <iostream>
#include <cassert>

//template<typename T>
//class Rational;

//template<typename T>
//std::ostream& operator<< (std::ostream &cout, const Rational<T> r);
//
//template<typename T>
//std::istream& operator>> (std::istream &cin, Rational<T> &r);

template <typename T>
class Rational {
public:
	Rational<T>(T numerator = 0, T denominator = 1);

	template<typename T2>
	Rational<T>(Rational<T2> r);

	~Rational<T>();

	//Typecast to different data types of rational.
	template<typename T2>
	explicit operator Rational<T2>();

	template<typename T2>
	explicit operator T2();

	bool operator== (const Rational<T> &r);

	template<typename T2>
	bool operator==(T2 n) { return ((T2)*this) == n; };

	Rational<T> operator= (const Rational<T> &r);
	Rational<T> operator- (const Rational<T> &r);
	Rational<T> operator+ (const Rational<T> &r);
	Rational<T> operator+= (const Rational<T> &r);
	Rational<T> operator-= (const Rational<T> &r);
	Rational<T> operator- ();
	Rational<T>& operator++ (); //Prefix
	Rational<T> operator++ (int); //PostFix

	friend std::ostream& operator<< (std::ostream& cout, const Rational<T> r)
	{
		return cout << r.numerator << '/' << r.denominator;
	}

	friend std::istream& operator>> (std::istream& cin, Rational<T> &r)
	{
		cin >> r.numerator;
		cin.get();
		cin >> r.denominator;
		cin.get();
		Reduce(r.numerator, r.denominator);
		return cin;
	}

public:
	T numerator;
	T denominator;

};
#endif //!Rational_H

template<typename T>
Rational<T>::Rational(T num, T den) {
	numerator = num;
	denominator = den;

	assert(den != 0 && "Division by zero");
}

template <typename T>
template<typename T2>
Rational<T>::Rational(const Rational<T2> r) {
	this->numerator = r.numerator;
	this->denominator = r.denominator;
}

template<typename T>
Rational<T>::~Rational() {

}

//Typecast to different data types of rational.
template<typename T>
template<typename T2>
Rational<T>::operator Rational<T2>() {
	return Rational<T2>((T2)numerator, (T2)denominator);
}

template<typename T>
T GCD(T A, T B) {
	if (A<B)
		return GCD(B, A);
	while (B != 0) {
		T temp = A%B;
		A = B;
		B = temp;
	}
	if (A>0)
		return A;
	else
		return 1;
}

template<typename T>
void Reduce(T &A, T &B) {
	T gcd = GCD(A, B);
	A /= gcd;
	B /= gcd;
}

template<typename T>
template<typename T2>
Rational<T>::operator T2() {
	return static_cast<T2>((double)numerator / (double)denominator);
}

template<typename T>
bool Rational<T>::operator== (const Rational<T> &r) {
	return (r.denominator == denominator && r.numerator == numerator);
}

template<typename T>
Rational<T> Rational<T>::operator+ (const Rational<T> &r) {
	T num = ((this->numerator * r.denominator) + (this->denominator * r.numerator));
	T den = (this->denominator * r.denominator);
	Reduce(num, den);
	return Rational<T>(num, den);
}

template<typename T>
Rational<T> Rational<T>::operator- (const Rational<T> &r) {
	T num = ((this->numerator * r.denominator) - (this->denominator * r.numerator));
	T den = (this->denominator * r.denominator);
	Reduce(num, den);
	return Rational<T>(num, den);
}

//Operatorn finns i alla klasser!
template<typename T>
Rational<T> Rational<T>::operator= (const Rational<T> &r) {
	this->numerator = r.numerator;
	this->denominator = r.denominator;
	Reduce(numerator, denominator);
	return Rational<T>(numerator, denominator);
}

template<typename T>
Rational<T> Rational<T>::operator+= (const Rational<T> &r) {
	*this = *this + r;
	return *this;
}

template<typename T>
Rational<T> Rational<T>::operator-= (const Rational<T> &r) {
	*this = *this - r;
	return *this;
}

//Unary numbers.
template<typename T>
Rational<T> Rational<T>::operator- () {
	numerator = -numerator;
	return Rational<T>(numerator, denominator);
}

//Prefix, ++i.
template<typename T>
Rational<T>& Rational<T>::operator++() {
	//Increment object.
	numerator += denominator;
	Reduce(numerator, denominator);
	return *this;
}

//Postfix, i++.
template<typename T>
Rational<T> Rational<T>::operator++(int) {
	Rational<T> temp(numerator, denominator); //Create a copy
	numerator += denominator;
	Reduce(temp.numerator, temp.denominator);
	return temp; //return the copy (the old value).
}

//Global Scope
//template<typename T>
//std::ostream& operator<< (std::ostream &cout, const Rational<T> r) {
//	return cout << r.numerator << '/' << r.denominator;
//}

//Global Scope
//template<typename T>
//std::istream& operator>> (std::istream &cin, Rational<T> &r) {
//	
//	char temp;
//	return cin >> r.numerator >> temp >> r.denominator;
//}