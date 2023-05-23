#include <iostream>
using namespace std;

class Time
{
public:
	Time(int h, int m, int s);
	void setTime(int h, int m, int s);
	void chooseTime();
	void priTime()const
	{
		cout << hour << ":" << minute << ":" << second << endl;
	}
	Time& operator++()
	{
		++second;
		chooseTime();
		return *this;
	}
	Time operator++(int)
	{
		Time temp(hour, minute, second);
		++second;
		chooseTime();
		return temp;
	}
private:
	int hour, minute, second;
};

int main()
{
	Time t(23, 59, 50);
	t.priTime();
	++t;
	t.priTime();
	Time t2 = ++t;
	t2.priTime();
	t.priTime();
}

Time::Time(int h, int m, int s)
{
	setTime(h, m, s);
}
void Time::setTime(int h, int m, int s)
{
	hour = h, minute = m, second = s;
}
void Time::chooseTime()
{
	if (second >= 60)
	{
		minute += second / 60;
		second %= 60;
	}
	if (minute >= 60)
	{
		hour += minute / 60;
		minute %= 60;
	}
	if (hour >= 24)
	{
		hour %= 24;
	}
}
