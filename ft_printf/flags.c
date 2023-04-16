/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:34:25 by gbohm             #+#    #+#             */
/*   Updated: 2023/04/16 11:00:46 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	has_left_justify_flag(t_tag *tag)
{
	return (tag->properties.left_justify);
}

int	has_plus_flag(t_tag *tag)
{
	return (tag->properties.plus);
}

int	has_space_flag(t_tag *tag)
{
	return (tag->properties.space);
}

int	has_prefix_flag(t_tag *tag)
{
	return (tag->properties.prefix);
}

int	has_zeroes_flag(t_tag *tag)
{
	return (tag->properties.zeroes);
}
