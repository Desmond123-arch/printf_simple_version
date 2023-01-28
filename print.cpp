#include "main.h"

/**
* printk - passes the formats and the argument list to the vprint function(varadic fucntion)
* @fmt: normal string passed in
*/
void printk(const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	vprintk(fmt, args);
}