/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 09:17:48 by tyi               #+#    #+#             */
/*   Updated: 2023/05/13 15:12:03 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 32

typedef struct s_list
{
	char			buff[BUFFER_SIZE + 1];
	char			*save;
	int				fd;
	int				bytes;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
int		ft_len_or_chr(char *s, int flag);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*node_free(t_list **list, t_list *node, int flag);
t_list	*init_node(int fd);
char	*ft_strjoin(char *s1, char *s2);
t_list	*make_node(t_list **headp, int fd);
char	*ft_substr(char **save, int s_i);
char	**ft_split(char const *s, char c);
#endif