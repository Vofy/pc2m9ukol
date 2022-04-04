#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"

float *get_average_temperatures_in_years(int years, float measurements[][12])
{
    float *average_years = malloc(years * sizeof(float));

    for(int year = 0; year < years; year++)
    {
        float year_sum = 0;

        for (int month = 0; month < 12; month++)
            year_sum += measurements[year][month];

        average_years[year] = year_sum / 12;
    }

    return average_years;
}

float *get_average_temperatures_in_months(int years, float measurements[][12])
{
    float *average_months = malloc(years * sizeof(float));

    for (int month = 0; month < 12; month++)
    {
        float month_sum = 0;

        for(int year = 0; year < years; year++)
            month_sum += measurements[year][month];

        average_months[month] = month_sum / 12;
    }

    return average_months;
}

t_month_array get_tropical_months(int years, float measurements[][12])
{
    t_month *tropical_months = malloc(10 * sizeof tropical_months);

    int index = 0;
    for(int year = 0; year < years; year++)
        for (int month = 0; month < 12; month++)
            if(measurements[year][month] >= 32)
                tropical_months[index++] = (t_month) { month + 1, year, measurements[year][month] };

    return (t_month_array) { tropical_months, index };
}

t_month_array get_arctic_months(int years, float measurements[][12])
{
    t_month *arctic_months = malloc(10 * sizeof(t_month));

    int index = 0;
    for(int year = 0; year < years; year++)
        for (int month = 0; month < 12; month++)
            if(measurements[year][month] <= -6)
                arctic_months[index++] = (t_month) { month + 1, year, measurements[year][month] };

    return (t_month_array) { arctic_months, index };
}
