#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"

float *get_average_temperatures_in_years(t_measurements_array measurements)
{
    float *average_years = malloc(measurements.length * sizeof(float));

    for(int year = 0; year < measurements.length; year++)
    {
        float year_sum = 0;

        for (int month = 0; month < 12; month++)
            year_sum += measurements.data[year][month];

        average_years[year] = year_sum / 12;
    }

    return average_years;
}

float *get_average_temperatures_in_months(t_measurements_array measurements)
{
    float *average_months = malloc(measurements.length * sizeof(float));

    for (int month = 0; month < 12; month++)
    {
        float month_sum = 0;

        for(int year = 0; year < measurements.length; year++)
            month_sum += measurements.data[year][month];

        average_months[month] = month_sum / 12;
    }

    return average_months;
}

t_month_array get_tropical_months(t_measurements_array measurements)
{
    t_month *tropical_months = malloc(10 * sizeof tropical_months);

    int index = 0;
    for(int year = 0; year < measurements.length; year++)
        for (int month = 0; month < 12; month++)
            if(measurements.data[year][month] >= 32)
                tropical_months[index++] = (t_month) { month + 1, year, measurements.data[year][month] };

    return (t_month_array) { tropical_months, index };
}

t_month_array get_arctic_months(t_measurements_array measurements)
{
    t_month *arctic_months = malloc(10 * sizeof(t_month));

    int index = 0;
    for(int year = 0; year < measurements.length; year++)
        for (int month = 0; month < 12; month++)
            if(measurements.data[year][month] <= -6)
                arctic_months[index++] = (t_month) { month + 1, year, measurements.data[year][month] };

    return (t_month_array) { arctic_months, index };
}
