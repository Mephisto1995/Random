#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <ctime>
#include <typeinfo>
#pragma warning(disable:4996)

namespace Constants
{
	const int LEGS = 4;
}

class Animal
{
public:
	Animal() :
		mAge(-1),
		mLegs(Constants::LEGS)
	{}

	Animal(const int age) :
		mAge(age),
		mLegs(Constants::LEGS)
	{}

	virtual const int GetAge() const { return mAge; }
	virtual void SetAge(const int age) { mAge = age; }

private:
	const int mLegs;
	int mAge;
};

class Dog : public Animal
{
public:
	Dog() :
		Animal(),
		mName("UNKNOWN")
	{}

	Dog(const std::string name, const int age) :
		Animal(age),
		mName(name)
	{}

	const std::string GetName() const { return mName; }
	void SetName(const std::string name) { mName = name; }


private:
	std::string mName;
};

class Cat : public Animal
{
public:
	Cat() :
		Animal(),
		mName("UNKNOWN")
	{}

	Cat(const std::string name, const int age) :
		Animal(age),
		mName(name)
	{}

	const std::string GetName() const { return mName; }
	void SetName(const std::string name) { mName = name; }

private:
	std::string mName;
};

class Lion : public Animal
{
public:
	Lion() :
		Animal()
	{}

	Lion(const int age) :
		Animal(age)
	{}

private:
};

class Book
{
public:
	Book(Animal &a)
	{
		mAnimals.push_back(&a);
		mAnimals.push_back(&a);
	}

	Book(Animal &a, Animal &a1)
	{
		mAnimals.push_back(&a);
		mAnimals.push_back(&a1);
	}

	Book(Animal &a, Animal &a1, Animal &a2)
	{
		mAnimals.push_back(&a);
		mAnimals.push_back(&a1);
		mAnimals.push_back(&a2);
	}

	void DescribeAll()
	{
		for (auto& animal : mAnimals)
		{
			Dog* d = GetAnimalType<Dog>(animal);

			if (d != nullptr)
			{
				std::cout << d->GetName() << std::endl;
				std::cout << d->GetAge() << std::endl;
			}
			else
			{
				Cat* c = GetAnimalType<Cat>(animal);

				if (c != nullptr)
				{
					std::cout << c->GetName() << std::endl;
					std::cout << c->GetAge() << std::endl;
				}
				else
				{
					Lion* l = GetAnimalType<Lion>(animal);

					if (l != nullptr)
					{
						std::cout << l->GetAge() << std::endl;
					}
				}
			}
		}
	}

private:
	std::vector<Animal*> mAnimals;

private:
	template<typename T>
	T* GetAnimalType(Animal* animal)
	{
		return dynamic_cast<T*>(animal);
	}
};

void main()
{
	Dog d = Dog("Cherry", 11);
	Cat c = Cat("Lola", 6);
	Lion l = Lion(4);
	Book b = Book(d, c, l);
	b.DescribeAll();
}