/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:24:56 by gbohm             #+#    #+#             */
/*   Updated: 2022/12/02 11:41:51 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*result;
	t_list	*mapped;
	t_list	*node;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	mapped = NULL;
	while (lst != NULL)
	{
		result = f(lst->content);
		node = ft_lstnew(result);
		if (node == NULL)
			return (del(result), ft_lstclear(&mapped, del), NULL);
		ft_lstadd_back(&mapped, node);
		lst = lst->next;
	}
	return (mapped);
}
