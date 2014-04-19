#include <interval.h>
#include <item.h>
#include <Sinbyen.h>

inherit Sinbyen_Armour("Crimson_Armour");

void configure() {
	::configure();
	armour()->set_autonomon_adapt(True);
	armour()->set_armour_type(Armour_Type_Full_Suit);
	armour()->set_armour_style(Armour_Style_Articulated);
	armour()->set_race("human");
	add_proportion(([
		Element_Type              : Material_Leather,
		Element_Proportion        : 3.0,
		Element_Color             : random_element(({
									"black",
									"dark red",
									"brown",
	})),
}
