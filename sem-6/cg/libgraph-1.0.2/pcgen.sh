#!/bin/sh

printf "prefix=%s\n" $1
printf "exec_prefix=%s\n" $1
printf "libdir=%s\n" $2
printf "bindir=%s\n" $3
printf "includedir=%s\n\n" $4
printf "Name: %s\n" $5
printf "Description: TC graphics API on GNU/Linux\n"
printf "Version: %s\n" $6
printf "Requires: \n"
printf "Libs: -L%s -lgraph\n" $2
printf "Cflags: -I%s\n" $4

