/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:02:23 by gbohm             #+#    #+#             */
/*   Updated: 2023/04/16 11:00:46 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	is_hex_lower_specifier(t_tag *tag)
{
	return (tag->properties.specifier == 'x');
}

int	is_hex_upper_specifier(t_tag *tag)
{
	return (tag->properties.specifier == 'X');
}

int	is_hex_specifier(t_tag *tag)
{
	return (is_hex_lower_specifier(tag) || is_hex_upper_specifier(tag));
}

int	is_ptr_specifier(t_tag *tag)
{
	return (tag->properties.specifier == 'p');
}

int	is_num_specifier(t_tag *tag)
{
	return (is_hex_specifier(tag)
		|| is_unsigned_specifier(tag)
		|| is_int_specifier(tag));
}
