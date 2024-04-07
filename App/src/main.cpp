//
// Created by 4rtemTrickster on 07-Apr-24.
//

#include "Application.h"
#include "EntryPoint.h"

class ExampleLayer : public Layer
{
public:
    virtual void on_ui_render() override
    {
        ImGui::Begin("Hello");
        ImGui::Button("Button");
        ImGui::End();

        ImGui::ShowDemoWindow();
    }
};

UI::Application* UI::CreateApplication(int argc, char** argv)
{
    UI::ApplicationSpec spec;
    spec.name = "PowerC";

    UI::Application* app = new UI::Application(spec);

    app->push_layer(std::make_shared<ExampleLayer>());
    auto menubar_callback = [app]()
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Exit"))
            {
                app->close();
            }
            ImGui::EndMenu();
        }
    };

    app->set_menubar_callback(menubar_callback);

    return app;
}
