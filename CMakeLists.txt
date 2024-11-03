cmake_minimum_required(VERSION 3.10)
project(Blackjack)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the SFML package
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

# Add source files
set(SOURCES
        main.cpp
        blackjackfunctions.cpp
        button.cpp
        card.cpp
        deck.cpp
        game.cpp
        genplayer.cpp
        hand.cpp
        house.cpp
        player.cpp
        ResourcePath.mm  # Objective-C++ file
)

# Include directories
include_directories(${SFML_INCLUDE_DIR})

# Add the executable
add_executable(Blackjack ${SOURCES})

# Link SFML libraries and Foundation framework explicitly
target_link_libraries(Blackjack sfml-system sfml-window sfml-graphics sfml-network sfml-audio "-framework Foundation")

# Set Objective-C++ compilation for ResourcePath.mm
set_source_files_properties(ResourcePath.mm PROPERTIES LANGUAGE CXX)

# Copy Images folder to the build directory
add_custom_command(TARGET Blackjack POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Images $<TARGET_FILE_DIR:Blackjack>/Images)
