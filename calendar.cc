/**
 *
 * @file calendar.cc
 * @author Ryan Sordillo
 * @collaborators
 * @date 2/7/2024
 */
#include <string>
#include <iostream>

using namespace std;

#define MONTHS_PER_YEAR 12
const int START_YEAR = 1900;
const int START_DAY = 1;

const unsigned short DAYS_PER_MONTH[MONTHS_PER_YEAR] =
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const string MONTH_NAMES[MONTHS_PER_YEAR] =
    {"January",   "February", "March",    "April",
     "May",       "June",     "July",     "August",
     "September", "October",  "November", "December"};

const string WEEK_NAMES[7] = 
    {"Su", "M", "T", "W", "Th", "F", "Sa"};
/**
* Returns true if the chosen year is a leap year by calculating if the year is divisible
*by 4 and not 100, or if it is divisible by 400, then it is a leap year
* @param year the year to check if leap year
* @return true if is leap year, false if not
*/
bool is_leap_year(int year) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return true;
    else
        return false;
}
/**
* determines and calculates the calendar for the chosen year and month
* also formats the calendar properly
* @param year the year to print
* @param month the month to print
* @param start_day the start day of the month
*/
void print_month(int month, int year, int start_day) {
    int num_days = DAYS_PER_MONTH[month - 1];
    if (is_leap_year(year) && month == 2) {
        num_days++;
    }
    cout << "Su  M  T  W Th  F Sa" << endl;

    for (int indent = 0; indent < start_day; indent++) {
        cout << "   ";
    }
    cout << " ";
    for (int day_num = 1; day_num <= num_days; day_num++) {
        cout << day_num;
        if ((day_num + start_day) % 7 == 0) {
            cout << endl;
            if (day_num < 9) {
                cout << " ";
            }
        }
        else if (day_num < 9 && (day_num + start_day) % 7 != 0) {
            cout << "  ";
        }
        else {
            if (day_num < num_days) { // don't add space when the last day is printed
                cout << " ";
            }
        }
    }
        if ((num_days + start_day) % 7 != 0) {
        cout << endl;
        }
}
/**
* calculates and returns the starting day of the month for the given year
* @param year the year of the chosen year
* @param month the month of the chosen year
* @return numbers from 0 to 6 which correlates to days of week, 0 = sunday, 1 = monday... 6 = saturday
*/
int find_start_day(int month, int year) {
    int days_in_year = 0;
    for (int y = START_YEAR; y < year; y++) {
        if (is_leap_year(y))
            days_in_year += 366;
        else
            days_in_year += 365;
    }
    for (int i = 0; i < month; i++) {
        days_in_year += DAYS_PER_MONTH[i];
    }
    if (is_leap_year(year) && month >= 2)
        days_in_year++;
    int start_day = (START_DAY + days_in_year) % 7;
    return start_day;
}


// Controls operation of the program.
int main() {
    int month;
    int year;
    cout << "Enter the month: ";
    cin >> month;
    cout << "Enter the year: ";
    cin >> year;
    cout << MONTH_NAMES[month - 1] << " " << year << endl;
    int first_day = find_start_day(month - 1, year);
    print_month(month, year, first_day);
    return 0;
}
