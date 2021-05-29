#include "sp.h"

char	*ft_strdup(const char *s1, int size)
{
	char	*arr;
	char	*rar;

	if (s1 == NULL)
		return (NULL);
	if ((arr = malloc((size + 1) * sizeof(char))) == NULL)
		return (NULL);
	rar = arr;
	while (*s1 && size--)
		*arr++ = *s1++;
	*arr = '\0';
	return (rar);
}
