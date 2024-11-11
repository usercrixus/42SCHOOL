/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 23:49:55 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/11 21:27:03 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	test_ft_isalpha(void)
{
	if (
		ft_isalpha('a') == 1
		&& ft_isalpha('A') == 1
		&& ft_isalpha('z') == 1
		&& ft_isalpha('Z') == 1
		&& ft_isalpha('1') == 0
		&& ft_isalpha('~') == 0
	)
		return (0);
	return (1);
}

int	test_ft_isdigit(void)
{
	if (
		ft_isdigit('0') == 1
		&& ft_isdigit('9') == 1
		&& ft_isdigit('a') == 0
	)
		return (0);
	return (1);
}

int test_ft_isalnum(void)
{
	if (
		ft_isalnum('a') == 1
		&& ft_isalnum('A') == 1
		&& ft_isalnum('z') == 1
		&& ft_isalnum('Z') == 1
		&& ft_isalnum('0') == 1
		&& ft_isalnum('9') == 1
		&& ft_isalnum('+') == 0
		&& ft_isalnum('~') == 0
	)
		return (0);
	return (1);	
}

int test_ft_isascii()
{
	if (
		ft_isascii(-1) == 0
		&& ft_isascii(0) == 1
		&& ft_isascii(127) == 1
		&& ft_isascii(128) == 0
	)
		return (0);
	return (1);	
}

int	test_ft_isprint()
{
	if (
		ft_isprint(' ' - 1) == 0
		&& ft_isprint(' ') == 1
		&& ft_isprint('~') == 1
		&& ft_isprint('~' + 1) == 0
	)
		return (0);
	return (1);	
}

int test_ft_strlen()
{
	if (
		ft_strlen("") == 0
		&& ft_strlen("1") == 1
		&& ft_strlen("12") == 2
		&& ft_strlen("1234") == 4
	)
		return (0);
	return (1);	
}

int	test_ft_memset()
{
	unsigned char *block;
	int	i;

	block = (unsigned char *)malloc(sizeof(unsigned char) * 16);
	ft_memset(block, 0xff, 16);
	i = 0;
	while (i < 16)
	{
		if(block[i] != 0xff)
			return (1);
		i++;
	}
	return (0);
}

int test_ft_bzero()
{
	unsigned char *block;
	int	i;

	block = (unsigned char *)malloc(sizeof(unsigned char) * 16);
	ft_memset(block, 0xff, 16);
	ft_bzero(block, 8);
	i = 0;
	while (i < 8)
	{
		if (block[i] != 0x00)
			return (1);
		i++;
	}
	while (i < 16)
	{
		if(block[i] != 0xff)
			return (1);
		i++;
	}
	return (0);
}

int test_ft_memcpy()
{
	int	i;
	char *str1;
	char *str2;

	str1 = (char *)malloc(sizeof(char) * 16);
	str2 = "1234567891234567";
	ft_memcpy(str1, str2, 16);
	i = 0;
	while (i < 16)
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	return (0);
}

int test_ft_memmove()
{
	int	i;
	char *str1;
	char *str2;

	char	*result1 = "01230123456723456789012345678901";
	str1 = (char *)malloc(sizeof(char) * 32);
	i = 0;
	while (i < 32)
	{
		str1[i] = '0' + (i % 10);
		i++;
	}
	str1[i] = '\0';

	ft_memmove(str1 + 4, str1, 8);
	i = 0;
	while (i < 32)
	{
		if (str1[i] != result1[i])
			return (1);
		i++;
	}

	char	*result2 = "04567890123123456789012345678901";
	i = 0;
	while (i < 32)
	{
		str1[i] = '0' + (i % 10);
		i++;
	}
	str1[i] = '\0';
	ft_memmove(str1 + 1, str1 + 4, 10);
	i = 0;
	while (i < 32)
	{
		if (str1[i] != result2[i])
			return (1);
		i++;
	}

	return (0);
}

int	test_ft_strlcat()
{
	char dest[30] = "It is a ";
	char src[] = "Hello world";
	int x = ft_strlcat(dest, src, 13 + 1);
	if (x == 8 + 11 && ft_strncmp(dest, "It is a Hello", 13) == 0)
		return (0);
	return (1);
}

int test_ft_strlcpy()
{
	char dest[30] = "";
	char src[] = "Hello world !";
	int x = ft_strlcpy(dest, src, 6);
	if (x == 13 && ft_strncmp(dest, "Hello", 5) == 0)
		return (0);
	return (1);
}

