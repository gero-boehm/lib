/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isqrt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:24:21 by gbohm             #+#    #+#             */
/*   Updated: 2023/03/22 20:33:51 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_isqrt(unsigned int num)
{
	unsigned int	i;

	if (num == 0)
		return (0);
	if (num < 4)
		return (1);
	i = 2;
	while (i * i < num)
		i++;
	if (i * i > num)
		i--;
	return (i);
}
