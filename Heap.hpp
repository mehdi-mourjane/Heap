/*
** EPITECH PROJECT, 2021
** pv
** File description:
** Heap
*/

#ifndef HEAP_HPP_
#define HEAP_HPP_

#include <vector>
#include <iostream>
#include <cmath>

enum HTYPE {
            HMAX = 0,
            HMIN
        };

template <class T = bool>
class Heap
{
    public:

        Heap(HTYPE type = HMAX) : _type(type) {};
        ~Heap() = default;

    // methodes
        void push(T);
        T pop_first(T) {};
        std::vector<T> pop(T) {};

    // getters / setters
        unsigned int size() {return size;};
        // std::vector<T, std::allocator<T>>::iterator begin() {return _heap.begin();};
        // std::vector<T, std::allocator<T>>::iterator end() {return _heap.end();};
        T front() {return _heap.front();};
        T back() {return _heap.back();};

    //static methodes
        static double getParentIndex(double id) {return (id - 1) / 2;};
        static double getChildLeftIndex(double id) {return id * 2 + 1;};
        static double getChildRightIndex(double id) {return id * 2 + 2;};
        static std::pair<double, double> getChildsIndex(double id) {return {getChildLeftIndex(id), getChildRightIndex(id)};};
        std::vector<T> _heap;

    private:
        //private methodes;
        void __heapifyUp();
        void __heapifyDown();
        bool __compare(double parentId, double childId);
        void __swap(double parentId, double childId);
    private:
        unsigned int _size = 0;
        HTYPE _type;
};

#endif /* !HEAP_HPP_ */
