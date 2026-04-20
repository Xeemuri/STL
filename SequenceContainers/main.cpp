#include<iostream>
#include <array>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;

#define tab '\t'
#define delimeter "\n-------------------------------------------------------------------\n"

//#define STL_ARRAY
#define STL_VECTOR

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
	for (int i : i_vec)cout << i << tab;
	cout << endl;
	vector_properties(i_vec);


	i_vec.shrink_to_fit();
	vector_properties(i_vec);
	i_vec.resize(5);
	for (int i : i_vec)cout << i << tab;
	vector_properties(i_vec);
	//std::vector<double> d_vec;
	//vector_properties(d_vec);
#endif // STL_VECTOR




}