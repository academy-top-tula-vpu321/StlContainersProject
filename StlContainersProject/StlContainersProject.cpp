#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <string>

class Person
{
	std::string name;
	int age;
public:
	std::string& Name() { return name; }
	int& Age() { return age; }

	Person(std::string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	friend std::ostream& operator<<(std::ostream& out, Person p)
	{
		out << "Name: " << p.name << ", Age: " << p.age;
		return out;
	}

	std::string ToString()
	{
		return "Name: " + name + ", Age: " + std::to_string(age);
	}

	friend bool operator<(const Person& p1, const Person& p2)
	{
		return p1.name < p2.name;
	}
};

bool AgeComparer(Person& p1, Person& p2)
{
	return p1.Age() < p2.Age();
}

int main()
{
	srand(time(nullptr));

	// ARRAY
	//std::array<int, 10> arr1;
	//try
	//{
	//	for (int i{}; i < arr1.size(); i++)
	//		//arr1[i] = i + 1;
	//		arr1.at(i) = i + 1;
	//}
	//catch (...)
	//{
	//	std::cout << "error\n";
	//}
	//arr1.fill(5);

	// VECTOR
	//std::vector<Person*> persons;
	//std::vector<int> arr;

	//for (int i{}; i < 10; i++)
	//	arr.push_back(rand() % 100);
	//
	//arr.insert(arr.begin() + 5, 500);

	//for (auto item : arr)
	//	std::cout << item << " ";
	///*std::cout << arr.max_size() << "\n";
	//std::cout << persons.max_size() << "\n";*/
	//std::vector<std::vector<int>> matrix;

	std::forward_list < std::string> students;
	students.push_front("Sam");
	students.push_front("Joe");
	students.push_front("Tom");

	for (auto item : students)
		std::cout << item << " ";
	std::cout << "\n";

	students.sort();

	for (auto item : students)
		std::cout << item << " ";
	std::cout << "\n";


	std::forward_list<int> ilist;
	for (int i{}; i < 10; i++)
		ilist.push_front(rand() % 100);
	
	for (auto item : ilist)
		std::cout << item << " ";
	std::cout << "\n";

	ilist.sort();

	for (auto item : ilist)
		std::cout << item << " ";
	std::cout << "\n";

	std::forward_list<Person> persons;

	persons.push_front(Person("Leo", 40));
	persons.push_front(Person("Tommy", 25));
	persons.push_front(Person("Joe", 32));
	persons.push_front(Person("Leo", 20));

	for (auto item : persons)
		std::cout << item.ToString() << "\n";
	std::cout << "\n";


	persons.remove_if([](Person p) {
		return p.Age() >= 30;
		});

	/*persons.sort([](auto p1, auto p2) 
		{
			return p1.Age() <= p2.Age() && p1.Name() <= p2.Name();
		});*/
	//persons.sort();
	//persons.sort(AgeComparer);

	for (auto item : persons)
		std::cout << item.ToString() << "\n";
	std::cout << "\n";

	
	std::forward_list<int> vnums{ 5, 6, 7, 8, 9 };
	auto ait1 = vnums.begin();
	auto ait2 = ++++++vnums.begin();

	std::forward_list<int> numbers{ 1, 2, 2, 2, 3, 3, 2, 1, 1, 2 };
	for (auto item : numbers)
		std::cout << item << " ";
	std::cout << "\n";


	auto it = numbers.begin();
	(((it++)++)++);
	numbers.splice_after(it, vnums, ait1, ait2);
	
	//numbers.sort();
	//numbers.unique();
	
	//numbers.remove(1);

	for (auto item : numbers)
		std::cout << item << " ";
	std::cout << "\n";

	for (auto item : vnums)
		std::cout << item << " ";
	std::cout << "\n";

}
