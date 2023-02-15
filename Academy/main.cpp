//Academy
#include<iostream>
#define _CRT_SECURE_NO_WARGNINGS
using namespace std;

class Human
{
	std::string first_name;
	std::string last_name;
	tm birth_date;  //tm-timepoint
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	tm get_birth_date()const
	{
		return birth_date;
	}
	unsigned int get_age()const
	{
		time_t t_today = time(NULL);
			//cout << today << endl;
		tm* tm_today = localtime(&t_today);
		unsigned int age=tm_today->tm_year - birth_date.tm_year;
		if (tm_today->tm_mon < birth_date.tm_mon) age--;
		if (tm_today->tm_mon == birth_date.tm_mon && tm_today ->tm_mday < birth_date.tm_mday)age--;
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_birth_date(int year, int month, int day)
	{
		birth_date.tm_year = year - 1990;
		birth_date.tm_mon = month-1;
		birth_date.tm_mday = day;
	}

	//                   Constructors:
	Human(const std::string& last_name, const std::string first_name,int year, int month, int day)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_birth_day(year,month,day);

		cout << "HConstructor" << this << endl;
	}
		~Human()
	{
		cout << "HDestructor" << this << endl;
	}
    //                Methods:
		void info() const
		{
			cout << last_name << " " << first_name << " " << get_age() << endl;
		}

};
class Student : public Human
{
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string&& get_speciality ()const
	{
		return speciality;
	}
};
#define TIME_CHECK
void main()
{
	setlocale (LC_ALL, "");
#ifdef TIME_CHECK
	time_t t_today = time(NULL);// �������� 
	cout << t_today << endl;
	tm* tm_today = localtime(&t_today);
	cout << tm_today->tm_year << "\t";
	cout << tm_today->tm_mon + 1 << "\t";
	cout << tm_today->tm_mday << "\t";
	cout << asctime(tm_today) << "\t";
#endif // TIME_CHECK

}