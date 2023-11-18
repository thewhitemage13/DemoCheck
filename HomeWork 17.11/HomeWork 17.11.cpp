#include <iostream>
#include <string>
using namespace std;

struct DataTime {
	unsigned short day{};
	unsigned short month{};
	long long year{};
	string weekday;
};

struct Check {
	
	string name;
	string adress;
	string goodsname;
	unsigned int index{};
	float price{};
	float mymoney{};
	unsigned int MWST{};
	float wm{};
	float netto{};
	float surrenders{};
	unsigned int TSEnummer{};
};

struct CheckDataTime {
	DataTime now;
	Check today;
};

void InfoChek(CheckDataTime& p)
{
	cout << "Enter shop name:";
	cin >> p.today.name;

	cout << "Enter adress: ";
	cin >> p.today.adress;

	cout << "Enter idex: ";
	cin >> p.today.index;

	cout << "Enter day:";
	cin >> p.now.day;
	
	if (p.now.day < 1 || p.now.day > 31)
	{
		cout << "Oops, inccorrect value for day!\n";
		throw "ERROR DAY!";
	}

	cout << "Enter month:";
	cin >> p.now.month;
	
	if (p.now.month < 1 || p.now.month > 12)
	{
		cout << "Oops, inccorrect value for month!\n";
		throw "ERROR MONTH!";
	}

	cout << "Enter year:";
	cin >> p.now.year;


	cout << "Enter product name: ";
	cin >> p.today.goodsname;

	cout<< "Enter price: ";
	cin >> p.today.price;

	if (p.now.month < 0)
	{
		cout << "Oops, inccorrect value for price!\n";
		throw "ERROR PRICE!";
	}

	cout << "Enter your money: ";
	cin >> p.today.mymoney;

	if (p.today.mymoney < p.today.price)
	{
		cout << "Oops, inccorrect value for your money!\n";
		throw "ERROR MONEY!";
	}

	cout << "Enter Transaction number: ";
	cin >> p.today.TSEnummer;

	if (p.today.TSEnummer < 0)
	{
		cout << "Oops, inccorrect value for Transaction number!\n";
		throw "ERROR TRANSACTION NUMBER!";
	}

	cout << "Enter MWST in %: ";
	cin >> p.today.MWST;

	int a = (14 - p.now.month) / 12;
	int y = p.now.year - a;
	int m = p.now.month + 12 * a - 2;
	int wd = (p.now.day + (31 * m) / 12 + y + y / 4 - y / 100 + y / 400) % 7;

	string weekdays[] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
	p.now.weekday = weekdays[wd];
	p.today.wm = (p.today.price / 100) * p.today.MWST;
	p.today.netto = p.today.price - p.today.wm;
	p.today.surrenders = p.today.price - p.today.mymoney;
}

void PrintCheck(const CheckDataTime& p)
{
	cout << "\t" << p.today.name << "\n";
	cout << "\t" << p.today.adress << "\n";
	cout << "\t" << p.today.index << "\n";
	cout << p.today.goodsname;
	cout << "\t" <<"Price: " << p.today.price << " A" << "\n";
	cout << "\t"<<"Your money: " << p.today.mymoney << "\n";
	cout << "\t"<<"" << p.today.surrenders << "\n";
	printf("%.2f,\t", p.today.wm);
	cout << "\n";
	printf("%.2f,\t", p.today.price);
	cout << "\n";
	printf("%.2f,\t", p.today.netto);
	cout << "\n";
	printf("%.2f,\t", p.today.surrenders);
	cout << "\n";
	cout << p.today.TSEnummer << "\n";
	cout << p.now.weekday << ", ";
	printf("%02d.%02d.%04d", p.now.day, p.now.month, p.now.year);
}

int main()
{
	CheckDataTime now;
	InfoChek(now);
	PrintCheck(now);
}