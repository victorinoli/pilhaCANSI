cmake_minimum_required(VERSION 3.30)
project(pilhaCansi C)

set(CMAKE_C_STANDARD 90)

add_executable(pilhaCansi main.c
        leArquivo.c
        leArquivo.h
        node.c
        node.h
        pegaSeta.c
        pegaSeta.h)
