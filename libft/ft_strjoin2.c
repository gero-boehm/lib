/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:42:05 by gbohm             #+#    #+#             */
/*   Updated: 2023/02/08 19:25:13 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_strjoin2(char **dst, const char *src)
{
	char	*new;

	new = ft_strjoin(*dst, src);
	free(*dst);
	*dst = new;
	return (new == NULL);
}
