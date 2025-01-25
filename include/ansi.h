/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ansi.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:08:48 by ielyatim          #+#    #+#             */
/*   Updated: 2025/01/25 18:09:11 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANSI_H
# define ANSI_H

# define BLACK "\x1B[30m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"
# define MAGENTA "\x1B[35m"
# define CYAN "\x1B[36m"
# define WHITE "\x1B[37m"
# define RESET "\x1B[0m"
# define BOLD "\x1B[1m"
# define CLEAR "\x1B[H\x1B[J"

# define B_RED "\x1B[1;31m"
# define B_RED "\x1B[1;31m"
# define B_GREEN "\x1B[1;32m"
# define B_YELLOW "\x1B[1;33m"
# define B_WHITE "\x1B[1;37m"

# define R_RED "\x1B[0m\x1B[31m"
# define R_GREEN "\x1B[0m\x1B[32m"
# define R_YELLOW "\x1B[0m\x1B[33m"

# define ERROR_START "\x1B[1;31mError\n\x1B[0m\x1B[31m"
# define ERROR_END ".\n\n\x1B[0m"

#endif // ANSI_H
