#pragma once
#include <cstddef>

namespace laba1 {
int* array_create(std::size_t size); // new int[size], +1 слот под '\0'не нужен

void array_delete(int*& arr); // delete[] и обнулить указатель

int* array_resize(int* arr, std::size_t size, std::size_t new_size); // новая память + копия

int* array_insert(int* arr, std::size_t& size, std::size_t pos, int value); // вставка

int* array_remove(int* arr, std::size_t& size, std::size_t pos); // удаление

void array_print(const int* arr, std::size_t size);

int* array_merge(const int* a, std::size_t na, const int* b, std::size_t nb, std::size_t& out_size); //cлияние двух отсортированных массивов
}