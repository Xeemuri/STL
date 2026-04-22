#include<iostream>
#include <array>
#include <vector>
#include <string>
#include <deque>
#include<forward_list>
#include<list>
using std::cin;
using std::cout;
using std::endl;

#define tab '\t'
#define delimeter "\n-------------------------------------------------------------------\n"
template<typename T> void vector_properties(const std::vector<T>& vec)
{
	cout << "Size:	 " << vec.size() << endl;	//фактический размер
	cout << "Capacity:" << vec.capacity() << endl;
	cout << "MaxSize: " << vec.max_size() << endl; //максимально-воможный размер
}

//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_DEQUE
//#define STL_LIST
#define STL_FORWARD_LIST

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

#ifdef STL_LIST
	std::list<int> i_list = { 1,2,3,4,5 };
	for (int i : i_list)cout << i << tab;
	cout << endl;
	i_list.push_back(1);
	i_list.push_back(34);
	i_list.push_back(55);
	i_list.push_back(89);
	int index, value;
	cout << "Введите индекс добавляемого элемента:"; cin >> index;
	cout << "Введите значение добавляемого элемента:"; cin >> value;
	std::list<int>::iterator position = i_list.begin();
	//for (int i = 0; i < index; i++)position++;
	std::advance(position, index);
	i_list.insert(position, value);


	for (int i : i_list)cout << i << tab;
	cout << endl;
	cout << i_list.size();
	//i_list.erase(i_list.begin() + index);

#endif // STL_LIST

#ifdef STL_FORWARD_LIST
	std::forward_list<int> i_flist = { 3,5,8,13,21 };
	for (std::forward_list<int>::iterator it = i_flist.begin(); it != i_flist.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	i_flist.push_front(10);
	int index;
	int value;
	cout << "введите индекс добавляемого элемента: "; cin >> index;
	cout << "введите znachenie добавляемого элемента: "; cin >> value;
	/*bool less_then_10(const int value)
	{
		return value < 10;
	}*/

	i_flist.remove_if([](const int value) {return value % 2; });
	//std::forward_list<int>::iterator position = i_flist.begin();
	//if (index > 0 && index < std::distance(i_flist.begin(), i_flist.end()))
	//{
	//	std::advance(position, index - 1);
	//	i_flist.insert_after(position, value);
	//}
	//for (int i = 0; i < index-1; i++) ++position;
	//i_flist.insert_after(position, value);
	i_flist.remove(13);
	for (int i : i_flist) cout << i << tab;
	cout << endl;
#endif // STL_FORWARD_LIST

}