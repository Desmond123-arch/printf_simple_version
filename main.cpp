#include <stdio.h>
#include "main.h"



/*
* main - test the fucntion
*/
int main(void)
{
	void* pointer_to_main = (void*)main;
	printk("Print a character:%c, Done\n", 'H');
	printk("Print a string:%s. Done\n", "Hello World");
	printk("Print a integer:%d. Done\n", 10);
	printk("Print a neg integer:%d. Done\n", -10);
	printk("Print a zero integer:%d. Done\n", 0);
	printk("Print a hex integer:%x. Done\n", 10);
	printk("Print a zero hex integer:%x. Done\n", 0);
	printk("Print a pointer:%p. Done\n", pointer_to_main);


}