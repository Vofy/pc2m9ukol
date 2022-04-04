#ifndef DATA_READ_H_INCLUDED
#define DATA_READ_H_INCLUDED

int resolve_char_type(char c);
int count_lines(FILE *file);
void read_measurements(FILE *file, float measurements[][12]);

#endif // DATA_READ_H_INCLUDED
