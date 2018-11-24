#include <memory>
#include <string>
#include "Component.h"

namespace myengine
{
	class Object : public Component
	{

	public:
		Object();
		Object(std::string output);
	};

}