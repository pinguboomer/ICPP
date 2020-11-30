#pragma once

#ifndef MATICE_H
#define MATICE_H

#include <stdexcept>
#include <iostream>

template<typename T>
class Matrix
{
private:
	T** mat;
	int rows;
	int columns;
public:
	Matrix();
	~Matrix();
	Matrix(int rows, int columns);
	Matrix(const Matrix<T>& m);
	void set(int row, int column, T hodnota);
	void setFrom(T* array);
	T& get(int row, int column);
	const T& get(int row, int column) const;	
	Matrix<T> trans() const;
	Matrix<T> multiplication(const Matrix& m) const;
	Matrix<T> multiplication(T scalar) const;
	Matrix<T> sum(const Matrix& m) const;
	Matrix<T> sum(T scalar) const;
	bool isSame(const Matrix& m) const;
	void print() const;

	template<typename R>
	Matrix<R> retype() const;

};

template<typename T>
inline Matrix<T>::Matrix()
{
}

template<typename T>
inline Matrix<T>::~Matrix()
{
	for (int i = 0; i < rows; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}

template<typename T>
inline Matrix<T>::Matrix(int rows, int columns)
{
	if (rows < 1 || columns < 1) {
		throw std::out_of_range("Neplatné rozmìry");
	}

	this->rows = rows;
	this->columns = columns;
	mat = new T* [rows];
	for (int i = 0; i < rows; i++) {
		mat[i] = new T[columns];
		for (int j = 0; j < columns; j++) {
			mat[i][j] = 0;
		}
	}
}

template<typename T>
inline Matrix<T>::Matrix(const Matrix<T>& m)
{
	rows = m.rows;
	columns = m.columns;
	mat = new T * [rows];
	for (int i = 0; i < rows; ++i) {
		mat[i] = new T[columns];
		for (int j = 0; j < columns; j++) {
			mat[i][j] = m.mat[i][j];
		}
	}
}

template<typename T>
inline void Matrix<T>::set(int row, int column, T hodnota)
{
	if (row > rows || column > columns || row < 0 || column < 0) {
		throw std::out_of_range("Neplatný index");
	}
	mat[row][column] = hodnota;
}

template<typename T>
inline void Matrix<T>::setFrom(T* array)
{
	for (int  i = 0; i < rows; i++)
	{
		for (int  j = 0; j < columns; j++)
		{
			mat[i][j] = array[(i * columns) + j];
		}
	}
}

template<typename T>
inline T& Matrix<T>::get(int row, int column)
{
	if (row > rows || column > columns || row < 0 || column < 0) {
		throw std::out_of_range("Neplatný index");
	}
	return mat[row][column];
}

template<typename T>
inline const T& Matrix<T>::get(int row, int column) const
{
	if (row > rows || column > columns || row < 0 || column < 0) {
		throw std::out_of_range("Neplatný index");
	}
	return mat[row][column];
}

template<typename T>
inline Matrix<T> Matrix<T>::trans() const
{
	Matrix<T> transMatrix{ columns, rows };

	for (int i = 0; i < transMatrix.rows; i++) {
		for (int j = 0; j < transMatrix.columns; j++) {
			transMatrix.mat[j][i] = mat[i][j];
		}
	}
	return transMatrix;
}

template<typename T>
inline Matrix<T> Matrix<T>::multiplication(const Matrix& m) const
{

	if (columns != m.rows) {
		throw std::invalid_argument("Nelze provést – špatné rozmìry");
	}

	Matrix<T> newMatrix{ rows, columns };

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < m.columns; j++) {
			T temp = 0;
			for (int k = 0; k < m.rows; k++) {
				temp += mat[i][k] * m.mat[k][j];
			}
			newMatrix.mat[i][j] = temp;
		}
	}
	return newMatrix;
}

template<typename T>
inline Matrix<T> Matrix<T>::multiplication(T scalar) const
{
	Matrix<T> newMatrix{ rows, columns };

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			newMatrix.mat[i][j] = mat[i][j] * scalar;
		}
	}
	return newMatrix;
}

template<typename T>
inline Matrix<T> Matrix<T>::sum(const Matrix& m) const
{
	if (rows != m.rows || columns != m.columns) {
		throw std::invalid_argument("Nelze provést – špatné rozmìry");
	}

	Matrix<T> newMatrix{ rows, columns };

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			newMatrix.mat[i][j] = m.mat[i][j] + mat[i][j];
		}
	}

	return newMatrix;
}

template<typename T>
inline Matrix<T> Matrix<T>::sum(T scalar) const
{
	Matrix<T> newMatrix{ rows, columns };

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			newMatrix.mat[i][j] = mat[i][j] + scalar;
		}
	}

	return newMatrix;
}


template<typename T>
inline bool Matrix<T>::isSame(const Matrix& m) const
{
	if (rows != m.rows || columns != m.columns) {
		return false;
	}
	for (int  i = 0; i < rows; i++){
		for (int  j = 0; j < columns; j++){
			if (mat[i][j] != m.mat[i][j]) {
				return false;
			}
			
		}
	}
	return true;
}

template<typename T>
inline void Matrix<T>::print() const
{
	for (int  i = 0; i < rows; i++)
	{
		for (int  j = 0; j < columns; j++)
		{
			std::cout << mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
}

template<typename T>
template<typename R>
Matrix<R> Matrix<T>::retype() const
{
	Matrix<R> newMatrix{ rows, columns };

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			newMatrix.set(i, j, static_cast<R>(get(i, j)));
		}
	}

	return newMatrix;
}

#endif // !MATICE_H


