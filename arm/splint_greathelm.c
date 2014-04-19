#include <interval.h>
#include <item.h>
#include <Sinbyen.h>

inherit "/std/item";

void configure() {
	::configure();
	add_description(Description_Type_Generic);
	set_craft(Craft_Exquisite);
	armour()->set_autonomon_adapt(True);
	armour()->set_armour_type(Armour_Type_Greathelm);
	armour()->set_armour_style(Armour_Style_Splint_Mounted);
	armour()->set_race("orc");


	add_proportion(([
		Element_Type              : Material_Steel,
		Element_Proportion        : 3.0,
		Element_Color             : "gray",
	]));
	add_proportion(([
		Element_Type              : Material_Leather,
		Element_Proportion        : 0.15,
		Element_Part			  : Part_Underlayer,
	]));
}
