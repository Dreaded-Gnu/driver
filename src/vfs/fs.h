
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

#if ! defined( __VFS_FS__ )
#define __VFS_FS__

#include <stdint.h>

#define FS_TYPE_FILE 0x1
#define FS_TYPE_DIRECTORY 0x2
#define FS_TYPE_CHARDEVICE 0x3
#define FS_TYPE_BLOCKDEVICE 0x4
#define FS_TYPE_PIPE 0x5
#define FS_TYPE_SYMLINK 0x6
#define FS_TYPE_MOUNTPOINT 0x8

typedef struct fs_node fs_node_t, *fs_node_ptr_t;
typedef struct dirent dirent_t, *dirent_ptr_t;

typedef uint32_t ( *read_type_t )( fs_node_ptr_t, uint32_t, uint32_t, uint8_t* );
typedef uint32_t ( *write_type_t )( fs_node_ptr_t, uint32_t, uint32_t, uint8_t* );
typedef void ( *open_type_t )( fs_node_ptr_t );
typedef void ( *close_type_t )( fs_node_ptr_t );
typedef dirent_ptr_t ( *readdir_type_t )( fs_node_ptr_t, uint32_t );
typedef fs_node_ptr_t ( *finddir_type_t )( fs_node_ptr_t, char* );

typedef struct fs_node {
  char name[ 128 ];
  uint32_t mask;
  uint32_t uid;
  uint32_t gid;
  uint32_t flags;
  uint32_t inode;
  uint32_t length;
  uint32_t impl;

  read_type_t read;
  write_type_t write;
  open_type_t open;
  close_type_t close;
  readdir_type_t readdir;
  finddir_type_t finddir;
  fs_node_ptr_t ptr;
} fs_node_t, *fs_node_ptr_t;

typedef struct dirent {
  char name[ 128 ];
  uint32_t ino;
} dirent_t, *dirent_ptr_t;

extern fs_node_ptr_t fs_root;

uint32_t fs_read( fs_node_ptr_t, uint32_t, uint32_t, uint8_t* );
uint32_t fs_write( fs_node_ptr_t, uint32_t, uint32_t, uint8_t* );
void fs_open( fs_node_ptr_t, uint8_t, uint8_t );
void fs_close( fs_node_ptr_t );
dirent_ptr_t fs_readdir( fs_node_ptr_t, uint32_t );
fs_node_ptr_t fs_finddir( fs_node_ptr_t, char* );

#endif
