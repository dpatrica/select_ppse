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

char	**delete_arr(char **array, int del)
{
	int i;
	int j;
	char **arr;

	i = 0;
	while (array[i])
		i++;
	if (i == 1)
	{
		free(array[0]);
		free(array);
		return (NULL);
	}
	arr = (char**)malloc(sizeof(char*) * i);
	arr[i - 1] = NULL;
	i = 0;
	j = 0;
	while (array[i])
	{
		if (i == del)
			free(array[i++]);
		else
			arr[j++] = array[i++];
	}
	free(array);
	return (arr);
}

char	**swap_array(char **array, int first, int last)
{
	char *temp;

	temp = array[first];
	array[first] = array[last];
	array[last] = temp;
	return (array);
}