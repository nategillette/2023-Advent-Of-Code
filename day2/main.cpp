#include <cctype>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>
#include <locale>

struct Game
{
   int id;
   int red;
   int green;
   int blue;
};

int getMaxRed(const std::string& in)
{
	int max,temp = 0;
	std::smatch sm;
	std::locale loc;
	std::regex r1 ("(\\d?\\d)\\sred");
	bool b = std::regex_match(in, sm, r1);
	std::cout << "Regex passed: " << b << std::endl;
	for(const auto& x : sm)
	{
		std::cout << "X is: " << x.str() << std::endl;
		if(std::isdigit(x, loc))
		{
			std::stringstream(x) >> temp;
			std::cout << "Temp is: " << temp << std::endl;
			max = (max < temp) ? temp : max;
		}
	}
	std::cout << "Max red: " << max << std::endl;
	return max;
}

std::vector<Game> readFile(std::fstream& file)
{
	std::vector<Game> games;
	if(file.is_open())
	{
		std::string input;
		int id = 1;
		Game game{};
		while(std::getline(file, input))
		{
			game.id = id;
			game.red = getMaxRed(input);
			games.push_back(game);

			id++;
		}
	}
	return games;
}


int main()
{
    std::fstream file;
	file.open("input.txt", std::ios::in);
	readFile(file); 
    
    return 0;
}