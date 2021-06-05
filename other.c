#include "sp.h"

int constructed_or_primitiv(int c)
{
	if (c == '2' || c == '3' || c == '6' || c == '7' || c == 'A' || c == 'B' ||\
	c == 'E' || c == 'F')
		return (1);
	return (0);
}

int is_large_tag(int dig1, int dig2)
{
	if (dig2 == 'F' && (dig1 == '1' || dig1 == '3' || dig1 == '5' || dig1 == '7' ||\
	dig1 == '9' || dig1 == 'B' || dig1 == 'D' || dig1 == 'F'))
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
			while (spec)
			{
				write(1, "  ", 2);
				spec--;
			}
			spec = old_spec;
			printf("T: %s\n", tlv[i].t);
			while (spec)
			{
				write(1, "  ", 2);
				spec--;
			}
			spec = old_spec;
			printf("L: %d\n", tlv[i].l);
			while (spec)
			{
				write(1, "  ", 2);
				spec--;
			}
			spec = old_spec;
			printf("V: %s\n", tlv[i].v);
		}
		else
		{
			while (spec)
			{
				write(1, "  ", 2);
				spec--;
			}
			spec = old_spec;
			printf("T: %s\n", tlv[i].t);
			while (spec)
			{
				write(1, "  ", 2);
				spec--;
			}
			spec = old_spec;
			printf("L: %d\n", tlv[i].l);
			while (spec)
			{
				write(1, "  ", 2);
				spec--;
			}
			spec = old_spec;
			printf("val:\n");
			print_tlv(tlv[i].tlv, spec + 1);
		}
		i++;
	}
}