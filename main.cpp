#include <cstdio>
#include "matrix.h"

int main() 
{
  matrix A(2,2);
  
  A.assign(0,0,1.0);
  A.assign(0,1,0.0);
  A.assign(1,0,0.0);
  A.assign(1,1,1.0);
  
  matrix B(2,2);
  
  B.assign(0,0,1.0);
  B.assign(0,1,1.0);
  B.assign(1,0,1.0);
  B.assign(1,1,1.0);
  
  printf("A:");
  disp(A);
  
  printf("B:");
  disp(B);
  
  int i,j;
  A.size(i,j);
  
  double AdotB = frobProd(A,B);
  printf("<A,B>: %f\n",AdotB);
  matrix C(i,j);
  printf("A+B\n");
  C=A+B;
  disp(C);
  
  printf("A-B\n");
  C=A-B;
  disp(C);
  
  C=A*B;
  printf("\n A*B is:");
  disp(C);
  
  
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
