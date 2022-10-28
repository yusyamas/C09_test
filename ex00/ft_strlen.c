/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 08:11:37 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/24 08:12:08 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_NULL '\0'

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (*str != FT_NULL)
	{
		length += 1;
		str += 1;
	}
	return (length);
}
