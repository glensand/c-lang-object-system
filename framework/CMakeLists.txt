cmake_minimum_required(VERSION 3.15)

project(ooc-framework C)

file(GLOB TABLE_HEADERS
    *.h
)

file(GLOB TABLE_SOURSES
    *.c
)

add_library(ooc-framework STATIC ${TABLE_HEADERS} ${TABLE_SOURSES})
