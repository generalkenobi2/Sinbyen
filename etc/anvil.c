#include <Sinbyen.h>
#include <item.h>

inherit "/std/item";

mixed query_room_desc() {
    mixed array content = ({
        ({ 'a', this_object() }), "and a {{brown}water trough} sit near the forge.",
    });
    return Description(([
        Description_Type                                : Description_Type_Simple,
        Description_Order                               : Description_Order_Very_Slightly_Early,
        Description_Content                             : content,
    ]));
}
void configure() {
    ::configure();
       alter_identity(([
        Identity_Name           : "anvil",
        Identity_Nouns          : ({ "anvil" }),
    ]));
    set_indestructible(True);
    add_description(({
        ({ 't', 0 }), "nicked and scratched from repeated use.",
        "It appears to have been bolted into the stone flooring for added stability",
 
    }));
    set_craft(Craft_Excellent);
        set_shape(([
        Shape_Type              : Geometry_Block,
        Shape_Length            : 8.0,
        Shape_Width             : 2.0,
        Shape_Height            : 4.0,
    ]));
    add_proportion(([
        Element_Type            : Material_Steel,
        Element_Proportion      : 2.0,
        Element_Color           : "dark gray",
    ]));
}

status get() {
        return True;
}

