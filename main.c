#include "sp.h"

int main(int argc, char **argv)
{
	int i;
	t_tlv *tlv;
	char **rid_pix;

	if (argc == 1)
		return (ft_putstr_fd("Error!\nNo token.", 2));
	tlv = pars_tlv(argv[1]);
	print_tlv(tlv, 0);
	write(1, "END\n", 4);
	rid_pix = sort_rid_pix(tlv);
	rid_pix = sort_priority_rid_pix(rid_pix);
	i = -1;
	while (rid_pix[++i])
		printf("%s\n", rid_pix[i]);
	return (0);
}
