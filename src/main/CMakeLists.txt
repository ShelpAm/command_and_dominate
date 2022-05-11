set (src_main main.cc)

add_executable (main ${src_main})

target_link_directories (main PUBLIC ${PROJECT_SOURCE_DIR}/lib)

set (base_libraries
	camera
	font
	game
	game_object
	image
	light
#	memory_tracer
	shader
	sound
	uniform_block
	window
	assimp
	glad
	small_utility
	glfw
)

set (linux_libraries
	pthread
	X11
	#	${CMAKE_DL_LIBS}
)

set (windows_libraries

)

if (UNIX)
	set (libraries ${base_libraries} ${linux_libraries})
elseif (WIN32)
	set (libraries ${base_libraries} ${windows_libraries})
endif ()

target_link_libraries (main ${libraries})
