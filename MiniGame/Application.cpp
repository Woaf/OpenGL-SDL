#include "Application.h"

Application* Application::applicationInstance = nullptr;

Application* Application::GetInstance ()
{
	if (nullptr == applicationInstance) {
		applicationInstance = new Application ();
	}

	return applicationInstance;
}

Application::Application ()
{
	try {
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
			throw ApplicationException("Failed to initialize SDL.");
		}
		else {
			this->window = new Window("My first SDL window", 720, 480);
		}
	} catch (const ApplicationException& ex) {
		std::cerr << "Application error: ";
		#ifdef _DEBUG
		std::cerr << "at line " << 20 << std::endl;
		#endif
		std::cerr << ex.what () << std::endl;
	} catch (WindowException& ex) {
		std::cerr << "Window error occured: " << std::endl;
		#ifdef _DEBUG 
		std::cerr << "at line " << __LINE__ << std::endl;
		#endif
		std::cerr << ex.what () << std::endl;
	} catch (GlContextException& ex) {
		std::cerr << "Renderer creation error occured: " << std::endl;
		#ifdef _DEBUG 
		std::cerr << "at line " << __LINE__ << std::endl;
		#endif
		std::cerr << ex.what () << std::endl;
	}
}

bool Application::Run ()
{
	if (this->active)
	{
		SDL_Event event;
		while (SDL_PollEvent (&event))
		{
			switch (event.type)
			{
			case SDL_QUIT: 
				this->Stop ();
			case SDL_KEYDOWN: 
				switch (event.key.keysym.sym) {
				case SDLK_ESCAPE: 
					this->Stop ();
					break;
				}
				break;
			}
		}
		glClearColor(0.87f, 0.32f, 0.43f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		this->window->Update ();
	}

	return this->active;
}

void Application::Stop ()
{
	this->active = false;
}

template <class T>
void Application::SetState()
{
	if (this->state != nullptr)
	{
		this->state->Destroy();
	}
	this->state = new T();
	this->state->Init();
}

Application::~Application ()
{
	SDL_Quit ();
}

