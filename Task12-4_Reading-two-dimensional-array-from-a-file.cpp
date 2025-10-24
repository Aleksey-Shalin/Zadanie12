#include<iostream>
#include<fstream>
int main()
{
	std::ifstream file("C:\\Users\\HP\\Document\\in.txt");
	if (file.is_open())
	{
		int rows = 0;
		int columns = 0;
		file >> rows >> columns;   // передача размера массива из файл в программу
		int** array = new int* [rows];     // создание указателя второго уровня двумерного динамического массива с присвоением указателя динамического массива строк
		for (int a_row = 0; a_row < rows; a_row++)
		{
			array[a_row] = new int[columns];    // создание одномерных динамических массивов (столбцов) в созданных строках
		}

		for (int a_row = 0; a_row < rows; a_row++)
		{
			for (int a_column = 0; a_column < columns; a_column++)
			{
				file >> array[a_row][a_column];      // передача из файла в программу элементов массива
			}
		}

		for (int a_row = 0; a_row < rows; a_row++)       // строки не меняяются местами
		{
			for (int a_column = columns - 1; a_column >= 0; a_column--)    // меняются с обратном направлении значения в столбцах (массивах) каждой строки
			{
				std::cout << array[a_row][a_column] << " ";    
			}
			std::cout << std::endl;
		}

		for (int a_row = 0; a_row < rows; a_row++)
		{
			delete[] array[a_row];
		}
		delete[] array;
		file.close();
	}
	else
	{
		std::cout << "Не получилось открыть файл!" << std::endl;
	}
	return 0;
}
