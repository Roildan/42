/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:14:22 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/08 22:32:50 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TEST_H
# define LIBFT_TEST_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

# include "../../Libft/libft.h"

# define RED		"\x1B[31m"
# define GRN		"\x1B[32m"
# define ORG		"\x1B[33m"
# define RESET		"\033[0m"

typedef enum	e_bool
{
	FALSE	= 0,
	TRUE	= 1
}				t_bool;

#endif
