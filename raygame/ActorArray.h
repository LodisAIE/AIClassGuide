#pragma once
#include <exception>

template<typename T>
class DynamicArray {
public:
	DynamicArray();
	~DynamicArray();
	void addItem(T item);
	void addItem(T item[], int size);
	bool remove(T item);
	void sortItems();
	T getItem(int index);
	int getLength();
	/// <summary>
	/// Checks if the item is in the array
	/// </summary>
	/// <param name="item">A reference to the item to use to check</param>
	/// <returns>False if the item is not in the array</returns>
	bool contains(T item);

	T operator [](int index);
private:
	T* m_items;
	int m_count;
};

template<typename T>
inline DynamicArray<T>::DynamicArray() {
	m_count = 0;
	m_items = nullptr;
}

template<typename T>
inline DynamicArray<T>::~DynamicArray() {
}

template<typename T>
inline void DynamicArray<T>::addItem(T item) {
	T* tempArray = new T[getLength() + 1];
	for (int i = 0; i < getLength(); i++) {
		tempArray[i] = m_items[i];
	}

	delete[] m_items;
	tempArray[getLength()] = item;
	m_items = tempArray;
	m_count++;
}

template<typename T>
inline void DynamicArray<T>::addItem(T item[], int size) {
	T* tempArray = new T[getLength() + size];

	int j = 0;
	for (int i = 0; i < getLength(); i++) {
		tempArray[j] = m_items[i];
		j++;
	}
	for (int i = 0; i < size; i++) {
		tempArray[j] = item[i];
		j++;
	}

	m_count += size;
	m_items = tempArray;
}

template<typename T>
inline bool DynamicArray<T>::remove(T item) {
	bool itemRemoved = false;

	if (!item || getLength() <= 0)
		return itemRemoved;

	T* tempArray = new T[getLength() - 1];

	int j = 0;
	for (int i = 0; i < getLength(); i++) {
		if (item != m_items[i] || itemRemoved) {
			tempArray[j] = m_items[i];
			j++;
		}
		else {
			itemRemoved = true;
		}
	}

	if (itemRemoved) {
		delete[] m_items;
		m_items = tempArray;
		m_count--;
	}

	return itemRemoved;
}

template<typename T>
inline void DynamicArray<T>::sortItems() {
	T key = T();
	int j = 0;

	for (int i = 1; i < getLength(); i++) {
		key = m_items[i];
		j = i - 1;
		while (j >= 0 && m_items[j] > key) {
			m_items[j + 1] = m_items[j];
			j--;
		}

		m_items[j + 1] = key;
	}
}

template<typename T>
inline T DynamicArray<T>::getItem(int index) {
	if (index > 0 || index < getLength()) {
		return m_items[index];
	}
	return T();
}

template<typename T>
inline int DynamicArray<T>::getLength() {
	return m_count;
}

template<typename T>
inline bool DynamicArray<T>::contains(T value)
{
	//Iterate through item array
	for (int i = 0; i < m_count; i++)
	{
		//return the current item if it matches the argument
		if (m_items[i] == value)
			return true;
	}

	return false;
}

template<typename T>
inline T DynamicArray<T>::operator[](int index)
{
	if (index > 0 || index < getLength()) {
		return m_items[index];
	}

	throw std::exception("Index was outside the bounds of the array.");
}