int test_ft_toupper()
{
	if (ft_toupper('a') == 'A' 
		&& ft_toupper('A') == 'A' 
		&& ft_toupper('z') == 'Z' 
		&& ft_toupper('Z') == 'Z'
		&& ft_toupper('0') == '0'
	)
		return (0);
	return (1);
}

int test_ft_tolower()
{
	if (ft_tolower('A') == 'a' 
		&& ft_tolower('a') == 'a'
		&& ft_tolower('Z') == 'z'
		&& ft_tolower('z') == 'z'
		&& ft_tolower('0') == '0'
	)
		return (0);
	return (1);
}

int test_ft_strchr()
{
	char *test = "123456789";
	if (ft_strchr(test, '4') == test + 3
		&& ft_strchr(test, '\0') == test + 9
		&& ft_strchr(test, '0') == 0
	)
		return (0);
	return (1);
}

int test_ft_strrchr()
{
	char *test = "12345678987654321";
	if (ft_strrchr(test, '4') == test + 13 
		&& ft_strrchr(test, '\0') == test + 17
		&& ft_strrchr(test, '0') == 0
	)
		return (0);
	return (1);
}

int test_ft_strncmp()
{
	if(ft_strncmp("1234", "1334", 4) == -1
		&& ft_strncmp("1334", "1234", 4) == 1
		&& ft_strncmp("1234", "1234", 4) == 0
		&& ft_strncmp("1234", "1234", 5) == 0
		&& ft_strncmp("1234", "1234", 6) == 0
		&& ft_strncmp("123456", "1234", 6) == 53
		&& ft_strncmp("1234", "123456", 6) == -53
	)
		return (0);
	return (1);
}

int test_ft_memchr()
{
	char *test = "123456789";
	char *result1 = ft_memchr(test, '3', 3);
	char *result2 = ft_memchr(test, '3', 2);
	if (result1 == test + 2 && result2 == 0)
		return (0);
	return (1);
}

int test_ft_memcmp()
{
	char *test1 = "123456789";
	char *test2 = "123456789";
	char *test3 = "123456799";

	if (ft_memcmp(test1, test2, 9) == 0 && ft_memcmp(test1, test3, 9) == -1)
		return (0);
	return (1);
}

int test_ft_strnstr()
{
	char *big = "Hello World !";
	char *little = "llo World !";
	char *little2 = "llo";

	char *res1 = ft_strnstr(big, little, 13);
	char *res2 = ft_strnstr(big, little, 4);
	char *res3 = ft_strnstr(big, little2, 5);
	char *res4 = ft_strnstr(big, little2, 4);
	if(res1 == big + 2
		&& res2 == 0
		&& res3 == big + 2
		&& res4 == 0
	)
		return (0);
	return (1);
}

int	test_ft_atoi()
{
	int	min;
	int	max;
	int	zero;
	int	one;
	int	minus_one;

	min = ft_atoi("-2147483648");
	max = ft_atoi("2147483647");
	zero = ft_atoi("0");
	one = ft_atoi("1");
	minus_one = ft_atoi("-1");
	if (min == -2147483648 && max == 2147483647 && zero == 0 && one == 1 && minus_one == -1)
		return (0);
	return (1);
}

int test_ft_calloc()
{
	char *test = ft_calloc(5, sizeof(char));
	int i = 0;
	while (i < 5)
	{
		if (test[i] != 0)
			return (1);
		i++;
	}
	return (0);
}

int test_ft_strdup()
{
	char *s1 = "123456789";
	char *s2 = ft_strdup(s1);
	if (ft_strncmp(s1, s2, ft_strlen(s1)) == 0 && ft_strlen(s1) == ft_strlen(s2))
		return (0);
	return (1);
}

int test_ft_substr()
{
	char *s1 = "0123456789";
	char *s2= ft_substr(s1, 3, 6);
	if (ft_strncmp(s2, "345678", 6) == 0 && ft_strlen(s2) == 6)
		return (0);
	return (1);
}

int	test_ft_strjoin()
{
	char *s1 = "Hello ";
	char *s2 = "World !";
	char *result = ft_strjoin(s1, s2);
	if(ft_strncmp(result, "Hello World !", 13) == 0 && ft_strlen(result) == 13)
		return (0);
	return (1);
}

int	test_ft_strtrim()
{
	char	*test = "abcabcHello Worldabcabc";
	char	*result = ft_strtrim(test, "acb");
	if (ft_strncmp(result, "Hello World", 11) == 0 && ft_strlen(result) == 11)
		return (0);
	return (1);
}

