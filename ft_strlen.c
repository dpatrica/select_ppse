#include "sp.h"

size_t		ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	if (str)
		while (str[n])
			n++;
	return (n);
}
