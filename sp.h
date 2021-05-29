#ifndef SP_H
#define SP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char		**pars_sp(char *sp);
size_t		ft_strlen(const char *str);
int			ft_putstr_fd(char *s, int fd);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			convert_16_10(int dig1, int dig2);
char		*ft_strdup(const char *s1, int size);
char		**add_first_array(void);
char		**add_array(char **array, int i);

#endif
