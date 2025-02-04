#pragma once
#include "core.h"
#include "core-files/Event/Event.h"
#include "core-files/Event/ApplicationEvent.h"
#include "Window.h"	
#include "LayerStack.h"
#include "core-files/ImGui/ImGuiLayer.h"


#include "Timestep.h"

namespace HyperR
{
	class HyperR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		inline Window& GetWindow() { return *m_Window; }
		
		inline static Application& Get() { return *s_Instance; }
	
	private:

		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		bool m_Minimized = false;

		float m_LastFrameTime = 0.0f;
		static Application* s_Instance;
	};
	Application* CreateApplication();
}


