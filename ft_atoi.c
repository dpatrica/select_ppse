#include "sp.h"

int	ft_atoi(const char *str)
{
	long int	num;
	int			i;
	int			sign;

	sign = 1;
	i = 0;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		i++;
		if ((num > 2147483647) && (sign == 1))
			return (2147483647);
		if ((num > 2147483648) && (sign == -1))
			return (-1);
	}
	return (num * sign);
}
