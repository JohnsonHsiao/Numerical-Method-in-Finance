#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double Max(double a, double b)
{
  if(a > b)  return a;
  else return b;
}

double vanilla_option(float S, float T, float X, float r, float Sigma, int n)
{
  // Calculate parameters
  double U, D, Pu, Pd, DeltaT;
  DeltaT = T/n;
  U = exp(Sigma*sqrt(DeltaT));
  D = exp(-Sigma*sqrt(DeltaT));
  Pu = (exp(r*DeltaT) - D) / (U - D);
  Pd = 1 - Pu;

  // Calculate payoff at final period
  double Array[500];
  double CurrentS = S*pow(U, n);
  for(int i = 0; i <= n; i=i+1)
  {
    Array[i] = Max(CurrentS - X, 0);
    CurrentS = CurrentS * D * D;
  }

  // Backward Induction
  for(int i = n-1; i >= 0; i = i - 1)
  {
    for(int j = 0; j <= i; j++)
    {
      Array[j] = exp(-r * DeltaT) * (Array[j] * Pu + Array[j + 1] * Pd);
    }
  }

  return Array[0];
}

double down_and_out_option(float S, float T, float X, float H, float r, float Sigma, int n)
{
  // Calculate parameters
  double U, D, Pu, Pd, DeltaT;
  DeltaT = T/n;
  U = exp(Sigma*sqrt(DeltaT));
  D = exp(-Sigma*sqrt(DeltaT));
  Pu = (exp(r*DeltaT) - D) / (U - D);
  Pd = 1 - Pu;

  // Calculate barrier step
  int u_power;
  u_power = (int)floor(log(H/S)/log(U));

  // Calculate payoff at final period
  double Array[500];
  double CurrentS = S*pow(U, n);
  for(int i = 0; i <= n; i=i+1)
  {
    Array[i] = Max(CurrentS - X, 0);
    CurrentS = CurrentS * D * D;
  }
  
  if((((n - u_power) % 2) == 0) && (u_power >= -n) && (u_power <= n)) 
  {
    Array[(n - u_power) / 2] = 0;
  }
  
  // Backward Induction
  for(int i = n-1; i >= 0; i = i - 1)
  {
    for(int j = 0; j <= i; j++)
    {
      Array[j] = exp(-r * DeltaT) * (Array[j] * Pu + Array[j + 1] * Pd);
    }
    
    if((((i - u_power) % 2) == 0) && (u_power >= -i) && (u_power <= i)) 
    {
      Array[(i - u_power) / 2] = 0;
    }
  }
  
  return Array[0];
}

int main()
{
  // Input data
  float S, T, X, H, r, Sigma; 
  int n; // periods
  printf("輸入標的物價格:");
  scanf("%f",&S);
  printf("輸入到期日:");
  scanf("%f",&T);
  printf("輸入履約價格:");
  scanf("%f",&X);
  printf("輸入障礙價格:");
  scanf("%f",&H);
  printf("輸入無風險利率:");
  scanf("%f",&r);
  printf("輸入標的物價格波動率:");
  scanf("%f",&Sigma);
  printf("輸入期數:");
  scanf("%d",&n);
  
  // Calculate vanilla and down-and-out option prices
  double vanillaPrice = vanilla_option(S, T, X, r, Sigma, n);
  double downAndOutPrice = down_and_out_option(S, T, X, H, r, Sigma, n);
  
  // Down-and-in price = vanilla price - down-and-out price
  double downAndInPrice = vanillaPrice - downAndOutPrice;

  printf("Down-and-in 選擇權價格=%f\n", downAndInPrice);
  return 0;
}
