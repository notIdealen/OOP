#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <string>

std::string GetWord();

using MultiDictionary = std::multimap<std::string, std::string>;

void LoadDictionary(std::string path, MultiDictionary& dic);

void PrintTranslation(MultiDictionary& dic, std::string word);

// void PrintReverseTranslation(MultiDictionary& dic, std::string word);

void SaveDictionary(std::string path, MultiDictionary& buf);

std::string SaveWord(MultiDictionary& dic, std::string word);
