#include "ECSquareMat.h"
#include <iostream>
using namespace std;


ECSquareMat :: ECSquareMat(int nDim)     // nDim: dimension of matrix (number of rows or columns)
{ 
    listMatEntries.resize(nDim);
    for(int i = 0; i < listMatEntries.size(); ++i)
    {
        listMatEntries[i].resize(nDim);
    }   
}
ECSquareMat :: ECSquareMat(const ECSquareMat &rhs)
{
    listMatEntries = rhs.listMatEntries;
}
ECSquareMat :: ~ECSquareMat()
{
}    
int ECSquareMat :: GetDimension() const
{
    return listMatEntries.size();
}
void ECSquareMat :: SetValAt(int nRow, int nCol, int val)
{
    listMatEntries[nRow][nCol] = val;
}
int ECSquareMat :: GetValAt(int nRow, int nCol) const
{
    return listMatEntries[nRow][nCol];
}
ECSquareMat ECSquareMat :: operator+(const ECSquareMat &rhs)
{
    ECSquareMat temp = ECSquareMat(rhs.GetDimension());
    for(int i = 0; i < temp.listMatEntries.size(); ++i)
    {
        for(int k = 0; k < temp.listMatEntries[i].size(); ++k)
        {
            temp.listMatEntries[i][k] = listMatEntries[i][k] + rhs.listMatEntries[i][k];
        }
    }
    return temp;
}
ECSquareMat ECSquareMat :: operator*(const ECSquareMat &rhs)
{
    ECSquareMat temp = ECSquareMat(rhs.GetDimension());
    for(int i = 0; i < temp.listMatEntries.size(); ++i)
    {
        for(int k = 0; k < temp.listMatEntries.size(); ++k)
        {
            temp.listMatEntries[i][k] = 0;
            for(int p = 0; p < temp.listMatEntries.size(); ++p)
            {
                temp.listMatEntries[i][k] += listMatEntries[i][p] * rhs.listMatEntries[p][k];
            }
        }
    }
    return temp;
}
ECSquareMat & ECSquareMat :: operator=(const ECSquareMat &rhs)
{
    for(int i = 0; i < listMatEntries.size(); ++i)
    {
        for(int k = 0; k < listMatEntries.size(); ++k)
        {
            listMatEntries[i][k] = rhs.listMatEntries[i][k];
        }
    }
}