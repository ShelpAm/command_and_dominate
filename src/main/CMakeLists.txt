set (src_main main.cc)

add_executable (command_and_dominate ${src_main})

target_link_directories (command_and_dominate
	PUBLIC ${PROJECT_SOURCE_DIR}/lib)

target_link_libraries (command_and_dominate
	camera
	font
	game
	game_object
	image
	light
#	memory_tracer
	model
	shader
	sound
	uniform_block
	window
	glad
	${CMAKE_DL_LIBS}
	small_utility
	glfw3
	pthread
	X11
)
