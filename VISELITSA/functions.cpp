#include <iostream>
#include <array>
#include <ctime>
#include "termcolor.hpp"
#include <vector>
#include <Windows.h>
#include <algorithm>
#include <cctype>

using Slova = std::array < std::string, 100>;

// ���������� ������ ���������� �����
int getWord(Slova& slova)
{
	int randomNumber = rand() % 39;

	return randomNumber;
}

void instruction()
{
	std::cout
		<< "\t\t\t����� ���������� � ���� '��������'!\n";
		std::cin.get();
		std::cout<< "���� ����: \n"
		<< "� ���� ��� ����� ������� �����, ������� �������� ���������, ����� �� ������.\n" 
		<< "����� ��������� ���� ����� �� ��� � ����� ��������� ������ 6 ���(����� ����� �� �����������).\n\n";

	std::cout << "������� ����� �������, ����� ������...";
	std::cin.get();
	system("cls");
}

// ������� ��� ����� ����
void printDifferentStage(int &tries)
{
	if (tries == 0)
		std::cout
		<< "   _____\n"
		<< "  |     |\n"
		<< "  |\n"
		<< "  |\n"
		<< "  |\n"
		<< " _|_";
	else if (tries == 1)
		std::cout
		<< "   _____\n"
		<< "  |     |\n"
		<< "  |     0\n"
		<< "  |\n"
		<< "  |\n"
		<< " _|_";
	else if (tries == 2)
		std::cout
		<< "   _____   \n"
		<< "  |     |  \n"
		<< "  |     0  \n"
		<< "  |     |  \n"
		<< "  |\n"
		<< " _|_";
	else if (tries == 3)
		std::cout
		<< "   _____   \n"
		<< "  |     |  \n"
		<< "  |     0  \n"
		<< "  |    /|  \n"
		<< "  |\n"
		<< " _|_";
	else if (tries == 4)
		std::cout
		<< "   _____     \n"
		<< "  |     |    \n"
		<< "  |     0    \n"
		<< "  |    /|\\  \n"
		<< "  |\n"
		<< " _|_";
	else if (tries == 5)
		std::cout
		<< "   _____     \n"
		<< "  |     |    \n"
		<< "  |     0    \n"
		<< "  |    /|\\  \n"
		<< "  |    /     \n"
		<< " _|_";
	else if (tries == 6)
		std::cout
		<< "   _____     \n"
		<< "  |     |    \n"
		<< "  |     0    \n"
		<< "  |    /|\\  \n"
		<< "  |    / \\  \n"
		<< " _|_";
	else if (tries == -1)
	{
		std::cout 
			<< "\n   \\0/  \n"
			<< "    |    \n"
			<< "   / \\  \n";
	}

	std::cout << "\n\n";
}

// ��������, ���� �� ����� � �����
bool checkIfLetterInWord(std::string hiddenWord, std::string &currentWord, std::string letter, std::vector<int> &currentIndex)
{
	int count = 0;
	// ���� �� ���� �� ���� �����
	bool check = false;
	for (int i = 0; i < hiddenWord.size(); i++)
	{
		if (hiddenWord[i] == letter[0])
		{
			currentIndex.push_back(i);
			count++;
			check = true;
		}
	}
	return check;
}

// ������� ��������� �����
void CurrentWord(std::string &currentWord, int ifLetterInWord, std::vector<int> &currentIndex, std::string hiddenWord)
{
	for (int i = 0; i < hiddenWord.size(); i++)
	{
		for (int j = 0; j < currentIndex.size(); j++)
		{
			if (i == currentIndex[j])
			{
				currentWord[i] = hiddenWord[i];
				continue;
			}
			if (currentWord[i] == '_')
			{
				currentWord[i] = '_';
			}
		}
		
	}
}
// ��������, ���� �� ����� � ��� ���������
void checkIfLettetInSelected(std::string letter, std::vector<char> &selectedLetters)
{
	int count = 0;
	for (int i = 0; i < selectedLetters.size(); i++)
	{
		if (letter[0] == selectedLetters[i])
			count++;
	}
	if (count == 0)
		selectedLetters.push_back(letter[0]);
}
// ��������, ��������� �� ������ �����
int checkIfLetterWasEntered(std::string letter, std::vector<char>& selectedLetters)
{
	// ������� ��������� �����
	int count = 0;
	for (int i = 0; i < selectedLetters.size(); i++)
	{
		if (letter[0] == selectedLetters[i])
		{
			count++;
			return 1;
		}	
	}
	if (count == 0)
		return 0;
}

