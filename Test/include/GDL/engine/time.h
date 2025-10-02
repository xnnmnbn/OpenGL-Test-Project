#include "../tools/typedefs.h"

namespace gdl::engine {

class Time {
public:
	static f32 time;
	static f32 delta;

	static void update();
};


}
