#pragma once

#include <iostream>
#include <array>
#include <ctime>
#include <vector>

using Slova = std::array < std::string, 100>;

void getWord(Slova& slova);
void mainMenu(Slova& slova);
void instruction();
void printDifferentStage(int& tries);
bool checkIfLetterInWord(std::string hiddenWord, std::string& currentWord, std::string letter, std::vector<int> &currentIndex);
void CurrentWord(std::string &currentWord, int ifLetterInWord, std::vector<int> &currentIndex, std::string hiddenWord);
void checkIfLettetInSelected(std::string letter, std::vector<char> &selectedLetters);
int checkIfLetterWasEntered(std::string letter, std::vector<char>& selectedLetters);
int checkInput(std::string letter, std::array<char, 34> allLetters, int tries);