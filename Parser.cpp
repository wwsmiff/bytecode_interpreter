#include "Parser.hpp"

Parser::Parser()
{}

Parser::~Parser()
{}

void Parser::parse(const std::string &line)
{
	std::string operation = "";
	std::string reg = "";
	std::string data = "";
	bool isReg = false;
	bool isFloat = 0;
	uint64_t instruction = 0;
	uint32_t strIndex = 0;

	if(!line.empty())
	{
		if(line[strIndex] == '#')
		{
			return;
		}

		while(line[strIndex] != ';')
		{
			while(line[strIndex] != ' ')
			{
				operation += line[strIndex];
				strIndex++;
			}

			while(line[strIndex] != ',' && line[strIndex] != ';')
			{
				if(line[strIndex] != ' ')
				{
					reg += line[strIndex];
					strIndex++;	
				}
				else strIndex++;
			}

			while(line[strIndex] != ';')
			{
				if(line[strIndex] != ';' && !isReg && line[strIndex] == '$' && line[strIndex] != ' ' && line[strIndex] != ',')
				{
					isReg = true;
					strIndex++;	
				}
				else if(line[strIndex] != ';' && isReg && line[strIndex] != ' ' && line[strIndex] != ',')
				{
					data += line[strIndex];
					instruction |= static_cast<uint64_t>(0x8000'0000'0000'0000);
					strIndex++;
				}
				else if(line[strIndex] != ';' && !isReg && line[strIndex] != ' ' && line[strIndex] != ',')
				{
					data += line[strIndex];
					strIndex++;
				}
				else strIndex++;
			}
		}

		// std::cout << "OP: " << operation
		// 	<< ", REG: " << reg
		// 	<< ", DATA: " << data
		// 	<< std::endl;

		if(operation[0] == 'F') 
		{
			isFloat = 1;
			instruction |= static_cast<uint64_t>(0x4000'0000'0000'0000);
		}

		instruction |= (static_cast<uint64_t>(OPERATION_MAP.at(operation)) << 48) & 0x7FFF'0000'0000'0000;

		if(isFloat) instruction |= (static_cast<uint64_t>(FP_REGISTER_MAP.at(reg)) << 32) & 0x0000'FFFF'0000'0000;
		else instruction |= (static_cast<uint64_t>(REGISTER_MAP.at(reg)) << 32) & 0x0000'FFFF'0000'0000;

		if(isReg && !data.empty() && !isFloat) 
		{
			instruction |= (static_cast<uint64_t>(REGISTER_MAP.at(data))) & 0x0000'0000'FFFF'FFFF;
		}

		else if(isReg && !data.empty() && isFloat)
		{
			instruction |= (static_cast<uint64_t>(FP_REGISTER_MAP.at(data))) & 0x0000'0000'FFFF'FFFF;
		}

		else if(!isReg && !data.empty() && !isFloat)
		{
			instruction |= std::stoi(data) & 0x0000'0000'FFFF'FFFF;
		}

		else if(!isReg && !data.empty() && isFloat)
		{
			float ff = std::stof(data);
			uint32_t ffToUint = *(reinterpret_cast<uint32_t*>(&ff)); 
			instruction |= ffToUint & 0x0000'0000'FFFF'FFFF;
		}
		else
		{
			instruction |= 0 & 0x0000'0000'FFFF'FFFF;
		}

		mParsedInstructions.push_back(instruction);
	}
}

std::vector<uint64_t> Parser::getInstructions() const
{
	return mParsedInstructions;
}
