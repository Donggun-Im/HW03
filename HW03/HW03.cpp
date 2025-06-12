#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


template <typename T>
class SimpleVector
{
private:
	T* data;
	int currentSize = 0;
	int currentCapacity;
public:
	SimpleVector()
	{
		data = new T[10];
		currentCapacity = 10;
	}
	SimpleVector(int num)
	{
		data = new T[num];
		currentCapacity = num;
	}
	SimpleVector(const SimpleVector& SV)
	{
		currentSize = SV.currentSize;
		currentCapacity = SV.currentCapacity;
		data = new T[currentCapacity];
		for (int i = 0; i < currentSize; ++i)
		{
			data[i] = SV.data[i];
		}
	}



	void push_back(T value)
	{
		if (currentCapacity <= currentSize)
		{
			T* temp = new T[currentCapacity + 5];
			for (int i = 0; i < currentSize; ++i)
			{
				temp[i] = data[i];
			}
			delete[] data;
			data = temp;
			currentCapacity += 5;
		}
		*(data + currentSize) = value;
		++currentSize;

	}

	void pop_back()
	{
		if (currentSize == 0)
		{
			return;
		}
		currentSize -= 1;
	}

	int size()
	{
		return currentSize;
	}

	int capacity()
	{
		return currentCapacity;
	}

	void resize(int newSize)
	{
		if (newSize < currentCapacity)
		{
			return;
		}

		T* temp = new T[newSize];
		for (int i = 0; i < currentSize; ++i)
		{
			temp[i] = data[i];
		}
		delete[] data;
		data = temp;

		currentCapacity = newSize;
	}

	void sortData()
	{
		sort(data, data + currentSize);
	}
	T& operator[](int i)
	{
		return data[i];
	}




	~SimpleVector()
	{
		delete[] data;
	}
};


int main() {
	SimpleVector<char> vec1;
	vec1.push_back('c');
	vec1.push_back('a');
	vec1.push_back('b');
	SimpleVector<char> vec2(vec1);

	cout << "vec1 " << vec1[0] << " " << vec1[1] << " " << vec1[2] << endl;
	cout << vec1.size() << endl;
	cout << vec1.capacity() << endl;

	vec1.pop_back();
	vec1.sortData();
	vec1.resize(15);

	cout << "vec1 " << vec1[0] << " " << vec1[1] << endl;
	cout << vec1.size() << endl;
	cout << vec1.capacity() << endl;

	cout << "vec2 " << vec2[0] << " " << vec2[1] << " " << vec2[2] << endl;
	cout << vec2.size() << endl;
	cout << vec2.capacity() << endl;

}