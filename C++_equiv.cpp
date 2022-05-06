#include <iostream>

using namespace std;

class Foo
{
public:
	int value;
	
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
