#include <item.h>

inherit "/std/comestible";


configure() {
	::configure();
		alter_identity(([
			Identity_Nouns          : ({ "water pack", "water", "pack"}),
		]));
	add_description("A backpack fitted with a large pouch to carry several balaths of water");
	set_restore_endurance(24);
	armour()->set_armour_type(Armour_Type_Backpack);
	armour()->set_autonomon_adapt(True);
	armour()->set_race("orc");
	set_comestible_type("drink");
	set_servings(24);
	set_drink(24);
	set_pleasure(0.40);
	set_consume_message("The water is cool, clear and refreshing.  Ahh!.");

	set_container(LS_Container("backpack"));
	set_portable(True);
	set_shape(([
		Shape_Type              : Geometry_Block,
		Shape_Length            : 1.5,
		Shape_Width				: 3.0,
		Shape_Height			: 4.0,
	]));
	add_proportion(([
		Element_Type		: Material_Leather,
		Element_Proportion	: 1.0,
		Element_Flags		: Element_Flag_Provide_Default_Color | Element_Flag_Suppress_Material_Adjectives | Element_Flag_Suppress_Color_Name,
		Element_Color		: "brown",
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

}

