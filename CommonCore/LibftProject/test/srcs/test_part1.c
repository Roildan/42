/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_part1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:42:11 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/09 19:00:52 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_test.h"

void	memset_test(void)
{
	char s1[9] = "T3sting!";
	char s2[9] = "T3sting!";

	if (strcmp(ft_memset(s1, 'a', 2), memset(s2, 'a', 2)) == 0)
		if (strcmp(ft_memset(s1, 'b', 8), memset(s2, 'b', 8)) == 0)
		{
			printf(GRN "WORKING !\n" RESET);
			return ;
		}
	printf(RED "FAILED !\n" RESET);
}

void	bzero_test(void)
{
	char	s1[9] = "testing1";
	char	s2[9] = "TESTING2";
	size_t	i = 0;

	ft_bzero(s1, 7);
	bzero(s2, 7);
	while (i < 7)
	{
		if (s1[i] == s2[i])
			i++;
		else
		{
			printf(RED "FAILED !\n" RESET);
			return ;
		}
	}
	if (s1[i] == s2[i])
		printf(RED "FAILED !\n" RESET);
	else
		printf(GRN "WORKING !\n" RESET);
}

void	memcpy_test(void)
{
	char s[9] = "T3sting!";
	char s1[9] = "testing1";
	char s2[9] = "TESTING2";

	if (strncmp(ft_memcpy(s1, s, 3), memcpy(s2, s, 3), 3) == 0)
		if (strcmp(ft_memcpy(s1, s, 9), memcpy(s2, s, 9)) == 0)
		{
			printf(GRN "WORKING !\n" RESET);
			return ;
		}
	printf(RED "FAILED !\n" RESET);
}

void	memccpy_test(void)
{
	char s[9] = "T3sting!";
	char s1[9] = "testing1";
	char s2[9] = "TESTING2";
	char *ptr1;
	char *ptr2;

	ptr1 = ft_memccpy(s1, s, 'a', 3);
	ptr2 = memccpy(s2, s, 'a', 3);
	if (strncmp(s1, s2,  3) == 0)
	{
		if (ptr1 || ptr2)
		{
			printf(RED "FAILED !\n" RESET);
			return ;
		}
		ptr1 = ft_memccpy(s1, s, 'g', 9);
		ptr2 = memccpy(s2, s, 'g', 9);
		if (strncmp(s1, s2, 7) == 0 && ptr1 && ptr2)
		{
			printf(GRN "WORKING !\n" RESET);
			return ;
		}
	}
	printf(RED "FAILED !\n" RESET);
}

void	memmove_test(void)
{
	char	s1[10] = "123456789";
	char	s2[10] = "123456789";
	int		*p1 = (int *)malloc(3 * sizeof(int));
	int		*p2 = (int *)malloc(3 * sizeof(int));
	int		arr[3] = {1, 2, 3};
	size_t	i = 0;

	if (strcmp(ft_memmove(s1 + 4, s1 + 3, 3), memmove(s2 + 4, s2 + 3, 3)) != 0)
	{
		printf(RED "FAILED !\n" RESET);
		return ;
	}
	ft_memmove(p1, arr, 3 * sizeof(int));
	memmove(p2, arr, 3 * sizeof(int));
	while (i < 3)
	{
		if (p1[i] != p2 [i])
		{
			printf(RED "FAILED !\n" RESET);
			return ;
		}
		i++;
	}
	printf(GRN "WORKING !\n" RESET);
}

void	memchr_test(void)
{
	char str[9] = "Testing!";

	if (strcmp(ft_memchr(str, 't', 20), memchr(str, 't', 20)) == 0)
		if (ft_memchr(str, 't', 3) == memchr(str, 't', 3))
			if (ft_memchr(str, 'a', 9) == memchr(str, 'a', 9))
			{
				printf(GRN "WORKING !\n" RESET);
				return ;
			}
	printf(RED "FAILED !\n" RESET);
}

void	memcmp_test(void)
{
	char s1[4] = "abc";
	char s2[9] = "abd";

	if (ft_memcmp(s1, s2, 4) == memcmp(s1, s2, 4))
		if (ft_memcmp(s2, s1, 4) == memcmp(s2, s1, 4))
			if (ft_memcmp(s1, s1, 4) == memcmp(s1, s1, 4))
			{
				printf(GRN "WORKING !\n" RESET);
				return ;
			}
	printf(RED "FAILED !\n" RESET);
}

