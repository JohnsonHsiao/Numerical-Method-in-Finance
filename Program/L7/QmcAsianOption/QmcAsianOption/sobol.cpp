#include <stdafx.h>
# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <ctime>

using namespace std;

# include "sobol.h"

//******************************************************************************

int i4_bit_hi1_base_2 ( int n )

//******************************************************************************
//
//  Purpose:
//
//    I4_BIT_HI1_BASE_2 returns the position of the high 1 bit base 2 in an integer.
//

//      17       10001     5

{
  int bit;

  bit = 0;

  while ( 0 < n )
  {
    bit = bit + 1;
    n = n / 2;
  }

  return bit;
}
//******************************************************************************

int i4_bit_lo0_base_2 ( int n )

//******************************************************************************
//
//  Purpose:
//
//    I4_BIT_LO0_BASE_2 returns the position of the low 0 bit base 2 in an integer.
//

//       1           1     2
//       2          10     1

//      15        1111     5
//      16       10000     1

{
  int bit;
  int n2;

  bit = 0;

  while ( true )
  {
    bit = bit + 1;
    n2 = n / 2;

    if ( n == 2 * n2 )
    {
      break;
    }

    n = n2;

  }

  return bit;
}
//******************************************************************************

void i4_sobol ( int dim_num, int *seed, float quasi[ ] )


