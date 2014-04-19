#include <Grinning_Cat.h>
#include <Sinbyen.h>
#include <item.h>

inherit Sinbyen_Comestible("Mammoth");

void configure() {
        ::configure();
		alter_identity(([
			Identity_Nouns          : ({ "mammoth wings", "wings" }),
		]));
        add_description("Apparently mammoths have wings.  This is a large plate of boneless, breaded, and fried mammoth wings.");
        set_consume_message("The wings taste heavenly.");
        set_servings(10);
        set_container(Grinning_Cat_Misc("ceramic_plate"));
		add_proportion(([
			Element_Type		: Material_Ceramic,
			Element_Proportion	: 0.5,
			Element_Part		: Part_Backing,
			Element_Flags		: Element_Flag_Secondary,
		]));

}
