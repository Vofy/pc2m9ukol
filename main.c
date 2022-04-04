#include <stdio.h>
#include <stdlib.h>
#include "data_read/data_read.h"
#include "data_analisys/data_analisys.h"
#include "data_print/data_print.h"

int main()
{
    // Read data
    FILE *input  = fopen("data/input.txt",  "r");

    const int years_count = count_lines(input);
    float measurements[years_count][12];

    read_measurements(input, measurements);
    fclose(input);

    // Analyze data
    float        *avyear          = get_average_temperatures_in_years(years_count, measurements);
    float        *avmonth         = get_average_temperatures_in_months(years_count, measurements);
    month_array_t tropical_months = get_tropical_months(years_count, measurements);
    month_array_t arctic_months   = get_arctic_months(years_count, measurements);


    // Print data
    FILE *output = fopen("data/output.txt", "w");

    print_measurements(output, years_count, measurements);

    int selected_month = 1;
    int selected_year  = 1999;
    print_average_temperature(output, selected_month, selected_year, measurements);

    print_average_temperatures_in_years(output, years_count, avyear);
    print_average_temperatures_in_months(output, avmonth);
    print_tropical_months(output, tropical_months);
    print_arctic_months(output, arctic_months);

    fclose(output);

    free(avyear);
    free(avmonth);
    free(tropical_months.data);
    free(arctic_months.data);

    return 0;
}

