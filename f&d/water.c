#include <item.h>

inherit "/std/comestible";

void configure() {
	::configure();
	set_names(({ "water pack", "flask", "water" }));
	add_description("A backpack fitted with a large pouch to carry several balaths of water");
	set_restore_endurance(24);
	set_comestible_type("drink");
	set_drink(24);
	set_pleasure(0.40);
	set_consume_message("The water is cool, clear and refreshing.  Ahh!.");
	set_servings(10);
    set_container(LS_Container("backpack"));
	set_portable(True);
	set_shape(([
		Shape_Type              : Geometry_Block,
		Shape_Length            : 1.5,
		Shape_Width				: 3.0,
		Shape_Height			: 4.0,
	]));
	add_proportion(([
		Element_Type		: Material_Water,
		Element_Proportion	: 2.00,
		Element_Part		: Part_Infusion,
		Element_Flags		: Element_Flag_Secondary,
	]));
	add_proportion(([
		Element_Type		: Material_Plastic,
		Element_Proportion	: 0.01,
		Element_Part		: Part_Infusion,
		Element_Flags		: Element_Flag_Secondary,
	]));
	add_proportion(([
		Element_Type		: Material_Leather,
		Element_Proportion	: 0.5,
	]));
}

