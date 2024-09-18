/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:59:37 by bwong             #+#    #+#             */
/*   Updated: 2022/07/14 14:59:39 by bwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	if (start < ft_strlen(s))
	{
		s += start;
		while (s[i] && i < len)
		{
			sub[i] = s[i];
			i++;
		}
	}
	sub[i] = '\0';
	return (sub);
}
