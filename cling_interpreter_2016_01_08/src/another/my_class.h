template <typename T>
class MyClass {
public:
	MyClass(const T & t) : total(t) {}
	T inc();
	T dec();
private:
	T total;
};
