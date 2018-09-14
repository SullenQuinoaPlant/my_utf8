/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inner.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:00:16 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/14 10:00:23 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INNER_H
# define INNER_H

# include <limits.h>
# include "libmystupidmath.h"
# include "libft.h"

# define CHAR_HBIT (CHAR_BIT - 1)
# define ASCII_MASK (~0 << CHAR_HBIT)
# define UTF8_BITS (CHAR_BIT - 2)
# define UTF8_BMASK (~0 << UTF8_BITS)
# define UTF8_10X ('\1' << CHAR_HBIT)

/*
** 4 = 4. But it's portable! (maybe)
*/
# define UTF8_TTL_BITS 21
# define UTF8_MAJ_TTL_BITS (UTF8_TTL_BITS + CHAR_HBIT)
# define UTF8_BIT_GRPS (UTF8_MAJ_TTL_BITS / UTF8_BITS)
# define UTF8_LST_GRP (UTF8_TTL_BITS % UTF8_BITS)
# define UTF8_LEAD_PRFX (UTF8_BIT_GRPS + 1)
# define UTF8_LEAD_BITS (UTF8_LST_GRP + UTF8_LEAD_PRFX)
# define UTF8_LEAD (UTF8_LEAD_BITS > CHAR_BIT)
# define UTF8_MAX_CHARS (UTF8_LEAD + UTF8_BIT_GRPS)
/*
** # define UTF8_MAX_CHARS 4
*/

#endif
