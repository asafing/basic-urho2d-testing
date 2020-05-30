#include <Urho3D/Engine/Application.h>
#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Input/InputEvents.h>
#include <Urho3D/Input/Input.h>

namespace Urho3D
{
	class Node;
	class Scene;
	class Sprite;
}


using namespace Urho3D;

class FirstApp : public Application
{
private:
	int a;
	int b;
	SharedPtr<Scene> scene_;	
	SharedPtr<Node> cameraNode_;
	SharedPtr<Graphics> graphics;
public:
	FirstApp(Context* context);
	virtual void Setup();
	virtual void Start();
	virtual void Stop();
	void HandleKeyDown(StringHash eventType, VariantMap& eventData);
};