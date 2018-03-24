set(SRC main.cpp MainWindow.cpp)

add_executable(app ${SRC})
target_link_libraries(app SuperOpenGL)
