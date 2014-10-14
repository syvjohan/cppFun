#ifndef Rational_H
#define Rational_H

#include <iostream>
#include <cassert>

template<typename T>
class Rational;

template<typename T>
std::ostream& operator<< (std::ostream &cout, const Rational<T> &r);

template<typename T>
std::istream& operator>> (std::istream &cin, const Rational<T> &r);

template <typename T>
class Rational {
public:
	Rational<T>(T numerator = 0, T denominator = 1);
	~Rational<T>();

	//Makes it possible for different data types to interact.
	template<typename T2>
	operator Rational<T2>();

	bool operator== (const Rational<T> &r);
	Rational<T> operator= (const Rational<T> &r);
	Rational<T> operator- (const Rational<T> &r);
	Rational<T> operator+ (const Rational<T> &r);
	Rational<T> operator+= (const Rational<T> &r);
	Rational<T> operator-= (const Rational<T> &r);
	Rational<T>& operator++ (); //Prefix
	Rational<T> operator++ (int); //PostFix

	friend std::ostream& operator<< (std::ostream&, const Rational<T> &);
	friend std::istream& operator>> (std::istream&, const Rational<T> &);

private:
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

template<typename T>
Rational<T>::~Rational() {

}

//Makes it possible for different data types to interact.
template<typename T, typename T2>
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
bool Rational<T>::operator== (const Rational<T> &r) {
	return (r.denominator == this->denominator && r.numerator == this->numerator);
}

template<typename T>
Rational<T> Rational<T>::operator+ (const Rational<T> &r) {
	T num = ((this->numerator * r.denominator) + (this->denominator * r.numerator));
	T den = (this->denominator * r.denominator);
	Reduce(numb1, numb2);
	return Rational<T>(numb1, numb2);
}

template<typename T>
Rational<T> Rational<T>::operator- (const Rational<T> &r) {
	T num = ((this->numerator * r.denominator) - (this->denominator * r.numerator));
	T den = (this->denominator * r.denominator);
	Reduce(num, den);
	return Rational<T>(num, den);
}

template<typename T>
Rational<T> Rational<T>::operator= (const Rational<T> &r) {
	this->numerator = r.numerator;
	this->denominator = r.denominator;
	Reduce(numerator, denominator);
	return Rational<T>(numerator, denominator);
}

template<typename T>
Rational<T> Rational<T>::operator+= (const Rational<T> &r) {
	operator+(Rational<T>(r.numerator, r.denominator));
	return Rational<T>(operator=(Rational<T>(r.numerator, r.denominator)));
}

template<typename T>
Rational<T> Rational<T>::operator-= (const Rational<T> &r) {
	operator-(r.numerator, r.denominator);
	return Rational<T>(operator=(r.numerator, r.denominator))
}

//Prefix, ++i.
template<typename T>
Rational<T>& Rational<T>::operator++() {
	//Increment object.
	numerator += denominator;
	Reduce(numerator, denominator);
	return Rational<T>(numerator, denominator);
}

//Postfix, i++.
template<typename T>
Rational<T> Rational<T>::operator++(int) {
	Rational<T>(numerator, denominator) temp(numerator, denominator); //Create a copy
	numerator += denominator;
	Reduce(numerator, denominator);
	return temp; //return the copy (the old value).
}

//Global Scope
template<typename T>
std::ostream& operator<< (std::ostream &cout, const Rational<T> &r) {
	return cout << r.numerator << '/' << r.denominator;
}

//Global Scope
template<typename T>
std::istream& operator>> (std::istream &cin, const Rational<T> &r) {
	return cin >> r.numerator >> r.denominator;
}