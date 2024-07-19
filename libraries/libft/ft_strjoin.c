/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/04/08 15:20:25 by miafonso          #+#    #+#             */
/*   Updated: 2024/04/08 15:20:25 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	size_t			len_s1;
	size_t			len_s2;
	char			*new_str;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_str = malloc(((len_s1 + len_s2) + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (s1[++i])
		new_str[i] = s1[i];
	i = -1;
	while (s2[++i])
		new_str[len_s1++] = s2[i];
	new_str[len_s1] = '\0';
	return (new_str);
}

/*int main()
{
	const char s1_strjoin[] = "";
	const char s2_strjoin[] = "";
	char *result_strjoin = ft_strjoin(s1_strjoin, s2_strjoin);
	printf("TESTING FT_STRJOIN \n\n");
	printf("meu: %s\n\n", result_strjoin);
	free(result_strjoin);
}*/