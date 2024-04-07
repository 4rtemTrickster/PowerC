project(UIFramework)

add_library(${PROJECT_NAME} STATIC
    src/Layer.h
    src/Application.cpp
    src/Application.h
    src/EntryPoint.h
)

target_include_directories(${PROJECT_NAME} PRIVATE src)

find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(Vulkan REQUIRED)
find_package(glm CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PUBLIC
    glfw
    imgui::imgui
    glm::glm
    Vulkan::Vulkan
)