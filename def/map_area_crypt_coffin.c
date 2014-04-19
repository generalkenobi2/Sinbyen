#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("crypt coffin");
    set_map_feature_summary("near a large tomb");
	add_map_feature_terrain(Terrain_Unholy);
	add_map_feature_terrain(Terrain_Ground);
	add_map_feature_realm("Sinbyen_Crypt");
	add_map_feature_adjacency_exclusion("up");
	add_map_feature_adjacency_exclusion("down");	
	set_map_feature_exposure(Exposure_None);
	set_map_feature_exploration_significant(True);
	set_map_feature_visualize("{{gray}+}");
	set_map_feature_specify("+");
	set_map_feature_light(0);
		add_map_feature_contents(({
			Sinbyen_Misc("deathstone"),
		}));
	
		add_map_feature_description(([
				Description_Type            : Description_Type_Viewer_Condition,
				Description_Index           : ([
					Condition_Type_Code     : Condition_Type_Astral_Perception,
					Condition_Value         : (3),
				]),
				Description_Content         : ({
					"The area seems almost alive with an {{unholy fire}ancient, evil, power}.",
				}),
		]));
}
