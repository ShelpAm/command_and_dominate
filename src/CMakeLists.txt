set (include_native ${PROJECT_SOURCE_DIR}/include)
set (include_shared ${PROJECT_SOURCE_DIR}/shared/include)

set (includes ${include_native} ${include_shared})

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

