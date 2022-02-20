#!/bin/bash

declare fileName=$1

as $fileName.asm -o $fileName.o
ld $fileName.o -o $fileName
./$fileName
echo $?