#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool checkLeapYear(int year) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return true;
    else
        return false;
}

int offsetCalc(int year, int month) {
    int _offset;
    const int _offset_list[] = {4, 0, 2, 5, 0, 3, 6, 1, 4, 6};

    bool _is_leap_year = checkLeapYear(year);

    if (month <= 2) return 3*(month - 1);

    _offset = _offset_list[month - 3];
    if (!_is_leap_year) --_offset;
    if (_offset < 0) _offset = 6;

    return _offset;
}

int calcDayOfWeek(int year, int month) {
    int _offset = offsetCalc(year, month);

    int _index = (1 + _offset + 5*((year - 1)%4) + 4*((year - 1)%100) + 6*((year - 1)%400))%7;

    return _index;
}

int getDaysinMonth(int year, int month) {
    int _days_list[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    bool _is_leap_year = checkLeapYear(year);

    int _days = _days_list[month - 1];
    if (month == 2 && _is_leap_year == true) _days = 29;

    return _days;
}

void ptrCalendar(int year, int month) {
    int _weeks;
    int _first_day_of_week = calcDayOfWeek(year, month);
    int _days_in_month = getDaysinMonth(year, month);

    int _weeks_in_month = ceil((float)(_first_day_of_week + _days_in_month) / 7);

    printf("\tSUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n\n");

    int _counter = 1;
    for (int i = 0; i < _first_day_of_week + _days_in_month; i++) {
        if (i < _first_day_of_week) {
            printf("\t   ");
            continue;
        }

        printf("\t %02d", _counter);
        _counter++;

        if (i % 7 == 6) printf("\n");
    }

    printf("\n\n");
    return;
}

int main() {
    int year, month;

    printf("Year: ");
    scanf_s("%d", &year, sizeof(int));
    printf("Month: ");
    scanf_s("%d", &month, sizeof(int));
    puts("");

    ptrCalendar(year, month);

    return 0;
}