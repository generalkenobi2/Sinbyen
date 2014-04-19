#include <materials.h>
#include <properties.h>

inherit "/std/comestible";

void create() {
::create();
	set_names(({"glass of {{fire}firebreather} whiskey","glass","firebreather","whiskey"}));
set_long("A tall glass of {{dark red}cinnamon spiced} firebreather whiskey");
	set_intoxication(15);
	set_heal(5);
	set_comestible_type("drink");
set_portable(1);
	set_mass(1);
	set_container("/obj/containers/glass");
	set_consume_message("A shockwave runs through your body.\n");
	add_material(Material_Glass);
	add_material(Material_Alcohol);
	add_material(Material_Cinnamon);
}
