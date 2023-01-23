#ifndef CPU_HPP_
#define CPU_HPP_

#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include <fstream>

#include "Definitions.hpp"
#include "Parser.hpp"

#define GET_OPERATION(o, ins) o |= ((ins & 0xFFFF'0000'0000'0000) >> 48)
#define GET_REGISTER(r, ins)  r |= (ins & 0x0000'FFFF'0000'0000) >> 32
#define GET_DATA(d, ins) 			d |= (ins & 0x0000'0000'FFFF'FFFF)

class CPU
{
public:
	CPU();
	~CPU();

	void read(const std::string &line);
	void readFile(const std::string &fname);
	void execute();

	friend class Parser;

private:
	int32_t mStack[1024] = {0};
	int32_t *mStackPointer = nullptr;
	std::array<int32_t, 8> mRegisters = {0};
	std::array<float, 8> mFPRegisters = {0.0f};
	Parser mParser;
	std::vector<uint64_t> mParsedInstructions;
};

#endif // CPU_HPP_
