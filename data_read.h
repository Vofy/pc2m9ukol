#ifndef DATA_READ_H_INCLUDED
#define DATA_READ_H_INCLUDED

int resolve_char_type(char c);
int count_lines(FILE *file);
t_measurements_array read_measurements(FILE *file);

#endif // DATA_READ_H_INCLUDED
