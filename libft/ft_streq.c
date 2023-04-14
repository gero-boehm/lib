/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_streq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:04:18 by gbohm             #+#    #+#             */
/*   Updated: 2023/04/14 14:07:40 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_streq(char *haystack, char *needle)
{
	size_t	len;

	len = ft_strlen(needle);
	return (ft_strncmp(haystack, needle, len) == 0);
}
