cmake_minimum_required(VERSION 3.23)
project(ing2_tg_2023_2024_groupe7_equipe9 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ing2_tg_2023_2024_groupe7_equipe9
        main.c maintest.c precedence.c precedence.h exclusions.c exclusions.h operation.c operation.h exclusionstest.h menu.c)
