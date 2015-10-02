#ifndef MATRIX_H
#define MATRIX_H

#include <cstdio>
#include <vector>
#include <cmath>
#include <cassert>



class matrix
{

typedef std::vector<double> vec;
std::vector<vec> mat;
  
public:
  
  //Public member variables of linAlg
  int numCols;
  int numRows;

  //Constructor
  matrix(int nRow, int nCol)
  {
      //construct object with matrix size
      numRows=nRow;
      numCols=nCol;
      
      //resize the mat member to nRow and nCol
      mat.resize(nRow);//set the number of rows
      
      std::vector<double> genericCol;//put a generic column into each row to get size right
      genericCol.resize(nCol);
      
      for(int i=0;i<nRow;i++)
      {
          mat.at(i)=genericCol;
      };
  }
  
  //Get entry at index
  double index(int rowIndex, int colIndex)
  {
      //Pointer to indexed row
      std::vector<double>* rowPointer;
      rowPointer=&mat.at(rowIndex);
      //Pick out the column entry of that row
      double entry = rowPointer->at(colIndex);
  }
  
  //Assign entry of mat
  void assign(int rowIndex, int colIndex, double value)
  {
      //Pointer to indexed row
      std::vector<double>* rowPointer;
      rowPointer=&mat.at(rowIndex);
      //Pick out the column entry of that row
      rowPointer->at(colIndex)=value;
  }
  
  //Put the size into arguments
  void size(int& rowSize, int& colSize)
  {
      rowSize = numRows;
      colSize = numCols;
  }
  
  //Change the size of matrix
  void resize(int& newRowSize, int& newColSize)
  {
      //construct object with matrix size
      numRows=newRowSize;
      numCols=newColSize;
      
      //resize to the new row dimensions
      mat.resize(newRowSize);//set the number of rows
      //resize to new column dimension
      std::vector<double> genericCol(newColSize);//put a generic column into each row to get size right
      
      for(int i=0;i<newRowSize;i++)
      {
          mat.at(i)=genericCol;
      };
  }
  
};


/*****  Basic Matrix Operations *****/

//Transpose
matrix transpose(matrix& A)
{
  //get the size of A
  int numRows,numCols;
  A.size(numRows,numCols);
     
  //make a matrix B with the dimensions of transpose(A)
  matrix B(numCols,numRows);
  for(int i=0;i<numRows;i++)
  {
    for(int j=0;j<numCols;j++)
    {
      B.assign(j,i,A.index(i,j));
    };
  };
  return B;
}

//Elementwise sum of two matrices
matrix operator+(matrix& A, matrix& B)
{
    //Get the size of A (and B hopefully) to figure out return size
    int numRows,numCols;
    A.size(numRows,numCols);
    matrix C(numRows,numCols);
    
    //entrywise compute Cij=Aij+Bij
    for(int i=0;i<numRows;i++)
    {
        for(int j=0;j<numCols;j++)
        {
            C.assign(i,j,A.index(i,j)+B.index(i,j));
        };
    };
    
    return C;
}

//Elementwise difference of two matrices
matrix operator-(matrix& A, matrix& B)
{
    //Get the size of A (and B hopefully) to figure out return size
    int numRows,numCols;
    A.size(numRows,numCols);
    matrix C(numRows,numCols);
    
    //entrywise compute Cij=Aij+Bij
    for(int i=0;i<numRows;i++)
    {
        for(int j=0;j<numCols;j++)
        {
            C.assign(i,j,A.index(i,j)-B.index(i,j));
        };
    };
    
    return C;
}

//Matrix product
matrix operator*(matrix& A, matrix& B)
{
    //Get the size of A (and B hopefully) to figure out return size
    int aRows,aCols,bRows,bCols;
    
    A.size(aRows,aCols);
    B.size(bRows,bCols);
    
    //Make sure dimensions are compatible
    assert(bRows==aCols);
    
    //Define a matrix which is the the size of the product of A and B
    matrix C(A.numRows,B.numCols);
    
    //entrywise compute Cij=sum_k(Aik+Bkj)
    double entry;
    for(int i=0;i<aRows;i++)
    {
        for(int j=0;j<aCols;j++)
        {
            //sum across colum and row 
            for(int k=0;k<A.numCols;k++)
            {
                entry=entry+A.index(i,k)*B.index(k,j);
            };
            C.assign(i,j,entry);
            entry=0;
        };
    };
    
    return C;
}

//Get the inner product of two matrices as a vector
double frobProd(matrix& A,matrix& B)
{
    //if(A.numCols != B.numCols || A.numRows != B.numRows)
    //{
    //  printf("\nMatrix dimension mismatch in frobProd\n");
    //};
    
    double innerProduct=0;
    for(int i=0;i<A.numRows;i++)
    {
        for(int j=0;j<A.numCols;j++)
        {
            innerProduct=innerProduct+A.index(i,j)*B.index(i,j);
        };
    };
    
    
    return innerProduct;
}

//Get the ith column of A
matrix column(matrix& A, const int& colIndex)
{
    matrix col(A.numRows,1);

    for(int i=0;i<A.numRows;i++)
    {
        col.assign(i,0,A.index(i,colIndex));  
    };
    return col;
    
}

//Get the jth row of A
matrix row(matrix& A, const int& rowIndex)
{
    matrix col(1,A.numCols);
    
    for(int i=0;i<A.numCols;i++)
    {
        col.assign(0,i,A.index(rowIndex,i));
    };
    
    return col;
}

//Print the matrix to the terminal
void disp(matrix& A)
{
    printf("\nPrinting Matrix Object:\n\n");
    for(int i=0;i<A.numRows;i++)
    {
        matrix aRow = row(A,i);
        for(int j=0;j<A.numCols;j++)
        {
            printf("%4.2f ",aRow.index(0,j));
        };
        printf("\n");
    };
    printf("\n");
}

/*** Vector Operations ***/

std::vector<double> operator+(const std::vector<double>& x, const std::vector<double>& y)
{
    assert(x.size()==y.size());
    std::vector<double> z(x.size());
    for(int i=0;i<x.size();i++)
    {
        z.at(i)=x.at(i)+y.at(i);
    }
    
    return z;
}

std::vector<double> operator-(const std::vector<double>& x, const std::vector<double>& y)
{
    assert(x.size()==y.size());
    std::vector<double> z(x.size());
    for(int i=0;i<x.size();i++)
    {
        z.at(i)=x.at(i)-y.at(i);
    }
    
    return z;
}

std::vector<double> operator*(const double& c, const std::vector<double>& x)
{
    std::vector<double> z(x.size());
    for(int i=0;i<x.size();i++)
    {
        z.at(i)=c*x.at(i);
    }
    
    return z;
}

void disp(std::vector<double>& x)
{
    printf("vector:\n");
    for(int i=0;i<x.size();i++)
    {
        printf("%f\n",x.at(i));
    }
}




#endif