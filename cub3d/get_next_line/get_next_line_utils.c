/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:55:51 by tyi               #+#    #+#             */
/*   Updated: 2022/08/03 12:16:39 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_len_or_chr(char *s, int flag)
{
	int	i;

	i = 0;
	if (flag == 0)
	{
		while (s[i])
			i ++;
		return (i);
	}
	else if (flag == 1)
	{
		while (s[i])
		{	
			if ((unsigned char)s[i] == '\n')
				return (i);
			i ++;
		}
		return (-1);
	}
	else
		return (0);
}

char	*node_free(t_list **list, t_list *node, int flag)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp->next)
	{
		if (tmp->next == node)
		{
			tmp->next = node->next;
			free (node->save);
			if (flag == 1)
			{
				free (node);
				if (!((*list)->next))
				{
					free (*list);
					(*list) = 0;
				}
			}
			return (0);
		}
		tmp = tmp->next;
	}
	return (0);
}

t_list	*init_node(int fd)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (fd != -1)
		new->save = ft_calloc(1, 1);
	new->fd = fd;
	new->bytes = 0;
	new->next = 0;
	return (new);
}

t_list	*make_node(t_list **headp, int fd)
{
	t_list	*tmp;

	if (!*headp)
		*headp = init_node(-1);
	tmp = *headp;
	while ((tmp))
	{
		if (tmp->fd == fd)
		{
			ft_bzero(tmp->buff, BUFFER_SIZE + 1);
			tmp->bytes = read(fd, tmp->buff, BUFFER_SIZE);
			if (tmp->bytes == -1)
				return ((void *)node_free(headp, tmp, 1));
			return (tmp);
		}	
		if (!(tmp->next))
		{	
			tmp->next = init_node(fd);
			if (!tmp->next)
				return (0);
			return (make_node(headp, fd));
		}
		tmp = tmp->next;
	}
	return (tmp);
}
