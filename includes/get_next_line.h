/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 15:12:09 by tdieumeg          #+#    #+#             */
/*   Updated: 2013/12/17 15:19:26 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

# include	"libft.h"
# include	<stdlib.h>
# include	<unistd.h>
# define	BUFF_SIZE 512

int			get_next_line(int const fd, char **line);

#endif		/* !GET_NEXT_LINE_H */
