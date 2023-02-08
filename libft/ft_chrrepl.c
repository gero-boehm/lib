/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrrepl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:54:27 by gbohm             #+#    #+#             */
/*   Updated: 2023/02/08 19:23:56 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_charrepl(char *str, char find, char repl)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == find)
		{
			*str = repl;
			count++;
		}
	}
	return (count);
}
