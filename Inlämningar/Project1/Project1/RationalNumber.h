#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <iostream>

template <typename T> 
class RationalNumber {
public:
	RationalNumber<T> (T numerator1, T numerator2, T denominator1, T denominator2);
	RationalNumber<T> operator== (const RationalNumber<T> &r);
	RationalNumber<T> operator= (const RationalNumber<T> &r);
	RationalNumber<T> operator+= (const RationalNumber<T> &r);
	RationalNumber<T> operator+ (const RationalNumber<T> &r);
	RationalNumber<T> operator-= (const RationalNumber<T> &r);
	//RationalNumber<T> operator++ (const RationalNumber<T> &r);
	RationalNumber<T> operator << (const RationalNumber<T> &r);
	RationalNumber<T> operator>> (const RationalNumber<T> &r);
	//T ExplicitConversion(auto, auto, auto, auto);//Explicit konvertering till tal, ändrar entitet på datam till en annan.
	~RationalNumber();

private:
	T numerator1;
	T numerator2;
	T denominator1;
	T denominator2;

	T CalculateA(const RationalNumber<T> &r);
	T CalculateB(const RationalNumber<T> &r);
	bool ValidateFraction(RationalNumber<T> r);
};
#endif //!RATIONALNUMBER_H

template <typename T>
RationalNumber<T>::RationalNumber(T num1, T num2, T den1, T den2) {
	num1 = numerator1 = -1;
	num2 = numerator2 = -1;
	den1 = denominator1 = -1;
	den2 = denominator2 = -1;
}

template <typename T>
RationalNumber<T>::~RationalNumber() {

}

template <typename T>
bool RationalNumber<T>::ValidateFraction(const RationalNumber<T> r) {
	if (r.numerator1 <= 0) {
		printf("Numerator1 can't be zero or a negative number!");
		return false;
	} else if (r.denominator1 < 0) {
		printf("Denominator1 can't be less than zero!");
		return false;
	} else if (r.numerator2 <= 0) {
		printf("Numerator2 can't be zero or a negative number!");
		return false;
	} else if (r.denominator2 < 0) {
		printf("Denominator2 can't be less than zero!");
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

template <typename T>
T RationalNumber<T>::CalculateA(const RationalNumber<T> &r) {
	//( (ad + cb / GCD( (ad + cb, db) ) / ( db / GCD( ad + cb, db ) ) = p / q.
	//a = numerator1. b = denominator1. c = numerator2. d = denominator2
	T sum = (((rnumerator1*denominator2) + (r.numerator2*r.denominator2)) / GCD((r.numerator1*r.denominator2) + (r.numerator2*r.denominator1), (r.denominator2* r.denominator1)));
	return sum;
}

template <typename T>
T RationalNumber<T>::CalculateB(const RationalNumber<T> &r) {
	T sum = ((r.denominator2 * r.denominator1) / GCD((r.numerator1*r.denominator2) + (r.numerator2*r.denominator1), (r.denominator2*r.denominator1)));
	return sum;
}

template <typename T>
RationalNumber<T> RationalNumber<T>::operator== (const RationalNumber<T> &r) {
	return (CalculateA(RationalNumber<T>) == CalculateB(RationalNumber<T>));
}

template <typename T>
RationalNumber<T> RationalNumber<T>::operator+ (const RationalNumber<T> &r) {
	return (CalculateA(RationalNumber<T>) + CalculateB(RationalNumber<T>));
}

template <typename T>
RationalNumber<T> RationalNumber<T>::operator+ (const RationalNumber<T> &r) {
	return (CalculateA(RationalNumber<T>) - CalculateB(RationalNumber<T>));
}

template <typename T>
RationalNumber<T> RationalNumber<T>::operator= (const RationalNumber<T> &r) {
	return (CalculateA(RationalNumber<T>) = CalculateB(RationalNumber<T>));
}

template <typename T>
RationalNumber<T> RationalNumber<T>::operator+= (const RationalNumber<T> &r) {
	return (CalculateA(RationalNumber<T>) = (CalculateA(RationalNumber<T>) + CalculateB(RationalNumber<T>));
}

template <typename T>
RationalNumber<T> RationalNumber<T>::operator-= (const RationalNumber<T> &r) {
	return (CalculateA(RationalNumber<T>) = (CalculateA(RationalNumber<T>) - CalculateB(RationalNumber<T>));
}

//template <typename T>
//RationalNumber<T> RationalNumber<T>::operator++(const RationalNumber<T> &r) {
//
//}

template <typename T>
RationalNumber<T> RationalNumber<T>::operator<< (const RationalNumber<T> &r) {

}

template <typename T>
RationalNumber<T> RationalNumber<T>::operator>> (const RationalNumber<T> &r) {

}
