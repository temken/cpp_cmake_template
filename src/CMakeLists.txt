file(GLOB SOURCES "./*.cpp")

add_executable( executable ${SOURCES})

# # Linking up all libraries (includes the coverage settings set by 'example' library)
# target_link_libraries(executable PRIVATE example)

# Include code-coverage settings:
target_link_libraries(executable PUBLIC coverage_config)

install(TARGETS executable DESTINATION ${BIN_DIR})

# add_test(NAME executable_test COMMAND executable)