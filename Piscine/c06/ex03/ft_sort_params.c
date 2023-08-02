/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:46:20 by tyi               #+#    #+#             */
/*   Updated: 2022/06/02 17:54:05 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1 ++;
		s2 ++;
	}
	return (*s1 - *s2);
}

void	print(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		while (*argv[i])
		{
			write(1, argv[i], 1);
			argv[i]++;
		}
		i ++;
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	if (argc == 0)
		return (0);
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (strcmp(argv[i], argv[j]) > 0)
			{
				tmp = argv[i];
				argv[i] = argv[j];
				argv[j] = tmp;
			}
			j ++;
		}
		i ++;
	}
	print(argv);
	return (0);
}
