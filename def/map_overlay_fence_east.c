#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Overlay_Fence");

void configure() {
        ::configure();
		set_map_feature_name("fence east");
        set_fence_direction(Direction_East);
		set_fence_direction(Direction_Southeast);
		set_fence_direction(Direction_Northeast);
		add_map_feature_exit_boundary(Direction_East, "fence");
		add_map_feature_exit_boundary(Direction_Northeast, "fence");
		add_map_feature_exit_boundary(Direction_Southeast, "fence");
}