void	strlen_test(void)
{
	if (ft_strlen("") == strlen(""))
		if (ft_strlen("a") == strlen("a"))
			if (ft_strlen("0123456789") == strlen("0123456789"))
			{
				printf(GRN "WORKING !\n" RESET);
				return ;
			}
	printf(RED "FAILED !\n" RESET);
}

void	strdup_test(void)
{
	if (strcmp(ft_strdup(""), strdup("")) == 0)
		if (strcmp(ft_strdup("Test0!"), strdup("Test0!")) == 0)
		{
			printf(GRN "WORKING !\n" RESET);
			return ;
		}
	printf(RED "FAILED !\n" RESET);
}

void	strcpy_test(void)
{
	char s[20];
	char s1[1] = "";
	char s2[7] = "Test0!";

	if (strcmp(ft_strcpy(s, s1), strcpy(s, s1)) == 0)
		if (strcmp(ft_strcpy(s, s2), strcpy(s, s2)) == 0)
		{
			printf(GRN "WORKING !\n" RESET);
			return ;
		}
	printf(RED "FAILED !\n" RESET);
}

void	strncpy_test(void)
{
	char s[20];
	char s1[1] = "";
	char s2[7] = "Test0!";

	if (strcmp(ft_strncpy(s, s1, 1), strncpy(s, s1, 1)) == 0)
		if (strcmp(ft_strncpy(s, s2, 10), strncpy(s, s2, 10)) == 0)
		{
			printf(GRN "WORKING !\n" RESET);
			return ;
		}
	printf(RED "FAILED !\n" RESET);
}

void	strcat_test(void)
{
	char s1[20] = "";
	char s2[20] = "";

	if (strcmp(ft_strcat(s1, ""), strcat(s2, "")) == 0)
		if (strcmp(ft_strcat(s1, "Hell0 !"), strcat(s2, "Hell0 !")) == 0)
		{
			printf(GRN "WORKING !\n" RESET);
			return ;
		}
	printf(RED "FAILED !\n" RESET);
}

void	strncat_test(void)
{
	char s1[20] = "";
	char s2[20] = "";

	if (strcmp(ft_strncat(s1, "", 1), strncat(s2, "", 1)) == 0)
		if (strcmp(ft_strncat(s1, "Hell0 !", 5), strncat(s2, "Hell0 !", 5)) == 0)
		{
			printf(GRN "WORKING !\n" RESET);
			return ;
		}
	printf(RED "FAILED !\n" RESET);
}

void	strlcat_test(void)
{
	char s1[20] = "";
	char s2[20] = "";

	if (ft_strlcat(s1, "", 1) == strlcat(s2, "", 1) && strcmp(s1, s2) == 0)
		if (ft_strlcat(s1, "Hell0 !", 5) == strlcat(s2, "Hell0 !", 5) && strcmp(s1, s2) == 0)
		{
			printf(GRN "WORKING !\n" RESET);
			return ;
		}
	printf(RED "FAILED !\n" RESET);
}

void	strchr_test(void)
{
	const char str[22] = "Yes, this is a test !";

	if (ft_strchr(str, '0') == strchr(str, '0'))
		if (ft_strchr(str, ' ') == strchr(str, ' '))
			if (ft_strchr(str, '\0') == strchr(str, '\0'))
			{
				printf(GRN "WORKING !\n" RESET);
				return ;
			}
	printf(RED "FAILED !\n" RESET);
}

void	strrchr_test(void)
{
	const char str[22] = "Yes, this is a test !";

	if (ft_strrchr(str, '0') == strrchr(str, '0'))
		if (ft_strrchr(str, ' ') == strrchr(str, ' '))
			if (ft_strrchr(str, '\0') == strrchr(str, '\0'))
			{
				printf(GRN "WORKING !\n" RESET);
				return ;
			}
	printf(RED "FAILED !\n" RESET);
}

void	strstr_test(void)
{
	const char str[22] = "Yes, this is a test !";

	if (ft_strstr(str, "") == strstr(str, ""))
		if (ft_strstr(str, ", this") == strstr(str, ", this"))
			if (ft_strstr(str, "this is A t") == strstr(str, "this is A t"))
			{
				printf(GRN "WORKING !\n" RESET);
				return ;
			}
	printf(RED "FAILED !\n" RESET);
}

