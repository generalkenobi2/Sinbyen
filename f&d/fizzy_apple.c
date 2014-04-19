#include <Sinbyen.h>
#include <item.h>

inherit Sinbyen_Comestible("Fizzy_Base");

void configure() {
        ::configure();
		alter_identity(([
			Identity_Nouns          : ({ "apple fizzy", "fizzy", "apple" }),
		]));
        add_description("A tall bubbling apple flavoured beverage with a {{dark red}red} label.");
        set_consume_message("The sweet {{dark red}apple} flavour is delightful.");
		add_proportion(([
			Element_Type		: Material_Apple,
			Element_Proportion	: 1.0,
			Element_Part		: Part_Infusion,
			Element_Flags		: Element_Flag_Provide_Default_Color
		]));
}
