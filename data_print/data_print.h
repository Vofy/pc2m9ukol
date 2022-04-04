#ifndef DATA_PRINT_H_INCLUDED
#define DATA_PRINT_H_INCLUDED

int ofprintf(FILE *file, char format[], ...);

void print_average_temperature(FILE *file, int month, int year, float measurements[][12]);
void print_measurements(FILE *file, int years, float measurements[years][12]);
void print_average_temperatures_in_years(FILE *file, int years, float *average_years);
void print_average_temperatures_in_months(FILE *file, float average_months[]);
void print_tropical_months(FILE *file, month_array_t tropical_months);
void print_arctic_months(FILE *file, month_array_t arctic_months);

#endif // DATA_PRINT_H_INCLUDED
