/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepl2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:43:58 by gbohm             #+#    #+#             */
/*   Updated: 2023/02/08 20:47:25 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_strrepl2(char **str, char *find, char *repl)
{
	char	*new;

	new = ft_strrepl(*str, find, repl);
	free(*str);
	*str = new;
	return (new == NULL);
}
