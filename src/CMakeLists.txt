set (CMAKE_BUILD_TYPE "DEBUG")
#set (CMAKE_BUILD_TYPE "RELEASE")

set (thirdparty_directory ${PROJECT_SOURCE_DIR}/thirdparty)

set (include_native ${PROJECT_SOURCE_DIR}/include)
set (include_thirdparty
	${thirdparty_directory}/glad/include
	${thirdparty_directory}/glfw-3.3.7/include
)
set (includes ${include_native} ${include_thirdparty})

include_directories (${includes})

add_subdirectory (camera)
add_subdirectory (font)
add_subdirectory (game)
add_subdirectory (game_object)
add_subdirectory (image)
add_subdirectory (light)
add_subdirectory (main)
add_subdirectory (model)
add_subdirectory (shader)
add_subdirectory (sound)
add_subdirectory (uniform_block)
add_subdirectory (window)

