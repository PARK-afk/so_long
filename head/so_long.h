/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 03:46:36 by junsepar          #+#    #+#             */
/*   Updated: 2023/07/28 18:54:34 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3

# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define BUFFER_SIZE 1
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>

typedef struct s_position
{
	int		p_x;
	int		p_y;
}	t_position;

typedef struct s_game
{
	t_position	chr;
	t_position	exi;
	int			clt;
	void		*mlx_ptr;
	void		*mlx_win;
	void		**mlx_img;
	char		**map;
	int			move_cnt;
}	t_game;

// main.c
char		**map_maker(int fd);
int			check_mapname(char	*map_name, char *ber);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

// check.c
void		check(t_game *game);
void		check_map(char **map);
t_position	check_player(char **map);
t_position	check_exit(char **map);
int			check_collectible(char **map);

//check_size.c
int			get_x_size(char **map);
int			get_y_size(char **map);

// check_error.c
void		ft_error(int i);
void		allfree(char **smap);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
void		*clear(char **result, char **ptr);

// dfs.c
void		do_dfs(char **map, int y, int x);
char		**dfs_mapinit(char **map);
int			check_valid(char **map, int y, int x);

// exit.c
void		exit_game(t_game *game, int i);
int			exit_game2(t_game *game);

// ft_split.c
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
char		**word_dup(char **ptr, char *word, char const *s, char c);
size_t		word_count(char const *s, char c);
char		*find_word(char const *s, char c);

// get_next_line.c
char		*get_next_line(int fd);
char		*need_backup(char *line);
char		*read_line(int fd, char *buf, char *backup, int n);
size_t		ft_strlen(const char *s);

// get_next_line_utils.c
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const*s2);
int			ft_strlcpy(char *dst, \
			const char *src, int dstsize);
int			ft_strlcat(char *dst, \
			const char *src, int dstsize);

// key.c
int			press_key(int key_code, t_game *game);
void		move_w(t_game *game);
void		move_a(t_game *game);
void		move_s(t_game *game);
void		move_d(t_game *game);

// mlx_start.c
void		mlx_start(t_game *game);
void		**mlx_map_init(void *mlx);
void		mlx_put_map(t_game *game, void *mlx, void *win);
int			img_check(char c, int clt);
int			*size_of_window(char **map);

// mlx_utils.c
void		move_count_print(int i);
void		move_count(int i);

#endif
