set (src_main main.cc)

add_executable (command_and_dominate ${src_main})

target_link_directories (command_and_dominate PUBLIC ${PROJECT_SOURCE_DIR}/lib)

set (libraries
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
	small_utility
	glfw
	pthread
	X11
	${CMAKE_DL_LIBS}
)

target_link_libraries (command_and_dominate ${libraries})
