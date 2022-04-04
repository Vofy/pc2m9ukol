#ifndef DATA_PRINT_H_INCLUDED
#define DATA_PRINT_H_INCLUDED

void print_measurements(FILE *file, t_measurements_array measurements);
void print_average_temperature(FILE *file, t_date date, t_measurements_array measurements);
void print_average_temperatures_in_years(FILE *file, int years, float *average_years);
void print_average_temperatures_in_months(FILE *file, float average_months[]);
void print_tropical_months(FILE *file, t_month_array *months);
void print_arctic_months(FILE *file, t_month_array *months);

#endif // DATA_PRINT_H_INCLUDED
