include_directories (${SDL_gpu_SOURCE_DIR})

set(DEMO_LIBS SDL_gpu)

if(MINGW)
    set(DEMO_LIBS ${DEMO_LIBS} mingw32)
endif(MINGW)

add_executable(init-demo init/main.c)
target_link_libraries (init-demo ${DEMO_LIBS})

add_executable(3d-demo 3d/main.c ../src/externals/glew/glew.c)
target_link_libraries (3d-demo ${DEMO_LIBS})

add_executable(tutorial-space-demo tutorial-space/main.c)
target_link_libraries (tutorial-space-demo ${DEMO_LIBS})