int test_ft_split()
{
	char	*test = "  Hello World to  All  ";
	char	**result = ft_split(test, ' ');
	if (ft_strncmp(result[0], "Hello", 5) == 0 && ft_strlen(result[0]) == 5
		&& ft_strncmp(result[1], "World", 5) == 0 && ft_strlen(result[1]) == 5
		&& ft_strncmp(result[2], "to", 2) == 0 && ft_strlen(result[2]) == 2
		&& ft_strncmp(result[3], "All", 3) == 0 && ft_strlen(result[3]) == 3
		&& result[4] == 0
	)
		return (0);
	return (1);
}

int test_ft_itoa(){
	char *test = ft_itoa(-2147483647 - 1);
	char *test2 = ft_itoa(2147483647);
	char *test3 = ft_itoa(0);
	if(ft_strncmp(test, "-2147483648", 11) == 0 && ft_strlen(test) == 11
		&& ft_strncmp(test2, "2147483647", 10) == 0 && ft_strlen(test2) == 10
		&& ft_strncmp(test3, "0", 1) == 0 && ft_strlen(test3) == 1
	)
		return (0);
	return (1);
}

char ft_strmapi_helper(unsigned int i, char c)
{
	return (c + i);
}

int test_ft_strmapi()
{
	char *test = "abcdef";
	char *result = ft_strmapi(test, ft_strmapi_helper);
	if (ft_strncmp(result, "acegik", 6) == 0 && ft_strlen(result) == 6)
		return (0);
	return (1);
}

void ft_striteri_helper(unsigned int i, char *c)
{
	*c += i;
}

int test_ft_striteri(){
	char *test = malloc(sizeof(char) * (6 + 1));
	int i = 0;
	while (i < 6)
	{
		test[i] = 'a' + i;
		i++;
	}
	test[i] = '\0';
	ft_striteri(test, ft_striteri_helper);
	if (ft_strncmp(test, "acegik", 6) == 0 && ft_strlen(test) == 6)
		return (0);
	return (1);
}

void test_ft_putchar_fd()
{
	int i = 0;
	char *msg = "ft_putchar_fd : 0\n";
	while (msg[i]){
		ft_putchar_fd(msg[i++], 1);
	}
}

void test_ft_putstr_fd()
{
	ft_putstr_fd("ft_putstr_fd : 0\n", 1);
}

void test_ft_putendl_fd()
{
	ft_putendl_fd("ft_putendl_fd : 0", 1);
}

void test_ft_putnbr_fd()
{
	ft_putstr_fd("ft_putnbr_fd : ", 1);
	ft_putnbr_fd(0, 1);
}

int	main(void)
{
	printf("ft_isalpha : %d\n", test_ft_isalpha());
	printf("ft_isdigit : %d \n", test_ft_isdigit());
	printf("ft_isalnum : %d \n", test_ft_isalnum());
	printf("ft_isascii : %d \n", test_ft_isascii());
	printf("ft_isprint : %d \n", test_ft_isprint());
	printf("ft_strlen : %d \n", test_ft_strlen());
	printf("ft_memset : %d \n", test_ft_memset());
	printf("ft_bzero : %d \n", test_ft_bzero());
	printf("ft_memcpy : %d \n", test_ft_memcpy());
	printf("ft_memmove : %d \n", test_ft_memmove());
	printf("ft_strlcpy : %d \n", test_ft_strlcpy());
	printf("ft_strlcat : %d \n", test_ft_strlcat());
	printf("ft_toupper : %d\n", test_ft_toupper());
	printf("ft_tolower : %d\n", test_ft_tolower());
	printf("ft_strchr : %d\n", test_ft_strchr());
	printf("ft_strrchr : %d\n", test_ft_strrchr());
	printf("ft_strncmp : %d\n", test_ft_strncmp());
	printf("ft_memchr : %d\n", test_ft_memchr());
	printf("ft_memcmp : %d\n", test_ft_memcmp());
	printf("ft_strnstr : %d\n", test_ft_strnstr());
	printf("ft_atoi : %d\n", test_ft_atoi());
	printf("ft_calloc : %d\n", test_ft_calloc());
	printf("ft_strdup : %d\n", test_ft_strdup());
	printf("ft_substr : %d\n", test_ft_substr());
	printf("ft_strjoin : %d \n", test_ft_strjoin());
	printf("ft_strtrim : %d \n", test_ft_strtrim());
	printf("ft_split : %d \n", test_ft_split());
	printf("ft_itoa : %d \n", test_ft_itoa());
	printf("ft_strmapi : %d \n", test_ft_strmapi());
	printf("ft_striteri : %d \n", test_ft_striteri());
	test_ft_putchar_fd();
	test_ft_putstr_fd();
	test_ft_putendl_fd();
	test_ft_putnbr_fd();
}