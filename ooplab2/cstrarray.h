#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "cstr.h"

class CStrArray {
private:
    Cstr** data;
    int capacity;
    int size;
public:
    CStrArray(int cap) {
        if (cap < 0) cap = 0;
        capacity = cap;
        size = 0;

        data = new Cstr * [cap];
        for (int i = 0; i < cap; ++i) {
            data[i] = nullptr;
        }
    }
    CStrArray& operator+=(Cstr* str) {
        if (str == nullptr) {
            return *this;
        }
        if (size < capacity) {
            data[size] = str;
            size++;
        }
        else {
            std::cout << "error. array if full.";
        }
        return *this;
    }
    ~CStrArray() {
        delete[] data;
    }
    Cstr* operator[](int i) {
        if (i < 0 || i >= capacity) { puts("index out of range"); exit(0); }
        return data[i];
    }
    void Sort() {
        if (isSorted()) {
            std::cout << "already sorted." << std::endl;
            return;
        }
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - 1 - i; ++j) {
                if (*(data[j]) > *(data[j + 1])) {
                    Cstr* temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }
    void SortLen() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - 1 - i; ++j) {
                if ((*(data[j])).len() > (*(data[j + 1])).len()) {
                    Cstr* temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }
    bool isSorted() const {
        if (size <= 1) return true;
        for (int i = 0; i < size - 1; ++i) {
            if (*(data[i]) > *(data[i + 1])) {
                return false;
            }
        }
        return true;
    }
    friend std::ostream& operator<<(std::ostream& os, const CStrArray& arr) {
        for (int i = 0; i < arr.size; ++i) {
            os << *(arr.data[i]);
            os << " ";
        }
        return os;
    }
};
