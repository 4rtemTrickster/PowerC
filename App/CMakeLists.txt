project(App)
set(AppName PowerC)

add_executable(${AppName} src/main.cpp)

target_link_libraries(${AppName} PRIVATE UIFramework)

target_include_directories(${AppName} PUBLIC ${PowerC_SOURCE_DIR}/Core/UIFramework/src)