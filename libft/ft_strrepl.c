/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:57:11 by gbohm             #+#    #+#             */
/*   Updated: 2023/02/08 20:50:28 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_count(char *str, char *find, size_t len)
{
	int		count;
	char	*tmp;

	tmp = str;
	count = 0;
	while (1)
	{
		tmp = ft_strnstr(tmp, find, len);
		if (tmp == NULL)
			break ;
		tmp++;
		count++;
	}
	return (count);
}

static void	replace(char *str, char *find, char *repl, char *new)
{
	char	*tmp;
	size_t	len;
	size_t	len_find;
	size_t	len_repl;

	len = ft_strlen(str);
	len_find = ft_strlen(find);
	len_repl = ft_strlen(repl);
	while (1)
	{
		tmp = ft_strnstr(str, find, len);
		if (tmp == NULL)
		{
			ft_strlcpy(new, str, ft_strlen(str) + 1);
			return ;
		}
		ft_strlcpy(new, str, tmp - str + 1);
		new += tmp - str;
		ft_strlcpy(new, repl, len_repl + 1);
		str = tmp + len_find;
		new += len_repl;
	}
}

char	*ft_strrepl(char *str, char *find, char *repl)
{
	size_t	len;
	size_t	new_len;
	int		count;
	char	*new;

	if (str == NULL || find == NULL || repl == NULL)
		return (NULL);
	len = ft_strlen(str);
	count = get_count(str, find, len);
	new_len = len + (ft_strlen(repl) - ft_strlen(find)) * count;
	if (ft_malloc2(new_len + 1, (void **) &new))
		return (NULL);
	replace(str, find, repl, new);
	return (new);
}
