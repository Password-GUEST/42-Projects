/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:00:36 by sbejaoui          #+#    #+#             */
/*   Updated: 2023/11/20 13:32:50 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_base(int len_base, char *base)
{
	int	i;
	int	j;

	i = 0;
	if (len_base <= 1)
		return (1);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[j] == '-' || base[j] == '+' || base[j] == '\t'
				|| base[j] == '\n' || base[j] == '\r' || base[j] == '\v'
				|| base[j] == '\f' || base[j] == ' ' )
				return (1);
			else if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_start_str(char *str, int *sign)
{
	while (*str == '\t' || *str == '\n' || *str == '\r' || *str == '\v'
		|| *str == '\f' || *str == ' ' )
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign *= -1;
		str++;
	}
	return (str);
}

int	ft_get_nb(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int	ft_check_end(char c, char *base)
{
	while (*base)
	{
		if (*base == c)
			return (1);
		base++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	result;
	int	len_base;

	sign = 1;
	result = 0;
	len_base = 0;
	while (base[len_base])
		len_base++;
	str = ft_start_str(str, &sign);
	if (len_base < 2 || ft_check_base(len_base, base))
		return (0);
	while (*str)
	{
		if (ft_check_end(*str, base))
		{
			result = (result * len_base) + (ft_get_nb(*str, base));
			str++;
		}
		else
			return (result * sign);
	}
	return (result * sign);
}
