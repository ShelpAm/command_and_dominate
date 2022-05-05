set (src_main main.cc)

add_executable (command_and_dominate ${src_main})
target_link_libraries (command_and_dominate
	game
	window)
