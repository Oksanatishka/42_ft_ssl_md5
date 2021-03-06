/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 21:41:53 by obibik            #+#    #+#             */
/*   Updated: 2018/12/28 21:41:53 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char *csrc;
	unsigned char		*cdst;
	size_t				i;

	i = 0;
	csrc = (const unsigned char*)src;
	cdst = (unsigned char*)dst;
	while (n > i)
	{
		cdst[i] = csrc[i];
		if (cdst[i] == (unsigned char)c)
			return ((void *)cdst + i + 1);
		i++;
	}
	return (NULL);
}
