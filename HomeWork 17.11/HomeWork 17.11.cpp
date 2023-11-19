#include <iostream>
#include <string>
using namespace std;

struct DataTime {
	unsigned short day{};
	unsigned short month{};
	long long year{};
	unsigned short hour{};
	unsigned short minuts{};
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
	DataTime now;
};

void InfoChek(Check& p)
{
	cout << "Enter shop name:";
	cin >> p.name;

	cout << "Enter adress: ";
	cin >> p.adress;

	cout << "Enter idex: ";
	cin >> p.index;

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

	cout << "Enter hour:";
	cin >> p.now.hour;
	if (p.now.hour<0 || p.now.hour > 23)
	{
		cout << "Oops, inccorrect value for hour!\n";
		throw "ERROR HOUR!";
	}
	cout << "Enter minutes:";
	cin >> p.now.minuts;

	if (p.now.minuts < 0 || p.now.minuts > 60)
	{
		cout << "Oops, inccorrect value for minutes!\n";
		throw "ERROR MINUTES!";
	}

	cout << "Enter product name: ";
	cin >> p.goodsname;

	cout << "Enter price: ";
	cin >> p.price;

	if (p.now.month < 0)
	{
		cout << "Oops, inccorrect value for price!\n";
		throw "ERROR PRICE!";
	}

	cout << "Enter your money: ";
	cin >> p.mymoney;

	if (p.mymoney < p.price)
	{
		cout << "Oops, inccorrect value for your money!\n";
		throw "ERROR MONEY!";
	}

	cout << "Enter Transaction number: ";
	cin >> p.TSEnummer;

	if (p.TSEnummer < 0)
	{
		cout << "Oops, inccorrect value for Transaction number!\n";
		throw "ERROR TRANSACTION NUMBER!";
	}

	cout << "Enter MWST in %: ";
	cin >> p.MWST;

	int a = (14 - p.now.month) / 12;
	int y = p.now.year - a;
	int m = p.now.month + 12 * a - 2;
	int wd = (p.now.day + (31 * m) / 12 + y + y / 4 - y / 100 + y / 400) % 7;

	string weekdays[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	p.now.weekday = weekdays[wd];
	p.wm = (p.price / 100) * p.MWST;
	p.netto = p.price - p.wm;
	p.surrenders = p.price - p.mymoney;
}

void PrintCheck(const Check& p)
{
	cout << "\t" << p.name << "\n";
	cout << "\t" << p.adress << "\n";
	cout << "\t" << p.index << "\n";
	cout << "\t" << p.goodsname << "\n";
	cout << "\t";
	printf("Price: %.2f $ \n\t", p.price);
	printf("Your money: %.2f $\n\t", p.mymoney);
	printf( "Netto: %.2f\n\t", p.netto);
	printf("Brutto: %.2f\n\t", p.price);
	printf("MWST: %.2f\n\t", p.wm);
	printf("Surrenders: %.2f $\n\t", p.surrenders);
	cout <<"TSE: " << p.TSEnummer << "\n";
	cout<<"\t" << "Date: " << p.now.weekday << ", ";
	printf("%02d.%02d.%04d", p.now.day, p.now.month, p.now.year);
	cout << "\n\t";
	cout << "Time: " << p.now.hour << ":" << p.now.minuts;
}

int main()
{
	Check now;
	InfoChek(now);
	PrintCheck(now);
}
