// sobol.h

int i4_bit_hi1_base_2 ( int n );
int i4_bit_lo0_base_2 ( int n );
void i4_sobol ( int dim_num, int *seed, float quasi[ ] );
int i8_bit_hi1_base_2 ( long int n );
int i8_bit_lo0_base_2 ( long int n );
void i8_sobol ( int dim_num, long int *seed, double quasi[ ] );
void timestamp ( void );

