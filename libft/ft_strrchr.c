/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:58:08 by bwong             #+#    #+#             */
/*   Updated: 2022/07/14 14:58:11 by bwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	slen;

	slen = ft_strlen(s);
	s += slen;
	if (*s == (char)c)
		return ((char *)s);
	while (slen > 0)
	{
		s--;
		if (*s == (char)c)
			return ((char *)s);
		slen--;
	}
	return (NULL);
}
