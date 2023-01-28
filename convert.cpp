#include "main.h"
/**
* unsigned_number_tostring - converts a number to a particular base and stores it in buffer
* @buffer: stores the numbers converted (possibility of buffer overflow) or not check line 66
* @buf: array for stroing the numbers converted temporarly
*
*/
void unsigned_number_tostring(uint64_t number, int base, char* buffer)
{
	//check if number is 0
	if (number == 0)
	{
		*buffer++ = '0';
		*buffer = 0;
		return;
	}
	//decalare buffer and set values to be zero
	char buf[65];
	for (int i = 0; i < 65; i++)
		buf[i] = 0;

	int cur = 0; //used to check number of digits

	//loop to convert to proper base
	//Stores converted number in reverse order
	while (number)
	{
		int digit = number % base;
		if (digit >= 10)
			buf[cur++] = 'a' + (digit - 10);
		else
		{
			buf[cur++] = '0' + digit;
		}
		number /= base;
	}
	//store numbers in correct order
	for (int i = cur - 1; i != 0; i--)
	{
		*buffer++ = buf[i];
	}
	*buffer++ = buf[0];
	*buffer = 0;

}
/**
* number_to_string - converts a singned number to an unsinged
* then calls the unsinged_number-tostring function
* @number: number to be checked
* @base: base the number is suppose to be converted to
* @buffer: location to store the converted numbers
*/
void number_to_string(int64_t number, int base, char* buffer)
{
	if (number < 0)
	{
		*buffer++ = '-';
		number = -number;
	}
	unsigned_number_tostring(number, base, buffer);
}