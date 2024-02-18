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

class Dog 
{

private:

	string name;
	int age;
	Toy* lovelyToy;

public:

	Dog(string _name, string toyName, int _age) :name(_name)
	{
		if (_age < 30 && _age >= 0) {
			age = _age;
		}
		else {
			age = 0;
		}

		lovelyToy = new Toy(toyName);
	}

	Dog() :Dog("snow", "sometoy", 0) {};
	Dog(string _name) :Dog(_name, "sometoy", 0) {};
	Dog(int _age) :Dog("snow", "sometoy", _age) {};

	Dog(const Dog& other) 
	{
		name = other.name;
		age = other.age;
		lovelyToy = new Toy(*other.lovelyToy);
	}

	Dog& operator=(const Dog& other) 
	{
		if (this == &other) return *this;

		name = other.name;
		age = other.age;

		if (lovelyToy != nullptr) delete lovelyToy;

		lovelyToy = new Toy(*other.lovelyToy);
		return *this;
	}

	virtual ~Dog()
	{
		delete lovelyToy;
		cout << "delete dog and toy" << endl;
	}

};

int main() {

	Dog d("cwe", "Wcew", 3);
	Dog q(d);

}*/