#include <iostream>
#include <fstream>
#include <Windows.h>
#include <tchar.h>
#include <string>
#include "YuanGong.h"

int main(int argc, char* argv[]) {

	std::string binFileName;
	std::cout << "����bin�ļ��� Enter bin file name: ";
	getline(std::cin, binFileName);
	std::cout << "�����¼�� Enter records count: ";
	int recordsCount;
	std::cin >> recordsCount;

	STARTUPINFO ep;
	ZeroMemory(&ep, sizeof(ep));
	PROCESS_INFORMATION pi;
	ZeroMemory(&pi, sizeof(pi));

	std::string command = "Creator.exe " + binFileName + " " + std::to_string(recordsCount);
	TCHAR commandLine[MAX_PATH];
	_tcscpy_s(commandLine, MAX_PATH, command.c_str());
	

	if (!CreateProcess(NULL, commandLine, NULL, NULL, FALSE, 0, NULL, NULL, &ep, &pi))
	{
		std::cerr << "�������̳��� Error creating process (Creator)";
		return 1;
	}

	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hProcess);

	std::ifstream readFile(binFileName, std::ios::binary);
	if (!readFile) {
		std::cerr << "�����޷��� bin �ļ� Error: Could not open bin file";
		return 1;
	}

	employee person;
	std::cout << "\nEmployee list:\n";
	while (readFile.read(reinterpret_cast<char*>(&person), sizeof(person))) {
		std::cout << "ID: " << person.num << '\n';
		std::cout << "Name: " << person.name << '\n';
		std::cout << "Hours: " << person.hours << '\n';
		std::cout << '\n';
	}

	std::cout << "\nΪ�����ļ�д������ Write name for Report file: ";
	std::string reportFile;
	std::cin >> reportFile;
	double salary;
	std::cout << "д���� Write salary: ";
	std::cin >> salary;
	readFile.close();

	ZeroMemory(&ep, sizeof(ep));
	ep.cb = sizeof(ep);
	ZeroMemory(&pi, sizeof(pi));

	command = "Reporter.exe " + binFileName + " " + reportFile + " " + std::to_string(salary);
	_tcscpy_s(commandLine, MAX_PATH, command.c_str());
	

	if (!CreateProcess(NULL, commandLine, NULL, NULL, FALSE, 0, NULL, NULL, &ep, &pi))
	{
		std::cerr << "�������̳������ߣ� Error creating process (Reporter)" << '\n';
		return 1;
	}

	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hProcess);

	readFile.open(reportFile);
	if (!readFile) {
		std::cerr << "�����޷��򿪼����ļ� Error: Could not open reporter file" << '\n';
		return 1;
	}

	std::string line;
	std::cout << '\n';
	while (std::getline(readFile, line))
		std::cout << line << '\n';
	return 0;
}
