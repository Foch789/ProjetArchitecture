set(SRC ColorImage.cpp Face.cpp FragmentShader.cpp Image.cpp Maths.cpp NormalCalculation.cpp Object.cpp OpenMPNormalCalculation.cpp Program.cpp PThreadNormalCalculation.cpp SequentialNormalCalculation.cpp Shader.cpp Texture.cpp TextureCoordinates.cpp Toolbox.cpp Vector.cpp Vertex.cpp VertexShader.cpp Window.cpp)

add_library(SuperOpenGL STATIC ${SRC})
target_include_directories(SuperOpenGL SYSTEM PUBLIC ${INCLUDE_DIR})
target_link_libraries(SuperOpenGL ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} ${JPEG_LIBRARIES})
