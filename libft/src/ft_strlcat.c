/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 21:41:53 by obibik            #+#    #+#             */
/*   Updated: 2018/12/28 21:41:53 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		slen;
	size_t		dlen;

	d = dst;
	s = src;
	slen = dstsize;
	while (slen-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	slen = dstsize - dlen;
	if (slen == 0)
		return (dlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (slen != 1)
		{
			*d++ = *s;
			slen--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
