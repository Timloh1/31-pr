#include <iostream>
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
	shared_ptr<Toy> lovelyToy;
	weak_ptr<Dog> bestie;

public:

	Dog(string _name, shared_ptr<Toy> toy, int _age) : name(_name), lovelyToy(toy)
	{
		if (_age < 30 && _age >= 0) {
			age = _age;
		}
		else {
			age = 0;
		}
	}

	Dog() :Dog("snow", make_shared<Toy>("sometoy"), 0) {};
	Dog(string _name) :Dog(_name, make_shared<Toy>("sometoy"), 0) {};
	Dog(int _age) :Dog("snow", make_shared<Toy>("sometoy"), _age) {};

	void copyLovelyToy(const Dog& oth)
	{
		lovelyToy = oth.lovelyToy;
	}

	void setBestie(shared_ptr<Dog> _bestie)
	{
		bestie = _bestie;
	}

};

int main() {

	shared_ptr<Toy> ball = make_shared<Toy>("Ball");
	shared_ptr<Toy> bone = make_shared<Toy>("Bone");

	shared_ptr<Dog> a = make_shared<Dog>("qqqqq", ball, 10);
	shared_ptr<Dog> b = make_shared<Dog>("aaaaa", ball, 10);
	shared_ptr<Dog> c = make_shared<Dog>("bbbbb", ball, 10);

	a->setBestie(b);
	b->setBestie(a);

	Dog* pa = a.get();
	Dog* pb = b.get();

	a.reset();
	b.reset();
	//e.copyLovelyToy(c);
	//Toy* f = bone.get();
	//d.copyLovelyToy(c);
	ball.reset();
	bone.reset();

}
