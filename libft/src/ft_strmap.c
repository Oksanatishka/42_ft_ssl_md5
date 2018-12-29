/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 21:41:53 by obibik            #+#    #+#             */
/*   Updated: 2018/12/28 21:41:53 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*p;
	int		i;

	if (!s)
		return (NULL);
	p = ft_strnew(ft_strlen(s));
	i = 0;
	if (!p)
		return (NULL);
	while (s[i] != '\0')
	{
		p[i] = f(s[i]);
		i++;
	}
	return (p);
}
