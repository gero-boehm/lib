/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:02:58 by gbohm             #+#    #+#             */
/*   Updated: 2023/01/17 14:18:41 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

int	ft_strappend(char **dst, char *src, int src_length)
{
	char	*new;
	int		dst_length;

	if (dst == NULL || src == NULL)
		return (1);
	if (src_length == 0)
		return (0);
	dst_length = 0;
	while ((*dst)[dst_length])
		dst_length++;
	if (ft_calloc2(dst_length + src_length + 1, sizeof(char), (void **) &new))
		return (2);
	while (src_length--)
		new[dst_length + src_length] = src[src_length];
	while (dst_length--)
		new[dst_length] = (*dst)[dst_length];
	free(*dst);
	free(src);
	*dst = new;
	return (0);
}

int	has_newline(char *str)
{
	while (*str && *str != '\n')
		str++;
	return (*str == '\n');
}

char	*free_all(int c, ...)
{
	va_list	args;
	void	**buffer;

	va_start(args, c);
	while (c--)
	{
		buffer = va_arg(args, void **);
		if (buffer == NULL)
			continue ;
		free(*buffer);
		*buffer = NULL;
	}
	va_end(args);
	return (NULL);
}

char	*cut(char **str)
{
	int		i;
	int		length;
	char	*cut;
	char	*leftover;

	if (!**str)
		return (free_all(1, str));
	length = 0;
	while ((*str)[length] && (!length || (length
		&& (*str)[length - 1] != '\n')))
		length++;
	i = length;
	while ((*str)[i])
		i++;
	if (ft_calloc2(i - length + 1, sizeof(char), (void **) &leftover))
		return (free_all(1, str));
	while (i-- > length)
		leftover[i - length] = (*str)[i];
	if (ft_calloc2(length + 1, sizeof(char), (void **) &cut))
		return (free_all(2, str, &leftover));
	while (length--)
		cut[length] = (*str)[length];
	free(*str);
	*str = leftover;
	return (cut);
}
