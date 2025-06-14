include_directories(negocio)
add_subdirectory(negocio)
include_directories(presentacion)
add_subdirectory(presentacion)

add_executable(${PROJECT_NAME} laboratorio4.cpp)

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/negocio
        ${CMAKE_CURRENT_SOURCE_DIR}/presentacion
)
