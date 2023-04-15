/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:52:13 by gbohm             #+#    #+#             */
/*   Updated: 2023/04/15 11:25:21 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

static int	run(va_list args, t_buffer *buffer)
{
	t_tag	tag;

	while (1)
	{
		if (advance_cursor(buffer))
			return (0);
		if (parse_tag(buffer, &tag))
			return (1);
		if (evaluate(args, &tag))
			return (2);
		if (apply_flags(&tag))
			return (free_tag(&tag), 3);
		if (substitute(&tag, buffer))
			return (free_tag(&tag), 4);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_buffer	buffer;
	size_t		printed;

	va_start(args, format);
	if (init_buffer(format, &buffer))
		return (-1);
	if (run(args, &buffer))
		return (free_buffer(&buffer), -1);
	va_end(args);
	printed = write(1, buffer.str, buffer.size);
	free_buffer(&buffer);
	return (printed);
}

int	ft_sprintf(char **res, const char *format, ...)
{
	va_list		args;
	t_buffer	buffer;

	va_start(args, format);
	if (init_buffer(format, &buffer))
		return (-1);
	if (run(args, &buffer))
		return (free_buffer(&buffer), -1);
	va_end(args);
	*res = buffer.str;
	return (buffer.size);
}

int	ft_fdprintf(int fd, const char *format, ...)
{
	va_list		args;
	t_buffer	buffer;
	size_t		printed;

	va_start(args, format);
	if (init_buffer(format, &buffer))
		return (-1);
	if (run(args, &buffer))
		return (free_buffer(&buffer), -1);
	va_end(args);
	printed = write(fd, buffer.str, buffer.size);
	free_buffer(&buffer);
	return (printed);
}