// �������� ����������������� �����
int checkInput(std::string letter, std::array<char, 34> allLetters, int tries)
{
	if (letter.size() > 1)
	{
		system("cls");
		std::cout << termcolor::red << "������� ���� �����!" << termcolor::reset;
		Sleep(1500);
		system("cls");
		printDifferentStage(tries); 
		return 1;
	}


	int count = 0;
	for (int i = 0; i < allLetters.size(); i++)
	{
		if (letter[0] != allLetters[i])
			count++;
	}
	if (count == allLetters.size())
	{
		system("cls");
		std::cout << termcolor::red << "������� ����� �� ������!" << termcolor::reset;
		Sleep(1500);
		system("cls");
		printDifferentStage(tries);
		return 1;
	}
	else
		return 0;
}

void mainMenu(Slova& slova)
{
	int tries = 0;
	std::vector<int> currentIndex;
	std::array<char, 34> allLetters;
	std::vector<char> selectedLetters;
	selectedLetters.reserve(33);
	allLetters = {"��������������������������������"};
	currentIndex.reserve(10);
	std::string letter;
	int ifLetterInWord;
	std::string hiddenWord = slova.at(getWord(slova));
	std::string currentWord(hiddenWord.length(), '_');

	instruction();
	// ��������� ��������� ��������
	printDifferentStage(tries);

	bool check = false;
	do
	{
		std::cout << "����� - " << currentWord << std::endl;
		// ��������� �����
		for (int i = 0; i < allLetters.size(); i++)
		{
			check = false;
			for (int j = 0; j < selectedLetters.size(); j++)
			{
				if (allLetters[i] == selectedLetters[j])
				{
					std::cout << termcolor::green << allLetters[i] << " " << termcolor::reset;
					check = true;
				}
			}
			if (!check)
			{
				std::cout << allLetters[i] << " ";
			}
		}
	
		std::cout << "\n�������� �����: ";
		std::cin >> letter;
		std::transform(letter .begin(), letter.end(), letter.begin(), [](unsigned char c) { return std::tolower(c); });
		
		if (checkInput(letter, allLetters, tries))
		{
			continue;
		}


		if (checkIfLetterWasEntered(letter, selectedLetters))
		{
			system("cls");
			std::cout << termcolor::red << "�� ��� �������� ������ �����, �������� ������!" << termcolor::reset;
			Sleep(1500);
			system("cls");
			printDifferentStage(tries);
			continue;
		}


		checkIfLettetInSelected(letter, selectedLetters);


		system("cls");
		// 1 - ����� ����, 0 - ����� ����� ���
		ifLetterInWord = checkIfLetterInWord(hiddenWord, currentWord, letter, currentIndex);

		if (ifLetterInWord)
		{
			printDifferentStage(tries);
			std::cout << termcolor::green << "\t�����!\n" << termcolor::reset;
			CurrentWord(currentWord, ifLetterInWord, currentIndex, hiddenWord);
			if (currentWord == hiddenWord)
			{
				tries = -1;
				system("cls");
				printDifferentStage(tries);
				std::cout << termcolor::green << "�� ��������!\n" << termcolor::reset;
				std::cout << "���������� ����� - " << termcolor::blue << hiddenWord << ".\n" << termcolor::reset;;
				break;
			}
			continue;
		}

		tries++;
		if (!ifLetterInWord and tries != 6)
		{
			printDifferentStage(tries);
			std::cout << termcolor::red << "�������!����� ����� ���, � ��� �������� " << 6 - tries << " ������� ������� ������� �����!\n" << termcolor::reset;
		}
		else if (tries == 6)
		{
			system("cls");
			printDifferentStage(tries);
			std::cout <<termcolor::red<< "�� ���� ��������!\n"<<termcolor::reset;
			std::cout << "���������� ����� - " << termcolor::blue << hiddenWord << ".\n" << termcolor::reset;
		}

		CurrentWord(currentWord, ifLetterInWord, currentIndex, hiddenWord);
	} while (tries != 6);
}