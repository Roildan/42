/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:52:10 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/09 18:59:04 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_test.h"
#include "../includes/libft_part1.h"
#include "../includes/libft_part2.h"

static void		test_part1(void)
{
	printf(ORG "\n#############\tTEST PART 1\t#############\n" RESET);
	printf("Testing\t\t'ft_memset'\t--> ");
	memset_test();
	printf("Testing\t\t'ft_bzero'\t--> ");
	bzero_test();
	printf("Testing\t\t'ft_memcpy'\t--> ");
	memcpy_test();
	printf("Testing\t\t'ft_memccpy'\t--> ");
	memccpy_test();
	printf("Testing\t\t'ft_memmove'\t--> ");
	memmove_test();
	printf("Testing\t\t'ft_memchr'\t--> ");
	memchr_test();
	printf("Testing\t\t'ft_memcmp'\t--> ");
	memcmp_test();
	printf("Testing\t\t'ft_strlen'\t--> ");
	strlen_test();
	printf("Testing\t\t'ft_strdup'\t--> ");
	strdup_test();
	printf("Testing\t\t'ft_strcpy'\t--> ");
	strcpy_test();
	printf("Testing\t\t'ft_strncpy'\t--> ");
	strncpy_test();
	printf("Testing\t\t'ft_strcat'\t--> ");
	strcat_test();
	printf("Testing\t\t'ft_strncat'\t--> ");
	strncat_test();
	printf("Testing\t\t'ft_strlcat'\t--> ");
	strlcat_test();
	printf("Testing\t\t'ft_strchr'\t--> ");
	strchr_test();
	printf("Testing\t\t'ft_strrchr'\t--> ");
	strrchr_test();
	printf("Testing\t\t'ft_strstr'\t--> ");
	strstr_test();
	printf("Testing\t\t'ft_strnstr'\t--> ");
	strnstr_test();
	printf("Testing\t\t'ft_strcmp'\t--> ");
	strcmp_test();
	printf("Testing\t\t'ft_strncmp'\t--> ");
	strncmp_test();
	printf("Testing\t\t'ft_atoi'\t--> ");
	atoi_test();
	printf("Testing\t\t'ft_isalpha'\t--> ");
	isalpha_test();
	printf("Testing\t\t'ft_isdigit'\t--> ");
	isdigit_test();
	printf("Testing\t\t'ft_isalnum'\t--> ");
	isalnum_test();
	printf("Testing\t\t'ft_isascii'\t--> ");
	isascii_test();
	printf("Testing\t\t'ft_isprint'\t--> ");
	isprint_test();
	printf("Testing\t\t'ft_toupper'\t--> ");
	toupper_test();
	printf("Testing\t\t'ft_tolower'\t--> ");
	tolower_test();
}

static void		test_part2(void)
{
	printf(ORG "\n#############\tTEST PART 2\t#############\n" RESET);
	printf("Testing\t\t'ft_putchar'\t--> ");
	putchar_test();
	printf("Testing\t\t'ft_putchar_fd'\t--> ");
	putchar_fd_test();
}

static void		test_bonus(void)
{
	printf(ORG "\n#############\tTEST BONUS\t#############\n" RESET);
}

static void		test_all(void)
{
	test_part1();
	test_part2();
	test_bonus();
}

static void		help(void)
{
	printf(ORG "\n########## HELP ##########\n\n" RESET
			"Welcome to Libft Test !\n"
			"Read this guideline in order to use this programme.\n"
			"First of all, should have your own libft compiled at :\n"
			RED "../Libft/libft.a\n\n" RESET
			"There is the options you can use as arguments to suit your needs :\n"
			GRN "part1" RESET " --> test only the first part.\n"
			GRN "part2" RESET " --> test only the second part.\n"
			GRN "bonus" RESET " --> test only the bonus part.\n"
			GRN "all" RESET "   --> test all the libft.\n"
			GRN "help" RESET "  --> print this help.\n\n"
			"The first 3 options can be combined to do multiple tests.\n"
			"'all' and 'help' must be used alone only.\n"
			"Feel free to midify the source code if you want to improve or adapt his behavior.\n"
			ORG "Good Luck !\n" RESET);
}

int				main(int ac, char **av)
{
	int		i		= 1;
	t_bool	part1	= FALSE;
	t_bool	part2	= FALSE;
	t_bool	bonus	= FALSE;

	if (ac == 1)
	{
		help();
		return (0);
	}
	while (i < ac)
	{
		if (strcmp(av[i], "part1") == 0)
		{
			if (part1)
			{
				printf(RED "Argument Error !\n" RESET
						"Read The Fucking Manual...\n");
				return (1);
			}
			part1 = TRUE;
			test_part1();
		}
		else if (strcmp(av[i], "part2") == 0)
		{
			if (part2)
			{
				printf(RED "Argument Error !\n" RESET
						"Read The Fucking Manual...\n");
				return (1);
			}
			part2 = TRUE;
			test_part2();
		}
		else if (strcmp(av[i], "bonus") == 0)
		{
			if (bonus)
			{
				printf(RED "Argument Error !\n" RESET
						"Read The Fucking Manual...\n");
				return (1);
			}
			bonus = TRUE;
			test_bonus();
		}
		else if (strcmp(av[i], "all") == 0)
		{
			if (part1 || part2 || bonus)
			{
				printf(RED "Argument Error !\n" RESET
						"Read The Fucking Manual...");
				return (1);
			}
			test_all();
			return (0);
		}
		else if (strcmp(av[i], "help") == 0)
		{
			if (part1 || part2 || bonus)
			{
				printf(RED "Argument Error !\n" RESET
						"Read The Fucking Manual...");
				return (1);
			}
			help();
			return (0);
		}
		i++;
	}
	return (0);
}
