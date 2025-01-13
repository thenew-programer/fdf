/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:13:41 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/12 09:13:48 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err_msg.h"
#include "fdf.h"
#include "libft.h"

int ft_strs_len(char **strs) {
  int i;

  if (!strs)
    return (-1);
  i = 0;
  while (strs[i])
    i++;
  return (i);
}

void free_split_strs(char **strs, char *line) {
  int i;

  i = 0;
  while (strs[i])
    free(strs[i++]);
  free(strs);
  if (line)
    free(line);
}

t_bool check_file_ext(char *filename, t_fdf *data) {
  char **strs;
  int i;
  int len;

  if (!filename)
    die(FILE_EXT_ERR, data);
  strs = ft_split(filename, '.');
  if (!strs || !*strs)
    die(FILE_EXT_ERR, data);
  i = 0;
  while (strs[i + 1])
    i++;
  len = ft_strlen(strs[i]);
  if (ft_strncmp(strs[i], "fdf", len) != 0) {
    free_split_strs(strs, NULL);
    die(FILE_EXT_ERR, data);
  }
  return (free_split_strs(strs, NULL), TRUE);
}

int open_file(char *filename, t_fdf *data) {
  int fd;

  fd = open(filename, O_RDONLY);
  if (fd < 3)
    die(FILE_ERR, data);
  return (fd);
}

t_bool check_map(char *filename, t_fdf *data) {
  int fd;
  char *line;
  char **strs;
  int coor[2];

  fd = open_file(filename, data);
  line = get_next_line(fd);
  if (!line)
    die(MAP_EMPTY, data);
  strs = ft_split(line, ' ');
  coor[0] = ft_strs_len(strs);
  free_split_strs(strs, NULL);
  coor[1] = 0;
  while (line && ++coor[1] >= 0) {
    strs = ft_split(line, ' ');
    if (ft_strs_len(strs) != coor[0])
      return (free_split_strs(strs, line), FALSE);
    free_split_strs(strs, line);
    line = get_next_line(fd);
  }
  data->cols = coor[0];
  data->rows = coor[1];
  close(fd);
  return (TRUE);
}

int min(int x, int y) {
  if (x <= y)
    return (x);
  return (y);
}
