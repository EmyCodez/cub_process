/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:34:15 by esimpson          #+#    #+#             */
/*   Updated: 2024/10/22 13:52:55 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (!len && !haystack)
		return (NULL);
	if (needle_len == 0)
		return ((char *)(haystack));
	while (*haystack && needle_len <= len)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle,
				needle_len) == 0)
			return ((char *)haystack);
		++haystack;
		--len;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*c;
// 	char	*locate;
// 	size_t	n;

// 	str = "oh no not the empty string !";
// 	n = 0;
// 	c = "";
// 	locate = ft_strnstr(str, c, n);
// 	if (locate == NULL)
// 		ft_printf("\n %s not found %s when checking %zu characters", c, locate, n);
// 	else
// 		ft_printf("\n %s  found %s when checking %zu characters", c, locate, n);
// 	return (0);
// }
