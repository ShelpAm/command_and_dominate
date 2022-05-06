set (src_game_object
	basic_object.cc
	game_object.cc
	immovable_object.cc
	movable_object.cc
	rendered_object.cc
)

add_library (game_object ${src_game_object})
