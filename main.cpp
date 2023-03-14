#include <iostream>

using namespace std;

// A date has day 'd', month 'm' and year 'y'
struct Date {
    int d, m;
};

// To store number of days in
// all months from January to Dec.
const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int getDifference(Date dt1, Date dt2)
{
    // COUNT TOTAL NUMBER OF DAYS
    // BEFORE FIRST DATE 'dt1'

    // initialize count using years and day
    long int n1 = dt1.d;

    // Add days for months in given date
    for (int i = 0; i < dt1.m - 1; i++)
        n1 += monthDays[i];

    // SIMILARLY, COUNT TOTAL NUMBER OF
    // DAYS BEFORE 'dt2'

    long int n2 = dt2.d;
    for (int i = 0; i < dt2.m - 1; i++)
        n2 += monthDays[i];

    // return difference between two counts
    return (n2 - n1);
}

void cal_quote(Date dueDate, int day, float remaining, float quota) {
	Date nw = { day, dueDate.m };
	if (dueDate.d < day)
		nw.m--;

	float proposed = quota / (float) monthDays[dueDate.m - 2];
	int elapsedDays = getDifference(nw, dueDate);
	float consumed = quota - remaining;
	float curr = consumed / elapsedDays;

	cout << "Proposed GB/D = " << proposed << "\tYour Consumption GB/D: " << curr << "\n";
	if (curr <= proposed)
		cout << "You have extra = " << proposed - curr << "GB\n";
	else
		cout << "You used more " << curr - proposed << "GB than you should\n";
}
int main() {
	Date dueDate;
	int day;
	float remaining, quota;

	cout << "Enter your due day and month: ";
	cin >> dueDate.d >> dueDate.m;
	cout << "Enter current day";
	cin >> day;
	cout << "Enter your remaining quota and your total quota: ";
	cin >> remaining >> quota;

	cal_quote(dueDate, day, remaining, quota);
	return 0;
}
