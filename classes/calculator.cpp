#include "calculator.h"

template <class T> T Calculator<T>::Multiplication(T a, T b) {
	return a * b;
}

template <class T> T Calculator<T>::Division(T a, T b) {
	
	return a / b;
}

template <class T> T Calculator<T>::Addition(T a, T b) {
	return a + b;
}

template <class T> T Calculator<T>::Substraction(T a, T b) {
	return Addition(a, -b);

}