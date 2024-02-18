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

class Animal 
{
public:
	virtual ~Animal()
	{
		cout << "delete animal" << endl;
	};

	virtual void voice() = 0;
};

class Dog : public Animal
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
		else{
			age = 0;
		}

		lovelyToy = new Toy(toyName);
	}

	Dog() :Dog("snow","sometoy", 0) {};
	Dog(string _name) :Dog(_name, "sometoy", 0) {};
	Dog(int _age) :Dog("snow", "sometoy", _age) {};

	virtual ~Dog()
	{
		delete lovelyToy;
		cout << "delete dog and toy" << endl;
	}

	void voice() override
	{
		cout << "bark" << endl;
	}

};

class OperaDog : public Dog
{
public:
	void voice() override final
	{
		cout << "baaaaaark" << endl;
	}
};

class SuperOperaDog : public OperaDog
{

};


int main() {

	Animal* d = new Dog("evre", "evqew", 5);
	delete d;

	SuperOperaDog a;
	a.voice();

	Dog c;

}*/