cmake_minimum_required(VERSION 3.30)
project(Laboratorio4)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SRC_SUB_HEADERS src/*.h)
file(GLOB_RECURSE SRC_SUB_SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} src/laboratorio4.cpp ${SRC_SUB_SOURCES}
        src/negocio/controller/usuario/IUsuarioController.cpp)

if(SRC_SUB_SOURCES)
    add_library(Src STATIC ${SRC_SUB_HEADERS} ${SRC_SUB_SOURCES}
            src/presentacion/AltaUsuario.cpp
            src/presentacion/AltaUsuario.h
            src/negocio/dto/DTOUsuario.cpp
            src/negocio/dto/DTOUsuario.h
            src/negocio/dto/DTOVendedor.cpp
            src/negocio/dto/DTOVendedor.h
            src/negocio/dto/DTOCliente.cpp
            src/negocio/dto/DTOCliente.h
            src/negocio/controller/usuario/IUsuarioController.h
            src/negocio/controller/usuario/IUsuario.h
            src/presentacion/ListarUsuarios.cpp
            src/presentacion/ListarUsuarios.h
            src/presentacion/DejarComentario.cpp
            src/presentacion/DejarComentario.h)

    target_include_directories(Src PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}
            ${CMAKE_CURRENT_SOURCE_DIR}/src
    )
else()
    message(FATAL_ERROR "No se encontraron archivos en Source")
endif()
