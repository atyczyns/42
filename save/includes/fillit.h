/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 08:41:37 by fpayen            #+#    #+#             */
/*   Updated: 2019/01/29 19:00:27 by fpayen           ###   ########.fr       */
/*   Updated: 2019/01/09 12:43:48 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>

typedef struct	s_piece
{
	unsigned int	mask[4];
	size_t			x;
	size_t			y;
	unsigned int	profile;
	size_t			index;
	size_t			applied;
}				t_piece;

char			**get_tetris(const int fd, const char *file_name,
		size_t *nb_pieces);
int				two_connected(char **area, int x, int y);
int				three_connected(char **area, int x, int y);
int				check_last_character(int fd, const char *file_name);
t_piece			*char_to_bit(char **tetris, size_t nb_pieces);
char			**bit_to_char(unsigned int *square, t_piece *pieces);
void			free_2darr(char **arr);
unsigned int	*biggest_square(t_piece *pieces, size_t nb_pieces);
int				room_check(unsigned int *square, t_piece p, size_t y,
		size_t size);
void			mask_reset(t_piece *piece, size_t i, size_t *y);
void			mask_shift_right(t_piece *piece, size_t i);
void			mask_shift_left(t_piece *piece, size_t i);
void			mask_apply(unsigned int *square, t_piece *piece, size_t i,
		size_t y);
void			mask_remove(unsigned int *square, t_piece *piece, size_t i,
		size_t y);
size_t			square_size(unsigned int *square);
void			pieces_reset(t_piece *piece);
t_piece			*pieces_cpy(t_piece *piece, size_t nb_pieces);
void			piece_swap(t_piece *piece, size_t i, size_t j);
void			piece_overwrite(t_piece *dst, t_piece *src);
int				final_square(unsigned int *square, t_piece *piece, size_t size,
		size_t nb_pieces);
void			list_reset(t_piece **piece);

#endif
