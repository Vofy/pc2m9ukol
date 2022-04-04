#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int month;
    int year;
    float temperature;
} month_t;

typedef struct {
    month_t *data;
    int length;
} month_array_t;

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

month_array_t get_tropical_months(int years, float measurements[][12])
{
    month_t *tropical_months = malloc(10 * sizeof tropical_months);

    int index = 0;
    for(int year = 0; year < years; year++)
        for (int month = 0; month < 12; month++)
            if(measurements[year][month] >= 32)
                tropical_months[index++] = (month_t) { month + 1, year, measurements[year][month] };

    return (month_array_t) { tropical_months, index };
}

month_array_t get_arctic_months(int years, float measurements[][12])
{
    month_t *arctic_months = malloc(10 * sizeof(month_t));

    int index = 0;
    for(int year = 0; year < years; year++)
        for (int month = 0; month < 12; month++)
            if(measurements[year][month] <= -6)
                arctic_months[index++] = (month_t) { month + 1, year, measurements[year][month] };

    return (month_array_t) { arctic_months, index };
}
