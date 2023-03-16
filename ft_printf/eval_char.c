/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:35:05 by gbohm             #+#    #+#             */
/*   Updated: 2023/03/16 13:24:33 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	set_char(char c, char *str)
{
	str[0] = c;
	str[1] = 0;
}

static void	set_result(char *str, t_tag *tag)
{
	tag->result.str = str;
	tag->result.size = 1;
}

int	eval_char(int value, t_tag *tag)
{
	char	*str;

	if (ft_malloc2(2, (void **) &str))
		return (1);
	set_char((char) value, str);
	set_result(str, tag);
	return (0);
}
