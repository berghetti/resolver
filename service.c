/*
 *  Copyright (C) 2020 Mayco S. Berghetti
 *
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

int
port2serv ( unsigned short int port,
            char *proto,
            char *buf,
            const size_t buf_len )
{
  struct servent *sve;

  char *protocol = (proto) ? proto : "tcp";

  sve = getservbyport ( port, protocol );

  if ( sve != NULL )
    {
      strncpy ( buf, sve->s_name, buf_len );
      return 1;
    }
  else
    snprintf ( buf, buf_len, "%u", port );

  return 0;
}
