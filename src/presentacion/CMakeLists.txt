file(GLOB PRESENTACION_HEADERS *.h)
file(GLOB PRESENTACION_SOURCES *.cpp)

if(PRESENTACION_SOURCES)
    add_library(Presentacion STATIC ${PRESENTACION_SOURCES} ${PRESENTACION_HEADERS})
    target_include_directories(Presentacion PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
else()
    message(FATAL_ERROR "No se encontraron archivos en Presentacion")
endif()