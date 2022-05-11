#include "command_and_dominate/game/game.h"
#include <cstdio>
#include <exception>
#include "small_utility/log/logger.h"
#include "small_utility/math/color/color.h"
#include "small_utility/utility/utility.h"
#include "command_and_dominate/glad.h"
#include "command_and_dominate/game_object/rendered_object.h"
#include "command_and_dominate/model/mesh.h"
#include "command_and_dominate/shader/shader.h"
#include "command_and_dominate/uniform_block/uniform_block.h"

bool Game::keys_[348] = { false };
bool Game::keys_pressed_single_times_[348] = { false };
//Camera Game::camera_(glm::vec3(0.0f, 1.0f, 0.0f), 1.0f,
//                    glm::vec3(0.0f), glm::vec3(0.0f),
//                    nullptr, glm::vec3(0.0f), 0.0f, 0.0f, 0.0f,
//                    "test_camera_", "test_camera_ui");

void Game::Initialize(int argc, char *argv[]) {
  try {
    small_utility::log_stuff::Logger::Instance().SetPatternDefault(
        "[$(time)] $(log_level) $(file_name):$(line) in function"
        " `$(function_name)': $(content)\n");
    small_utility::log_stuff::Logger::Instance().SetLogLevelMinimum(
        small_utility::log_stuff::LogLevel::kLogLevelDebug);

    small_utility::log_stuff::Debug("initializing game");
    Window::Initialize();
  } catch (std::exception const &e) {
    throw;
  }
}

void Game::Terminate() {
  small_utility::log_stuff::Debug("terminating game");
  small_utility::log_stuff::Logger::Instance().WriteToTarget("console");

  Shader::Terminate();
  UniformBlock::Terminate();
  Window::Terminate();
}

GamePtr Game::Create(WindowPtr const &window_ptr) {
  GamePtr game_ptr = std::make_shared<Game>(window_ptr);
  UniformBlockPtr uniform_block_ptr0 =
      UniformBlock::Create("0", "matrices", 3 * sizeof(Matrix4x4<float>), 0);
  ShaderPtr shader_ptr0 = Shader::Create("0", "shader/test.vert",
                                         "shader/test.frag",
                                         "shader/test.geom");
  if (uniform_block_ptr0) {
    if (shader_ptr0) {
      shader_ptr0->BindUniformBlock(uniform_block_ptr0);
    }
  }
  RenderedObjectPtr rp = RenderedObject::Create("0");
  game_ptr->rendered_object_ptrs_.push_back(rp);
  game_ptr->game_state_ = GameState::kGameStateStarted;
  return game_ptr;
}

Game::Game(WindowPtr const &window_ptr)
    : window_ptr_(window_ptr),
      window_clear_color_(Color(0.5f, 0.5f, 0.5f, 1.0f)),
      blend_(true),
      blend_default_(true),
      pause_(false),
      pause_default_(false),
      game_state_(GameState::kGameStateStarted) {}

Game::~Game() {
  Delete();
}

unsigned int indices[] = { // 注意索引从0开始! 
  0, 1, 3, // 第一个三角形
  1, 2, 3  // 第二个三角形
};


void Game::Run() {
  int begin_time = 0, end_time = 0, delta_time = 0, sleep_time = 0;
  float constexpr target_fps = 30;
  while (!glfwWindowShouldClose(window_ptr_->GetGLFWWindowPtr())) {
    glfwPollEvents();

    glClearColor(window_clear_color_.GetR(), window_clear_color_.GetG(),
                 window_clear_color_.GetB(), window_clear_color_.GetA());
    glClear(GL_COLOR_BUFFER_BIT);

    ProcessInput();

    // all the units of time is millisecond,
    // and the unit of return value of glfwGetTime() is second
    end_time = glfwGetTime() * 1000;
    delta_time = end_time - begin_time;

    sleep_time = 1000 / target_fps - delta_time;
    printf("[Debug::Game::Update] delta_time_: %ims.\n", delta_time);
    printf("[Debug::Game::Update] sleep_time: %ims.\n", sleep_time);
    small_utility::utility_stuff::Sleep(sleep_time);

    begin_time = glfwGetTime() * 1000;

    Update(delta_time);
    Render();
    std::vector<Vertex<float>> vv;
    Vertex<float> v;
    v.position = Vector3D<float>(0.5f,0.5f,0.0f);
    vv.push_back(v);
    v.position = Vector3D<float>(0.5f,-0.5f,0.0f);
    vv.push_back(v);
    v.position = Vector3D<float>(-0.5f,-0.5f,0.0f);
    vv.push_back(v);
    v.position = Vector3D<float>(-0.5f,0.5f,0.0f);
    vv.push_back(v);
    std::vector<unsigned int> iv(indices, indices+6);
    MeshPtr<float> mp = Mesh<float>::Create(vv,iv,std::vector<Image2DPtr>());
    mp->Render(Shader::Get("0"));

    glfwSwapBuffers(window_ptr_->GetGLFWWindowPtr());
  }
}

void Game::ProcessInput() {
  if (keys_[GLFW_KEY_ESCAPE]) {
    glfwSetWindowShouldClose(window_ptr_->GetGLFWWindowPtr(), true);
  }
}

void Game::Update(float const delta_time) {
  for (auto &iterator : rendered_object_ptrs_) {
    iterator->Update(delta_time);
  }
}

void Game::Render() const {
  if (game_state_ == GameState::kGameStateOnMenu) {
  } else if (game_state_ == GameState::kGameStateStarted) {
    // sends data to gpu
    UniformBlockPtr uniform_block_ptr0 = UniformBlock::Get("0");
    ShaderPtr shader_ptr0 = Shader::Get("0");
    if (!shader_ptr0 || !uniform_block_ptr0) {
      return;
    }
    Matrix4x4<float> projection = Perspective(1.0f, 1.25f, 0.1f, 100.0f);
    //Matrix4x4<float>
    //uniform_block_ptr0->FillBuffer();

    shader_ptr0->Use();
    shader_ptr0->Set1Float("test", 0.5f);

    if (glIsEnabled(GL_BLEND)) {
      glDisable(GL_BLEND);
    }
    // for each -> render.
    for (auto &iterator : rendered_object_ptrs_) {
      iterator->Render(shader_ptr0);
    }
  }
}

void Game::Delete() {
  window_ptr_.reset();
}
