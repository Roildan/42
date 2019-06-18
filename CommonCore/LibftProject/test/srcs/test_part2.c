/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_part2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:54:56 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/08 18:58:14 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_test.h"

void	putchar_test(void)
{
	int		my_pipe[2];
	int		out;
	char	buff[5];

	out = dup(STDOUT_FILENO);
	pipe(my_pipe);
	dup2(my_pipe[1], STDOUT_FILENO);
	ft_putchar('T');
	ft_putchar('3');
	ft_putchar('s');
	ft_putchar('t');
	dup2(out, STDOUT_FILENO);
	read(my_pipe[0], buff, 4);
	buff[4] = '\0';
	close(my_pipe[0]);
	close(my_pipe[1]);
	close(out);
	if (strcmp(buff, "T3st") == 0)
		printf(GRN "WORKING !\n" RESET);
	else
		printf(RED "FAILED !\n" RESET);
}

void	putchar_fd_test(void)
{
	int		my_pipe[2];
	char	buff[5];

	pipe(my_pipe);
	ft_putchar_fd('T', my_pipe[1]);
	ft_putchar_fd('3', my_pipe[1]);
	ft_putchar_fd('s', my_pipe[1]);
	ft_putchar_fd('t', my_pipe[1]);
	read(my_pipe[0], buff, 4);
	buff[4] = '\0';
	close(my_pipe[0]);
	close(my_pipe[1]);
	if (strcmp(buff, "T3st") == 0)
		printf(GRN "WORKING !\n" RESET);
	else
		printf(RED "FAILED !\n" RESET);
}
