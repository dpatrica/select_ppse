#include "sp.h"

int main(int argc, char **argv)
{
	t_tlv *tlv;

	if (argc == 1)
		return (ft_putstr_fd("Error!\nNo token.", 2));
	tlv = pars_tlv(argv[1]);
	print_tlv(tlv, 0);
	write(1, "END\n", 4);
	return (0);
}
