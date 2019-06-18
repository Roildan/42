/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:51:41 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/08 16:17:28 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

/*
** General :
*/
# define SPACE 13
# define CHAR_WIDTH 10
# define CHAR_HEIGHT 23
# define LINE 50

/*
** Main window :
*/
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

/*
** Title settings :
*/
# define TITLE_NAME "FDF by Armoulin"
# define TITLE_WIDTH 1080
# define TITLE_HEIGHT 50

/*
** Menu settings :
*/
# define MENU_WIDTH 400
# define MENU_HEIGHT (WIN_HEIGHT - TITLE_HEIGHT)
# define FIXED_MENU (LINE * 7 - SPACE)
# define OFFSET (LINE + CHAR_HEIGHT * 2)
# define ROTATIONS (SPACE * 3 + LINE * 3)
# define CASE_HEIGHT (LINE * 2)
# define CASE_WIDTH (((MENU_WIDTH - SPACE * 2) / 3) + 1)
# define PROJECTIONS (LINE * 7)

/*
** Image settings :
*/
# define IMG_WIDTH (WIN_WIDTH - MENU_WIDTH)
# define IMG_HEIGHT (WIN_HEIGHT - TITLE_HEIGHT)

#endif
