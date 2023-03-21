/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:16:16 by joaoteix          #+#    #+#             */
/*   Updated: 2022/11/07 02:18:22 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>
#include <string.h>
#include "libft.h"
#include <time.h>
#include <limits.h>
#include <stdint.h>

void	putchrcont(void *content)
{
	printf("%s\n",(unsigned char *)content);
}

char	*ft_strrchr2(const char *s, int c)
{
	char	*buff;

	buff = (char *)s + strlen(s);
	while (*buff != c)
	{
		if (buff == s)
			return (NULL);
		buff--;
	}
	return (buff);
}

void	iterihelper(unsigned int i, char *c)
{
	printf("Index: %d - %c\n", i, *c);
}

char	mapihelper(unsigned int i, char c)
{
	(void)i;
	return (++c);
}

void	*lstmapper(void	*content)
{
	return (ft_itoa(ft_strlen((const char *)content)));	
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char	str[] = "memmove can be very useful......";
	char	str1[] = "memmove can be very useful......";

#define T_LABEL(tname) puts("\n------------- ** " #tname " test **-------------\n");
#define T_GENSTRS(funcname, s) char funcname ## _str[] = s; char ft_ ## funcname ## _str[] = s;
#define T_STRCMP(funcname, s1, s2) \
	printf(#funcname ": %s\nft_" #funcname ": %s\nstr compare: %d\n", s1, s2, ft_strncmp(s1, s2, ft_strlen(s1))); \

	T_LABEL(memmove)
	memmove(str + 15, str + 20, 11);
	ft_memmove(str1 + 15, str1 + 20, 11);
	T_STRCMP(memmove, str, str1)

	T_LABEL(bzero)
	T_GENSTRS(bzero, "ok lets go")
	bzero(bzero_str, 4);
	ft_bzero(ft_bzero_str, 4);
	T_STRCMP(bzero,bzero_str, ft_bzero_str)

	T_LABEL(strdup)
	char	*dup = strdup(str);
	char	*dup1 = ft_strdup(str);
	T_STRCMP(strdup,dup, dup1);
	free(dup); free(dup1);

	T_LABEL(calloc)
	int	callarrl = 6;
	int	i = 0;
	int	*callarr = calloc(callarrl,sizeof(int));
	int	*ft_callarr = ft_calloc(callarrl, sizeof(int));
	for (; i < callarrl; i++)
	{
		callarr[i] = i;
		ft_callarr[i] = i;
	}
	for (i = 0; i < callarrl; i++)
		printf("def: %d\ncustom: %d\n", callarr[i], ft_callarr[i]);
	free(callarr); free(ft_callarr);

	T_LABEL(strrchar)
	char	strrchar_str[] = "ok bom dia pessoal";
	char	*res;
	clock_t beg = clock();
	res = ft_strrchr(strrchar_str, 'o'); 
	double t = (double)(clock() - beg) / CLOCKS_PER_SEC;
	printf("%f\n", t ); 
	beg = clock();
	res = ft_strrchr2(strrchar_str, 'o'); 
	t = (double)(clock() - beg) / CLOCKS_PER_SEC;
	printf("%p\n%f\n", res, t );

#define	T_ALLOCD(funcname, ...) \
	char	*allocd_ ## funcname = ft_ ## funcname(__VA_ARGS__); \
	printf("%s%%\n", allocd_ ## funcname); \
	free(allocd_ ## funcname); \

	T_LABEL(strtrim)
	T_ALLOCD(strtrim, "  ola vamos todos la\\", " \\")

	T_LABEL(strjoin)
	T_ALLOCD(strjoin, "ok vamos"," todos la!")

	T_LABEL(split)
	char    **splitarr;
    splitarr = ft_split(" ok vamos    todos la   pa  men", ' ');
	
	i = 0;
	while (splitarr[i])
	{
		printf("%s\n", splitarr[i]);
		free(splitarr[i++]);
	}
	free(splitarr);

	T_LABEL(itoa)
	T_ALLOCD(itoa, INT_MIN)

	T_LABEL(strmapi)
	T_ALLOCD(strmapi, "abcdefg", mapihelper)
	
	T_LABEL(striteri)
	ft_striteri("ok vamos la pa", iterihelper);

	T_LABEL(lst funcs)
	t_list	*head = ft_lstnew(ft_itoa(0));
	int	lstsize = 6;
	for (int i = 1; i < lstsize; i++)
		ft_lstadd_back(&head, ft_lstnew(ft_itoa(i)));
	ft_lstiter(head, putchrcont);
	ft_lstclear(&head, free);

/*	t_list	*map = ft_lstmap(head, lstmapper, free);
	ft_lstiter(map, putchrcont);
	ft_lstclear(&map, free);*/

	T_LABEL(calloc)

	void	*tp = ft_calloc(1,0);
	printf("%p\n", tp);
	free(tp);
	tp = ft_calloc(2, SIZE_MAX);
	printf("%p\n", tp);
	if (tp)
		free(tp);
	tp = ft_calloc(0,0);
	printf("%p\n", tp);
	if (tp)
		free(tp);
	tp = ft_calloc(0,1);
	printf("%p\n", tp);
	if (tp)
		free(tp);
	
	return (0);
}
