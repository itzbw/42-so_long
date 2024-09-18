/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:16:46 by bwong             #+#    #+#             */
/*   Updated: 2022/07/14 14:28:24 by bwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joint;
	size_t	bufsize;

	if (!s1 || !s2)
		return (NULL);
	bufsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!s1 || !s2)
		return (NULL);
	joint = (char *)malloc(sizeof(char) * bufsize);
	if (!joint)
		return (NULL);
	ft_strlcpy(joint, s1, bufsize);
	ft_strlcat(joint, s2, bufsize);
	return (joint);
}
