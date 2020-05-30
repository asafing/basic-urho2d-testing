#include "Application.h"
#include <Urho3D/Engine/Application.h>
#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Engine/Console.h>
#include <Urho3D/UI/Cursor.h>
#include <Urho3D/Engine/DebugHud.h>
#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Engine/EngineDefs.h>
#include <Urho3D/IO/FileSystem.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/Input/InputEvents.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Scene/SceneEvents.h>
#include <Urho3D/UI/Sprite.h>
#include <Urho3D/Graphics/Texture2D.h>
#include <Urho3D/Core/Timer.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/Resource/XMLFile.h>
#include <Urho3D/IO/Log.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Graphics/Octree.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Graphics/Zone.h>

FirstApp::FirstApp(Context* context) :
    Application(context)
{
}
void FirstApp::Setup()
{
    // Called before engine initialization. engineParameters_ member variable can be modified here
}
void FirstApp::Start()
{
    scene_ = new Scene(context_);
    scene_->CreateComponent<Octree>();
    cameraNode_ = scene_->CreateChild("Camera");
    cameraNode_->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
    Camera* camera = cameraNode_->CreateComponent<Camera>();
    camera->SetOrthographic(true);
    graphics = GetSubsystem<Graphics>(); 
    // Set camera ortho size (the value of PIXEL_SIZE is 0.01)
    camera->SetOrthoSize((float)graphics->GetHeight() * 0.01); 

    // Called after engine initialization. Setup application & subscribe to events here
    SubscribeToEvent(E_KEYDOWN, URHO3D_HANDLER(FirstApp, HandleKeyDown));
}
void FirstApp::Stop()
{
    // Perform optional cleanup     after main loop has terminated
    this->b--;
   
}
void FirstApp::HandleKeyDown(StringHash eventType, VariantMap& eventData)
{
    using namespace KeyDown;
    // Check for pressing ESC. Note the engine_ member variable for convenience access to the Engine object
    int key = eventData[P_KEY].GetInt();
    if (key == KEY_ESCAPE) 
        engine_->Exit();
    if (key == KEY_UP)
        this->a++;
}

URHO3D_DEFINE_APPLICATION_MAIN(FirstApp)