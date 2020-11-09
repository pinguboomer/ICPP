#pragma once

#ifndef INCREASINGCONTAINER_H
#define INCREASINGCONTAINER_H

#include <stdexcept>

template<typename DataType, int startingValue = 5, int increasingCoefficient = 2>
class IncreasingContainer {
private:
	DataType* _array;
	unsigned _arraySize;
	unsigned _numberOfValidNodes;
public:
	IncreasingContainer();
	~IncreasingContainer();
	bool isSpaceInArray() const;
	void increaseArray();
	void add(const DataType& o);
	DataType& operator[](int index);
	DataType operator[](int index) const;
	unsigned int quantity() const;

	void addToIndex(int index, const DataType& o);
	void remove(int index);

};

#endif

template<typename DataType, int startingValue, int increasingCoefficient>
inline IncreasingContainer<DataType, startingValue, increasingCoefficient>::IncreasingContainer()
{
	this->_arraySize = startingValue;
	this->_numberOfValidNodes = 0;
	this->_array = new DataType[_arraySize];
}

template<typename DataType, int startingValue, int increasingCoefficient>
inline IncreasingContainer<DataType, startingValue, increasingCoefficient>::~IncreasingContainer()
{
	delete[] _array;
}

template<typename DataType, int startingValue, int increasingCoefficient>
inline bool IncreasingContainer<DataType, startingValue, increasingCoefficient>::isSpaceInArray() const
{
	return _numberOfValidNodes < _arraySize;
}

template<typename DataType, int startingValue, int increasingCoefficient>
inline void IncreasingContainer<DataType, startingValue, increasingCoefficient>::increaseArray()
{
	_arraySize = _arraySize * increasingCoefficient;
	DataType* temp = new DataType[_arraySize];

	for (size_t i = 0; i < _numberOfValidNodes; i++)
	{
		temp[i] = _array[i];
	}
	delete[] _array;
	_array = temp;
}

template<typename DataType, int startingValue, int increasingCoefficient>
inline void IncreasingContainer<DataType, startingValue, increasingCoefficient>::add(const DataType& o)
{

	if (isSpaceInArray()) {
		_array[_numberOfValidNodes++] = o;
	}
	else {
		increaseArray();
		_array[_numberOfValidNodes++] = o;
	}
}

template<typename DataType, int startingValue, int increasingCoefficient>
inline DataType& IncreasingContainer<DataType, startingValue, increasingCoefficient>::operator[](int index)
{
	if (index < 0 || index > _numberOfValidNodes) {
		throw std::invalid_argument("Neplatný index");
	}
	return _array[index];
}

template<typename DataType, int startingValue, int increasingCoefficient>
inline DataType IncreasingContainer<DataType, startingValue, increasingCoefficient>::operator[](int index) const
{
	if (index < 0 || index > _numberOfValidNodes) {
		throw std::invalid_argument("Neplatný index");
	}
	return _array[index];
}

template<typename DataType, int startingValue, int increasingCoefficient>
inline unsigned int IncreasingContainer<DataType, startingValue, increasingCoefficient>::quantity() const
{
	return _numberOfValidNodes;
}

template<typename DataType, int startingValue, int increasingCoefficient>
inline void IncreasingContainer<DataType, startingValue, increasingCoefficient>::addToIndex(int index, const DataType& o)
{
	if (index < 0 || index > _numberOfValidNodes) {
		throw std::invalid_argument("Neplatný index");
	}
	int k = _numberOfValidNodes;
	if (k == _arraySize) {
		increaseArray();
	}
	_numberOfValidNodes++;
	DataType* temp = new DataType[_arraySize];
	for (size_t i = 0; i < _numberOfValidNodes; i++)
	{
		if (i < index) {
			temp[i] = _array[i];
		}
		else if (i == index) {
			temp[i] = o;
		}
		else {
			temp[i] = _array[i - 1];
		}
	}
	delete[] _array;
	_array = temp;
}

template<typename DataType, int startingValue, int increasingCoefficient>
inline void IncreasingContainer<DataType, startingValue, increasingCoefficient>::remove(int index)
{
	if (index < 0 || index > _numberOfValidNodes) {
		throw std::invalid_argument("Neplatný index");
	}
	//_numberOfValidNodes--;
	DataType* temp = new DataType[_arraySize];
	for (size_t i = 0; i < _numberOfValidNodes; i++)
	{
		if (i < index) {
			temp[i] = _array[i];
		}
		else {
			temp[i] = _array[i + 1];
		}
	}
	delete[] _array;
	_array = temp;

}

