cmake_minimum_required (VERSION 2.6)
project (Libpaillier-with-constant-time-dec)

set(CMAKE_C_FLAGS "-pthread -O3 -lgmp -lm")
find_package(GMP REQUIRED)

add_library(libpaillier.a paillier.c)

install(TARGETS libpaillier.a DESTINATION lib)
install(FILES paillier.h DESTINATION include)

add_executable(Test test.c)
target_link_libraries(Test GMP libpaillier.a)