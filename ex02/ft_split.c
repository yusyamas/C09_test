/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:08:20 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/28 18:05:54 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#define FT_NULL '\0'

int	ascii_check(char c, char *charset)
{
	while (*charset != FT_NULL)
	{
		if (c == *charset)
			return (0);
		charset++;
	}
	return (1);
}

int	two_div_len(char *str, char *charset)
{
	int	len;

	len = 0;
	while (*str != FT_NULL && ascii_check(*str, charset))
	{
		len++;
		str++;
	}
	return (len);
}

int	size_check(char *str, char *charset)
{
	int	ret;
	int	i;
	int	is_split;

	ret = 0;
	i = 0;
	is_split = 0;
	if (charset[i] == FT_NULL)
		return (1);
	while (str[i] != FT_NULL)
	{
		if (is_split == 0 && ascii_check(str[i], charset))
		{
			ret++;
			is_split = 1;
		}
		if (is_split == 1 && !ascii_check(str[i], charset))
		{
			is_split = 0;
		}
		i++;
	}
	return (ret);
}

char	*set_split(char *str, char *charset)
{
	int		cnt;
	int		len;
	char	*ret;

	len = two_div_len(str, charset);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	cnt = 0;
	while (cnt < len)
	{
		ret[cnt] = str[cnt];
		cnt++;
	}
	ret[cnt] = FT_NULL;
	return (ret);
}

char	**ft_split(char *str, char *charset)
{
	int		ac;
	char	**ret;
	int		cnt;

	ac = size_check(str, charset);
	ret = (char **)malloc(sizeof(char *) * (ac + 1));
	cnt = 0;
	while (*str != FT_NULL)
	{
		while (*str != FT_NULL && !ascii_check(*str, charset))
			str++;
		if (*str != FT_NULL)
		{
			ret[cnt] = set_split(str, charset);
			cnt++;
		}
		while (*str != FT_NULL && ascii_check(*str, charset))
			str++;
	}
	ret[cnt] = 0;
	return (ret);
}
