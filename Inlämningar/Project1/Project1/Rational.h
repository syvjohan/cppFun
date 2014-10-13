#ifndef Rational_H
#define Rational_H

#include <iostream>

template <typename T> 
class Rational {
public:
	Rational<T> (T numerator, T denominator);
	bool operator== (const Rational<T> &r);
	Rational<T> operator= (const Rational<T> &r);
	Rational<T> operator- (const Rational<T> &r);
	Rational<T> operator+ (const Rational<T> &r);
	Rational<T> operator+= (const Rational<T> &r);
	Rational<T> operator* (const Rational<T> &r);
	Rational<T> operator*= (const Rational<T> &r);
	Rational<T> operator-= (const Rational<T> &r);
	Rational<T>& operator++ (); //Prefix
	Rational<T> operator++ (int); //PostFix
	std::ostream& operator<< (std::ostream &cout);
	std::ostream& operator>> (std::ostream &cin);
	~Rational();

private:
	T numerator;
	T denominator;

	bool ValidateInput(Rational<T> r);
};
#endif //!Rational_H

template <typename T>
Rational<T>::Rational(T num, T den) {
	numerator = num;
	denominator = den;
}

template <typename T>
Rational<T>::~Rational() {

}

template <typename T>
bool Rational<T>::ValidateInput(const Rational<T> r) {
	if (r.numerator <= 0) {
		printf("Numerator1 can't be zero or a negative number!");
		return false;
	} else if (r.denominator < 0) {
		printf("Denominator1 can't be less than zero!");
		return false;
	} else {
		return true;
	}
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
	if (A>0)	//behövs testen?????
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

template <typename T>
bool Rational<T>::operator== (const Rational<T> &r) {
	return (r.denominator == this->denominator && r.numerator == this->numerator);
}

template <typename T>
Rational<T> Rational<T>::operator+ (const Rational<T> &r) {
	if (ValidateInput(r.numerator, r.denominator)) {
		T num = ((this->numerator * r.denominator) + (this->denominator * r.numerator));
		T den = (this->denominator * r.denominator);
		Reduce(numb1, numb2);
		return Rational<T>(numb1, numb2);
	}
}

template <typename T>
Rational<T> Rational<T>::operator- (const Rational<T> &r) {
	if (ValidateInput(r.numerator, r.denominator)) {
		T num = ((this->numerator * r.denominator) - (this->denominator * r.numerator));
		T den = (this->denominator * r.denominator);
		Reduce(num, den);
		return Rational<T>(num, den);
	}
}

template <typename T>
Rational<T> Rational<T>::operator* (const Rational<T> &r) {
	if (ValidateInput(r.numerator, r.denominator)) {
		T num = ((this->numerator * r.denominator) * (this->denominator * r.numerator));
		T den = (this->denominator * r.denominator);
		Reduce(num, den);
		return Rational<T>(num, den);
	}
}

template <typename T>
Rational<T> Rational<T>::operator= (const Rational<T> &r) {
	this->numerator = r.numerator;
	this->denominator = r.denominator;
	Reduce(numerator, denominator);
	return Rational<T>(numerator, denominator);
}

template <typename T>
Rational<T> Rational<T>::operator+= (const Rational<T> &r) {
	operator+(Rational<T>(r.numerator, r.denominator));
	return Rational<T>(operator=(Rational<T>(r.numerator, r.denominator)));
}

template <typename T>
Rational<T> Rational<T>::operator-= (const Rational<T> &r) {
	operator-(r.numerator, r.denominator);
	return Rational<T>(operator=(r.numerator, r.denominator))
}

template <typename T>
Rational<T> Rational<T>::operator*= (const Rational<T> &r) {
	operator*(r.numerator, r.denominator);
	return Rational<T>(operator=(r.numerator, r.denominator))
}

//Prefix, ++i.
template <typename T>
Rational<T>& Rational<T>::operator++() {
	//Increment object.
	numerator += denominator;
	Reduce(numerator, denominator);
	return Rational<T>(numerator, denominator);
}

//Postfix, i++.
template <typename T>
Rational<T> Rational<T>::operator++(int) {
	Rational<T>(numerator, denominator) temp(numerator, denominator); //Create a copy
	numerator += denominator;
	Reduce(numerator, denominator);
	return temp; //return the copy (the old value).
}

//Global Scope
template <typename T>
std::ostream& Rational<T>::operator<< (std::ostream &cout) {
	return cout << this->numerator << '/' << this->denominator;
}

template <typename T>
std::ostream& Rational<T>::operator>> (std::ostream &cin) {
	return cin >> this->numerator >> this->denominator;
}