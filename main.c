#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"
#include "data_read.h"
#include "data_analisys.h"
#include "data_print.h"

const unsigned short int FIRST_YEAR = 1995;

t_date get_date_input(int years_count)
{
    int selected_month, selected_year;
    bool format_is_valid, input_is_valid;

    do {
        printf("Enter month and year to get average temperature (format: 'mm/yyyy'): ");
        format_is_valid = scanf("%d/%d", &selected_month, &selected_year);

        input_is_valid  = (selected_month >= 1 && selected_month <= 12) &&
                          (selected_year > FIRST_YEAR && selected_year < FIRST_YEAR + years_count);
    }
    while((!format_is_valid || !input_is_valid) && printf("Invalid input\n\n\n"));
    printf("\n");

    return (t_date) { selected_month, selected_year };
}

int main()
{
    // Read data

    FILE *input  = fopen("data/input.txt",  "r");
    t_measurements_array measurements = read_measurements(input);
    int years_count = measurements.length;
    fclose(input);


    // Analyze data

    float        *year_averages   = get_average_temperatures_in_years(measurements);
    float        *month_averages  = get_average_temperatures_in_months(measurements);
    t_month_array tropical_months = get_tropical_months(measurements);
    t_month_array arctic_months   = get_arctic_months(measurements);


    // Print data

    FILE *output = fopen("data/output.txt", "w");

    print_measurements(output, measurements);
    print_average_temperature(output, get_date_input(years_count), measurements);
    print_average_temperatures_in_years(output, years_count, year_averages);
    print_average_temperatures_in_months(output, month_averages);
    print_tropical_months(output, &tropical_months);
    print_arctic_months(output, &arctic_months);

    fclose(output);


    // Free memory

    free(year_averages);
    free(month_averages);
    free(measurements.data);
    free(tropical_months.data);
    free(arctic_months.data);


    return 0;
}

