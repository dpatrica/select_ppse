#include "sp.h"

int constructed_or_primitiv(int c)
{
	if (c & 0b000000010)
		return (1);
	return (0);
}

int is_large_tag(int c)
{
	if ((c & 0b00011111) == 0b00011111)
		return (1);
	return (0);
}

void print_tlv(t_tlv *tlv, int spec)
{
	int i;
	int old_spec;

	old_spec = spec;
	i = 0;
	while (tlv[i].t)
	{
		if (tlv[i].v)
		{
			while (spec--)
				write(1, "  ", 2);
			spec = old_spec;
			printf("T: %s\n", tlv[i].t);
			while (spec--)
				write(1, "  ", 2);
			spec = old_spec;
			printf("L: %d\n", tlv[i].l);
			while (spec--)
				write(1, "  ", 2);
			spec = old_spec;
			printf("V: %s\n", tlv[i].v);
		}
		else
		{
			while (spec--)
				write(1, "  ", 2);
			spec = old_spec;
			printf("T: %s\n", tlv[i].t);
			while (spec--)
				write(1, "  ", 2);
			spec = old_spec;
			printf("L: %d\n", tlv[i].l);
			while (spec--)
				write(1, "  ", 2);
			spec = old_spec;
			write(1, "val:\n", 5);
			print_tlv(tlv[i].tlv, spec + 1);
		}
		i++;
	}
}

void free_tlv(t_tlv *tlv)
{
	int i;

	i = 0;
	while (tlv[i].t)
	{
		free(tlv[i].t);
		if (tlv[i].v)
			free(tlv[i].v);
		else
			free_tlv(tlv[i].tlv);
		i++;
	}
	free(tlv);
}

int len_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char **shift_left(char **rid_pix)
{
	int i;
	char **temp;
	int len_arr;

	len_arr = len_array(rid_pix);
	temp = (char**)malloc(sizeof(char*) * (len_arr + 1));
	temp[len_arr] = NULL;
	i = 0;
	while (++i < len_arr)
		temp[i - 1] = rid_pix[i];
	temp[i - 1] = rid_pix[0];
	free(rid_pix);
	return (temp);
}
