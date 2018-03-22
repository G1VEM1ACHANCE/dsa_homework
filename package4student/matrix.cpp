#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <new>
#include "matrix.h"
int i,j;

Matrix::Matrix(const int& r, const int& c) //constructor
{
	double **array = new double *[r];
	for(int i=0;i<r;i++)
		array[i]=new double [c];
	this-> row = r;
	this-> col = c;
	this-> array = array;
}

Matrix::Matrix(const Matrix& rhs) //copy constructor
{
	double **array = new double *[rhs.row];
	for(int i=0;i<rhs.row;i++)
		array[i]=new double *[rhs.col];
	for(int i=0;i<rhs.row;i++)
		for(int j=0;j<rhs.col;j++)
			array[i][j]=rhs.array[i][j];

	this-> col=rhs.col;
	this-> row=rhs.row;
	this-> array = array;
}

Matrix::~Matrix() //destructor
{
	for(int i=0;i<row;i++)
		delete[] array[i];
	delete array;
}

double* & Matrix::operator [](const int& idx) const
{
	return array[idx];
}

Matrix Matrix::operator =(const Matrix& rhs) // assignment constructor
{
	
}

Matrix Matrix::operator -() const
{
	Matrix temp(row,col);
	for(int i=0;i<row;i++)
		for(int j = 0;j < col; j++)
			temp.array[i][j]=array[i][j]*-1;
	return temp;
}

Matrix Matrix::operator +() const
{
	Matrix temp(row,col);
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			temp.array[i][j]=array[i][j]*1;
	return temp;
}

Matrix Matrix::operator -(const Matrix& rhs) const
{
	Matrix temp(row,col);
	for(int i=0;i<rhs.row;i++)
		for(int j=0;j<rhs.col;j++)
			temp.array[i][j]=array[i][j]-rhs.array[i][j];
	return temp;
}

Matrix Matrix::operator +(const Matrix& rhs) const
{
	Matrix temp (row,col);
	for (int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			temp.array[i][j]+=array[i][j]+rhs[i][j];
}

Matrix Matrix::operator *(const Matrix& rhs) const
{
	Matrix temp (row, col);
	for(int i=0;i<row;i++)
		for(int j=0;j<rhs.col;j++)
			for(int k=0;k<col;k++)
				temp[i][j]=array[i][k]*rhs[k][j];
}

Matrix Matrix::operator /(const Matrix& rhs) const
{
}

Matrix Matrix::inverse() const
{
	Matrix I(row,col);
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
		{
			if(i=j)
				I[i][j]=1;
			else
				I[i][j]=0;
	
}

void Matrix::read(const char* fn)
{
	int r, c;
	FILE *fp = fopen(fn, "r");
	if(fp == NULL){
		printf("read file [%s] error\n", fn);
		exit(0);
	}
	fscanf(fp, "%d%d", &r, &c);
	Matrix tmp(r, c);
	for(int i = 0 ; i < r ; i++)
		for(int j = 0 ; j < c ; j++)
			fscanf(fp, "%lf", &tmp.array[i][j]);
	fclose(fp);
	*this = tmp;
}

void Matrix::write(const char* fn)
{
	FILE *fp = fopen(fn, "w");
	if(fp == NULL){
		printf("write file [%s] error\n", fn);
		exit(0);
	}
	fprintf(fp, "%d %d\n", row, col);
	for(int i = 0 ; i < row ; i++)
		for(int j = 0 ; j < col ; j++)
			fprintf(fp, "%lf%c", array[i][j], " \n"[j==col-1]);
	fclose(fp);
}

void Matrix::print() const
{
	for(int i = 0 ; i < row ; i++)
		for(int j = 0 ; j < col ; j++)
			printf("%lf%c", array[i][j], " \n"[j==col-1]);
}
