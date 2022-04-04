#ifndef DATA_ANALISYS_H_INCLUDED
#define DATA_ANALISYS_H_INCLUDED

#include "types.h"

float *get_average_temperatures_in_years(int years, float measurements[][12]);
float *get_average_temperatures_in_months(int years, float measurements[][12]);
t_month_array get_tropical_months(int years, float measurements[][12]);
t_month_array get_arctic_months(int years, float measurements[][12]);

#endif // DATA_ANALISYS_H_INCLUDED
