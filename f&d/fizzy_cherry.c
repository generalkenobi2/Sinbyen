#include <Sinbyen.h>
#include <item.h>

inherit Sinbyen_Comestible("Fizzy_Base");

void configure() {
        ::configure();
		alter_identity(([
			Identity_Nouns          : ({ "cherry fizzy", "fizzy", "cherry" }),
		]));
        add_description("A tall bubbling cherry flavoured beverage with a {{dark red}red} label.");
        set_consume_message("The sweet {{dark red}cherry} flavour is delightful.");
		add_proportion(([
			Element_Type		: Material_Cherry,
			Element_Proportion	: 1.0,
			Element_Part		: Part_Infusion,
			Element_Flags		: Element_Flag_Provide_Default_Color
		]));
}
