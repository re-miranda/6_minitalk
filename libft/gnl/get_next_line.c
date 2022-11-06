/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:37:03 by rmiranda          #+#    #+#             */
/*   Updated: 2022/05/28 02:38:00 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*find_node(int fd, t_list *head)
{
	t_list	*here;

	here = head;
	while (here->fd != fd)
	{
		if (here->next == NULL)
			here->next = new_node(fd, here);
		here = here->next;
	}
	return (here);
}

char	*return_and_free_node(t_list *node)
{
	char	*line;

	if (*node->buffer == '\0')
		line = NULL;
	else
		line = ft_strdup_gnl(node->buffer);
	if (node->previous != NULL)
	{
		node->previous->next = node->next;
	}
	if (node->next != NULL)
		node->next->previous = node->previous;
	free(node->buffer);
	free(node);
	return (line);
}

char	*erase_first_line(t_list *node)
{
	char	*line;
	char	*swap;
	char	*line_break;

	line_break = ft_strchr(node->buffer, '\n');
	if (line_break == NULL)
		return (return_and_free_node(node));
	swap = node->buffer;
	node->buffer = ft_strdup_gnl(line_break + 1);
	*(line_break + 1) = '\0';
	line = ft_strdup_gnl(swap);
	free(swap);
	return (line);
}

char	*get_line(t_list *node, int fd)
{
	char	*new_buffer;
	char	*swap;
	int		read_size;

	read_size = BUFFER_SIZE;
	while (ft_strchr(node->buffer, '\n') == NULL && read_size == BUFFER_SIZE)
	{
		new_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		read_size = read(fd, new_buffer, BUFFER_SIZE);
		if (read_size < 0)
		{
			free(new_buffer);
			return (NULL);
		}
		new_buffer[read_size] = '\0';
		swap = node->buffer;
		node->buffer = ft_strjoin(node->buffer, new_buffer);
		free(swap);
		free(new_buffer);
	}
	return (erase_first_line(node));
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*node;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (head == NULL)
		head = new_node(-42, head);
	node = find_node(fd, head);
	line = get_line(node, fd);
	if (head->next == NULL)
	{
		free(head->buffer);
		free(head);
		head = NULL;
	}
	return (line);
}
