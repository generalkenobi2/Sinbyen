#include <item.h>
#include <Sinbyen.h>

inherit "/std/item";

void configure() {
	::configure();
	add_description("a hand grenade");
	set_craft(Craft_Exquisite);
	set_identity(([
		Identity_Code			: "amulets of vengeance",
		Identity_Name           : "hand grenade",
		Identity_Nouns          : ({ "grenade" }),
	]));
	armour()->set_armour_type(Armour_Type_Panties);
	armour()->set_race("human");
	add_proportion(([
	    Element_Type            : Material_Steel,
	    Element_Proportion      : 1.0,
	    Element_Color           : "black",
	]));	
	set_global_rarity(Rarity_Unusual);
}
