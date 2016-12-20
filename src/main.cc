#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

class A {
public:
	A() {
		puts("Created an A");
	}
	virtual ~A() {
		puts("Destroyed an A");
	}
	virtual void print(const char* message) {
		exit(0);
	}
};

class B : public A {
public:
	B() {
		puts("Created a B");
	}
	~B() {
		puts("Destroyed a B");
	}
	void print(const char* message) {
		printf("%s\n", message);
	}
};

int main() {
	A *foo = new B();
	foo->print("Hello, world");
	delete foo;
}
