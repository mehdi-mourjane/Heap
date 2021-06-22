/*
** EPITECH PROJECT, 2021
** pv
** File description:
** Heap
*/

#include "Heap.hpp"

template <typename T>
void Heap<T>::__swap(double parentId, double childId)
{
    T tmp = this->_heap.at(childId);

    this->_heap.at(childId) = this->_heap.at(parentId);
    this->_heap.at(parentId) = tmp;
}

template <typename T>
bool Heap<T>::__compare(double parentId, double childId)
{
    if (!(int) _type)
        return _heap.at(parentId) < _heap.at(childId);
    return _heap.at(parentId) > _heap.at(childId);
}

template <typename T>
void Heap<T>::push(T val)
{
    _size += 1;
    this->_heap.push_back(val);
    this->__heapifyUp();
}

template <typename T>
void Heap<T>::__heapifyUp()
{
    unsigned int index = _size - 1;

    while (__compare(getParentIndex(index), index)) {
        __swap(getParentIndex(index), index);
        index = getParentIndex(index);
    }
}