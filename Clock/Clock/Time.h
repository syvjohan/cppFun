#ifndef TIME_H
#define TIME_H

class Time {
public:
	Time(int = 0, int = 0, int = 0); //default constructor

	//Set functions
	Time &setTime(int, int, int);
	Time &setHour(int);
	Time &setMinute(int);
	Time &setSecond(int);

	//get functions
	int getHour() const;
	int getMinute() const;
	int getSecond() const;

	//print functions
	void printUniversal() const;
	void printStandard() const;
private:
	int hour;
	int minute;
	int second;
};

#endif // !TIME_H