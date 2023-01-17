/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:50:18 by gbohm             #+#    #+#             */
/*   Updated: 2022/12/01 16:08:46 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	length;
	long	difference;
	char	*sub;

	if (s == NULL)
		return (NULL);
	length = ft_strlen(s);
	difference = length - start;
	if (difference < 0)
		return (ft_calloc(1, 1));
	if (len > (unsigned long) difference)
		len = difference;
	sub = malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	sub[len] = 0;
	while (len-- > 0)
		sub[len] = s[start + len];
	return (sub);
}
