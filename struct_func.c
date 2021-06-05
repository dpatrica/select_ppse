#include "sp.h"

static t_tlv *init_struct(t_tlv *tlv)
{
	tlv->t = NULL;
	tlv->l = 0;
	tlv->v = NULL;
	tlv->tlv = NULL;
	return (tlv);
}

t_tlv *init_tlv(void)
{
	t_tlv *tlv;

	tlv = (t_tlv*)malloc(sizeof(t_tlv));
	init_struct(tlv);
	return (tlv);
}

t_tlv *add_struct(t_tlv *tlv)
{
	t_tlv *new_tlv;
	int i;

	i = 0;
	while (tlv[i].t)
		i++;
	new_tlv = (t_tlv*)malloc(sizeof(t_tlv) * (i + 2));
	init_struct(&new_tlv[i++]);
	init_struct(&new_tlv[i]);
	i = -1;
	while (tlv[++i].t)
		new_tlv[i] = tlv[i];
	free(tlv);
	return (new_tlv);
}
