#include <iostream>



class smart_array
{
public:
	smart_array(int a);
	~smart_array();
	void add_element(int value);
	int get_element(int index);
private:
	int size;
	int* arr;
	int i;

};

smart_array::smart_array(int a)
{
	size = a;
	arr = new int[size];
	i = 0;
}

smart_array::~smart_array()
{
	delete[] arr;
}

void smart_array::add_element(int value)
{
	if (i < size)
	{
		arr[i] = value;
		++i;
	}
	else
	{
		throw std::exception("array overflow");
	}
}

int smart_array::get_element(int index)
{
	if (index <= i)
	{
		return arr[index];
	}
	else
	{
		throw std::exception("value not initialized");
	}
}

int main()
{
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}