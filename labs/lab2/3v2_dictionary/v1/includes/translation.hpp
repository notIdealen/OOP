#pragma once

// #include <fstream>
#include <iostream>
#include <map>
// #include <sstream>
#include <vector>
#include <string>

using Dictionary = std::map<std::string, std::vector<std::string>>;

std::string SaveWord(Dictionary& dic, std::string word);

std::string GetWord();

void LoadDictionary(std::string path, Dictionary& dic);

void PrintTranslation(Dictionary& dic, std::string word);

void SaveDictionary(std::string path, Dictionary& buf);
