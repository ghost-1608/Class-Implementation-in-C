#include <iostream>

using namespace std;

class Foo
{
	int value;

public:
	Foo (int a)
	{
		value = a;
	}

	void display()
	{
		cout << value;
	}
};

int main()
{
	Foo f(69);

	f.display();
}