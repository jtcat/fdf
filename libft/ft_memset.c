/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: joaoteix <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/11/02 13:50:11 by joaoteix		  #+#	#+#			 */
/*   Updated: 2022/11/10 03:59:41 by joaoteix         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	while (n-- > 0)
		((unsigned char *)s)[n] = c;
	return (s);
}
