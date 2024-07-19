/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:24:37 by miafonso          #+#    #+#             */
/*   Updated: 2024/04/08 15:24:37 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	start(char const *s1, char const *set)
{
	int	j;

	j = 0;
	while ((ft_strchr(set, s1[j])))
		j++;
	return (j);
}

int	end(char const *s1, char const *set)
{
	int	j;

	j = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[j]) && j >= 0)
		j--;
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		str_start;
	int		str_end;
	char	*str;

	str_start = start(s1, set);
	str_end = end(s1, set);
	if (str_start > str_end || (ft_strlen(s1) == 0))
	{
		str = malloc(1 * sizeof(char));
		str[0] = '\0';
		return (str);
	}
	str = malloc((str_end - str_start + 2) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[str_start], str_end - str_start + 2);
	return (str);
}

/*int main()
{
		const char *s1_strtrim = "teste";
	const char *set_strtrim = "e";
	char *str_strtrim = ft_strtrim(s1_strtrim, set_strtrim);
	printf("TESTING FT_STRTRIM \n\n");
	printf("meu: %s\n\n", str_strtrim);
	//printf("start: %d\n\n", start(s1_strtrim, set_strtrim));
	//printf("end: %d\n\n", end(s1_strtrim, set_strtrim));
	free(str_strtrim);
}*/