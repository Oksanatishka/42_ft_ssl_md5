/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 21:39:32 by obibik            #+#    #+#             */
/*   Updated: 2018/12/28 21:39:32 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

/*
** used in go_md5/go_sha256/go_sha224
*/

char		*add0(char *str)
{
	int i;

	i = ft_strlen(str);
	while (i < 8)
	{
		ft_putchar('0');
		i++;
	}
	return (str);
}

/*
** used in go_md5/go_sha256/go_sha224
*/

uint32_t	revers_uint32(uint32_t n)
{
	return ((n >> 24) | ((n & 0xff0000) >> 8) |
		((n & 0xff00) << 8) | (n << 24));
}

/*
** not used
*/

uint64_t	revers_uint64(uint64_t n)
{
	return ((n & 0xff00000000000000) >> 56 \
			| (n & 0x00ff000000000000) >> 40 \
			| (n & 0x0000ff0000000000) >> 24 \
			| (n & 0x000000ff00000000) >> 8 \
			| (n & 0x00000000ff000000) << 8 \
			| (n & 0x0000000000ff0000) << 24 \
			| (n & 0x000000000000ff00) << 40 \
			| (n & 0x00000000000000ff) << 56);
}

/*
** used in main.c
*/

void		fake_gnl(char **ptr)
{
	char	c[2];
	int		verif;
	char	*str;
	char	*tmp;

	verif = 42;
	c[1] = 0;
	str = ft_strdup("");
	while (verif > 0)
	{
		verif = read(0, c, 1);
		if (c[0] == 10)
			verif = 0;
		if (verif == 0)
			break ;
		tmp = str;
		str = ft_strjoin(str, c);
		free(tmp);
	}
	ptr[0] = str;
}

/*
** used in main.c
*/

void		fake_gnl_all(char **ptr, int fd)
{
	char	c[2];
	int		verif;
	char	*str;
	char	*tmp;

	c[1] = 0;
	verif = 42;
	str = ft_strdup("");
	while (verif > 0)
	{
		verif = read(fd, c, 1);
		if (verif == 0)
		{
			break ;
		}
		tmp = str;
		str = ft_strjoin(str, c);
		free(tmp);
	}
	ptr[0] = str;
}
