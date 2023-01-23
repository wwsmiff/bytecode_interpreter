#ifndef DEFINITIONS_HPP_
#define DEFINITIONS_HPP_

#include <unordered_map>

static constexpr uint64_t POOLSIZE = 1024;

enum OperationSet : uint16_t
{
	MOV = 1,
	ADD, SUB, MUL, DIV,
	RPRINT,

	FMOV,
	FADD, FSUB, FMUL, FDIV,
	FPRINT
};

enum RegisterSet : uint16_t
{
	R1 = 1, R2, R3, R4, R5, R6, R7, R8,
};

enum FloatingPointRegisterSet: uint8_t
{
	FPR1 = 1, FPR2, FPR3, FPR4, FPR5, FPR6, FPR7, FPR8
};

static const char *OPERATION_TABLE[] = {
	"MOV",
	"ADD",
	"SUB",
	"MUL",
	"DIV",
	"RPRINT",

	// For floats
	"FMOV",
	"FADD",
	"FSUB",
	"FMUL",
	"FDIV",
	"FPRINT"
};

static const char *REGISTER_TABLE[] = {
	"R1", "R2", "R3","R4", 
	"R5", "R6", "R7", "R8",
};

static const char *FP_REGISTER_TABLE[] = {
	"FPR1", "FPR2", "FPR3", "FP4",
	"FPR5", "FPR6", "FPR7", "FPR8"
};

static const std::unordered_map<std::string, uint16_t> OPERATION_MAP = 
{
	{"MOV", MOV},
	{"ADD", ADD},
	{"SUB", SUB},
	{"MUL", MUL},
	{"DIV", DIV},
	{"RPRINT", RPRINT},

  {"FMOV", FMOV},
	{"FADD", FADD},
	{"FSUB", FSUB},
	{"FMUL", FMUL},
	{"FDIV", FDIV},
	{"FPRINT", FPRINT},
};

static const std::unordered_map<std::string, uint16_t> REGISTER_MAP =  
{
	{"R1", R1}, {"R2", R2}, {"R3", R3}, {"R4", R4},
	{"R5", R5}, {"R6", R6}, {"R7", R7}, {"R8", R8}
};

static const std::unordered_map<std::string, uint16_t> FP_REGISTER_MAP = 
{
	{"FPR1", FPR1}, {"FPR2", FPR2}, {"FPR3", FPR3}, {"FPR4", FPR4},
	{"FPR5", FPR5}, {"FPR6", FPR6}, {"FPR7", FPR7}, {"FPR8", FPR8}
};

#endif // DEFINITIONS_HPP_
