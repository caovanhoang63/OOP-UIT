#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

public:
	void Enter()
	{
		cout << "Enter day: ";
		cin >> day;
		cout << "Enter month: ";
		cin >> month;
		cout << "Enter year: ";
		cin >> year;
	}
	void Print()
	{
		cout << day << "/" << month << "/" << year << endl;
	}
};
class Human
{
protected:
	string name;
	Date date_of_birth;
	string address;
	string gender;

public:
	Human() {}
	Human(string name, Date date_of_birth, string address, bool gender)
	{
		this->name = name;
		this->date_of_birth = date_of_birth;
		this->address = address;
		this->gender = gender;
	}
	Human(const Human &a)
	{
		*this = a;
	}
	void Enter()
	{
		cout << "Enter name: ";
		getline(cin, name);
		cout << "Enter date of birth: " << endl;
		date_of_birth.Enter();
		cout << "Enter address: ";
		cin.ignore();
		getline(cin, address);
		cout << "Enter gender: ";
		cin >> gender;
	}
	virtual void Print()
	{
		cout << "Name: " << name << endl;
		cout << "Date of birth: "; date_of_birth.Print();
		cout << "Address: " << address << endl;
		cout << "Gender: " << gender<<endl;
	}
	string get_name()
	{
		return name;
	}
	Date get_date_of_birth()
	{
		return date_of_birth;
	}
	string get_address()
	{
		return address;
	}
	string get_gender()
	{
		return gender;
	}
	void set_ho_ten(string name)
	{
		this->name = name;
	}
	void set_ngay_sinh(Date date_of_birth)
	{
		this->date_of_birth = date_of_birth;
	}
	void set_noi_o(string address)
	{
		this->address = address;
	}
	void set_gioi_tinh(string gender)
	{
		this->gender = gender;
	}
	virtual ~Human() {}
};
class Student : public Human
{
private:
	string school_name; //  ten truong
	string class_name;	//  ten lop
	int school_year;	// nien khoa
	int year_in;		// sinh vien nam may?
	string major;		// chuyen nganh
public:
	Student() {}
	Student(string name, Date date_of_bith, string address, bool gender, string school_name, string class_name, int school_year, int year_in, string major)
		: Human(name, date_of_birth, address, gender)
	{
		this->school_name = school_name;
		this->school_year = school_year;
		this->year_in = year_in;
		this->major = major;
	}
	Student(const Student &a)
	{
		*this = a;
	}
	void Enter()
	{
		Human::Enter();
		cout << "Enter school's name: ";
		cin.ignore();
		getline(cin, this->school_name);
		cout << "Enter school year: ";
		cin >> this->school_year;
		cout << "Which year are you in? ";
		cin >> this->year_in;
		cout << "Enter major: ";
		cin.ignore();
		getline(cin, this->major);
	}
	void Print() override
	{
		Human::Print();
		cout << "School's name: " << this->school_name << endl;
		cout << "School year: " << this->school_year << endl;
		cout << "Year in: " << this->year_in << endl;
		cout << "Major: " << this->major << endl;
	}
	// Getter functions
	string getSchoolName() const
	{
		return school_name;
	}
	string getClassName() const
	{
		return class_name;
	}
	int getSchoolYear() const
	{
		return school_year;
	}
	int getYearIn() const
	{
		return year_in;
	}
	virtual string getMajor()  const 
	{
		return major;
	}
	// Setter functions
	void setSchoolName(string name)
	{
		school_name = name;
	}
	void setClassName(string name)
	{
		class_name = name;
	}
	void setSchoolYear(int year)
	{
		school_year = year;
	}
	void setYearIn(int year)
	{
		year_in = year;
	}
	void setMajor(string major)
	{
		this->major = major;
	}
};
class Pupil : public Human
{
private:
	string school_name;
	string class_name;

public:
	Pupil() {}
	Pupil(string name, Date date_of_birth, string address, bool gender, string school_name, string class_name)
		: Human(name, date_of_birth, address, gender)
	{
		this->school_name = school_name;
		this->class_name = class_name;
	}
	Pupil(const Pupil &a)
	{
		*this = a;
	}
	// Getter functions
	string getSchoolName() const
	{
		return school_name;
	}
	string getClassName() const
	{
		return class_name;
	}
	// Setter functions
	void setSchoolName(string name)
	{
		school_name = name;
	}
	void setClassName(string name)
	{
		class_name = name;
	}
	void Enter()
	{
		Human::Enter();
		cin.ignore();
		cout << "Enter school's name: ";
		getline(cin, this->school_name);
		cout << "Enter class's name: ";
		getline(cin, this->class_name);
	}
	void Print()
	{
		Human::Print();
		cout << "School's name: " << this->school_name << endl;
		cout << "Class name: " << this->class_name << endl;
	}
};
class Worker : public Human
{
private:
	string workplace;
	int salary;

public:
	Worker() {}
	Worker(string name, Date date_of_birth, string address, bool gender, string workplace, int salary)
		: Human(name, date_of_birth, address, gender)
	{
		this->workplace = workplace;
		this->salary = salary;
	}
	Worker(const Worker &a)
	{
		*this = a;
	}
	// Getter functions
	string getWorkplace() const
	{
		return workplace;
	}
	int getSalary() const
	{
		return salary;
	}
	// Setter functions
	void setWorkplace(string place)
	{
		workplace = place;
	}
	void setSalary(int salary)
	{
		this->salary = salary;
	}
	void Enter()
	{
		Human::Enter();
		cout << "Enter workplace: ";
		cin.ignore();
		getline(cin, this->workplace);
		cout << "Enter salary: ";
		cin >> this->salary;
	}
	void Print()
	{
		Human::Print();
		cout << "Workplace: " << this->workplace << endl;
		cout << "Salary: " << this->salary << endl;
	}
};
class Artist : public Human
{
private:
	string stage_name;
	string field_of_art;

public:
	Artist() {}
	Artist(string name, Date date_of_birth, string address, bool gender, string stage_name, string field_of_art)
		: Human(name, date_of_birth, address, gender)
	{
		this->stage_name = stage_name;
		this->field_of_art = field_of_art;
	}
	Artist(const Artist &a)
	{
		*this = a;
	}
	// Getter functions
	string getStageName() const
	{
		return stage_name;
	}
	string getFieldOfArt() const
	{
		return field_of_art;
	}
	// Setter functions
	void setStageName(string name)
	{
		stage_name = name;
	}
	void setFieldOfArt(string field)
	{
		field_of_art = field;
	}
	void Enter()
	{
		Human::Enter();
		cin.ignore();
		cout << "Enter stage name: ";
		getline(cin, this->stage_name);
		cout << "Enter field of art: ";
		getline(cin, this->field_of_art);
	}
	void Print()
	{
		Human::Print();
		cout << "Stage name: " << this->stage_name << endl;
		cout << "Field of art: " << this->field_of_art << endl;
	}
};
class Singer : public Human
{
private:
	string stage_name;
	string field_of_art;

public:
	Singer() {}
	Singer(string name, Date date_of_birth, string address, bool gender, string stage_name, string field_of_art)
		: Human(name, date_of_birth, address, gender)
	{
		this->stage_name = stage_name;
		this->field_of_art = field_of_art;
	}
	Singer(const Singer &a)
	{
		*this = a;
	}
	// Getter functions
	string getStageName() const
	{
		return stage_name;
	}
	string getFieldOfArt() const
	{
		return field_of_art;
	}
	// Setter functions
	void setStageName(string name)
	{
		stage_name = name;
	}
	void setFieldOfArt(string field)
	{
		field_of_art = field;
	}
	void Enter()
	{
		Human::Enter();
		cout << "Enter stage name: ";
		cin.ignore();
		getline(cin, this->stage_name);
		cout << "Enter field of art: ";
		getline(cin, this->field_of_art);
	}
	void Print()
	{
		Human::Print();
		cout << "Stage name: " << this->stage_name << endl;
		cout << "Field of art: " << this->field_of_art << endl;
	}
};