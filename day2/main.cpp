#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::fstream file;
	file.open("input.txt", std::ios::in);
    if(file.is_open())
	{
		std::string input;
		while(std::getline(file, input))
		{
			//inputs.push_back(input);
		}
	}
    
    
    return 0;
}