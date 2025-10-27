#include<iostream>
#include<fstream>
//#include<windows.h>
#include<limits>
#include<cctype>
#include<string>

int main()
{
	// SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	std::ofstream file("out.txt");
	int array_size = 0;
	while (array_size <= 0 || (std::cin.fail()))
	{
		std::cout << "Введите размер массива: ";
		std::cin >> array_size;
		if (array_size <= 0 || (std::cin.fail()))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Нужно ввести целое положительное число для размерности массива" << std::endl;
			std::cout << std::endl;
		}
	}

	int* array = new int[array_size];      // создание динамического массива для передачи элементов массива из программы в файл
	for (int i = 0; i < array_size; i++)
	{
		std::cout << "arr[ " << i << " ]: ";
		std::cin >> array[i];     // запись элементов массива для передачи в файл
	}
	if (file.is_open())
	{
		file << array_size << std::endl;    // передача длины массива в качестве первого значения в файле
		for (int i = array_size - 1; i >= 0; i--)
		{
			file << array[i] << " ";       // передача элементов массива из программы в файл в обратном порядке
		}
	}
	else
	{
		std::cout << "Не удалось записать данные в файл" << std::endl;
	}
	delete[] array;
	file.close();
	return 0;

}
