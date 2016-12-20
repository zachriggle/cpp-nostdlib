#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

class A {
public:
	virtual void print(const char* message) {
		exit(0);
	}
};

class B : public A {
public:
	void print(const char* message) {
		printf("%s\n", message);
	}
};

int main() {
	B b;
	b.print("Hello, world");
}
