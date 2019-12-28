
/**
 * Copyright (C) 2018 - 2019 bolthur project.
 *
 * This file is part of bolthur/driver.
 *
 * bolthur/driver is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * bolthur/driver is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with bolthur/driver.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "fs.h"
#include <stddef.h>

fs_node_ptr_t fs_root = NULL;

uint32_t fs_read(
  fs_node_ptr_t node,
  uint32_t offset,
  uint32_t size,
  uint8_t* buffer
) {
  if ( NULL != node->read ) {
    return node->read( node, offset, size, buffer );
  }
  return 0;
}

uint32_t fs_write(
  fs_node_ptr_t node,
  uint32_t offset,
  uint32_t size,
  uint8_t* buffer
) {
  if ( NULL != node->write ) {
    return node->write( node, offset, size, buffer );
  }
  return 0;
}

void fs_open(
  fs_node_ptr_t node,
  __unused uint8_t read,
  __unused uint8_t write
) {
  if ( NULL != node->open ) {
    node->open( node );
  }
}

void fs_close(
  fs_node_ptr_t node
) {
  if ( NULL != node->close ) {
    node->close( node );
  }
}

dirent_ptr_t fs_readdir(
  fs_node_ptr_t node,
  uint32_t index
) {
  if (
    FS_TYPE_DIRECTORY == ( node->flags & 0x7 )
    && NULL != node->readdir
  ) {
    return node->readdir( node, index );
  }
  return NULL;
}

fs_node_ptr_t fs_finddir(
  fs_node_ptr_t node,
  char* name
) {
  if (
    FS_TYPE_DIRECTORY == ( node->flags & 0x7 )
    && NULL != node->finddir
  ) {
    return node->finddir( node, name );
  }
  return NULL;
}
