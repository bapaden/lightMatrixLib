#include <cstdio>
#include "matrix.h"

int main() 
{
  matrix A(2,2);
  
  A.assign(0,0,1);
  A.assign(0,1,0);
  A.assign(1,0,0);
  A.assign(1,1,1);
  
  A.disp();
  
  int i,j;
  A.size(i,j);
  //printf("Dimension of A: (%d,%d)",i,j);
  
  matrix B(i,j);
  B=A;
  double AdotB = frobProd(A,B);
  printf("AdotB: %f\n",AdotB);
  matrix C(i,j);
  printf("A+B\n");
  C=add(A,B);
  C.disp();
  
  C=subtract(A,B);
  C.disp();
  
  printf("\nA is: ");
  A.disp();
  A.disp();
  C=multiply(A,A);
  printf("\n C is:");
  C.disp();
  
  
  std::vector<double> x,y;
  x.resize(3,1.0);
  y.resize(3,1.0);
  
  disp(x);
  std::vector<double> z = x+y;
  disp(z);
  double c=2.5;
  z=c*z;
  disp(z);
  
  return 0;
}
