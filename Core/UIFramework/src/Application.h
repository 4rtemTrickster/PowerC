#pragma once

#include <string>
#include <functional>
#include <memory>

#include "imgui.h"
#include "vulkan/vulkan.h"

#include "Layer.h"

struct GLFWwindow;

namespace UI
{

struct ApplicationSpec
{
    std::string name = "App";
    uint32_t width = 1920;
    uint32_t height = 1080;
};

class Application
{
public:
    explicit Application(const ApplicationSpec& application_spec = ApplicationSpec());

    ~Application();

    static Application& get();

    void run();

    void set_menubar_callback(const std::function<void()>& menubar_callback) { m_menubar_callback = menubar_callback; }

    template<LayerSubclass T>
    void push_layer();

    void push_layer(const std::shared_ptr<Layer>& layer);

    void close() { m_running = false; }

    float get_time();

    [[nodiscard]]
    GLFWwindow* get_window_handle() const { return m_window_handle; }

    static VkInstance get_instance();
    static VkPhysicalDevice get_physical_device();
    static VkDevice get_device();

    static VkCommandBuffer get_command_buffer(bool begin);
    static void flush_command_buffer(VkCommandBuffer command_buffer);

    static void submit_resource_free(std::function<void()>&& func);

private:

    void init();

    void shutdown();

private:

    ApplicationSpec m_spec;
    GLFWwindow* m_window_handle = nullptr;
    bool m_running = false;

    float m_time_step = 0.0f;
    float m_frame_time = 0.0f;
    float m_last_frame_time = 0.0f;

    std::vector<std::shared_ptr<Layer>> m_layer_stack;
    std::function<void()> m_menubar_callback;
};

Application* CreateApplication(int argc, char** argv);

}