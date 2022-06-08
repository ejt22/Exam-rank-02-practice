/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:58:41 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/06/08 11:05:58 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <unistd.h>
# include <stdlib.h>

int	ft_strlen(char *s);
int	search_newline(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*read_and_stash(int fd, char *stash);
char	*extract_line(char *line_in);
char	*clean_up(char *line_in);
char	*get_next_line(int fd);

#endif
