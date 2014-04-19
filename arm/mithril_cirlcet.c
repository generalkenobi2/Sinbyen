#include <Valathyr.h>
#include <item.h>

inherit "/std/item";

void configure() {
	::configure();
	add_description(Description_Type_Generic);
	set_craft(Craft_Exquisite);
	armour()->set_armour_type(Armour_Type_Circlet);
	armour()->set_race("dana");
	armour()->set_autonomon_adapt(True);
	add_material(Material_Mithril);
}
