# In The Name Of God
# ========================================
# [] File Name : CMakeLists.txt
#
# [] Creation Date : 06-03-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
add_executable(CoDesign.out main.c
	defs.h
	decoder.h decoder.c
	population.h population.c
	lfsr.h lfsr.c
	text.h text.c
	serial.h serial.c
	)

target_link_libraries(CoDesign.out pthread)

# Add personal c flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O0 -g -std=gnu11 ")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -DDEBUG")
