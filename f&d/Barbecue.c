#include <Sinbyen.h>
#include <item.h>

inherit "/std/comestible";

void configure() {
        ::configure();
        set_comestible_type("food");
        set_pleasure(0.30);
        set_portable(True);
        set_consume_message("The smokey flavor is fantastic.");
        add_proportion(([
            Element_Type        : Material_Flesh,
            Element_Proportion    : 1.0,
            Element_Flags        : Element_Flag_Provide_Default_Color | Element_Flag_Suppress_Material_Adjectives | Element_Flag_Suppress_Color_Name,
            Element_Color        : "black-streaked dark red",
        ]));
        add_proportion(([
            Element_Type        : Material_Smoke,
            Element_Proportion    : 0.01,
            Element_Part        : Part_Infusion,
        ]));
}
