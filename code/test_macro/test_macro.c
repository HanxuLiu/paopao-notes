/*================================================================
*  Author: liu-paopao
*  Date: 2023-07-14
*  Description: Demo for gdb to expand macro
================================================================*/

#include<stdio.h>
#define SHIFT 26
#define DECODE(insn) ((insn & 0xfc000000) >> SHIFT)

int main()
{
	unsigned long insn = 0xe9d8c7d6;
	unsigned long opcode = DECODE(insn);
	printf("insn = 0x%lx, opcode = 0x%lx\n", insn, opcode);
	return 0;
}
