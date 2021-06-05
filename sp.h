#ifndef SP_H
#define SP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_tlv
{
	char			*t;
	int				l;
	char			*v;
	struct s_tlv	*tlv;
}				t_tlv;

t_tlv		*init_tlv(void);
t_tlv		*pars_tlv(char *sp);
int			constructed_or_primitiv(int c);
int			is_large_tag(int dig1, int dig2);
int			convert_16_10(int dig);
int			two_convert_16_10(int dig1, int dig2);
int			three_convert_16_10(int dig1, int dig2, int dig3, int dig4);
t_tlv		*add_struct(t_tlv *tlv);
void		print_tlv(t_tlv *tlv, int spec);
char		**pars_application_template(char *sp);
size_t		ft_strlen(const char *str);
int			ft_putstr_fd(char *s, int fd);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
char		*ft_strdup(const char *s1, int size);
char		**add_first_array(void);
char		**add_array(char **array, int i);
char		**pars_valid_rid_pix(char **rid_pix);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		**delete_arr(char **array, int del);
char		**sort_rid_pix(char **rid_pix);
char		**swap_array(char **array, int first, int last);
char		**only_rid_pix(char **rid_pix);

#endif
