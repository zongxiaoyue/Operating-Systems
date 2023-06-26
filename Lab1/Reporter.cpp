#include <iostream>
#include <fstream>
#include <string>
#include "YuanGong.h"

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cerr << "���󣺲����쳣��������� 4�� Error: Argument exception (must be equal 4)" << std::endl;
		return 1;
	}

	std::string binFileName = argv[1];
	std::string repFileName = argv[2];
	double salaryPerHour = std::stod(argv[3]);

	std::ifstream binFile(binFileName, std::ios::binary);
	if (!binFile)
	{
		std::cerr << "�򿪶������ļ�ʱ���� Error opening binary file" << binFileName;
		return 1;
	}

	std::ofstream repFile(repFileName);
	if (!repFile)
	{
		std::cerr << "�򿪱����ļ�ʱ���� Error opening report file" << repFileName;
		return 1;
	}

	repFile << "���ڶ������ļ��ı��� Report based on binary file" << binFileName;
	repFile << "\nEmployee \tName\tHours\tSalary\n";

	employee employee;
	while (binFile.read((char*)& employee, sizeof(employee)))
	{
		double salary = employee.hours * salaryPerHour;
		repFile << employee.num << "\t\t" << employee.name << "\t" << employee.hours << "\t" << salary << "$\n";
	}

	binFile.close();
	repFile.close();
	return 0;
}
