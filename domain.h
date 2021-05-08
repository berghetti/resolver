
/*
 *  Copyright (C) 2020-2021 Mayco S. Berghetti
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

#ifndef RESOLVER_H
#define RESOLVER_H

#include <sys/socket.h>  // struct sockaddr_storage
#include <netdb.h>       // NI_MAXHOST

#include "thread_pool.h"  // facility include in clients, include only domain.h

struct hosts
{
  struct sockaddr_storage ss;
  char fqdn[NI_MAXHOST];
  int status;
};

// retorna imediatamente o ip em formato de texto, porém na proxima requisição
// irá retornar o dominio que estará em cache (se tudo der certo).
// evitando a latencia que uma consulta DNS pode ter.
int
ip2domain ( struct sockaddr_storage *ss, char *buff, const size_t buff_len );

#endif  // RESOLVER_H
