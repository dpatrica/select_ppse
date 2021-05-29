#include "sp.h"

char **pars_sp(char *sp)
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
	return (app_tem);
}
