#include <Sinbyen.h>
#include <item.h>

inherit "/std/comestible";

void configure() {
        ::configure();
        set_creator(({ "kenobi" }));
        set_comestible_type("food");
        set_pleasure(0.30);
        set_food(24);
        set_portable(True);
        set_consume_message("The fresh fish is soft and tasty.");
        add_proportion(([
            Element_Type        : Material_Flesh,
            Element_Proportion  : 1.0,
            Element_Flags       : Element_Flag_Provide_Default_Color | Element_Flag_Suppress_Material_Adjectives,
        ]));
        add_proportion(([
            Element_Type        : Material_Vinegar,
            Element_Proportion  : 0.01,
            Element_Part        : Part_Coat,
            Element_Flags       : Element_Flag_Secondary,
        ]));
}
