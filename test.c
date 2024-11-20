#include "ft_printf.h"
#include <stdlib.h>
#include	<stdio.h>

int main()
{
	ft_printf("%#-10.6X|\n", 42);
	printf("%#-10.6X|\n", 42);
}
