/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:08:06 by gbohm             #+#    #+#             */
/*   Updated: 2023/02/06 21:21:30 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_arrfree(void **arr)
{
	void	**cursor;

	if (arr == NULL)
		return ;
	cursor = arr;
	while (*cursor != NULL)
		free(*cursor++);
	free(arr);
}
