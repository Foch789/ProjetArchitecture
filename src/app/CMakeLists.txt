set(SRC Game.cpp main.cpp MainWindow.cpp Projectile.cpp Target.cpp View.cpp)

add_executable(app ${SRC})
target_link_libraries(app SuperOpenGL)
