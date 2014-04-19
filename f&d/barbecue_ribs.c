#include <Sinbyen.h>
#include <item.h>

inherit Sinbyen_Comestible("Barbecue");

void configure() {
        ::configure();
		add_description("a large rack of barbecued ribs");
		alter_identity(([
			Identity_Nouns          : ({ "rack of barbecued ribs", "ribs", "rack"}),
		]));
        set_food(24);
        set_heal(5);
		set_shape(([
			Shape_Type              : Geometry_Block,
			Shape_Length            : 4.0,
			Shape_Width				: 1.3,
			Shape_Height			: 0.5,
		]));
        set_servings(4);
}
