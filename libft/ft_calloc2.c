/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:27:30 by gbohm             #+#    #+#             */
/*   Updated: 2023/01/17 11:37:04 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_calloc2(size_t count, size_t size, void **ptr)
{
	*ptr = ft_calloc(count, size);
	return (*ptr == NULL);
}
