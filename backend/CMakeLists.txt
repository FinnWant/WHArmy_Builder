add_executable(WHArmy_builder main.cpp units.cpp)

target_link_libraries(WHArmy_builder PRIVATE nlohmann_json::nlohmann_json)

target_include_directories(WHArmy_builder PRIVATE ${CMAKE_SOURCE_DIR}/backend)