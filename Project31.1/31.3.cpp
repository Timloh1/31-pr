/*#include <iostream>
#include <string>

using namespace std;

class Toy
{
private:
	string name;
public:
	Toy(string _name) :name(_name) {};
	Toy() :name("SomeToy") {};
};

class smart_pointer_toy 
{
private:
	Toy* obj;
public:

	smart_pointer_toy()
	{
		obj = new Toy("SomeName");
	}

	smart_pointer_toy(string name)
	{
		obj = new Toy(name);
	}

	smart_pointer_toy(const smart_pointer_toy& other)
	{
		obj = new Toy(*other.obj);
	}

	smart_pointer_toy& operator=(const smart_pointer_toy& other)
	{
		if (this == &other) return *this;
		if (obj != nullptr) delete obj;

		obj = new Toy(*other.obj);
		return *this;
	}

	~smart_pointer_toy() 
	{
		delete obj;
	}

};

class Dog
{

private:

	string name;
	int age;
	smart_pointer_toy lovelyToy;

public:

	Dog(string _name, string toyName, int _age) : name(_name), lovelyToy(toyName)
	{
		if (_age < 30 && _age >= 0) {
			age = _age;
		}
		else {
			age = 0;
		}
	}

	Dog() :Dog("snow", "sometoy", 0) {};
	Dog(string _name) :Dog(_name, "sometoy", 0) {};
	Dog(int _age) :Dog("snow", "sometoy", _age) {};

};

//void foo(unique_ptr<Dog> d) {
//}

int main() {

	unique_ptr<Dog> d = make_unique<Dog>("cwc", "wcwwc", 6);
	//foo(d); нельзя

}*/