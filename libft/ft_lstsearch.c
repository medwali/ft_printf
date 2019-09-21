/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:30:49 by mel-idri          #+#    #+#             */
/*   Updated: 2019/04/10 18:38:18 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsearch(t_list *lst, int (*f)(t_list *l))
{
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst)
	{
		if ((*f)(lst))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
