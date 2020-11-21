
void printMatrix(double**& m, size_t& rows, size_t& cols);
void read_new(double**& m, size_t& rows, size_t& cols);
void delete_matrix(double**& m, size_t& rows, size_t& cols);
double sum(double**& m, size_t& rows, size_t& cols);
void newcolum(double**& m, size_t& rows, size_t& cols);
void max_del(double**& m, size_t& rows, size_t& cols);
void print_func(bool (*f)(double*, size_t), double**& m, size_t& rows, size_t& cols);
bool check_row(double* row, size_t len);