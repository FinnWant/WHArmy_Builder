# Add the executable
add_executable(WHArmy_builder main.cpp units.cpp)

# Link libraries
target_link_libraries(WHArmy_builder PRIVATE nlohmann_json::nlohmann_json)

# Include Crow (header-only, no linking required)
target_include_directories(WHArmy_builder PRIVATE ${crow_SOURCE_DIR}/include)

# Include Asio (system-installed library)
target_include_directories(WHArmy_builder PRIVATE /usr/include)

# Include directories
target_include_directories(WHArmy_builder PRIVATE ${CMAKE_SOURCE_DIR}/backend)