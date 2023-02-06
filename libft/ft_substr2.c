/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:05:51 by gbohm             #+#    #+#             */
/*   Updated: 2023/02/06 21:06:01 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_substr2(char const *s, unsigned int start, size_t len, char **sub)
{
	*sub = ft_substr(s, start, len);
	return (*sub == NULL);
}
