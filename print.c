/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 21:39:32 by obibik            #+#    #+#             */
/*   Updated: 2018/12/28 21:39:32 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

/*
** go_md5 f-n contains 4 parts of hash value
**
** unsigned_itoa_base - Converts an integer value to a null-terminated string
** using the specified base:
** 10 means decimal base;
** 16 hexadecimal;
** 8 octal;
** 2 binary.
**
** add0 - to add zero at the beginning of hex string(containing of 8 chars).
*/

void		go_md5(char *std, t_gen *g)
{
	char	*tmp;

	if (md5((uint8_t *)std, ft_strlen(std), g) == -1)
		return ;
	tmp = unsigned_itoa_base(revers_uint32(g->h0), 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(revers_uint32(g->h1), 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(revers_uint32(g->h2), 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(revers_uint32(g->h3), 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
}

void		print_sha256(t_gen *g)
{
	char	*tmp;

	tmp = unsigned_itoa_base(g->h3, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h4, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h5, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h6, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h7, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
}

void		go_sha256(char *std, t_gen *g)
{
	char	*tmp;

	if (sha256(std, ft_strlen(std), g) == -1)
		return ;
	tmp = unsigned_itoa_base(g->h0, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h1, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h2, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	print_sha256(g);
}

void		print_sha224(t_gen *g)
{
	char	*tmp;

	tmp = unsigned_itoa_base(g->h3, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h4, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h5, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h6, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
}

void		go_sha224(char *std, t_gen *g)
{
	char	*tmp;

	if (sha224(std, ft_strlen(std), g) == -1)
		return ;
	tmp = unsigned_itoa_base(g->h0, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h1, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h2, 16);
	add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	print_sha224(g);
}
