/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 03:28:25 by sbejaoui          #+#    #+#             */
/*   Updated: 2023/11/20 12:29:02 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	calculx(char	*str, t_general *infg)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
			i++;
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] == ',' && str[i + 1] == '0' && str[i + 2] == 'x')
		{
			i += 3;
			while ((str[i] >= '0' && str[i] <= '9')
				|| (str[i] >= 'A' && str[i] <= 'F')
				|| (str[i] >= 'a' && str[i] <= 'f'))
				i++;
		}
		if (str[i])
			infg->x += 1;
	}
}

int	**sizetab(char *alire, t_general *infg)
{
	char	*str;
	int		fd;

	fd = open(alire, O_RDONLY);
	str = get_next_line(fd);
	calculx(str, infg);
	if (str)
		free (str);
	infg->tab = ft_calloc(infg->x, sizeof(int *));
	infg->tabcolor = ft_calloc(infg->x, sizeof(int *));
	while (str)
	{
		str = get_next_line(fd);
		if (str)
			free (str);
		infg->y += 1;
	}
	fd = 0;
	while (infg->tab && infg->tabcolor && fd < infg->x)
	{
		infg->tab[fd] = ft_calloc(infg->y, sizeof(int));
		infg->tabcolor[fd] = ft_calloc(infg->y, sizeof(int));
		fd++;
	}
	return (ft_txttotab(fd, alire, infg));
}

char	*avance(char	*str, t_general *infg, int k, int j)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == ',' && str[i + 1] == '0' && str[i + 2] == 'x')
	{
		i += 3;
		infg->tabcolor[k][j] = ft_atoi_base(str + i, "0123456789abcdef");
		while ((str[i] >= '0' && str[i] <= '9')
			|| (str[i] >= 'A' && str[i] <= 'F')
			|| (str[i] >= 'a' && str[i] <= 'f'))
			i++;
	}
	return (str + i);
}

int	**ft_txttotab(int fd, char *alire, t_general *infg)
{
	int		i;
	int		j;
	char	*str;
	char	*tmp;

	close(fd);
	fd = open(alire, O_RDONLY);
	j = 0;
	while (infg->tab && infg->tabcolor && j < infg->y)
	{
		str = get_next_line(fd);
		if ((!infg->tab || fd < 0))
			return (NULL);
		i = 0;
		tmp = str;
		while (infg->tab && infg->tabcolor && i < infg->x)
		{
			infg->tab[i][j] = ft_atoi(str);
			str = avance(str, infg, i++, j);
		}
		j++;
		if (tmp)
			free (tmp);
	}
	return (infg->tab);
}
