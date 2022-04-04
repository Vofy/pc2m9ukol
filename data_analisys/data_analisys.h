#ifndef DATA_ANALISYS_H_INCLUDED
#define DATA_ANALISYS_H_INCLUDED

typedef struct {
    int month;
    int year;
    float temperature;
} month_t;

typedef struct {
    month_t *data;
    int length;
} month_array_t;

float *get_average_temperatures_in_years(int years, float measurements[][12]);
float *get_average_temperatures_in_months(int years, float measurements[][12]);
month_array_t get_tropical_months(int years, float measurements[][12]);
month_array_t get_arctic_months(int years, float measurements[][12]);

#endif // DATA_ANALISYS_H_INCLUDED
