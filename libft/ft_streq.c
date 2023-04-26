/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_streq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:04:18 by gbohm             #+#    #+#             */
/*   Updated: 2023/04/26 10:26:43 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_streq(char *haystack, char *needle)
{
	size_t	len_h;
	size_t	len_n;

	len_h = ft_strlen(haystack);
	len_n = ft_strlen(needle);
	if (len_h != len_n)
		return (0);
	return (ft_strncmp(haystack, needle, len_n) == 0);
}
