#include "sp.h"

int main(int argc, char **argv)
{
	int i;
	int n;
	char **rid_pix;

	rid_pix = NULL;
	i = 1;
	if (argc == 1)
		return (ft_putstr_fd("Error!\nNo token.", 2));
	while (--argc)
	{
		rid_pix = pars_application_template(argv[i]);
		if (rid_pix)
			rid_pix = pars_valid_rid_pix(rid_pix);
		if (rid_pix)
		{
			rid_pix = sort_rid_pix(rid_pix);
			rid_pix = only_rid_pix(rid_pix);
		}
		n = -1;
		while (rid_pix && rid_pix[++n])
		{
			printf("RID + PIX %d:\n%s\n", n + 1, rid_pix[n]);
			free(rid_pix[n]);
		}
		if (rid_pix)
			free(rid_pix);
		write(1, "\n", 1);
		i++;
	}
	write(1, "END\n", 4);
	return (0);
}
