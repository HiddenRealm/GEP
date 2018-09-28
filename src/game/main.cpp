#include<myengine/myengine.h>
#include<memory>

using namespace myengine;

int main()
{
	//Init Engine
	std::shared_ptr<Core> core = Core::initialize();

	//Single Item
	std::shared_ptr<Entity> entity = core->addEntity();

	//Simple Component
	std::shared_ptr<TestScreen> testscreen = entity->addComponent<TestScreen>();

	//Start Loop
	core->start();

return 0;
}