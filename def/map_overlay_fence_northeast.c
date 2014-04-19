#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Overlay_Fence");

void configure() {
        ::configure();
		set_map_feature_name("fence northeast");
        set_fence_direction(Direction_Northeast);
		add_map_feature_exit_boundary(Direction_Northeast, "fence");
}
