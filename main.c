#include "sp.h"

int main(int argc, char **argv)
{
	int i;
	t_tlv *tlv;
	char **rid_pix;

	if (argc == 1)
		return (ft_putstr_fd("Error!\nNo token.", 2));
	tlv = pars_tlv(argv[1]);
	write(1, "\n_TLV_\n", 7);
	print_tlv(tlv, 0);
	write(1, "END TLV\n\n", 9);
	rid_pix = sort_rid_pix(tlv);
	free_tlv(tlv);
	rid_pix = sort_priority_rid_pix(rid_pix);
	i = -1;
	while (rid_pix[++i])
	{
		printf("RID + PIX %d:\n%s\n", i + 1, rid_pix[i]);
		free(--(rid_pix[i]));
	}
	if (!i)
		write(1, "No valid RID + PIX\n", 19);
	free(rid_pix);
	return (0);
}