void	strnstr_test(void)
{
	const char str[22] = "Yes, this is a test !";

	if (ft_strnstr(str, " ", 22) == strnstr(str, " ", 22))
		if (ft_strnstr(str, ", this", 8) == strnstr(str, ", this", 8))
			if (ft_strnstr(str, "this is A t", 22) == strnstr(str, "this is A t", 22))
			{
				printf(GRN "WORKING !\n" RESET);
				return ;
			}
	printf(RED "FAILED !\n" RESET);
}

void	strcmp_test(void)
{
	if (ft_strcmp("abc", "abc") == strcmp("abc", "abc"))
		if (ft_strcmp("adb", "abc") == strcmp("adb", "abc"))
			if (ft_strcmp("abc\200", "abc\0") == strcmp("abc\200", "abc\0"))
			{
				printf(GRN "WORKING !\n" RESET);
				return ;
			}
	printf(RED "FAILED !\n" RESET);
}

void	strncmp_test(void)
{
	if (ft_strncmp("abce", "abcf", 3) == strncmp("abce", "abcf", 3))
		if (ft_strncmp("adbe", "abcf", 3) == strncmp("adbe", "abcf", 3))
			if (ft_strncmp("abc\200", "abc\0", 4) == strncmp("abc\200", "abc\0", 4))
			{
				printf(GRN "WORKING !\n" RESET);
				return ;
			}
	printf(RED "FAILED !\n" RESET);
}

void	atoi_test(void)
{
	if (ft_atoi("test") == atoi("test"))
		if (ft_atoi("0") == atoi("0"))
			if (ft_atoi("   -9") == atoi("   -9"))
				if (ft_atoi("\t\v  +58aaa") == atoi("\t\v  +58aaa"))
					if (ft_atoi("2147483647") == atoi("2147483647"))
						if (ft_atoi("-2147483648") == atoi("-2147483648"))
						{
							printf(GRN "WORKING !\n" RESET);
							return ;
						}
	printf(RED "FAILED !\n" RESET);
}

void	isalpha_test(void)
{
	if (ft_isalpha('a') == isalpha('a'))
		if (ft_isalpha('\0') == isalpha('\0'))
			if (ft_isalpha(-127) == isalpha(-127))
			{
				printf(GRN "WORKING !\n" RESET);
				return ;
			}
	printf(RED "FAILED !\n" RESET);
}

void	isdigit_test(void)
{
	if (ft_isdigit('a') == isdigit('a'))
		if (ft_isdigit('0') == isdigit('0'))
			if (ft_isdigit(-127) == isdigit(-127))
			{
				printf(GRN "WORKING !\n" RESET);
				return ;
			}
	printf(RED "FAILED !\n" RESET);
}

void	isalnum_test(void)
{
	if (ft_isalnum('a') == isalnum('a'))
		if (ft_isalnum('0') == isalnum('0'))
			if (ft_isalnum(-127) == isalnum(-127))
			{
				printf(GRN "WORKING !\n" RESET);
				return ;
			}
	printf(RED "FAILED !\n" RESET);
}

void	isascii_test(void)
{
	if (ft_isascii('a') == isascii('a'))
		if (ft_isascii(127) == isascii(127))
			if (ft_isascii(-127) == isascii(-127))
			{
				printf(GRN "WORKING !\n" RESET);
				return ;
			}
	printf(RED "FAILED !\n" RESET);
}

void	isprint_test(void)
{
	if (ft_isprint('a') == isprint('a'))
		if (ft_isprint(127) == isprint(127))
			if (ft_isprint(-127) == isprint(-127))
			{
				printf(GRN "WORKING !\n" RESET);
				return ;
			}
	printf(RED "FAILED !\n" RESET);
}

void	toupper_test(void)
{
	if (ft_toupper('a') == toupper('a'))
		if (ft_toupper(127) == toupper(127))
			if (ft_toupper('C') == toupper('C'))
			{
				printf(GRN "WORKING !\n" RESET);
				return ;
			}
	printf(RED "FAILED !\n" RESET);
}

void	tolower_test(void)
{
	if (ft_tolower('a') == tolower('a'))
		if (ft_tolower(127) == tolower(127))
			if (ft_tolower('C') == tolower('C'))
			{
				printf(GRN "WORKING !\n" RESET);
				return ;
			}
	printf(RED "FAILED !\n" RESET);
}
