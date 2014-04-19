#include <item.h>
#include <Sinbyen.h>

inherit "/std/item";

void configure() {
	::configure();
	add_description(Description_Type_Generic);
	set_craft(Craft_Exquisite);
	armour()->set_armour_type(Armour_Type_Harness);
	armour()->set_race("kielleth");
	add_proportion(([
	    Element_Type            : Material_Leather,
	    Element_Proportion      : 0.8,
	    Element_Color           : "black",
	]));
	add_proportion(([
	    Element_Type            : Material_Qlippotam,
	    Element_Proportion      : 0.1,
	]));
	add_proportion(([
	    Element_Type            : Material_Logos,
	    Element_Proportion      : 0.1,
	]));
	
	set_global_rarity(Rarity_Unusual);
}
