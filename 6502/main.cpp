#include <iostream>

using Byte = unsigned char;
using Word = unsigned short;
using u32  = unsigned int;
struct Mem {

	static constexpr u32 MAX_MEM = 1024 * 64;
	Byte Data[MAX_MEM];

	void Initialize()
	{
		for (u32 i = 0; i < MAX_MEM; ++i)
		{
			Data[i] = 0;
		}
	}

	Byte operator[] (u32 Address) const
	{
		return Data[Address];
	}

};

struct CPU{

	Word PC; // Program couter.
	Word SP; // Srack Pointer.

	Byte A , X , Y;
	
	// Status flags
	
	Byte C : 1; 
	Byte Z : 1; 
	Byte I : 1; 
	Byte D : 1; 
	Byte B : 1; 
	Byte V : 1; 
	Byte N : 1; 

	void reset(Mem& memory)
	{
		PC = 0xFFFC;
		SP = 0x0100;
		C = Z = I = D = B = V = N = 0;
		A = X = Y = 0;
		memory.Initialize();
	}

	
	Byte FetchByte(u32& Cycles, Mem& memory)
	{
		Byte Data = memory[PC];
		++PC;
		Cycles--;	
	}

	static constexpr Byte
		INS_LDA_IM = 0xA9;

	void exec(u32 Cycles, Mem& memory)
	{
		while ( Cycles > 0 )
		{
			Byte Ins = FetchByte( Cycles , memory); // Fetch the next Instruction from memory.
			
			switch ( Ins )
			{
				case INS_LDA_IM :
				{
					Byte Value = FetchByte( Cycles, memory );
					A = Value;
					Z = (A == 0);
					N = (A & 0b10000000) > 0;
					
				} break;

				default :
				{
					std::cerr<<"Instruction "<<Ins<<"not handled."<<std::endl;
				} break;

			}	
		}		
	}	

};



	int main()
{
	Mem mem;
	CPU cpu;
	
	cpu.reset(mem);
	
	mem[0xFFFC] = CPU::INS_LDA_IM;
	mem[0xFFFD] = 0xFF;

	cpu.exec(2,mem);

}



	int a = 1;
