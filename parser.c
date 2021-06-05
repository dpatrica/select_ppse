#include "sp.h"

static int pars_l(char **sp)
{
	int len;

	if (convert_16_10((int)**sp) > 7)
	{
		(*sp)++;
		if (convert_16_10((int)**sp) == 1)
		{
			len = two_convert_16_10((int)*(*sp + 1), (int)*(*sp + 2));
			*sp += 3;
		}
		else if (convert_16_10((int)**sp) == 2)
		{
			len = three_convert_16_10((int)*(*sp + 1), (int)*(*sp + 2),
										(int)*(*sp + 3), (int)*(*sp + 4));
			*sp += 5;
		}
		else // FIXME нужно сделать адаптивную функцию перевода чисел (не точно)
			len = 0;
	}
	else
	{
		len = two_convert_16_10((int)**sp, (int)*(*sp + 1));
		*sp += 2;
	}
	return (len);
}

static char *pars_t(char **sp)
{
	int large_tag;
	int size;
	char *str;

	size = 2;
	large_tag = is_large_tag(**sp, *(*sp + 1));
	while (large_tag)
	{
		size += 2;
		if (convert_16_10((int)*(*sp + (size - 2))) <= 7)
			large_tag = 0;
	}
	str = ft_strdup(*sp, size);
	*sp += size;
	return (str);
}

static t_tlv *constructed_pars(char **sp, t_tlv *tlv, int bytes)
{
	int i;
	int con_or_primitiv;
	char *old_sp;

	i = 0;
	while (**sp && bytes > 0)
	{
		tlv = add_struct(tlv);
		while (tlv[i].t)
			i++;
		con_or_primitiv = constructed_or_primitiv(**sp);
		old_sp = *sp;
		tlv[i].t = pars_t(sp);
		bytes -= (*sp - old_sp);
		old_sp = *sp;
		tlv[i].l = pars_l(sp);
		bytes -= (*sp - old_sp);
		if (con_or_primitiv)
		{
			tlv[i].tlv = init_tlv();
			tlv[i].tlv = constructed_pars(sp, tlv[i].tlv, tlv[i].l * 2);
		}
		else
		{
			tlv[i].v = ft_strdup(*sp, tlv[i].l * 2);
			*sp += tlv[i].l * 2;
		}
		bytes -= tlv[i].l * 2;
	}
	return (tlv);
}

static t_tlv *pars(char *sp, t_tlv *tlv)
{
	int i;
	int con_or_primitiv;

	i = 0;
	while (*sp && ft_strncmp(sp, "9000", 4))
	{
		tlv = add_struct(tlv);
		while (tlv[i].t)
			i++;
		con_or_primitiv = constructed_or_primitiv(*sp);
		tlv[i].t = pars_t(&sp);
		tlv[i].l = pars_l(&sp);
		if (con_or_primitiv)
		{
			tlv[i].tlv = init_tlv();
			tlv[i].tlv = constructed_pars(&sp, tlv[i].tlv, tlv[i].l * 2);
		}
		else
		{
			tlv[i].v = ft_strdup(sp, tlv[i].l * 2);
			sp += tlv[i].l * 2;
		}
	}
	return (tlv);
}

t_tlv *pars_tlv(char *sp)
{
	t_tlv *tlv;

	tlv = init_tlv();
	tlv = pars(sp, tlv);
	return (tlv);
}
