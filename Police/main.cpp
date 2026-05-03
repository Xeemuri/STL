#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <ctime>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

#define tab '\t'
#define delimiter "\n-------------------------------------------------------------\n"

const std::map<int, std::string> OFFENCES =
{
	std::pair<int, std::string>(1, "Парковка в неположенном месте"),
	std::pair<int, std::string>(2, "Непристегнутый ремень безопасности"),
	std::pair<int, std::string>(3, "Превышение скорости"),
	std::pair<int, std::string>(4, "Пересечение сплошной"),
	std::pair<int, std::string>(5, "Вождение в нетрезвом состоянии"),
	std::pair<int, std::string>(6, "Оскорбление офицера"),
	std::pair<int, std::string>(7, "Проезд на красный сигнал светофора"),
};

class Offence
{
	std::string location;
	tm time; //Структура tm описывает дату и время
	int offence;
public:
	const std::string& get_location()const
	{
		return location;
	}
	std::string get_time()const
	{
		return std::asctime(&this->time);
	}
	int get_offence()const
	{
		return offence;
	}

	Offence(const std::string& location, const char* time, int offence)
	{
		char time_buffer[32] = {};
		strcpy(time_buffer, time);
		this->location = location;
		this->time = {};
		this->get_time_from_string(time_buffer);
		this->offence = offence;
	}
	Offence(const std::string& location, time_t timestamp, int offence)
	{
		this->location = location;
		this->time = *localtime(&timestamp);
		this->offence = offence;
	}
	tm get_time_from_string(char* str)
	{
		const char delimiters[] = "./ -:";
		char* dateparts[5] = {};
		int i = 0;
		for (char* pch = strtok(str, delimiters); pch; pch = strtok(NULL, delimiters))
			dateparts[i++] = pch;
		this->time.tm_year = std::atoi(dateparts[0]) - 1900;
		this->time.tm_mon = std::atoi(dateparts[1]) - 1;
		this->time.tm_mday = std::atoi(dateparts[2]);
		this->time.tm_hour = std::atoi(dateparts[3]);
		this->time.tm_min = std::atoi(dateparts[4]);
		time_t timestamp = mktime(&this->time);
		this->time = *localtime(&timestamp);

		return this->time;
	}

};
std::ostream& operator<<(std::ostream& os, const Offence& obj)
{
	std::string offence_time = obj.get_time();
	offence_time[offence_time.size() - 1] = 0;
	return os << offence_time << tab
		<< obj.get_location() << tab
		<< OFFENCES.at(obj.get_offence());
}
std::ostream& operator<<(std::ostream& os, const std::list<Offence>& offences)
{
	for (Offence i : offences) os << i << endl;
	return os;
}

void get_from_file(const std::string& filename)
{
	std::ifstream fin(filename);
	std::string line;
	while (std::getline(fin, line))
	{
		cout << line << endl;
	}
	fin.close();
}
void save_to_file(std::map<std::string, std::list<Offence>>& base, const std::string& filename)
{
	std::ofstream fout(filename);
	for (std::pair<std::string, std::list<Offence>> i : base)
	{
		fout << i.first << ": " << endl << i.second;
	}
	fout.close();
}
//#define OFFENCE_CHECK

int main()
{
	setlocale(LC_ALL, "");
#ifdef OFFENCE_CHECK
	Offence offence("Улица Ленина", "2026.04.29 11:52", 2);
	cout << offence << endl;

	Offence offence2("Переулок Космический", time(NULL), 2);
	cout << offence2 << endl;
	cout << time(NULL);
#endif // OFFENCE_CHECK

	std::map<std::string, std::list<Offence>> base =
	{
		std::pair<std::string,std::list<Offence>>{"A123BB",{Offence("Улица Ленина 22", 1777455953,5), Offence("Улица Космонавтов 33", "2016.10.16 17:30",2)}},
		std::pair<std::string,std::list<Offence>>{"O777OO",{Offence("Океанский проспект 11", 1777455953,4), Offence("Улица Пушкинская 10", "2016.10.16 17:30",6)}},
		std::pair<std::string,std::list<Offence>>{"H228YP",{Offence("Улица Борисенко 110", 1777455953,3), Offence("Улица Никифорова 55", "2016.10.16 17:30",5)}},
	};


	cout << "\t\t\t\tПОЛНАЯ БАЗА ПРАВОНАРУШИТЕЛЕЙ: \n";
	get_from_file("police_base.txt");
	save_to_file(base, "police_base.txt");
	cout << delimiter;
	cout << base.at("A123BB");
}