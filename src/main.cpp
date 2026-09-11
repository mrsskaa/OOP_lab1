#include "laba1/array_ops.hpp"

#include <iostream>


int main() {
    int command;
    int* arr = nullptr;
    std::size_t size = 0;

    do {
        std::cout << "Выберите команду:" << std::endl;
        std::cout << " 1. Создать массив\t                     2. Удалить массив\n 3. Вставить элемент\t                 4. Удалить элемент\n 5. Изменить размер\t                     6. Печать\n 7. Cлияние отсортированных массивов\t 0. Выход" << std::endl;

        if (!(std::cin >> command)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Некорректный ввод.\n";
            continue;
        }

        switch (command) {
            case 1: {
                std::size_t n;
                std::cout << "Введите размер массива: ";
                if (!(std::cin >> n)) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Некорректный ввод.\n";
                    break;
                }

                laba1::array_delete(arr);
                arr = laba1::array_create(n);
                size = n;

                std::cout << "Введите " << size << " элементов:\n";
                for (std::size_t i = 0; i < size; ++i) {
                    std::cin >> arr[i];
                }
                break;
            }
            case 2: {
                laba1::array_delete(arr);
                size = 0;
                break;
            }
            case 3: {
                std::size_t pos;
                int value;
                std::cout << "Введите позицию вставки:\n";
                if (!(std::cin >> pos)) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Некорректный ввод\n";
                    break;
                }
                std::cout << "Введите значение:\n";

                if (!(std::cin >> value)) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Некорректный ввод\n";
                    break;
                }

                if (pos > size) {
                    std::cout << "Позиция вне диапазона.\n";
                    break;
                }

                arr = laba1::array_insert(arr, size, pos, value);
                break;
            }
            case 4: {
                std::size_t pos;
                std::cout << "Введите позицию элемента для удаления:\n";
                if (!(std::cin >> pos)) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Некорректный ввод\n";
                    break;
                }
                if (pos >= size) {
                    std::cout << "Позиция вне диапазона.\n";
                    break;
                }

                arr = laba1::array_remove(arr, size, pos);
                break;
            }
            case 5: {
                std::size_t new_size;

                std::cout << "Введите новый размер:\n";

                if (!(std::cin >> new_size)) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout<< "Некорректный ввод\n";
                    break;
                }

                arr = laba1::array_resize(arr, size, new_size);
                size = new_size;
                break;
            }
            case 6: {
                laba1::array_print(arr, size);
                break;
            }
            case 7: {
                std::size_t na, nb;
                int* a = nullptr, * b = nullptr;
                std::size_t out_size;

                std::cout << "Введите размер первого массива\n";
                if (!(std::cin >> na)) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout<< "Некорректный ввод\n";
                    break;
                }

                laba1::array_delete(a);
                a = laba1::array_create(na);
                std::cout << "Введите первый массив\n";
                for (std::size_t i = 0; i < na; ++i) {
                    std::cin >> a[i];
                }

                std::cout << "Введите размер второго массива\n";
                if (!(std::cin >> nb)) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout<< "Некорректный ввод\n";
                    laba1::array_delete(a);
                    break;
                }

                laba1::array_delete(b);
                b = laba1::array_create(nb);
                std::cout << "Введите второй массив\n";
                for (std::size_t i = 0; i < nb; ++i) {
                    std::cin >> b[i];
                }

                laba1::array_delete(arr);
                arr = laba1::array_merge(a, na, b, nb, out_size);
                size = out_size;

                laba1::array_delete(a);
                laba1::array_delete(b);
                break;
            }
            default:
                std::cout << "Введена неверная команда\n";
                break;

        }
    }
    while (command != 0);

    return 0;
}