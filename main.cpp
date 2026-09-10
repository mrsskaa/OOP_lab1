#include <iostream>
#include "array_ops.h"


int main() {
    int command;
    std::cout << "Выберите команду:" << std::endl;
    std::cout << " 1. Создать массив\t     2. Напечатать\n 3. Вставить элемент\t 4. Удалить элемент\n 5. Изменить размер\t     6. Печать\n 7. Алгоритм варианта\t 0. Выход" << std::endl;
    std::cin >> command;

    while (command != 0){
        std::cin >> command;
        switch (command) {}
    }
return 0;
}