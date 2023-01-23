#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>
#include <vector>
#include <string>

#include "Definitions.hpp"

class Parser
{
public:
	Parser();
	~Parser();
	
	void parse(const std::string &line);
	std::vector<uint64_t> getInstructions() const;
	
private:
	std::vector<uint64_t> mParsedInstructions;
};

#endif // PARSER_HPP_
