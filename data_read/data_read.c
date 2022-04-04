#include <stdio.h>
#include <stdlib.h>

enum char_type
{
    PART_OF_NUMBER,
    SEPARATOR,
    END_OF_LINE,
    UNDEFINED
};

int resolve_char_type(char c)
{
    if(('0' <= c && c <= '9') || c == '.' || c == '-')
        return PART_OF_NUMBER;
    else if(c == ',' || c == EOF)
        return SEPARATOR;
    else if(c == '\n')
        return END_OF_LINE;

    return UNDEFINED;
}

int count_lines(FILE *file)
{
    char c;
    int lines = 0;

    do
    {
        c = fgetc(file);
        if(c == '\n') lines++;
    }
    while (c != EOF);

    fseek(file, 0, SEEK_SET);

    return lines + 1;
}

void read_measurements(FILE *file, float measurements[][12])
{
    char c;

    char cislo[6];              // Buffer pro jednotliva cisla
    int  cislo_n = 0;           // Poradi cisla v bufferu pro jednotliva cisla

    int  year = 0, month = 0;   // Pocitadla pro pohyb v poli

    do
    {
        c = fgetc(file);
        int c_char_type = resolve_char_type(c);

        if(c_char_type == PART_OF_NUMBER)
            cislo[cislo_n++] = c;

        else if(c_char_type == SEPARATOR)
        {
            cislo[cislo_n + 1] = '\0';
            cislo_n = 0;

            measurements[year][month] = atof(cislo);
            month++;
        }

        else if(c_char_type == END_OF_LINE || month > 12)
        {
            year++;
            month = 0;
        }
    }
    while (c != EOF);
}
