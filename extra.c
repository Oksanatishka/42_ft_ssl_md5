/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 21:39:32 by obibik            #+#    #+#             */
/*   Updated: 2018/12/28 21:39:32 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void	extra(t_gen *g, char **argv)
{
	if (ft_strcmp(argv[1], "sha256") == 0)
		go_sha256(g->stdin, g);
	else if (ft_strcmp(argv[1], "sha224") == 0)
		go_sha224(g->stdin, g);
	else
		go_md5(g->stdin, g);
	if (!g->f_q)
		printf(" %s\n", argv[g->pars]);
	else
		ft_printf("\n");
}
