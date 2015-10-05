#include <cstdio>
#include "matrix.h"

int main() 
{
  matrix A(2,2);
  
  A.assign(0,0,1.0);
  A.assign(0,1,2.0);
  A.assign(1,0,3.0);
  A.assign(1,1,4.0);
  
  matrix B(2,2);
  
  B=identity(2);
  
  printf("A:");
  disp(A);
  
  printf("B:");
  disp(B);
  
  std::vector<double> s(2);
  s.at(0)=1;
  s.at(1)=1;
  
  int n = 5;
  
  
  
  B=exp(B);
  disp(B);
  printf("maxRS %f\n",spectralRadius(B));
  
  std::vector<double> w=A*s;
  disp(w);
  
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
  
  
  
  return 0;
}
