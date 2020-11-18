#pragma once

#ifndef INCREASINGCONTAINER_H
#define INCREASINGCONTAINER_H

#include <stdexcept>

template<typename DataType, int startingValue = 5, int increasingCoefficient = 2>
class IncreasingContainer {
private:
	DataType* _array;
	int _arraySize;
	int _numberOfValidNodes;
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



template<typename DataType, int startingValue, int increasingCoefficient>
inline IncreasingContainer<DataType, startingValue, increasingCoefficient>::IncreasingContainer()
{
	_arraySize = startingValue;
	_numberOfValidNodes = 0;
	_array = new DataType[_arraySize];
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
		throw std::out_of_range("Neplatný index");
	}
	return _array[index];
}

template<typename DataType, int startingValue, int increasingCoefficient>
inline DataType IncreasingContainer<DataType, startingValue, increasingCoefficient>::operator[](int index) const
{
	if (index < 0 || index > _numberOfValidNodes) {
		throw std::out_of_range("Neplatný index");
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
		throw std::out_of_range("Neplatný index");
	}
	if (!(isSpaceInArray())) {
		increaseArray();
	}
	_numberOfValidNodes++;
	DataType temp, temp2;
	for (size_t i = index; i < _numberOfValidNodes; i++)
	{
		if (i == index) {
			temp = _array[i];
			_array[i] = o;
		}
		else if(i > index) {
			_array[i + 1] = _array[i];
			_array[i] = temp;			
		}
	}
}

template<typename DataType, int startingValue, int increasingCoefficient>
inline void IncreasingContainer<DataType, startingValue, increasingCoefficient>::remove(int index)
{
	if (index < 0 || index > _numberOfValidNodes) {
		throw std::out_of_range("Neplatný index");
	}

	DataType* temp = new DataType[_arraySize];
	temp = _array;
	for (size_t i = index; i < _numberOfValidNodes; i++)
	{
		if (i >= index) {
			_array[i] = _array[i + 1];
		}
	}
	_numberOfValidNodes--;
	_array = temp;
	
}

#endif
