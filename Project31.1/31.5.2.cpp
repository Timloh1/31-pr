#include <iostream>
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

class Counter
{
private:
	vector <Toy*> objects;
public:
	int getCount() {
		return objects.size();
	}
	void setCounter(Toy* object) {
		objects.push_back(object);
	}
};
 
class shared_ptr_toy{

private:

	Toy* object = nullptr;
	Counter* newCounter = new Counter();

public:

	shared_ptr_toy()
	{
		object = new Toy("SomeToy");
		newCounter->setCounter(object);
	}

	shared_ptr_toy(string name)
	{
		object = new Toy(name);
		newCounter->setCounter(object);
	}

	shared_ptr_toy(const shared_ptr_toy& other)
	{
		object = new Toy(other.object->getName());
		newCounter->setCounter(object);
	}

	shared_ptr_toy& operator=(const shared_ptr_toy& other)
	{
		if (this == &other) return *this;
		if (object != nullptr) {

			if (newCounter->getCount() == 1) {
				delete object;
				delete newCounter;
			}

			object = new Toy(other.object->getName());
			newCounter->setCounter(object);

		}

		return *this;
	}

	~shared_ptr_toy()
	{

		if (newCounter->getCount() == 1) {
			delete object;
			delete newCounter;
		}

	}

	shared_ptr_toy make_shared_toy(string name) 
	{
		object = new Toy("SomeToy");
		newCounter->setCounter(object);
		return *this;
	}

	string getToyName() {
		if (object != nullptr) return object->getName();
		return "Nothing";
	}

	void reset() {
		object = nullptr;
		newCounter = nullptr;
	}

	int use_count() {
		return newCounter->getCount();
	}

	Toy* get() {
		return object;
	}

};

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
	std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
		<< toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
		<< toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
	std::cout << "=================================================" << std::endl;
	return 0;
}