/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extstr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:51:32 by gbohm             #+#    #+#             */
/*   Updated: 2023/01/12 17:33:04 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_extstr2(char **str, size_t amount)
{
	size_t	len;
	char	*new_str;

	len = ft_strlen(*str);
	if (amount <= len)
		return (0);
	if (ft_calloc2(amount + 1, sizeof(char), (void **) &new_str))
		return (1);
	while (len--)
		new_str[len] = (*str)[len];
	free(*str);
	*str = new_str;
	return (0);
}
