typedef struct {
    float *measurements;
    int length;
} t_measurements_array;

typedef struct {
    int month;
    int year;
    float temperature;
} t_month;

typedef struct {
    t_month *data;
    int length;
} t_month_array;