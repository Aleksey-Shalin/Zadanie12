#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
int main()
{
	SetConsoleOutputCP(CP_UTF8);
	setlocale(LC_ALL, "Russian");
	std::string words;
	std::ifstream file ("C:\\Users\\HP\\in.txt");
	if (file.is_open())
	{
		while (!(file >> words).eof())
		{
			std::cout << words << std::endl;
		}
		file.close();
	}
	else
	{
		std::cout << "Не получилось открыть файл!" << std::endl;
	}
	return 0;
}