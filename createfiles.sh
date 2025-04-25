#!/bin/bash

gid="166794"
firstname="Sarthak"
lastname="Bosamiya"

read -p "Enter the Module number: " module
dir_path="./Module${module}/src"

read -p "Enter the number of C files to create: " num_files

base_name="${gid}_${firstname}${lastname}_DR${module}_T005"

current_date=$(date +"%d-%m-%Y")

content=$(cat <<EOF
// Question 

/** REQUIRED HEADER FILES **/

#include<stdio.h>
#include"../include/head.h"

/*
 * Name of the function:  
 * Author: ${firstname} ${lastname}
 * Created: $current_date
 * Modified: $current_date
*/
EOF
)

if [ ! -d "$dir_path" ]; then
    echo "Directory does not exist. Creating directory: $dir_path ...................."
    mkdir -p "$dir_path"
fi

for ((i=1; i<=num_files; i++))
do
	file_name="${dir_path}/${base_name}_${i}.c"
    	echo -e "$content" | cat > "$file_name"
    	echo "Created: $file_name .................."
done

echo -e "$content" | cat > "${dir_path}/main.c"
echo "Created: ${dir_path}/main.c .................."

head_dir="./Module${module}/include"
executable="./Module${module}/executable"
bin="./Module${module}/bin"

cp ./Module1/Makefile ./Module${module}/Makefile

echo "Makefile is copied.........."

mkdir -p "./Module${module}/include"
head_file="${head_dir}/head.h"
touch $head_file
head_content=$(cat <<EOF
#ifndef HEAD_H
#define HEAD_H


#endif
EOF
)
echo -e "$head_content" | cat > "$head_file"

mkdir -p $executable
mkdir -p $bin

echo "Diretories for head files, executable files and bin files are created.............."
