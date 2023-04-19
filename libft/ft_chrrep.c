/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrrep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:18:01 by gbohm             #+#    #+#             */
/*   Updated: 2023/04/19 11:23:26 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chrrep(char c, size_t n)
{
	char	*str;

	if (ft_malloc2(n + 1, (void **) &str))
		return (NULL);
	str[n] = 0;
	while (n--)
		str[n] = c;
	return (str);
}
