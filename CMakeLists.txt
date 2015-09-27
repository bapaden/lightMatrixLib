cmake_minimum_required(VERSION 2.6)
project(lightmatrixlib)

add_executable(lightmatrixlib main.cpp matrix.h)

install(TARGETS lightmatrixlib RUNTIME DESTINATION bin)
