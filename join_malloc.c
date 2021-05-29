#include "sp.h"

char	**add_first_array(void)
{
	char **array;

	array = (char**)malloc(sizeof(char*) * 2);
	array[1] = NULL;
	return (array);
}

char	**add_array(char **array, int i)
{
	char	**temp;
	int		k;

	k = -1;
	if (!array)
		return (NULL);
	temp = array;
	array = (char**)malloc(sizeof(char*) * (i + 2));
	while (temp[++k])
		array[k] = temp[k];
	free(temp);
	array[++k] = NULL;
	return (array);
}
