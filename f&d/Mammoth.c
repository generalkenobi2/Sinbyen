#include <Sinbyen.h>
#include <item.h>

inherit "/std/comestible";

void configure() {
        ::configure();
        set_creator(({ "kenobi" }));
        set_comestible_type("food");
		set_food(30);
        set_heal(5);
        set_pleasure(0.50);
        set_portable(True);
		add_proportion(([
			Element_Type		: Material_Flesh,
			Element_Proportion	: 1.0,
			Element_Flags		: Element_Flag_Provide_Default_Color | Element_Flag_Suppress_Material_Adjectives,
		]));
		add_proportion(([
			Element_Type		: Material_Salt,
			Element_Proportion	: 0.01,
			Element_Part		: Part_Infusion,
		]));
		add_proportion(([
			Element_Type		: Material_Pepper,
			Element_Proportion	: 0.01,
			Element_Part		: Part_Infusion,
		]));
}
