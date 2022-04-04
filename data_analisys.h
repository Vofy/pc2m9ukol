#ifndef DATA_ANALISYS_H_INCLUDED
#define DATA_ANALISYS_H_INCLUDED

#include "types.h"

float *get_average_temperatures_in_years(t_measurements_array measurements);
float *get_average_temperatures_in_months(t_measurements_array measurements);
t_month_array get_tropical_months(t_measurements_array measurements);
t_month_array get_arctic_months(t_measurements_array measurements);

#endif // DATA_ANALISYS_H_INCLUDED
