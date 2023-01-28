#include "main.h"
/**
* vprintk - checks the format to be printed(does the acutual printing)
* @fmt - string passed in with the formats
* @args - arguments to repalce the format specifiers with
*/
void vprintk(const char* fmt, va_list args)
{

	//State:check whether the current char is an escape sequence or is regular
	//0: regular
	//1:escape sequence
	int state = 0;
	while (*fmt)
	{
		char number_buffer[65];
		if (state == 0)
		{
			if (*fmt == '%')
			{
				state = 1;
			}
			else
			{
				putchar(*fmt);
			}
		}
		else if (state == 1)
		{
			switch (*fmt)
			{
			case 'c':
			{
				char ch = va_arg(args, int);
				putchar(ch);
				break;
			}
			case 's':
			{
				const char* s = va_arg(args, const char*);
				if (s == NULL)
				{
					s = "(NULL)";
				}
				while (*s)
				{
					putchar(*s++);
				}
			}
			break;
			case 'd':
			{
				int n = va_arg(args, int);
				number_to_string(n, 10, number_buffer);
				for (int i = 0; number_buffer[i]; i++)
				{
					putchar(number_buffer[i]);
				}
				break;
			}
			case 'x':
			{
				int n = va_arg(args, int);

				number_to_string(n, 16, number_buffer);
				for (int i = 0; number_buffer[i]; i++)
				{
					putchar(number_buffer[i]);
				}
				break;
			}
			case 'p':
			{
				putchar('0');
				putchar('x');

				void* n = va_arg(args, void*);
				//unit_64 used because thats how memory addresses work
				number_to_string((uint64_t)n, 16, number_buffer);
				for (int i = 0; number_buffer[i]; i++)
				{
					putchar(number_buffer[i]);
				}
				break;
			}

			}
			state = 0;
		}
		fmt++;
	}
}