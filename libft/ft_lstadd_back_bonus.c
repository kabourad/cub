/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:50:29 by kabourad          #+#    #+#             */
/*   Updated: 2021/01/11 18:22:48 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *niw)
{
	if (!alst)
		return ;
	if (*alst == NULL)
		*alst = niw;
	else
		ft_lstlast(*alst)->next = niw;
}