{
# define DIM_MAX 52

  static int atmost = 1073741823;
  static int dim_num_save = 0;
  int i;
  int i2;
  bool includ[9];
  static bool initialized = false;
  int j;
  int j2;
  int k;
  int l;
  static int lastq[DIM_MAX];
  int m;
  static int maxcol;
  int newv;
  static int poly[DIM_MAX] =
  {
        1,   3,   7,  11,  13,  19,  25,  37,  59,  47,
       61,  55,  41,  67,  97,  91, 109, 103, 115, 131,
      193, 137, 145, 143, 241, 157, 185, 167, 229, 171,
      213, 191, 253, 203, 211, 239, 247, 285, 369, 299,
      333, 351, 355, 357, 361, 369, 391, 397, 425, 451,
      463, 487
  };
  static float recipd;
  static int seed_save = 0;
  int seed_temp;
  static int v[DIM_MAX][30];
//
  if ( !initialized || dim_num != dim_num_save )
  {
    initialized = true;
//
//  Initialize (part of) V.
//
    v[ 0][0] = 1;
    v[ 1][0] = 1;
    v[ 2][0] = 1;
    v[ 3][0] = 1;
    v[ 4][0] = 1;
    v[ 5][0] = 1;
    v[ 6][0] = 1;
    v[ 7][0] = 1;
    v[ 8][0] = 1;
    v[ 9][0] = 1;
    v[10][0] = 1;
    v[11][0] = 1;
    v[12][0] = 1;
    v[13][0] = 1;
    v[14][0] = 1;
    v[15][0] = 1;
    v[16][0] = 1;
    v[17][0] = 1;
    v[18][0] = 1;
    v[19][0] = 1;
    v[20][0] = 1;
    v[21][0] = 1;
    v[22][0] = 1;
    v[23][0] = 1;
    v[24][0] = 1;
    v[25][0] = 1;
    v[26][0] = 1;
    v[27][0] = 1;
    v[28][0] = 1;
    v[29][0] = 1;
    v[30][0] = 1;
    v[31][0] = 1;
    v[32][0] = 1;
    v[33][0] = 1;
    v[34][0] = 1;
    v[35][0] = 1;
    v[36][0] = 1;
    v[37][0] = 1;
    v[38][0] = 1;
    v[39][0] = 1;
    v[40][0] = 1;
    v[41][0] = 1;
    v[42][0] = 1;
    v[43][0] = 1;
    v[44][0] = 1;
    v[45][0] = 1;
    v[46][0] = 1;
    v[47][0] = 1;
    v[48][0] = 1;
    v[49][0] = 1;
    v[50][0] = 1;
    v[51][0] = 1;
    





    v[ 2][1] = 1;
    v[ 3][1] = 3;
    v[ 4][1] = 1;
    v[ 5][1] = 3;
    v[ 6][1] = 1;
    v[ 7][1] = 3;
    v[ 8][1] = 3;
    v[ 9][1] = 1;
    v[10][1] = 1;
    v[11][1] = 3;
    v[12][1] = 3;
    v[13][1] = 1;
    v[14][1] = 1;
    v[15][1] = 3;
    v[16][1] = 1;
    v[17][1] = 1;
    v[18][1] = 3;
    v[19][1] = 3;
    v[20][1] = 3;
    v[21][1] = 3;
    v[22][1] = 3;
    v[23][1] = 1;
    v[24][1] = 3;
    v[25][1] = 1;
    v[26][1] = 1;
    v[27][1] = 1;
    v[28][1] = 3;
    v[29][1] = 1;
    v[30][1] = 3;
    v[31][1] = 1;
    v[32][1] = 1;
    v[33][1] = 3;
    v[34][1] = 1;
    v[35][1] = 3;
    v[36][1] = 1;
    v[37][1] = 3;
    v[38][1] = 1;
    v[39][1] = 3;
    v[40][1] = 1;
    v[41][1] = 3;
    v[42][1] = 3;
    v[43][1] = 1;
    v[44][1] = 3;
    v[45][1] = 1;
    v[46][1] = 1;
    v[47][1] = 3;
    v[48][1] = 3;
    v[49][1] = 1;
    v[50][1] = 3;
    v[51][1] = 1;
    


    v[ 3][2] = 7;
    v[ 4][2] = 5;
    v[ 5][2] = 1;
    v[ 6][2] = 3;
    v[ 7][2] = 3;
    v[ 8][2] = 7;
    v[ 9][2] = 5;
    v[10][2] = 7;
    v[11][2] = 7;
    v[12][2] = 5;
    v[13][2] = 1;
    v[14][2] = 3;
    v[15][2] = 3;
    v[16][2] = 7;
    v[17][2] = 1;
    v[18][2] = 5;
    v[19][2] = 1;
    v[20][2] = 1;
    v[21][2] = 3;
    v[22][2] = 7;
    v[23][2] = 3;
    v[24][2] = 1;
    v[25][2] = 5;
    v[26][2] = 3;
    v[27][2] = 7;
    v[28][2] = 5;
    v[29][2] = 1;
    v[30][2] = 5;
    v[31][2] = 7;
    v[32][2] = 1;
    v[33][2] = 5;
    v[34][2] = 7;
    v[35][2] = 7;
    v[36][2] = 5;
    v[37][2] = 1;
    v[38][2] = 3;
    v[39][2] = 3;
    v[40][2] = 5;
    v[41][2] = 7;
    v[42][2] = 1;
    v[43][2] = 3;
    v[44][2] = 7;
    v[45][2] = 1;
    v[46][2] = 3;
    v[47][2] = 5;
    v[48][2] = 1;
    v[49][2] = 3;
    v[50][2] = 5;
    v[51][2] = 7;
    




    v[ 5][3] =  1;
    v[ 6][3] =  7;
    v[ 7][3] =  9;
    v[ 8][3] = 7;
    v[ 9][3] = 11;
    v[10][3] =  3;
    v[11][3] =  13;
    v[12][3] =  1;
    v[13][3] =  9;
    v[14][3] =  13;
    v[15][3] = 5;
    v[16][3] = 13;
    v[17][3] = 3;
    v[18][3] =  11;
    v[19][3] = 7;
    v[20][3] =  15;
    v[21][3] =  3;
    v[22][3] = 9;
    v[23][3] =  15;
    v[24][3] =  9;
    v[25][3] = 5;
    v[26][3] =  1;
    v[27][3] =  7;
    v[28][3] = 5;
    v[29][3] =  15;
    v[30][3] =  15;
    v[31][3] = 11;
    v[32][3] =  1;
    v[33][3] = 15;
    v[34][3] = 11;
    v[35][3] =  5;
    v[36][3] =  3;
    v[37][3] =  1;
    v[38][3] =  7;
    v[39][3] =  9;
    v[40][3] = 5;
    v[41][3] = 7;
    v[42][3] = 9;
    v[43][3] = 11;
    v[44][3] = 13;
    v[45][3] = 15;
    v[46][3] = 1;
    v[47][3] = 3;
    v[48][3] = 7;
    v[49][3] = 9;
    v[50][3] = 11;
    v[51][3] = 13;
    




    v[ 7][4] =  9;
    v[ 8][4] =  21;
    v[ 9][4] = 27;
    v[10][4] = 29;
    v[11][4] = 3;
    v[12][4] = 15;
    v[13][4] = 23;
    v[14][4] = 11;
    v[15][4] = 19;
    v[16][4] = 25;
    v[17][4] =  13;
    v[18][4] = 7;
    v[19][4] = 3;
    v[20][4] =  17;
    v[21][4] = 25;
    v[22][4] = 31;
    v[23][4] =  29;
    v[24][4] = 5;
    v[25][4] = 1;
    v[26][4] =  23;
    v[27][4] = 19;
    v[28][4] = 21;
    v[29][4] = 5;
    v[30][4] = 17;
    v[31][4] =  13;
    v[32][4] =  1;
    v[33][4] = 17;
    v[34][4] = 13;
    v[35][4] =  7;
    v[36][4] = 15;
    v[37][4] =  9;
    v[38][4] = 31;
    v[39][4] =  9;
    v[40][4] = 21;
    v[41][4] = 23;
    v[42][4] = 25;
    v[43][4] = 27;
    v[44][4] = 29;
    v[45][4] = 31;
    v[46][4] = 1;
    v[47][4] = 3;
    v[48][4] = 7;
    v[49][4] = 9;
    v[50][4] = 11;
    v[51][4] = 13;
   



    v[13][5] = 37;
    v[14][5] = 7;
    v[15][5] =  33;
    v[16][5] =  5;
    v[17][5] = 39;
    v[18][5] = 11;
    v[19][5] = 23;
    v[20][5] = 63;
    v[21][5] = 17;
    v[22][5] = 29;
    v[23][5] = 15;
    v[24][5] = 21;
    v[25][5] =  27;
    v[26][5] = 13;
    v[27][5] = 25;
    v[28][5] = 9;
    v[29][5] = 49;
    v[30][5] =  19;
    v[31][5] = 29;
    v[32][5] = 33;
    v[33][5] = 19;
    v[34][5] = 29;
    v[35][5] = 11;
    v[36][5] = 19;
    v[37][5] = 27;
    v[38][5] = 15;
    v[39][5] = 25;
    v[40][5] = 21;
    v[41][5] = 27;
    v[42][5] = 3;
    v[43][5] = 13;
    v[44][5] = 5;
    v[45][5] = 27;
    v[46][5] = 13;
    v[47][5] = 13;
    v[48][5] = 27;
    v[49][5] = 21;
    v[50][5] = 5;
    v[51][5] = 1;
   





    v[19][6] =  79;
    v[20][6] =  13;
    v[21][6] = 115;
    v[22][6] =  41;
    v[23][6] =  17;
    v[24][6] =  41;
    v[25][6] = 119;
    v[26][6] = 33;
    v[27][6] =  75;
    v[28][6] =  105;
    v[29][6] = 7;
    v[30][6] =   59;
    v[31][6] =  21;
    v[32][6] =  65;
    v[33][6] =  21;
    v[34][6] =   3;
    v[35][6] = 113;
    v[36][6] =  61;
    v[37][6] =  89;
    v[38][6] =  45;
    v[39][6] = 107;
    v[40][6] = 41;
    v[41][6] = 63;
    v[42][6] = 9;
    v[43][6] = 23;
    v[44][6] = 49;
    v[45][6] = 55;
    v[46][6] = 19;
    v[47][6] = 61;
    v[48][6] = 29;
    v[49][6] = 17;
    v[50][6] = 55;
    v[51][6] = 17;
    

    v[37][7] =  7;
    v[38][7] = 23;
    v[39][7] = 39;
    v[40][7] = 99;
    v[41][7] = 47;
    v[42][7] = 19;
    v[43][7] = 9;
    v[44][7] = 85;
    v[45][7] = 17;
    v[46][7] = 95;
    v[47][7] = 123;
    v[48][7] = 45;
    v[49][7] = 103;
    v[50][7] = 51;
    v[51][7] = 115;
    

    


//
//  Check parameters.
//
    if ( dim_num < 2 || DIM_MAX < dim_num )
    {
      cout << "\n";
      cout << "I4_SOBOL - Fatal error!\n";
      cout << "  The spatial dimension DIM_NUM should satisfy:\n";
      cout << "    2 <= DIM_NUM <= " << DIM_MAX << "\n";
      cout << "  But this input value is DIM_NUM = " << dim_num << "\n";
      exit ( 1 );
    }

    dim_num_save = dim_num;
//
//  Find the number of bits in ATMOST.
//
    maxcol = i4_bit_hi1_base_2 ( atmost );
//
//  Initialize row 1 of V.
//
    for ( j = 1; j <= maxcol; j++ )
    {
      v[1-1][j-1] = 1;
    }
//
//  Initialize the remaining rows of V.
//
    for ( i = 1; i < dim_num; i++ )
    {
//
//  The bit pattern of the integer POLY(I) gives the form
//  of polynomial I.
//
//  Find the degree of polynomial I from binary encoding.
//
      j = poly[i];
      m = 0;

      while ( true )
      {
        j = j / 2;
        if ( j <= 0 )
        {
          break;
        }
        m = m + 1;
      }
//
//  We expand this bit pattern to separate components
//  of the logical array INCLUD.
//
      j = poly[i];
      for ( k = m-1; k >= 0; k-- )
      {
        j2 = j / 2;
        includ[k] = ( j != ( 2 * j2 ) );
        j = j2;
      }
//
//  Calculate the remaining elements of row I as explained
//  in Bratley and Fox, section 2.
//
//  Some tricky indexing here.  Did I change it correctly?
//
      for ( j = m; j < maxcol; j++ )
      {
        newv = v[i][j-m];
        l = 1;

        for ( k = 0; k < m; k++ )
        {
          l = 2 * l;

          if ( includ[k] )
          {
            newv = ( newv ^ ( l * v[i][j-k-1] ) );
          }

        }

        v[i][j] = newv;

      }

    }
//
//  Multiply columns of V by appropriate power of 2.
//
    l = 1;
    for ( j = maxcol-2; j >= 0; j-- )
    {
      l = 2 * l;
      for ( i = 0; i < dim_num; i++ )
      {
        v[i][j] = v[i][j] * l;
      }
    }
//
//  RECIPD is 1/(common denominator of the elements in V).
//
    recipd = 1.0E+00 / ( ( float ) ( 2 * l ) );
  }

  if ( *seed < 0 )
  {
    *seed = 0;
  }

  if ( *seed == 0 )
  {
    l = 1;
    for ( i = 0; i < dim_num; i++ )
    {
      lastq[i] = 0;
    }
  }
  else if ( *seed == seed_save + 1 )
  {
    l = i4_bit_lo0_base_2 ( *seed );
  }
  else if ( *seed <= seed_save )
  {
    seed_save = 0;
    l = 1;
    for ( i = 0; i < dim_num; i++ )
    {
      lastq[i] = 0;
    }

    for ( seed_temp = seed_save; seed_temp <= (*seed)-1; seed_temp++ )
    {

      l = i4_bit_lo0_base_2 ( seed_temp );

      for ( i = 0; i < dim_num; i++ )
      {
        lastq[i] = ( lastq[i] ^ v[i][l-1] );
      }

    }

    l = i4_bit_lo0_base_2 ( *seed );
  }
  else if ( seed_save+1 < *seed )
  {
    for ( seed_temp = seed_save+1; seed_temp <= (*seed)-1; seed_temp++ )
    {

      l = i4_bit_lo0_base_2 ( seed_temp );

      for ( i = 0; i < dim_num; i++ )
      {
        lastq[i] = ( lastq[i] ^ v[i][l-1] );
      }

    }

    l = i4_bit_lo0_base_2 ( *seed );

  }

//
//  Calculate the new components of QUASI.
//  The caret indicates the bitwise exclusive OR.
//
  for ( i = 0; i < dim_num; i++ )
  {
    quasi[i] = ( ( float ) lastq[i] ) * recipd;

    lastq[i] = ( lastq[i] ^ v[i][l-1] );
  }

  seed_save = *seed;
  *seed = *seed + 1;

  return;
# undef MAX_DIM
}

