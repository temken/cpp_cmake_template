file(GLOB SOURCES "./*.cpp")

add_executable( executable ${SOURCES})

install(TARGETS executable DESTINATION ${BIN_DIR})
