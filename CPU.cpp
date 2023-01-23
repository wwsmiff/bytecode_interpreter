#include "CPU.hpp"
#include <bitset>

CPU::CPU()
{}

CPU::~CPU()
{}

void CPU::read(const std::string &line)
{
	mParser.parse(line);
	mParsedInstructions = mParser.getInstructions();
}

void CPU::readFile(const std::string &fname)
{
	std::ifstream fpointer(fname.c_str());
	std::string line;
	while(std::getline(fpointer, line))
	{
		mParser.parse(line);
	}
	
	mParsedInstructions = mParser.getInstructions();
}

void CPU::execute()
{
	for(auto &x : mParsedInstructions)
	{
		uint16_t reg = 0;
		uint16_t	op = 0;
		int32_t data = 0;
		float fdata = 0.0f;

		GET_OPERATION(op, x);
		GET_REGISTER(reg, x);
		GET_DATA(data, x);
		
		if(op & 0x4000) fdata = *(reinterpret_cast<float*>(&data));
		
		if(op & 0x8000) 
		{
			if(op & 0x4000)
			{
				fdata = mFPRegisters[data - 1];
			}
			else
			{
			 	data = mRegisters[data - 1]; 
			}
		}
		
		switch(op & 0x00FF)
		{
			case MOV:
				mRegisters[reg - 1] = data;
				data = 0;
				break;
			case ADD:
				mRegisters[reg - 1] = mRegisters[reg - 1] + data;
				break;
			case SUB:
				mRegisters[reg - 1] = mRegisters[reg - 1] - data;
				break;
			case MUL:
				mRegisters[reg - 1] = mRegisters[reg - 1] * data;
				break;
			case DIV:
				mRegisters[reg - 1] = mRegisters[reg - 1] / data;
				break;
			case RPRINT:
				std::cout << REGISTER_TABLE[reg - 1]  << ": " << mRegisters[reg - 1] << std::endl;
				break;

			case FPRINT:
				if(fdata != 0)
				{
					std::cout << FP_REGISTER_TABLE[reg - 1]  << ": " << std::fixed << std::setprecision(data) <<  mFPRegisters[reg - 1] << std::endl;
					break;
				}			
				else
				{
					std::cout << FP_REGISTER_TABLE[reg - 1]  << ": " << std::fixed << std::setprecision(2) <<  mFPRegisters[reg - 1] << std::endl;
					break;
				}
				break;
			case FMOV:
				mFPRegisters[reg - 1] = fdata;
				break;
			case FADD:
				mFPRegisters[reg - 1] = mFPRegisters[reg - 1] + fdata;
				break;
			case FSUB:
				mFPRegisters[reg - 1] = mFPRegisters[reg - 1] - fdata;
				break;
			case FMUL:
				mFPRegisters[reg - 1] = mFPRegisters[reg - 1] * fdata;
				break;
			case FDIV:
				mFPRegisters[reg - 1] = mFPRegisters[reg - 1] / fdata;
				break;
		}
	}
}
