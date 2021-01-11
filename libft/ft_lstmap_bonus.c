/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:18:24 by kabourad          #+#    #+#             */
/*   Updated: 2019/10/31 16:24:11 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *y;
	t_list *niw;

	y = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		niw = ft_lstnew(f(lst->content));
		if (niw)
			ft_lstadd_back(&y, niw);
		else
		{
			ft_lstclear(&y, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (y);
}
