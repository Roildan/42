/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 00:07:27 by armoulin          #+#    #+#             */
/*   Updated: 2019/03/31 14:25:40 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "Get_Next_Line/get_next_line.h"

int		main(int ac, char **av)
{/*
	(void)ac;
	(void)av;
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "oiuytrew\n", 9);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	dprintf(1, "%d\n", strcmp(line, "oiuytrew") == 0);
	free(line);*/


	if (ac < 2)
		return (0);
	int fd = open(av[1], O_RDONLY);
/*	int fd2;
	int fd3;
	fd2 = open(av[2], O_RDONLY);
	fd3 = open(av[3], O_RDONLY);*/
	char *line;
/*	get_next_line(fd, &line);
	ft_putstr(line);
	ft_putstr("\n");
	free(line);
	get_next_line(fd2, &line);
	ft_putstr(line);
	ft_putstr("\n");
	free(line);
	get_next_line(fd3, &line);
	ft_putstr(line);
	ft_putstr("\n");
	free(line);
	get_next_line(fd, &line);
	ft_putstr(line);
	ft_putstr("\n");
	free(line);
	get_next_line(fd2, &line);
	ft_putstr(line);
	ft_putstr("\n");
	free(line);
	get_next_line(fd3, &line);
	ft_putstr(line);
	ft_putstr("\n");
	free(line);
	get_next_line(fd, &line);
	ft_putstr(line);
	ft_putstr("\n");
	free(line);
*/

	while (get_next_line(fd, &line))
	{
		ft_putstr(line);
		ft_putstr("\n");
		free(line);
	}
	close(fd);
	//while (1)
	//	;
	return (0);
/*	
	char *line;
	int fd;
	int fd2;
	int fd3;
	int	diff_file_size;
    
    system("mkdir -p sandbox");
	system("openssl rand -base64 $((30 * 1000 * 3/4)) | tr -d '\n' | tr -d '\r' > sandbox/one_big_fat_line.txt");
	system("echo '\n' >> sandbox/one_big_fat_line.txt");

	fd = open("sandbox/one_big_fat_line.txt", O_RDONLY);
	fd2 = open("sandbox/one_big_fat_line.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);

	while (get_next_line(fd, &line) == 1)
	{
	    write(fd2, line, strlen(line));
	    write(fd2, "\n", 1);
	}
	if (line)
		write(fd2, line, strlen(line));
	close(fd);
	close(fd2);

	system("diff sandbox/one_big_fat_line.txt sandbox/one_big_fat_line.txt.mine > sandbox/one_big_fat_line.diff");
	fd3 = open("sandbox/one_big_fat_line.diff", O_RDONLY);
	diff_file_size = read(fd3, NULL, 10);
	close(fd3);

	mt_assert(diff_file_size == 0);
*/
}
