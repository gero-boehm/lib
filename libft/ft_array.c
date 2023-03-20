/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:38:26 by gbohm             #+#    #+#             */
/*   Updated: 2023/03/20 12:56:00 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	grow_array(t_array *arr)
{
	int	*new;

	if (ft_malloc2(arr->max_size * 2 * arr->bytes, (void **) &new))
		return (1);
	arr->max_size *= 2;
	ft_memcpy(new, arr->elements, arr->size * arr->bytes);
	free(arr->elements);
	arr->elements = new;
	return (0);
}

int	add_element(t_array *arr, void *element)
{
	void	*ptr;

	if (arr->size == arr->max_size && grow_array(arr))
		return (1);
	ptr = arr->elements + arr->size * arr->bytes;
	ft_memcpy(ptr, element, arr->bytes);
	arr->size++;
	return (0);
}

void	*get_element_at(t_array *arr, unsigned int index)
{
	return (arr->elements + index * arr->bytes);
}

int	create_array(t_array *arr, unsigned int bytes)
{
	if (ft_malloc2(bytes, &arr->elements))
		return (1);
	arr->size = 0;
	arr->max_size = 1;
	arr->bytes = bytes;
	return (0);
}

void	free_array(t_array *arr)
{
	free(arr->elements);
	arr->size = 0;
	arr->max_size = 0;
	arr->bytes = 0;
}
