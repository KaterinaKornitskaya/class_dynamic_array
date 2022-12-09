// class_dynamic_array.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

/*
 Создайте класс Array.
Класс Array – это класс динамического массива. Размер массива может быть
передан в конструктор в качестве параметра или задан с помощью вызова функции-члена.
Класс должен позволять заполнять массив значениями, отображать содержимое массива,
изменять размер массива, сортировать массив, определять минимальное
и максимальное значение. Класс должен содержать набор конструкторов
(конструктор копирования обязателен), деструктор
*/

class Array
{
    int* arr;
    int count;

public:
    Array()
    {
        arr = nullptr;
        count = 0;
    }
    Array(int Count)  // заполнение массива
    {  
        count = Count;
        arr = new int[Count];
        for (size_t i = 0; i < count; i++)
        {
            arr[i] = rand() % 30;
        }
    }

    void output()  // вывод на экран
    {
        for (size_t i = 0; i < count; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    void sort()  // сортировка от меньшего
    {
        for (size_t i = 0; i < count; i++)
        {
            for (size_t k = count - 1; k > i; k--)
            {

                if (arr[k - 1] > arr[k]) {
                    int temp = arr[k - 1];
                    arr[k - 1] = arr[k];
                    arr[k] = temp;
                }
            }
        }
    }

    int Minimum()  // поиск минимального элемента
    {
        int min = arr[0];        
        for (int i = 0; i < count; i++)
        {
            if (min > arr[i])
            {
                min = arr[i];
            }         
        }
        return min;
    }

    int Maximum()  // поиск максимального элемента
    {
        int max = arr[0];
        for (int i = 0; i < count; i++)
        {
            if (max < arr[i])
            {
                max = arr[i];
            }
        }
        return max;
    }

    Array(const Array& source)  // конструктор копирования
    {
        count = source.count;
        arr = new int[count];
        for (size_t i = 0; i < count; i++)
        {
            arr[i] = source.arr[i];
        }
    }

    ~Array()
    {
        delete[] arr;
    }
};

int main()
{
    srand(time(NULL));
    int size;
    std::cout << "Enter size: ";
    std::cin >> size;;

    Array arr1(size);

    std::cout << "Array: " << std::endl;
    arr1.output();

    Array arr2(arr1);
    std::cout << "Copied array: " << std::endl;
    arr2.output();

    arr1.sort();
    std::cout << "Sorted array: " << std::endl;
    arr1.output();

    std::cout << "Min element: " << arr1.Minimum() << std::endl;
    std::cout << "Max element: " << arr1.Maximum() << std::endl;

    return 0;
}
