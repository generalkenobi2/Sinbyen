#include <Sinbyen.h>
#include <item.h>

inherit "/std/item";

mixed query_room_desc() {
    mixed array content = ({
        ({ 'a', this_object() }), "is attached to the {{dark gray}massive steel forge}.",
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
        Identity_Name           : "bellows",
        Identity_Nouns          : ({ "bellows" }),
    ]));
    add_description(({
        ({ 't', 0 }), "is worn with use but is holding together well",
 
    }));
    set_craft(Craft_Excellent);
        set_shape(([
        Shape_Type              : Geometry_Block,
        Shape_Length            : 6.0,
        Shape_Width             : 5.0,
        Shape_Height            : 2.0,
    ]));

    add_proportion(([
        Element_Type            : Material_Leather,
        Element_Proportion      : 1.0,
        Element_Flags           : Element_Flag_Secondary | Element_Flag_Provide_Default_Color,
    ]));
    add_proportion(([
        Element_Type            : Material_Steel,
        Element_Proportion      : 1.0,
        Element_Flags           : Element_Flag_Secondary,
    ]));
}

status get() {
        return True;
}
