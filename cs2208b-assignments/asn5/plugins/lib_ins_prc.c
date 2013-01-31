/*******************************************************************************
 *
 * File         : lib_ins_prc.c
 * Author       : Jeff Shantz <x@y, x = jshantz4, y = csd.uwo.ca>
 * Last Updated : March 29, 2012
 *
 * Implements the 'prc' synthetic instruction (print char). This moves the value
 * REQ_PRINT_CHAR (defined in western2208.h) into the I/O register, which 
 * tells the CPU to print the value stored in register %r1 as an character.
 * 
 ******************************************************************************/

#include "assembler_plugin.h"
#include <stdio.h>
#include <stdlib.h>

char mnemonic[] = "prc";

void handle(int pass, instruction_t i, void (*emit)(int, instruction_t)) 
{
	if (i.operand_count != 0)
	{
		fprintf(stderr, "Invalid arguments for 'prc'\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		emit(pass, ins("mov", 2, imm(REQ_PRINT_CHAR), reg(REG_IO)));
	}
	
}
