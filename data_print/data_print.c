#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "../data_analisys/data_analisys.h"

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

void print_average_temperature(FILE *file, int month, int year, float measurements[][12])
{
    ofprintf(file, "Average temperature in %d/%d was %f deg. C.\n\n\n", month, year/*, measurements[year][month - 1]*/);
}

void print_measurements(FILE *file, int years, float measurements[years][12])
{
    ofprintf(file, "Temperature table:\n\n         JAN   FEB   MAR   APR   MAY   JUN   JUL   AUG   SEP   OCT   NOV   DEC\n");

    for(int year = 0; year < years; year++)
    {
        ofprintf(file, "%4d: ", 1995 + year);

        for (int month = 0; month < 12; month++)
            ofprintf(file, "%6.1f", measurements[year][month]);

        ofprintf(file, "\n");
    }

    ofprintf(file, "\n\n");
}

void print_average_temperatures_in_years(FILE *file, int years, float *average_years)
{
    ofprintf(file, "Average temperature in year:\n\n");

    for(int year = 0; year < years; year++)
    {
        ofprintf(file, "%4d: %4.1f deg. C\n", 1995 + year, average_years[year]);
    }

    ofprintf(file, "\n\n");
}

void print_average_temperatures_in_months(FILE *file, float average_months[])
{
    ofprintf(file, "Average temperature in month (in period 1995-2010):\n\n");

    for(int month = 0; month < 12; month++)
    {
        ofprintf(file, "%2d: %4.1f deg. C\n", month + 1, average_months[month]);
    }

    ofprintf(file, "\n\n");
}

void print_tropical_months(FILE *file, month_array_t months)
{
    ofprintf(file, "Tropical months:\n\n");

    for(int count = 0; count < months.length; count++)
    {
        ofprintf(file, "%2d/%4d: %4.1f deg. C\n", months.data[count].month, months.data[count].year + 1995, months.data[count].temperature);
    }

    ofprintf(file, "\n\n");
}

void print_arctic_months(FILE *file, month_array_t months)
{
    ofprintf(file, "Arctic months:\n\n");

    for(int count = 0; count < months.length; count++)
    {
        ofprintf(file, "%2d/%4d: %4.1f deg. C\n", months.data[count].month, months.data[count].year + 1995, months.data[count].temperature);
    }

    ofprintf(file, "\n\n");
}

