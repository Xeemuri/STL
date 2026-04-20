#include<iostream>
#include <array>
#include <vector>
#include <string>
#include <deque>
using std::cin;
using std::cout;
using std::endl;

#define tab '\t'
#define delimeter "\n-------------------------------------------------------------------\n"

//#define STL_ARRAY
//#define STL_VECTOR
#define STL_DEQUE

template<typename T> void vector_properties(const std::vector<T>& vec)
{
	cout << "Size:	 " << vec.size() << endl;	//фактический размер
	cout << "Capacity:" << vec.capacity() << endl;
	cout << "MaxSize: " << vec.max_size() << endl; //максимально-воможный размер
}

int main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	//array - это контейнер, который хранит данные в виде статического массива.
	std::array<int, 5> arr = { 0,1,1,2,3 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY
#ifdef STL_VECTOR
	std::vector<int> i_vec = { 0,1,1,2,3,5,8,13,21,34 };
	vector_properties(i_vec);
	i_vec.push_back(55);
	i_vec.push_back(89);
	vector_properties(i_vec);

	i_vec.erase(i_vec.begin());
	i_vec.insert(i_vec.begin()+4,100);
	for (int i : i_vec) cout << i << tab;
	cout << endl;
	vector_properties(i_vec);


	i_vec.shrink_to_fit();
	vector_properties(i_vec);
	i_vec.resize(5);
	for (int i : i_vec) cout << i << tab;
	cout << endl;
	vector_properties(i_vec);
	cout << "Front:\t" << i_vec.front()<<endl;
	cout << "Back:\t" << i_vec.back()<<endl;
	
	int index, value;
	cout << "Введите индекс добавляемого элемента:"; cin >> index;
	cout << "Введите значение добавляемого элемента:"; cin >> value;
	if(index<=i_vec.size())
		i_vec.insert(i_vec.begin() + index, value);
	for (std::vector<int>::iterator it = i_vec.begin(); it != i_vec.end(); ++it)
	{
		cout << *it << tab;
	}
	cout <<  endl;
#endif // STL_VECTOR

#ifdef STL_DEQUE
	std::deque<int> i_deque = { 3,5,8,13,21 };
	for (int i = 0; i < i_deque.size(); i++)
	{
		cout << i_deque[i] << tab;
	}
	cout << endl;
	i_deque.push_front(1);
	i_deque.push_front(1);
	i_deque.push_front(0);
	for (std::deque<int>::iterator it = i_deque.begin(); it != i_deque.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
#endif // DEQUE



}