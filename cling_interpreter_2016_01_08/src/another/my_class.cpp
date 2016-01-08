#include "my_class.h"

template <typename T>
T MyClass<T>::inc() {
	return ++total;
}

template <typename T>
T MyClass<T>::dec() {
	return --total;
}
