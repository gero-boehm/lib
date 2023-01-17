/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:25:38 by gbohm             #+#    #+#             */
/*   Updated: 2023/01/17 14:15:16 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

// int	get_fd(int fd, t_list *links, t_list **link)
// {
// 	t_list	*new;

// 	while (1)
// 	{
// 		if (links->fd == fd)
// 		{
// 			*link = links;
// 			return (0);
// 		}
// 		if (links->next == NULL)
// 			break ;
// 		links = links->next;
// 	}
// 	if (ft_calloc2(1, sizeof(t_list), (void **) &new))
// 		return (1);
// }

char	*get_next_line(int fd)
{
	static char	*last = NULL;
	char		*buffer;
	int			bytes_read;

	if ((fd < 0) || (BUFFER_SIZE <= 0)
		|| (last == NULL && ft_calloc2(1, sizeof(char), (void **) &last)))
		return (NULL);
	while (1)
	{
		if (has_newline(last))
			return (cut(&last));
		if (ft_calloc2(BUFFER_SIZE + 1, sizeof(char), (void **) &buffer))
			return (free_all(1, &last));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			if (bytes_read == -1)
				return (free_all(1, &last));
			return (cut(&last));
		}
		if (ft_strappend(&last, buffer, bytes_read))
			return (free_all(2, &buffer, &last));
	}
	return (NULL);
}
