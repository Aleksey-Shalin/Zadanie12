#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
int main()
{
	SetConsoleOutputCP(CP_UTF8);
	std::string words;
	std::ifstream file ("in.txt");
	if (file.is_open())
	{
		while (file >> words)
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