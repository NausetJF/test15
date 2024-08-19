

file(GLOB helloworld_SRC CONFIGURE_DEPENDS "*.h" "*.c")

add_executable(${PROJECT_NAME} ${helloworld_SRC})
target_link_libraries(${PROJECT_NAME} raylib)
# find_library(sodium NAMES sodium)
target_link_libraries(${PROJECT_NAME} sodium)
# target_link_libraries(${PROJECT_NAME} ImageMagick)

# file(CREATE_LINK "${PROJECT_SOURCE_DIR}/media"
#         "${CMAKE_CURRENT_BINARY_DIR}/media" SYMBOLIC)
# set(RESOURCE_DIR ${CMAKE_SOURCE_DIR}/media)
# set(MEDIA_DIR ${CMAKE_SOURCE_DIR}/src/media)


file(COPY ${CMAKE_SOURCE_DIR}/media DESTINATION ${CMAKE_BINARY_DIR}/media)
