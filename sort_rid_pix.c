#include "sp.h"

static char **pars_value_87(t_tlv *tlv, char **rid_pix)
{
	int i;

	i = 0;
	while (rid_pix[i])
		i++;
	if (i)
		rid_pix[i - 1][0] = tlv->v[1];
	return (rid_pix);
}

static char **pars_value_4f(t_tlv *tlv, char **rid_pix)
{
	int i;

	i = 0;
	while (rid_pix[i])
		i++;
	if (i)
		rid_pix[i - 1] = ft_strjoin(rid_pix[i - 1], tlv->v);
	rid_pix = add_array(rid_pix, i);
	return (rid_pix);
}

static char **app_tem_sort(t_tlv *tlv, char **rid_pix)
{
	int i;

	i = -1;
	while (tlv[++i].t)
	{
		if (!ft_strncmp(tlv[i].t, "4F", 2) &&\
        !ft_strncmp(tlv[i].v, "A000000658", 10))
			rid_pix = pars_value_4f(&tlv[i], rid_pix);
		else if (!ft_strncmp(tlv[i].t, "87", 2))
			rid_pix = pars_value_87(&tlv[i], rid_pix);
	}
	return (rid_pix);
}

static char **sort_plus(t_tlv *tlv, char **rid_pix)
{
	int i;

	i = -1;
	while (tlv[++i].t)
	{
		if (!ft_strncmp(tlv[i].t, "61", 2))
			rid_pix = app_tem_sort(tlv[i].tlv, rid_pix);
		else if (&(tlv[i].tlv->t))
				rid_pix = sort_plus(tlv[i].tlv, rid_pix);
	}
	return (rid_pix);
}

char **sort_rid_pix(t_tlv *tlv)
{
	int i;
	char **rid_pix;

	i = -1;
	rid_pix = add_first_array();
	while (tlv[++i].t)
	{
		if (!ft_strncmp(tlv[i].t, "61", 2))
			rid_pix = app_tem_sort(tlv[i].tlv, rid_pix);
		else if (&(tlv[i].tlv->t))
				rid_pix = sort_plus(tlv[i].tlv, rid_pix);
	}
	i = len_array(rid_pix);
	free(rid_pix[--i]);
	rid_pix[i] = NULL;
	return (rid_pix);
}

char **sort_priority_rid_pix(char **rid_pix)
{
	int len;

	len = len_array(rid_pix);
	for (int i = 0 ; i < len ; i++)
		for (int j = i + 1 ; j < len ; j++)
			if (rid_pix[j][0] < rid_pix[i][0])
				rid_pix = swap_array(rid_pix, i, j);
	for (int i = 0 ; i < len ; i++)
		if (rid_pix[0][0] == '0')
			rid_pix = shift_left(rid_pix);
	for (int i = 0 ; i < len ; i++)
		*(rid_pix[i])++ = '\0';
	return (rid_pix);
}
