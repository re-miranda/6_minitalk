/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:37:07 by rmiranda          #+#    #+#             */
/*   Updated: 2022/05/27 23:52:04 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_gnl(char *str)
{
	char	*dup;
	size_t	i;

	i = ft_strlen(str) + 1;
	dup = malloc(sizeof(char) * i);
	if (!dup)
		return (NULL);
	while (i--)
		dup[i] = str[i];
	return (dup);
}

t_list	*new_node(int fd, t_list *previous)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->buffer = ft_strdup_gnl("");
	new->previous = previous;
	new->next = NULL;
	return (new);
}
