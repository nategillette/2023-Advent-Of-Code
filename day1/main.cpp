#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> readFile(std::fstream& file)
{
	std::vector<std::string> inputs;
	if(file.is_open())
	{
		std::string input;
		while(std::getline(file, input))
		{
			inputs.push_back(input);
		}
	}
	return inputs;
}

std::vector<std::string> convertInputs(const std::vector<std::string>& inputs)
{	
	std::vector<std::string> stringsToAdd;

	for(const auto& line : inputs)
	{
		std::string temp{};
		char first, second = '\0';
		int index = 0;
		for(uint i=0; i < line.length(); i++)
		{
			if(std::isdigit(line[i]))
			{
				if(index == 0)
				{
					first= line[i];
				}
				else
				{
					second = line[i];
				}
				index ++;
			}
		}
		if(second == '\0')
		{
			second = first;
		}
		temp += first + second;
		stringsToAdd.push_back(temp);
	}
	return stringsToAdd;
}

int calculateTotal(const std::vector<std::string>& stringsToAdd)
{
	int total = 0;
	for(const auto& string : stringsToAdd)
	{
		total += std::atoi(string.c_str());
	}
	return total;
}

int main()
{
	std::vector<std::string> inputs;
	std::vector<std::string> stringsToAdd;
	int finalTotal = 0;
	std::fstream file;
	file.open("input.txt", std::ios::in);

	inputs = readFile(file);
	stringsToAdd = convertInputs(inputs);
	finalTotal = calculateTotal(stringsToAdd);

	std::cout << "The total is: " << finalTotal << std::endl;
	return 0;
}
