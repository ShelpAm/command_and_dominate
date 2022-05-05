#ifndef COMMAND_AND_DOMNIATE_SRC_GAME_GAME_FORWARD_H_
#define COMMAND_AND_DOMNIATE_SRC_GAME_GAME_FORWARD_H_

#include <memory>

class Game;
using GamePtr = std::shared_ptr<Game>;

enum class GameState : int;

#endif // !COMMAND_AND_DOMNIATE_SRC_GAME_GAME_FORWARD_H_
