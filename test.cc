#include <iostream>
using namespace std;

class A {
   public:
	A() {printSelf();}
	void printSelf() {cout << "IM GREAT" << endl;}
	void death() {delete this;}
};

int main() {
	A *a = new A;
	a->death();
	return 0;
}


