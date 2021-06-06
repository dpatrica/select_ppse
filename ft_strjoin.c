#include "sp.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;
	char	*rar;
	char	*temp;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!s1 || !s2)
		return (NULL);
	if ((arr = malloc(len * sizeof(char))) == NULL)
		return (NULL);
	temp = s1;
	rar = arr;
	while (*s1)
		*arr++ = *s1++;
	while (*s2)
		*arr++ = *s2++;
	*arr = '\0';
	free(temp);
	return (rar);
}
