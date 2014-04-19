#include <interval.h>
#include <item.h>
#include <Sinbyen.h>

inherit "/std/item";

void configure() {
	::configure();
	add_description(Description_Type_Generic);
	set_craft(Craft_Exquisite);
	armour()->set_autonomon_adapt(True);
	armour()->set_armour_type(Armour_Type_Hauberk);
	armour()->set_armour_style(Armour_Style_Light_Mail);


	add_proportion(([
		Element_Type              : Material_Mithril,
		Element_Proportion        : 0.85,
		Element_Color             : "gray",
	]));
	add_proportion(([
		Element_Type              : Material_Leather,
		Element_Proportion        : 0.15,
		Element_Part			  : Part_Underlayer,
	]));
}
