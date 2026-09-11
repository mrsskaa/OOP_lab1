#include <iostream>
#include "../include/laba1/array_ops.hpp"

int* array_create(std::size_t size) {
    return new int[size];
}

void array_delete(int*& arr) {
    delete[] arr;
    arr = nullptr;
}

int* array_resize(int* arr, std::size_t size, std::size_t new_size) {
    int* new_arr = new int[new_size];
    std::size_t copy_count = (size < new_size) ? size : new_size;

    for (std::size_t i = 0; i < copy_count; i++) {
        new_arr[i] = arr[i];
    }
    delete[] arr;

    return new_arr;
}

int* array_insert(int* arr, std::size_t& size, std::size_t pos, int value) {
    int* new_arr = new int[++size];

    for (std::size_t i = 0; i < size; i++) {
        if (i<pos){
            new_arr[i] = arr[i];
        }
        else if (i == pos) {
            new_arr[i] = value;
        }
        else {
            new_arr[i] = arr[i-1];
        }
    }
    delete[] arr;
    return new_arr;

}

int* array_remove(int* arr, std::size_t& size, std::size_t pos) {
    int* new_arr = new int[--size];

    for (std::size_t i = 0; i < size; i++) {
        if (i<pos) {
            new_arr[i] = arr[i];
        }
        else{
            new_arr[i] = arr[i+1];
        }
    }
    delete[] arr;
    return new_arr;
}

void array_print(const int* arr, std::size_t size) {
    for (std::size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int* array_merge(const int* a, std::size_t na, const int* b, std::size_t nb, std::size_t& out_size) {
    out_size = na + nb;
    int* new_arr = new int[out_size];
    std::size_t ia=0, ib=0, i=0;

    while (ia<na && ib<nb) {
        if (a[ia]<b[ib]) {
            new_arr[i++]=a[ia++];
        }
        else {
            new_arr[i++]=b[ib++];
        }
    }

    while (ia<na) {
        new_arr[i++]=a[ia++];
    }

    while (ib<nb) {
        new_arr[i++]=b[ib++];
    }

    return new_arr;
}