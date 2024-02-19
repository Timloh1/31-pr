/*#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Toy
{
private:
	string name = "";
public:
	string getName() {
		return name;
	}
	Toy(string _name) :name(_name) {};
	Toy() :name("SomeToy") {};
};

int counter = 0;

class shared_ptr_toy{

private:

	Toy* object = nullptr;

public:

	shared_ptr_toy()
	{
		object = new Toy("SomeToy");
		counter++;
	}

	shared_ptr_toy(string name)
	{
		object = new Toy(name);
		counter++;
	}

	shared_ptr_toy(const shared_ptr_toy& other)
	{
		object = new Toy(other.object->getName());
		counter++;
	}

	shared_ptr_toy& operator=(const shared_ptr_toy& other)
	{
		if (this == &other) return *this;
		if (object != nullptr) {

			if (counter == 1) {
				delete object;
				--counter;
				counter = 0;
			}

			object = new Toy(other.object->getName());

		}

		return *this;
	}

	~shared_ptr_toy()
	{

		if (counter == 1) {
			delete object;
			counter = 0;
		}

	}

	string getToyName() {
		if (object != nullptr) return object->getName();
		return "Nothing";
	}

	void reset() {
		object = nullptr;
		counter--;
	}

	int use_count() {
		return counter;
	}

	Toy* get() {
		return object;
	}

};

shared_ptr_toy make_shared_toy(string name)
{
	shared_ptr_toy object(name);
	return object;
}

int main() {
	shared_ptr_toy toy_01 = make_shared_toy("ball");
	shared_ptr_toy toy_02(toy_01);
	shared_ptr_toy toy_03("duck");
	std::cout << "=================================================" << std::endl;
	std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
		<< toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
		<< toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
	std::cout << "=================================================" << std::endl;
	toy_02 = toy_03;
	std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
		<< toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
		<< toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
	std::cout << "=================================================" << std::endl;
	toy_01.reset();
	toy_02.reset();
	std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
		<< toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
		<< toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
	std::cout << "=================================================" << std::endl;
	return 0;
}*/