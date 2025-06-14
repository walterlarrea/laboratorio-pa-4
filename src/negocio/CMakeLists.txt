file(GLOB NEGOCIO_HEADERS *.h)
file(GLOB NEGOCIO_SOURCES *.cpp)

file(GLOB_RECURSE NEGOCIO_SUB_HEADERS
        DTOs/*.h
        dominio/*.h
        controladores/*.h
)

file(GLOB_RECURSE NEGOCIO_SUB_SOURCES
        DTOs/*.cpp
        dominio/*.cpp
        controladores/*.cpp
)

set(ALL_NEGOCIO_HEADERS ${NEGOCIO_HEADERS} ${NEGOCIO_SUB_HEADERS})
set(ALL_NEGOCIO_SOURCES ${NEGOCIO_SOURCES} ${NEGOCIO_SUB_SOURCES})


if(ALL_NEGOCIO_SOURCES)
    add_library(Negocio STATIC ${ALL_NEGOCIO_SOURCES} ${ALL_NEGOCIO_HEADERS})

    target_include_directories(Negocio PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}
            ${CMAKE_CURRENT_SOURCE_DIR}/DTOs
            ${CMAKE_CURRENT_SOURCE_DIR}/dominio
            ${CMAKE_CURRENT_SOURCE_DIR}/controladores
    )
else()
    message(FATAL_ERROR "No se encontraron archivos en Negocio")
endif()


