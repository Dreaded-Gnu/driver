
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

#include <stdio.h>

int main( int argc, __unused char* argv[] ) {
  // check arguments
  if ( 1 >= argc ) {
    printf( "Initrd address missing!\r\n" );
    return -1;
  }

  return 0;
}
