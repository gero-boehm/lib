/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:56:13 by gbohm             #+#    #+#             */
/*   Updated: 2023/04/20 11:23:26 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free2d(void **arr)
{
	void	**cursor;

	if (arr == NULL)
		return ;
	cursor = arr;
	while (*cursor != NULL)
		free(*cursor++);
	free(arr);
}
