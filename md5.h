/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 21:39:32 by obibik            #+#    #+#             */
/*   Updated: 2018/12/28 21:39:32 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <unistd.h>
# include "libft/header/libft.h"

/*
** uint32_t is a numeric type that guarantees 32 bits, the value is unsigned, 
** meaning that the range of values goes from 0 to 232 - 1.
**
** uint8_t		unsigned char
** uint16_t		unsigned short
** uint32_t		unsigned int
** uint64_t		unsigned long long
**
**
** h0-h7 - These vars will contain the hash
** a-w   - temporary numbers
** f_p, f_q, f_r, f_s - flags
** tmp1-tmp6 - related to sha
*/

typedef struct		s_gen
{
	int				new_len;
	uint32_t		h0;
	uint32_t		h1;
	uint32_t		h2;
	uint32_t		h3;
	uint32_t		h4;
	uint32_t		h5;
	uint32_t		h6;
	uint32_t		h7;
	uint32_t		a;
	uint32_t		b;
	uint32_t		c;
	uint32_t		d;
	uint32_t		e;
	uint32_t		f;
	uint32_t		g;
	uint32_t		h;
	uint32_t		*w;
	unsigned char	*msg;
	uint32_t		*msg_32;
	int				i;
	uint32_t		tmp;
	uint32_t		bits_init_msg_len;
	int				offset;
	uint32_t		f_p;
	uint32_t		f_q;
	uint32_t		f_r;
	uint32_t		f_s;
	uint32_t		tmp1;
	uint32_t		tmp2;
	uint32_t		tmp3;
	uint32_t		tmp4;
	uint32_t		tmp5;
	uint32_t		tmp6;
	uint32_t		maj;
	uint32_t		ch;
	char			*stdin;
	int				nb_file;
	int				pars;
	int				fd;
}					t_gen;

int					md5(unsigned char *init_msg, size_t len, t_gen *g);
int					sha256(char *init_msg, size_t len, t_gen *g);
uint32_t			revers_uint32(uint32_t n);
uint64_t			revers_uint64(uint64_t n);
char				*add0(char *str);
void				fake_gnl(char **ptr);
void				fake_gnl_all(char **ptr, int fd);
void				go_md5(char *std, t_gen *g);
void				print_sha256(t_gen *g);
void				go_sha256(char *std, t_gen *g);
int					no_such_file(t_gen *g, char **argv);
int					print_s(t_gen *g, char **argv, int argc);
void				rotate_s(t_gen *g, char **argv);
void				no_ro_s(t_gen *g, char **argv);
void				pars_entre(t_gen *g, int argc, char **argv);
void				ft_bonus_ssl(t_gen *g, int confirm, char *red);
int					sha224(char *init_msg, size_t len, t_gen *g);
uint32_t			rigthrotat(uint32_t x, uint32_t n);
void				go_sha224(char *std, t_gen *g);
void				error(char *red);
void				extra(t_gen *g, char **argv);
#endif
