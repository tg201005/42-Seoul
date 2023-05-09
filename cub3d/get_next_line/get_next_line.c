/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 23:14:59 by tyi               #+#    #+#             */
/*   Updated: 2022/08/03 15:15:26 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i ++;
	}
	return ;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	t;

	if (count && size)
	{
		t = count * size;
		if (t / count != size)
			return (0);
	}
	ptr = malloc(count * size);
	ft_bzero(ptr, count * size);
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{			
	char	*newstr;
	char	*temp;
	int		i;

	newstr = (char *)malloc(sizeof(char) * \
	(ft_len_or_chr(s1, 0) + ft_len_or_chr(s2, 0) + 1));
	temp = newstr;
	i = 0;
	while (s1[i])
		*(temp++) = s1[i++];
	i = 0;
	while (s2[i])
		*(temp++) = s2[i++];
	*temp = 0;
	free (s1);
	return (newstr);
}

char	*ft_substr(char **save, int s_i)
{
	char	*returnstr;
	char	*savestr;
	char	*tmpsave;
	int		n;
	int		len;

	len = ft_len_or_chr(*save, 0);
	returnstr = (char *)malloc(sizeof(char) * (s_i + 2));
	savestr = (char *)malloc(sizeof(char) * (len - s_i));
	n = 0;
	tmpsave = *save;
	while ((n < s_i + 1) && *tmpsave)
		returnstr[n++] = *(tmpsave++);
	returnstr[n] = 0;
	while (n < len && *tmpsave)
		(savestr)[n++ - s_i - 1] = *(tmpsave++);
	if (n == s_i)
		n = s_i + 1;
	savestr[n - s_i - 1] = 0;
	free (*save);
	*save = savestr;
	return (returnstr);
}

char	*get_next_line(int fd)
{
	static t_list	*head = 0;
	t_list			*node;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	while (1)
	{	
		node = make_node(&head, fd);
		if (!(long long)node)
			return (0);
		node->save = ft_strjoin(node->save, node->buff);
		if (ft_len_or_chr(node->save, 1) != -1)
			return (ft_substr(&(node->save), ft_len_or_chr(node->save, 1)));
		if (node->bytes != BUFFER_SIZE)
		{
			if (!*(node->save))
				return (node_free(&head, node, 1));
			return (ft_substr(&(node->save), ft_len_or_chr(node->save, 0)));
		}
	}
}
