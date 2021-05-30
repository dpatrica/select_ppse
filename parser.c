#include "sp.h"

char **only_rid_pix(char **rid_pix)
{
	int i;
	int j;
	int size;
	char *temp;

	i = 0;
	while (rid_pix[i])
	{
		j = 0;
		while (rid_pix[i][j])
		{
			if (rid_pix[i][j] == '4' && rid_pix[i][j + 1] == 'F')
			{
				size = (convert_16_10((int)rid_pix[i][j + 2], (int)rid_pix[i][j + 3])) * 2;
				temp = ft_strdup(&rid_pix[i][j + 4], size);
				free(rid_pix[i]);
				rid_pix[i] = temp;
			}
			j++;
		}
		i++;
	}
	return (rid_pix);
}

char **sort_rid_pix(char **rid_pix)
{
	int i;
	int j;
	int priority1;
	int priority2;

	i = 0;
	while (rid_pix[i])
	{
		j = 0;
		while (rid_pix[i][j])
		{
			if (rid_pix[i][j] == '8' && rid_pix[i][j + 1] == '7')
			{
				if (!i)
				{
					priority1 = convert_16_10((int)rid_pix[i][j + 4], (int)rid_pix[i][j + 5]);
					if (!priority1)
						priority1 = 256;
				}
				else
				{
					priority2 = convert_16_10((int)rid_pix[i][j + 4], (int)rid_pix[i][j + 5]);
					if (!priority2)
						priority2 = 256;
					if (priority1 > priority2)
					{
						rid_pix = swap_array(rid_pix, i - 1, i);
						i = -1;
					}
					else
						priority1 = priority2;
				}
				break ;
			}
			j++;
		}
		i++;
	}
	return (rid_pix);
}

char **pars_valid_rid_pix(char **rid_pix)
{
	int i;
	int j;
	int search;

	i = 0;
	while (rid_pix && rid_pix[i])
	{
		j = 0;
		search = 0;
		while (rid_pix[i][j])
		{
			if (rid_pix[i][j] == '4' && rid_pix[i][j + 1] == 'F' && ++search)
				if (ft_strncmp(&rid_pix[i][j + 4], "A000000658", 10))
				{
					search = 0;
					break ;
				}
			j++;
		}
		if (!search)
			rid_pix = delete_arr(rid_pix, i);
		else
			i++;
	}
	return (rid_pix);
}

char **pars_application_template(char *sp)
{
	int i;
	int count;
	char **app_tem;

	i = 0;
	app_tem = add_first_array();
	while (*sp)
	{
		count = 1;
		if (*sp == '6' && *(sp + 1) == '1')
		{
			sp += 4;
			count = (convert_16_10((int)*(sp - 2), (int)*(sp - 1))) * 2;
			if (!app_tem[i])
				app_tem = add_array(app_tem, i);
			app_tem[i] = ft_strdup(sp, count);
			i++;
		}
		sp += count;
	}
	if (!i)
	{
		free(app_tem);
		app_tem = NULL;
	}
	return (app_tem);
}
