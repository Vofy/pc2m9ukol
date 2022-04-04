#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "types.h"
#include "data_analisys.h"

extern const unsigned short int FIRST_YEAR;

int ofprintf(FILE *file, char format[], ...)
{
    va_list ap;

    va_start(ap, format);
    vprintf(format, ap);
    va_end(ap);

    va_start(ap, format);
    vfprintf(file, format, ap);
    va_end(ap);

    return 0;
}

void print_measurements(FILE *file, t_measurements_array measurements)
{
    ofprintf(file, "Temperature table:\n\n         JAN   FEB   MAR   APR   MAY   JUN   JUL   AUG   SEP   OCT   NOV   DEC\n");

    for(int year = 0; year < measurements.length; year++)
    {
        ofprintf(file, "%4d: ", FIRST_YEAR + year);

        for (int month = 0; month < 12; month++)
            ofprintf(file, "%6.1f", measurements.data[year][month]);

        ofprintf(file, "\n");
    }

    ofprintf(file, "\n\n");
}


void print_average_temperature(FILE *file, t_date date, t_measurements_array measurements)
{
    ofprintf(file, "Average temperature in %d/%d was %3.1f deg. C.\n\n\n", date.month, date.year, measurements.data[date.year - FIRST_YEAR][date.month - 1]);
}

void print_average_temperatures_in_years(FILE *file, int years, float *average_years)
{
    ofprintf(file, "Average temperature in year:\n\n");

    for(int year = 0; year < years; year++)
    {
        ofprintf(file, "%4d: %4.1f deg. C\n", FIRST_YEAR + year, average_years[year]);
    }

    ofprintf(file, "\n\n");
}

void print_average_temperatures_in_months(FILE *file, float average_months[])
{
    ofprintf(file, "Average temperature in month:\n\n");

    for(int month = 0; month < 12; month++)
    {
        ofprintf(file, "%2d: %4.1f deg. C\n", month + 1, average_months[month]);
    }

    ofprintf(file, "\n\n");
}

void print_tropical_months(FILE *file, t_month_array *months)
{
    ofprintf(file, "Tropical months:\n\n");

    for(int count = 0; count < months -> length; count++)
    {
        ofprintf(file, "%2d/%4d: %4.1f deg. C\n", months -> data[count].month, months -> data[count].year + FIRST_YEAR, months -> data[count].temperature);
    }

    ofprintf(file, "\n\n");
}

void print_arctic_months(FILE *file, t_month_array *months)
{
    ofprintf(file, "Arctic months:\n\n");

    for(int count = 0; count < months -> length; count++)
    {
        ofprintf(file, "%2d/%4d: %4.1f deg. C\n", months -> data[count].month, months -> data[count].year + FIRST_YEAR, months -> data[count].temperature);
    }

    ofprintf(file, "\n\n");
}

