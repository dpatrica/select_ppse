#include "sp.h"

int convert_16_10(int dig)
{
	if (ft_isdigit(dig))
		dig -= 48;
	else
		dig -= 55;
	return (dig);
}

int two_convert_16_10(int dig1, int dig2)
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

int three_convert_16_10(int dig1, int dig2, int dig3, int dig4)
{
	if (ft_isdigit(dig1))
		dig1 -= 48;
	else
		dig1 -= 55;
	if (ft_isdigit(dig2))
		dig2 -= 48;
	else
		dig2 -= 55;
	if (ft_isdigit(dig3))
		dig3 -= 48;
	else
		dig3 -= 55;
	if (ft_isdigit(dig4))
		dig4 -= 48;
	else
		dig4 -= 55;
	return ((4096 * dig1) + (256 * dig2) + (16 * dig3) + dig4);
}
