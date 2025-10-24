#include<iostream>
#include<fstream>
#include<windows.h>
int main()
{
	//SetConsoleOutputCP(CP_UTF8);   если потребуется вывод текста из файла
	//setlocale(LC_ALL, "Russian");   с корректным отображением символов
	std::ifstream file("C:\\Users\\HP\\Files\\in.txt");
	if (file.is_open())
	{
		int array_elements = 0;    // переменная для передачи количества элементов в программу из файла
		//while (!(file >> array_elements).eof()) {
			file >> array_elements;     // передача (чтение) количества элементов массива из файла в программу 
			int* array = new int[array_elements];    // создание динамического массива на основе прочитанных из файла элементов
			for (int i = 0; i < array_elements; i++)
			{
				file >> array[i];    // передача (чтение) элементов массива из файла в программу
			}

			for (int i = array_elements - 1; i >= 0; i--)
			{
				std::cout << array[i] << " ";      // вывод на консоль полученных из файла элементов массива в обратном порядке
			}
			delete[] array;
			file.close();
		//}
	}
	else
	{
		std::cout << "Не получилось открыть файл!" << std::endl;
	}
	return 0;

}
