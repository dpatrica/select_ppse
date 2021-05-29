#include "sp.h"

int convert_16_10(int dig1, int dig2)
{
	if (ft_isdigit(dig1))
		dig1 -= 48;
	else
		dig1 -= 55;
	if (ft_isdigit(dig2))
		dig2 -= 48;
	else
		dig2 -= 55;
	return ((16 * dig1) + dig2);
}