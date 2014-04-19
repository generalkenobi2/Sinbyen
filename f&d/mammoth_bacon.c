#include <Grinning_Cat.h>
#include <Sinbyen.h>
#include <item.h>

inherit Sinbyen_Comestible("Mammoth");

void configure() {
        ::configure();
		alter_identity(([
			Identity_Nouns          : ({ "plate of bacon", "bacon" }),
		]));
        add_description("Six long thick strips of lightly salted mammoth bacon.");
        set_consume_message("The bacon is amazing, and leaves a salty aftertaste.");
        set_servings(6);
        set_container(Grinning_Cat_Misc("ceramic_plate"));
		add_proportion(([
			Element_Type		: Material_Ceramic,
			Element_Proportion	: 0.5,
			Element_Part		: Part_Backing,
			Element_Flags		: Element_Flag_Secondary,
		]));
}
