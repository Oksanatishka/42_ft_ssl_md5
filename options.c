/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 21:39:32 by obibik            #+#    #+#             */
/*   Updated: 2018/12/28 21:39:32 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

/*
** to parse flags -p/-q/-r/-s
*/

void		pars_entre(t_gen *g, int argc, char **argv)
{
	g->i = 2;
	g->f_p = 0;
	g->f_q = 0;
	g->f_r = 0;
	g->f_s = 0;
	while (g->i < argc)
	{
		if (ft_strcmp("-p", argv[g->i]) == 0)
			g->f_p = 1;
		else if (ft_strcmp("-q", argv[g->i]) == 0)
			g->f_q = 1;
		else if (ft_strcmp("-r", argv[g->i]) == 0)
			g->f_r = 1;
		else if (ft_strcmp("-s", argv[g->i]) == 0)
		{
			g->i++;
			g->f_s++;
		}
		else
			break ;
		g->i++;
	}
	g->nb_file = g->i - argc;
}

/*
** will add MD5 ("oks") =
*/

void		no_ro_s(t_gen *g, char **argv)
{
	if (!g->f_q)
	{
		if (ft_strcmp(argv[1], "sha256") == 0)
			ft_putstr("SHA256 (\"");
		else if (ft_strcmp(argv[1], "sha224") == 0)
			ft_putstr("SHA224 (\"");
		else
			ft_putstr("MD5 (\"");
		ft_putstr(argv[g->pars]);
		ft_putstr("\") = ");
	}
	if (ft_strcmp(argv[1], "sha256") == 0)
		go_sha256(argv[g->pars], g);
	else if (ft_strcmp(argv[1], "sha224") == 0)
		go_sha224(argv[g->pars], g);
	else
		go_md5(argv[g->pars], g);
	ft_putchar('\n');
}

/*
** if we use -r flag with -s flag
** will add g->pars string to the end
*/

void		rotate_s(t_gen *g, char **argv)
{
	if (ft_strcmp(argv[1], "sha256") == 0)
		go_sha256(argv[g->pars], g);
	else if (ft_strcmp(argv[1], "sha224") == 0)
		go_sha224(argv[g->pars], g);
	else
	{
		ft_printf("MD5 (\"%s\") = ", argv[g->pars]);
		go_md5(argv[g->pars], g);
	}
	if (!g->f_q)
		ft_printf(" \"%s\"\n", argv[g->pars]);
	else
		ft_putstr("\n");
}

int			print_s(t_gen *g, char **argv, int argc)
{
	if (ft_strcmp("-p", argv[g->pars]) == 0)
		g->f_p = 1;
	else if (ft_strcmp("-q", argv[g->pars]) == 0)
		g->f_q = 1;
	else if (ft_strcmp("-r", argv[g->pars]) == 0)
		g->f_r = 1;
	else if (ft_strcmp("-s", argv[g->pars]) == 0)
	{
		g->pars++;
		if (g->pars < argc)
		{
			if (!g->f_r)
				no_ro_s(g, argv);
			else
				rotate_s(g, argv);
		}
	}
	else
		return (-1);
	g->pars++;
	return (0);
}

/*
** if incorrect path to file was entered.
*/

int			no_such_file(t_gen *g, char **argv)
{
	if ((g->fd = open(argv[g->pars], O_RDWR)) < 0)
	{
		if (ft_strcmp(argv[1], "sha256") == 0)
			ft_putstr("ft_ssl: sha256: ");
		if (ft_strcmp(argv[1], "sha224") == 0)
			ft_putstr("ft_ssl: sha224: ");
		else
			ft_putstr("ft_ssl: md5: ");
		ft_putstr(argv[g->pars]);
		ft_putstr(": No such file or directory\n");
		g->pars++;
		return (-1);
	}
	return (0);
}
